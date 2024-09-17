#pragma once

#include "State.hpp"
#include "Context.hpp"
#include "Pokedex.hpp"
#include "Pokeball.hpp"
#include "Map.hpp"  // Inclure la classe Map pour accéder à l'instance de la carte et des Pokeballs

#include <iostream>
#include <string>

//à modifier : explordanger ne devrait pas gérer les pokeball
#include <iostream>

class ExplorDanger : public State {
public:
    //ExplorDanger(Pokedex* pokedex, Pokeball* pokeballs) : pokedex_(pokedex), pokeballs_(pokeballs) {}
    ExplorDanger() = default;

    void Handle1() override {
        std::cout << "ExplorDanger: Un Pokémon sauvage est apparu !\n";
        //handlePokemonCapture(); //Gère la capture de Pokémon ici
        }

    void Handle2() override {
        std::cout << "ExplorDanger: Attention, danger imminent !\n";
    }

// //version capture alt.
// private:
//     Pokedex* pokedex_;
//     Pokeball* pokeballs_;

//     void handlePokemonCapture() {
//         int availableSlot = -1;
//         for (int i = 0; i < 6; ++i) {
//             if (pokeballs_[i].isEmpty()) { 
//                 availableSlot = i;
//                 break;
//             }
//         }

//         if (availableSlot == -1) {
//             std::cout << "Vous n'avez plus de Pokéballs disponibles!\n";
//             return;
//         }

//         // Affichage de la liste des Pokémon disponibles dans le Pokédex
//         pokedex_->displayPokemonList();
//         std::cout << "Choisissez un Pokémon à capturer (nom ou index): ";
//         std::string choix;
//         std::cin >> choix;

//         Pokemon* chosenPokemon = nullptr;
//         try {
//             int index = std::stoi(choix) - 1;
//             chosenPokemon = pokedex_->getPokemonByIndex(index);
//         } catch (const std::invalid_argument&) {
//             chosenPokemon = pokedex_->getPokemonByName(choix);
//         }

//         if (chosenPokemon != nullptr) {
//             pokeballs_[availableSlot].addPokemon(chosenPokemon);
//             std::cout << "Vous avez capturé " << chosenPokemon->getName() << " dans la Pokéball " << (availableSlot + 1) << " !\n";
//         } else {
//             std::cout << "Le Pokémon choisi n'a pas été trouvé.\n";
//         }
//     }
};
