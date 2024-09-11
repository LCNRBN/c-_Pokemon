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

    /*  vector<Pokemon*> pokedex;
      for (int i=0;i<10;i++){
          char * name;
          sprintf(name,"Bullbizarre#%d",i);
          pokedex.push_back(new Pokemon(name));
      }

      for(Pokemon * pp :pokedex){
          pp->scream();
      }

      pokedex[15]->scream();
      //pokedex.at(15)->scream();*/

    Pokedex* pokedex = Pokedex::getInstance("pokedex.csv");

    pokedex -> displayPokemonList();
    return 0;
}




