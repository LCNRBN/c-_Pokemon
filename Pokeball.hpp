#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "SetOfPokemon.hpp"

class Pokeball : public SetOfPokemon{ //HERITAGE

    public:
        // CONSTRUCTEUR
        Pokeball()=default; //constructeur par défaut
        //Pokeball(){};
        // FONCTIONS
        Pokemon getPokemonByIndex(int index) const override; //Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
        Pokemon getPokemonByName(const string& name) const override; //Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
};

#endif //POKEBALL_HPP