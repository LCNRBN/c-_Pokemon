#pragma once

#include "State.hpp"
#include "Context.hpp"
#include "Pokedex.hpp"
#include "Pokeball.hpp"

#include <iostream>
#include <string>
#include <iomanip>

//gère le combat, déclenche l'affichage de l'arène, gère l'attaque du joueur et de X

class Combat : public State {
private:
    Pokemon* adversaryPokemon;
    Pokemon* playerPokemon;
    bool isPlayerTurn;

    Pokemon* getRandomPokemon(Pokedex* pokedex) { //choisi au hasard le Pokemon adversaire
        std::srand(std::time(0));
        int randomIndex = std::rand() % pokedex->totalnbOfPokemon;
        return pokedex->getPokemonByIndex(randomIndex);
    }

public:
    Combat() = default;

    void Handle1() override {
        std::cout << "Un Pokémon sauvage apparaît dans l'arène !" << std::endl;
    }
    
    void Handle2() override {
        std::cout << "Combat: en attente de nouvelles instructions\n";
    }
};