#include "Pokedex.hpp"
#include <stdexcept>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(const std::string& nomFichier){ // Constructeur privé qui lit le fichier CSV pour charger les Pokémon
    lireCSV("./ressources/" + nomFichier);
}

//attention au multi-threading !! le singleton ne marche pas bien (plusieurs joueurs en réseau)
Pokedex* Pokedex::getInstance(const std::string& nomFichier){
    if(instance == nullptr){// si l'instance est nulle alors on la crée
        instance = new Pokedex(nomFichier);
    }
    return instance;
}

//version ptr*
Pokemon* Pokedex::getPokemonByIndex(int index) {
    if (index>=0 && index <pokemons.size()){
        return pokemons[index];
    }
    throw std::out_of_range("Index out of range");
}
Pokemon* Pokedex::getPokemonByName(const string& name) {
    // for (const auto& pokemon : pokemons){
    //     if (pokemon.getName()==name){
    //         return pokemon;
    //     }
    // }
    for (auto& p : pokemons){
        if (p->getName() == name){
            return p; // ptr vers le pokemon
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

void Pokedex::lireCSV(const std::string& nomFichier){
    std::ifstream fichier(nomFichier);
    if(!fichier.is_open()){
        std::cerr << "Impossible d'ouvrir le fichier" << nomFichier << std::endl;
        return;
    }
    std::string ligne;
    std::getline(fichier, ligne); //skip le header
    while (std::getline(fichier, ligne)){
        std::stringstream ss(ligne);
        std::string cellule;
        std::vector<std::string> donneesLigne;
        while (std::getline(ss, cellule,',')){
            donneesLigne.push_back(cellule);
        }
        if (donneesLigne.size()==13){
            // Pokemon p(donneesLigne.at(1), 
            // std::stoi(donneesLigne.at(0)), 
            // std::stod(donneesLigne.at(5)), 
            // std::stod(donneesLigne.at(6)), 
            // std::stod(donneesLigne.at(7)), 
            // std::stod(donneesLigne.at(11)));
            // pokemons.push_back(p);// ajout du pointeur au vecteur

            //version ptr*
            Pokemon* p = new Pokemon(donneesLigne.at(1),
                std::stoi(donneesLigne.at(0)), 
                std::stod(donneesLigne.at(5)), 
                std::stod(donneesLigne.at(6)), 
                std::stod(donneesLigne.at(7)), 
                std::stod(donneesLigne.at(11)));
            pokemons.push_back(p);
        }
    }
    fichier.close();
}

//version ptr*
Pokedex::~Pokedex(){
    for (Pokemon* p : pokemons){
        delete p;//libère chaque ptr*
    }
}
void Pokedex::deleteInstance(){
    delete instance;
    instance = nullptr;
}