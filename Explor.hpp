#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "State.hpp"
#include "Context.hpp"
#include "ExplorDanger.hpp"

class Explor : public State {
    public:
        void Handle1() override {
            std::cout << "Explor: Vous explorez pour trouver un Pokémon...\n";
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Temps fixe avant un danger potentiel

            int dangerTime = rand() % 5 + 1; //temps aléatoire entre 1 et 5 secondes
            std::this_thread::sleep_for(std::chrono::seconds(dangerTime));
            std::cout << "Explor: Un danger approche !\n";
            this->context_->TransitionTo(new ExplorDanger);
        }

        void Handle2() override {
            std::cout << "Explor: Rien à signaler pour l'instant.\n";
        }
};
