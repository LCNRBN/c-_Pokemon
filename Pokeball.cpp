#include "Pokeball.hpp"
#include  <stdexcept>

// FONCTIONS

// Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
Pokemon Pokeball::getPokemonByIndex(int index) const{
    if (index>=0 && index < pokemons.size()){ //index valide
        //On copie le Pokémon à l'index spécifié
        Pokemon p = pokemons[index];
        //On retire le Pokémon de la Pokeball
        pokemons.erase(pokemons.begin() + index); // "pokemons.erase" attend un iterator, donc on utilise "pokemons.begin() + index"
        return p; //on retourne le Pokémon retiré
    }
    throw std::out_of_range("Index out of range"); //index invalide
}

// Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
Pokemon Pokeball::getPokemonByName(const std::string& name) const{
    for (auto it = pokemons.begin(); it != pokemons.end(); ++it){ //On parcourt la liste des Pokémon dans la Pokeball
        if (it->getName()==name){ // Si le nom du Pokémon correspond
            Pokemon p = *it; // On copie le Pokémon trouvé
            pokemons.erase(it); // On retire le Pokémon de la Pokeball
            return p; // On retourne le Pokémon retiré
        }
    }
    throw std::invalid_argument("Pokemon not found"); // Si le Pokémon avec le nom donné n'est pas trouvé
}