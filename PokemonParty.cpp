#include "PokemonParty.hpp"
#include <stdexcept> //pour gérer les exceptions

// CONSTRUCTEURS

PokemonParty::PokemonParty(const std::vector<int>& indices, Pokeball& pokeball){ //Constructeur qui prend un vecteur d'indices et ajoute les Pokémon de la Pokeball à la Party
    for (int index : indices){ //parcours de chaque index fourni
        // On prend le Pokémon du Pokeball et on l'ajoute à la Party
        // std::move permet de déplacer l'objet sans faire de copie
        //pokemons.push_back(std::move(pokeball.getPokemonByIndex(index)));
        Pokemon* pokemon = pokeball.removePokemonAtIndex(index);
        addPokemon(pokemon);
    }
}
// //1ère version ptr* commentée
// PokemonParty::PokemonParty(const std::vector<string>&names, Pokeball& pokeball){ //Constructeur qui prend un vecteur de noms et ajoute les Pokémon de la Pokeball à la Party
//     for (const string& name : names){ //parcours de chaque nom de Pokémon fourni
//         // On prend le Pokémon du Pokeball et on l'ajoute à la Party
//         //pokemons.push_back(std::move(pokeball.getPokemonByName(name)));

//         //version ptr*
//         Pokemon* pokemon = pokeball.removePokemonByName(name);
//         addPokemon(pokemon);
//         for (auto& p : pokeball.pokemons){
//             if (p != nullptr && p->getName() == name){
//                 p = nullptr; //libère le ptr
//                 break;
//             }
//         }
//     }
// }

//2ème version ptr*
PokemonParty::PokemonParty(const std::vector<std::string>& names, Pokeball& pokeball) {
    for (const std::string& name : names) {
        Pokemon* pokemon = pokeball.removePokemonByName(name); // Retire le Pokémon par son nom
        addPokemon(pokemon); // Ajoute le Pokémon à la Party
    }
}

// FONCTIONS

//version ptr*
Pokemon* PokemonParty::getPokemonByIndex(int index){ //Fonction pour obtenir un Pokémon par index à partir de la Party
    if (index >= 0 && index < pokemons.size()){
        return pokemons[index]; //index valide, retourne le pokemon à cet index
    }
    throw std::out_of_range("index out of range"); //index invalide on lance une exception
}
Pokemon* PokemonParty::getPokemonByName(const string& name){ //Fonction pour obtenir un Pokémon par nom à partir de la Party
    // for (const auto& pokemon : pokemons){
    //     if (pokemon.getName() == name){ //Si on trouve un Pokémon avec le même nom, on le retourne
    //         return pokemon;
    //     }
    // }

    //version ptr*
    for (Pokemon* pokemon : pokemons){
        if(pokemon != nullptr && pokemon->getName() == name){
            return pokemon;//retourne le ptr vers le pokemon trouvé
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

// void PokemonParty::addPokemon(Pokemon& pokemon){ //Fonction pour ajouter un Pokémon à la Party
//     //On ajoute le Pokémon à la liste des Pokémon dans la Party
//     pokemons.push_back(pokemon);
// }

//version avec ptr*
void PokemonParty::addPokemon(Pokemon* pokemon){
    if (pokemon != nullptr) {
        pokemons.push_back(pokemon); // Ajoute le Pokémon à la liste
    } else {
        throw std::invalid_argument("Cannot add a null Pokemon");
    }
}