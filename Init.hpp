#pragma once

#include <iostream>
#include <typeinfo>
#include <chrono>
#include <thread>

#include "State.hpp"
#include "Context.hpp"
#//include "Wait.hpp"
#include "Explor.hpp"

class Init : public State{

 public:
  void Handle1() override {
    std::cout << "Init Initialisation du jeu...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Init: Prêt à explorer.\n";
    this->context_->TransitionTo(new Explor);
  }

  void Handle2() override {
    std::cout << "Init: Rien d'autre à faire ici.";
  }

};