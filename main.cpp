#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Map.hpp"

#include "Context.hpp"
#include "Wait.hpp"
#include "ExplorDanger.hpp"

using std::vector;

int main() {
    std::cout << "******* Pokemon Start *******" << std::endl;
    
    //client code
    std::srand(std::time(nullptr));//initialise la génération de nb aléa
    Context *context = new Context(new Wait);
    context->Request1();//démarrer jeu
    Map gameMap;
    context->Request1();//de Init à Explor
    //context->Request1();//de Explor à ExplorDanger

    //Dipslay tests
    Pokemon mew("Mew",5,100,30,70,3);
    Pokemon mew2("Mew2",10,100,100,50,3);
    mew.displayInfo();
    mew2.displayInfo();
    mew.attack(mew2);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);

    std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    std::cout <<"Nombre de Pokemon en memoire : " << mew.getNumberOfPokemon() << std::endl;

    Pokedex* pokedex = Pokedex::getInstance("pokedex.csv");

    //pokedex->displayPokemonList();

    char input;
    while (true) {
        // Afficher la carte avec le joueur
        gameMap.display();
        std::cout << "Utilisez ^ pour haut, v pour bas, < pour gauche, > pour droite : ";
        std::cin >> input; // Lecture de l'entrée utilisateur

        // Traiter le mouvement du joueur
        if (input == '^' || input == 'v' || input == '<' || input == '>') {
            gameMap.movePlayer(input, context);
        } else {
            std::cout << "Entrée invalide, veuillez réessayer." << std::endl;
        }

        // Sortir si le jeu passe à l'état ExplorDanger
        if (typeid(*context->getCurrentState()).name() == typeid(ExplorDanger).name()) {
            std::cout << "Danger détecté! Un Pokémon sauvage pourrait apparaître!" << std::endl;
            break; // Terminer la boucle de jeu
        }
    }

    delete context;

    return 0;
}
