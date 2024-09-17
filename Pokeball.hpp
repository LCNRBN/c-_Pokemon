#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "SetOfPokemon.hpp"

class Pokeball : public SetOfPokemon{ //HERITAGE

    public:
        // CONSTRUCTEUR
        Pokeball()=default; //constructeur par défaut
        //Pokeball(){};

        // FONCTIONS
        //version ptr*
        Pokemon* getPokemonByIndex(int index) override; //Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
        Pokemon* getPokemonByName(const string& name) override; //Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
        Pokemon* removePokemonAtIndex(int index);
        Pokemon* removePokemonByName(const std::string& name);

        //version capture
        bool isEmpty() const ;
        void addPokemon(Pokemon* pokemon);        
};

#endif //POKEBALL_HPP