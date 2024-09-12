#include "Pokeball.hpp"
#include  <stdexcept>

// FONCTIONS

// Fonction pour obtenir un Pokémon par index et le retirer de la Pokeball
Pokemon* Pokeball::getPokemonByIndex(int index){// ou sans ptr*
    if (index>=0 && index < pokemons.size()){
        // On copie le Pokémon à l'index spécifié
        // Pokemon p = pokemons[index];
        // On retire le Pokémon de la Pokeball
        // pokemons.erase(pokemons.begin()+index);
        // return p; //on retourne le Pokémon retiré
        return pokemons[index]; //retourne un ptr brut
    }
    throw std::out_of_range("Index out of range"); //index invalide
}

// Fonction pour obtenir un Pokémon par nom et le retirer de la Pokeball
Pokemon* Pokeball::getPokemonByName(const std::string& name){// ou sans ptr*
    // for (auto it = pokemons.begin(); it != pokemons.end(); ++it){ //On parcourt la liste des Pokémon dans la Pokeball
    //     if (it->getName()==name){ // Si le nom du Pokémon correspond
    //         Pokemon p = *it; // On copie le Pokémon trouvé
    //         pokemons.erase(it); // On retire le Pokémon de la Pokeball
    //         return p; // On retourne le Pokémon retiré
    //     }
    // }
    for (auto& p : pokemons){
        if (p->getName() == name){
            return p; //retourne ptr brut
        }
    }

    throw std::invalid_argument("Pokemon not found"); // Si le Pokémon avec le nom donné n'est pas trouvé
}

//version ptr*
Pokemon* Pokeball::removePokemonAtIndex(int index) {
    if (index >= 0 && index < pokemons.size()) {
        Pokemon* pokemon = pokemons[index]; // Récupère le Pokémon
        pokemons[index] = nullptr; // Supprime le pointeur
        return pokemon; // Renvoie le Pokémon
    } else {
        throw std::out_of_range("Index out of range");
    }
}
Pokemon* Pokeball::removePokemonByName(const std::string& name) {
    for (auto& pokemon : pokemons) {
        if (pokemon != nullptr && pokemon->getName() == name) {
            Pokemon* p = pokemon;  // Récupère le pointeur vers le Pokémon
            pokemon = nullptr;     // Supprime le Pokémon en mettant nullptr
            return p;              // Retourne le pointeur vers le Pokémon
        }
    }
    throw std::invalid_argument("Pokemon not found");
}