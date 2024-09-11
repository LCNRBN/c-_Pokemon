#include "SetOfPokemon.hpp"

#include <iostream>

void SetOfPokemon::displayPokemonList() const {
    std::cout<<"Liste des Pokemon:"<<std::endl;
    for (size_t i = 0; i<pokemons.size();++i){
        std::cout<<i+1<<": "<<pokemons[i].getName()<<std::endl;
    }
}


//Potential Concrete Derived Class ????
//Since SetOfPokemon is an abstract class, you will need to create a derived class to implement the abstract methods.

// void SetOfPokemon::displayPokemonList() const {
//     std::cout << "Pokemon List:" << std::endl;
//     for (const auto& pokemon : pokemons) {
//         pokemon.displayInfo();  // Call Pokemon's displayInfo method
//     }
// }