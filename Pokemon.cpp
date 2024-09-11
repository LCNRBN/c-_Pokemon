//
// Created by antotauv on 05/09/2024.
//

#include "Pokemon.hpp"

#include <iostream>

int Pokemon::nbPokemon=0;

Pokemon::Pokemon(const string &name, int id, double hitPoint, double attack, double defense, int generation) : name(
        name), id(id), hitPoint(hitPoint), attackValue(attack), defense(defense), generation(generation) {
    std::cout << "Ici le constructeur de " << name << std::endl;
    nbPokemon++;
}

Pokemon::Pokemon(const Pokemon& anotherPokemon) : name(anotherPokemon.name),id(anotherPokemon.id),
        hitPoint(anotherPokemon.hitPoint), attackValue(anotherPokemon.attackValue), defense(anotherPokemon.defense),
        generation(anotherPokemon.generation){
    std::cout<<"Recopie de " << name <<std::endl;
        nbPokemon++;
}

void Pokemon::scream(){
    std::cout<<"Grrr ! I'm " << name << std::endl;
}

void Pokemon::displayInfo(){
    std::cout << "*** Pokemon #" << id << " : " << name << ", hitPoint : "
    << hitPoint <<" nbPokemon:"<< nbPokemon << std::endl;
}

Pokemon::~Pokemon() {
    std::cout << "Ici le destructeur" << std::endl;
    nbPokemon--;
}

void Pokemon::attack(Pokemon &anotherPokemon) {
    if (this->attackValue > anotherPokemon.defense){
        anotherPokemon.sustainDamage(this->attackValue-anotherPokemon.defense);
    }
    else{
        std::cout << "Attack missed ! " << std::endl;
    }
}

int Pokemon::getNumberOfPokemon() {
    return nbPokemon;
}

//hitPoint = health point HP
void Pokemon::sustainDamage(int value) {
    hitPoint=(hitPoint-value)>0?hitPoint-value:0;
    std::cout << "Pokemon " << name << " sustained a " << value <<
    " damage. New hitPoint : " << hitPoint << std::endl;
}

string Pokemon::getName() const {
    return name;
}
