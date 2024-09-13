#pragma once

#include "State.hpp"

#include <iostream>

class ExplorDanger : public State {
public:
    void Handle1() override {
        std::cout << "ExplorDanger: Un Pokémon sauvage est apparu !\n";
        // Ajouter ici la logique pour gérer un combat, fuir, etc.
    }

    void Handle2() override {
        std::cout << "ExplorDanger: Attention, danger imminent !\n";
    }
};
