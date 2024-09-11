#ifndef POKEMONIS_SETOFPOKEMON_HPP
#define POKEMONIS_SETOFPOKEMON_HPP

#include "Pokemon.hpp"

#include <string>
#include <vector>

using std::vector;
using std::string;

class SetOfPokemon{ //classe abstraite
    protected:
        vector<Pokemon> pokemons;
    public:
        virtual ~SetOfPokemon()=default;
    
        //Méthodes abstraites
        virtual Pokemon getPokemonByIndex(int index) const=0; //Abstract method to retrieve a Pokemon by its index in the vector.
        virtual Pokemon getPokemonByName(const string& name) const=0; //Abstract method to retrieve a Pokemon by its name.

        //Méthodes conrètes
        void displayPokemonList() const; //A method that can be used to display the list of all Pokémon in the collection.
    
        //Constructeur abstrait
        SetOfPokemon()=default; //Default constructor for the abstract class.
};

#endif //POKEMONIS_SETOFPOKEMON_HPP
