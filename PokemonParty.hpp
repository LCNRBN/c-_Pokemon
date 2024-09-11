#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP

#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"

class PokemonParty : public SetOfPokemon { //HERITAGE

    public:
        //Constructeur
        PokemonParty(const std::vector<int>& indices, Pokeball& pokeball); //Constructeur qui prend un vecteur d'indices et retire les Pokémon du Pokeball en les ajoutant à la Party
        PokemonParty(const std::vector<string>& names, Pokeball& pokeball); //Constructeur qui prend un vecteur de noms et retire les Pokémon du Pokeball en les ajoutant à la Party

        //Fonction
        Pokemon getPokemonByIndex(int index) const override; //Fonction pour obtenir un Pokémon par index (à partir de la liste de la Party)
        Pokemon getPokemonByName(const string& name) const override; //Fonction pour obtenir un Pokémon par nom (à partir de la liste de la Party)

        void addPokemon(Pokemon& pokemon); //Fonction pour ajouter un Pokémon à la Party
};

#endif //POKEBALLPARTY_HPP
