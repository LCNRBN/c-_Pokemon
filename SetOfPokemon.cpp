#include "SetOfPokemon.hpp"

#include <iostream>

void SetOfPokemon::displayPokemonList() const {
    std::cout<<"Liste des Pokemon:"<<std::endl;
    for (size_t i = 0; i<pokemons.size();++i){
        //std::cout<<i+1<<": "<<pokemons[i].getName()<<std::endl;

        //version ptr*
        std::cout << i+1 << ": " << pokemons[i]->getName() << std::endl;
    }
}

//version ptr*
SetOfPokemon::SetOfPokemon() {
    // Initialisation si nécessaire
}
SetOfPokemon::~SetOfPokemon() {
    // Destruction si nécessaire, en particulier si la classe gère des ressources
}

// SetOfPokemon::~SetOfPokemon(){
//     for (Pokemon* p : pokemons){
//         delete p;
//     }
//     pokemons.clear(); //vide vecteur
// }