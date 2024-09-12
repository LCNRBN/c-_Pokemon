#include <iostream>
#include <vector>

#include "Pokemon.hpp"
#include "Pokedex.hpp"


using std::vector;

int main() {
    std::cout << "******* Pokemon test *******" << std::endl;
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
    return 0;
}




