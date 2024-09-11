#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include "SetOfPokemon.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Pokedex : public SetOfPokemon{

    private:
        static Pokedex* instance; //Pointeur vers l'instance de Pokedex
        Pokedex(const std::string& nomFichier); // constructeur privé pour le singleton (empêche la création de plusieurs Pokedex)
    
    public:
        static Pokedex* getInstance(const std::string& nomFichier); //Méthode pour obtenir l'instance unique du Pokedex
        // Méthodes pour obtenir un Pokémon par index ou par nom
        Pokemon getPokemonByIndex(int index) const override;
        Pokemon getPokemonByName(const std::string& name) const override;

        void lireCSV(const std::string& nomFichier); // Méthode pour lire un fichier CSV et charger les Pokémon dans le Pokedex

};

#endif //POKEDEX_HPP