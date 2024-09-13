#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Context.hpp"
#include "Wait.hpp"

using std::vector;

int main() {
    std::cout << "******* Pokemon Start *******" << std::endl;
    
    //client code
    std::srand(std::time(nullptr));//initialise la génération de nb aléa
    Context *context = new Context(new Wait);
    context->Request1();//démarrer jeu
    context->Request1();//Initialisation
    context->Request1();//Exploration

    Pokemon mew("Mew",5,100,30,70,3);
    Pokemon mew2("Mew2",10,100,100,50,3);
    mew.displayInfo();
    mew2.displayInfo();
    mew.attack(mew2);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);

    std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    std::cout <<"Nombre de Pokemon en memoire : " << mew.getNumberOfPokemon() << std::endl;

    Pokedex* pokedex = Pokedex::getInstance("pokedex.csv");

    pokedex -> displayPokemonList();

    delete context;

    return 0;
}




