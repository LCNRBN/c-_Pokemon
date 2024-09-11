#include "Pokedex.hpp"
#include <stdexcept>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(const std::string& nomFichier){ // Constructeur privé qui lit le fichier CSV pour charger les Pokémon
    lireCSV(nomFichier);
}

//attention au multi-threading !! le singleton ne marche pas bien (plusieurs joueurs en réseau)
Pokedex* Pokedex::getInstance(const std::string& nomFichier){
    if(instance == nullptr){// si l'instance est nulle alors on la crée
        instance = new Pokedex(nomFichier);
    }
    return instance;
}

Pokemon Pokedex::getPokemonByIndex(int index) const{
    if (index>=0 && index <pokemons.size()){
        return pokemons[index];
    }
    throw std::out_of_range("Index out of range");
}

Pokemon Pokedex::getPokemonByName(const string& name) const{
    for (const auto& pokemon : pokemons){
        if (pokemon.getName()==name){
            return pokemon;
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

void Pokedex::lireCSV(const std::string& nomFichier){
    //nouveau code
    std::ifstream fichier(nomFichier);
    if(!fichier.is_open()){
        std::cerr << "Impossible d'ouvrir le fichier" << nomFichier << std::endl;
        return;
    }
    std::string ligne;
    while (std::getline(fichier, ligne)){
        std::stringstream ss(ligne);
        std::string cellule;
        std::vector<std::string> donneesLigne;
        while (std::getline(ss, cellule,',')){
            donneesLigne.push_back(cellule);
        }
        if (donneesLigne.size()==6){
            Pokemon p(donneesLigne[0], std::stoi(donneesLigne[1]), std::stod(donneesLigne[2]), std::stod(donneesLigne[3]), std::stod(donneesLigne[4]), std::stoi(donneesLigne[5]));
            pokemons.push_back(p);
        }
    }
    fichier.close();
}


