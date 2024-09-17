#pragma once

#include <vector>
#include <iostream>

#include "Context.hpp"
#include "ExplorDanger.hpp"
#include "Combat.hpp"
#include "Pokeball.hpp"
#include "Pokedex.hpp"

//à modifier : la Map ne devrait pas gérer les pokeball, ni les handleCapture, handleCombat

class Map {
public:
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> arena;
    int playerX, playerY;

    Pokedex* pokedex;
    //version capture à modifier en utilisant Pokeball.hpp aka "PC" à la place
    Pokeball pokeballs[6]; //6 Pokeballs max pour le joueur
    //version Combat
    Pokemon* playerPokemon;
    Pokemon* adversaryPokemon;
    bool isPlayerTurn;

    Map(Pokedex* pokedexInstance) : pokedex(pokedexInstance) { 
    //Lorsque le joueur se trouve à proximité des herbes, le jeu doit permettre au joueur de capturer un Pokémon
    //>>Pour que la carte puisse proposer cette liste de Pokémon au joueur, la classe Map doit avoir un accès direct au Pokedex
    //En passant un pointeur (Pokedex*) à la classe Map, on lui donne cet accès
    //Passer un pointeur à cette instance unique Pokedex garantit que toute modification ou interaction avec le Pokedex est effectuée sur cette unique instance partagée
    //>>Cela évite de créer plusieurs copies du Pokedex
        grid = { //Map
            {'.', 'o', '"', 'o', '.', '.', 'o', 'o', 'o', '"', '.', '.', '.', 'o', 'o'},
            {'.', 'o', '"', '.', '.', '.', '.', '.', '"', '"', '.', '.', 'o', 'o', 'o'},
            {'.', 'o', '"', '"', '.', '.', '.', '.', '"', '.', '.', '.', 'o', 'o', 'o'},
            {'.', 'o', '.', '.', 'o', '"', 'o', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', 'o', 'o', '.', 'o', '"', 'o', '.', '.', 'X', '.', '.', '.', 'o', '.'},
            {'.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', 'o', '.'},
            {'.', '.', 'o', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', 'o', 'o'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', 'o', '.', '.', 'o', 'o'},
            {'o', '.', 'o', '.', '.', '"', '"', '"', '.', 'o', 'o', 'o', '.', '"', 'o'},
            {'o', '.', '.', '.', '"', '"', '"', '"', '.', '.', '.', '.', '.', '"', '"'},
        };

        arena = {
            {'.', '.', '.', '.', '.', '.'},
            {'.', 'o', '.', '.', 'o', '.'},
            {'.', '.', 'J', 'X', '.', '.'},  // J pour joueur, X pour Pokémon adversaire
            {'.', 'o', '.', '.', 'o', '.'},
            {'.', '.', '.', '.', '.', '.'}
        };

        // Position initiale joueur
        playerX = 0;
        playerY = 0;
        isPlayerTurn = true; //par défaut
    }

    void display() {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == playerY && j == playerX) {
                    std::cout << "J "; // joueur : le caractère "J"
                } else {
                    std::cout << grid[i][j] << " "; // Affiche carte
                }
            }
            std::cout << std::endl;
        }
    }

    bool movePlayer(char direction, Context *context) {
        int newX = playerX;
        int newY = playerY;

        // Utilisation des caractères pour indiquer la direction
        if (direction == '^') newY--;
        else if (direction == 'v') newY++;
        else if (direction == '<') newX--;
        else if (direction == '>') newX++;

        // Vérifie si le mouvement est valide (dans les limites et pas de rocher)
        if (isValidMove(newX, newY)) {
            playerX = newX;
            playerY = newY;
            checkForDanger(context); // Vérifie s'il est proche des herbes hautes ou de X
            return true;
        } else {
            std::cout << "Mouvement bloqué par un obstacle ou les limites de la carte!\n";
            return false;
        }
    }

private:
    bool isValidMove(int x, int y) {
        if (x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()) {
            // On ne peut pas marcher sur un rocher : o
            return grid[y][x] != 'o';
        }
        return false;
    }

    void checkForDanger(Context *context) { //check si le joueur est à côté d'une case d'herbe (danger)
        //version capture
        if (isNextToGrass()) {
            std::cout << "Vous êtes proche d'une herbe haute '' ! Un Pokémon sauvage est apparu!\n";
            handlePokemonCapture(context);
        }
        //version Combat
        if (isNextToNaughtyPokemon()) {
            std::cout << "Vous faites face à un Pokémon sauvage X !\n";
            handleCombat(context);
        }
    }

    bool isNextToGrass() { //check si une case adjacente contient des herbes hautes : """"
        // checker les cases autour du joueur
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newX = playerX + j;
                int newY = playerY + i;
                if (newX >= 0 && newX < grid[0].size() && newY >= 0 && newY < grid.size()) {
                    if (grid[newY][newX] == '"') {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isNextToNaughtyPokemon() { //check si proche d'un adversaire : X
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newX = playerX + j;
                int newY = playerY + i;
                if (newX >= 0 && newX < grid[0].size() && newY >= 0 && newY < grid.size()) {
                    if (grid[newY][newX] == 'X') {
                        return true;
                    }
                }
            }
        }
        return false;
    }
//};

    //version capture
    void handlePokemonCapture(Context* context) {
        context->TransitionTo(new ExplorDanger);
        int availableSlot = -1;
        for (int i = 0; i < 6; ++i) { //check reste des Pokeballs vides ?
            if (pokeballs[i].isEmpty()) { //check si la Pokeball est vide
                availableSlot = i;
                break;
            }
        }

        if (availableSlot == -1) {
            std::cout << "Vous n'avez plus de Pokeball disponibles!\n";
            return;
        }

        // Affichage de la liste des Pokémon disponibles dans le Pokédex
        pokedex->displayPokemonList();
        std::cout << "Vous capturez ce dernier, choisissez son type (nom ou index du pokédex): ";
        std::string choix;
        std::cin >> choix;

        Pokemon* chosenPokemon = nullptr;
        try {
            int index = std::stoi(choix) - 1;
            chosenPokemon = pokedex->getPokemonByIndex(index);
        } catch (const std::invalid_argument&) {
            chosenPokemon = pokedex->getPokemonByName(choix);
        }

        if (chosenPokemon != nullptr) {
            //pokeballs[availableSlot].getPokemonByIndex(0); //Capturer le Pokémon
            pokeballs[availableSlot].addPokemon(chosenPokemon);
            std::cout << "Vous avez capturé " << chosenPokemon->getName() << " dans la Pokeball " << (availableSlot + 1) << " !\n";
        } else {
            std::cout << "Le Pokémon choisi n'a pas été trouvé.\n";
        }
    }

    //version Combat
    void handleCombat(Context* context) {
        context->TransitionTo(new Combat);
        context->Request1();

        // 1. Pokémon adversaire au hasard
        adversaryPokemon = getRandomPokemon();
        std::cout << "Un Pokémon sauvage " << adversaryPokemon->getName() << " apparaît !\n";

        // 2. Choix du Pokémon du joueur
        choosePlayerPokemon();

        // 3. Combat tour par tour
        displayArena();
        startCombat(context);
    }
     void displayArena() {
        std::cout << "****** Combat dans l'arène ******\n";
        for (int i = 0; i < arena.size(); ++i) {
            for (int j = 0; j < arena[i].size(); ++j) {
                std::cout << arena[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "*********************************\n";
    }
    // Sélection aléatoire d'un Pokémon pour l'adversaire
    Pokemon* getRandomPokemon() {
        std::srand(std::time(0));
        int randomIndex = std::rand() % pokedex->totalnbOfPokemon;
        return pokedex->getPokemonByIndex(randomIndex);
    }
    // Le joueur choisit un Pokémon parmi ses Pokéballs
    void choosePlayerPokemon() {
        std::cout << "Choisissez votre Pokémon (1 à 6) : ";
        int choice;
        while (true) {
            std::cin >> choice;
            if (choice < 1 || choice > 6 || pokeballs[choice - 1].isEmpty()) {
                std::cout << "Pokéball vide ou choix invalide. Réessayez : ";
            } else {
                // Utilisation de getPokemonByIndex() pour récupérer le Pokémon
                playerPokemon = pokeballs[choice - 1].getPokemonByIndex(0); // 0 car une Pokeball ne contient qu'un Pokémon
                if (playerPokemon != nullptr) {
                    std::cout << "Vous avez choisi : " << playerPokemon->getName() << "\n";
                    break;
                } else {
                    std::cout << "La Pokéball est vide. Réessayez : ";
                }
            }
        }
    }

    //  void choosePlayerPokemon() {
    //     std::cout << "Choisissez un Pokémon pour le combat :\n";
    //     for (int i = 0; i < 6; ++i) {
    //         if (!pokeballs[i].isEmpty()) {
    //             std::cout << (i + 1) << ". " << pokeballs[i].getPokemon()->getName() << "\n";
    //         }
    //     }
    //     int choice;
    //     std::cin >> choice;
    //     playerPokemon = pokeballs[choice - 1].getPokemon();
    // }

    // Début du combat
    void startCombat(Context* context) {
        while (true) {
            if (isPlayerTurn) {
                std::cout << "C'est votre tour!\n";
                std::cout << "1. Attaque \n2. Fuir \n";
                int action;
                std::cin >> action;
    /*PB*/          if (action == 1) {
                    playerPokemon->attack(* adversaryPokemon);
                    if (adversaryPokemon->getHp() <= 0) {
                        std::cout << "Le Pokémon sauvage est KO!\n";
                        break;
                    }
                } else if (action == 2) {
                    std::cout << "Vous avez fui le combat!\n";
                    break;
                }
                isPlayerTurn = false;
            } else {
                std::cout << "Le Pokémon sauvage attaque!\n";
                adversaryPokemon->attack(*playerPokemon);
                if (playerPokemon->getHp() <= 0) {
                    std::cout << "Votre Pokémon est KO!\n";
                    break;
                }
                isPlayerTurn = true;
            }
        }

        context->TransitionTo(new ExplorDanger);
    }
};