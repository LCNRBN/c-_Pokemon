#pragma once

#include <iostream>
#include <typeinfo>

#include "State.hpp"
#include "Init.hpp"

using std::string;

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class Wait : public State {
 public:
  void Handle1() override{
    string input;
    std::cout << "Démarrer le jeu ? (oui/non)\n";
    std::cin >> input;
    if (input == "oui"){
      std::cout << "Wait: Démarrage du jeu...\n";
      this->context_->TransitionTo(new Init); //Context *context_ 
    }
    else{
      std::cout <<"Wait: Le jeu n'a pas démarré.\n";
    }
  }

  void Handle2() override {
    std::cout << "Wait: Rien à faire ici.\n";
  }
};