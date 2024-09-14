#pragma once

#include <vector>
#include <iostream>

#include "Context.hpp"
#include "ExplorDanger.hpp"

class Map {
public:
    std::vector<std::vector<char>> grid;
    int playerX, playerY;

    Map() {
        grid = { //Map
            {'.', '.', '.', 'o', '.', '.', '.', '.', 'o', '.', '.', '.', '.', 'o', '.'},
            {'.', 'o', '.', '.', '.', '.', 'o', '.', '.', 'o', '.', '.', '.', '.', '.'},
            {'.', '.', '"', '"', '.', '.', '.', '.', '"', '"', '.', '.', 'o', '.', '.'},
            {'.', 'o', '.', '.', 'o', '.', 'o', '.', '.', '.', 'o', '.', '.', '.', '.'},
            {'.', '.', '.', 'o', '.', '.', 'o', '.', 'o', '.', '.', 'o', '.', 'o', '.'},
            {'.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.'},
            {'o', '.', '.', '.', 'o', '.', '.', 'o', '.', 'o', '.', '.', '.', 'o', '.'},
            {'.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.'},
            {'.', '.', 'o', '.', '.', 'o', '.', '.', '.', 'o', '.', 'o', '.', '.', '.'},
            {'.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        };
        // Position initiale joueur
        playerX = 0;
        playerY = 0;
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
            checkForDanger(context); // Vérifie s'il est proche des herbes hautes
            return true;
        } else {
            std::cout << "Mouvement bloqué par un obstacle ou les limites de la carte!\n";
            return false;
        }
    }

private:
    // Vérifie si la position est valide (dans les limites de la carte et pas de rocher)
    bool isValidMove(int x, int y) {
        // Vérifie que le joueur ne sort pas des limites de la carte
        if (x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()) {
            // On ne peut pas marcher sur un rocher
            return grid[y][x] != 'o';
        }
        return false;
    }

    // Vérifie si le joueur est à côté d'une case d'herbe (danger)
    void checkForDanger(Context *context) {
        if (isNextToGrass()) {
            std::cout << "Danger: Un Pokémon sauvage pourrait apparaître!\n";
            context->TransitionTo(new ExplorDanger);
        }
    }

    // Vérifie si une case adjacente contient des herbes hautes
    bool isNextToGrass() {
        // Vérifier les cases autour du joueur
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
};
