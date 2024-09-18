# c++_Pokemon
Cours de C++

Le dresseur de Pokémon peut se déplacer sur la MAP.
S'il est proche d'une haute herbe, alors il peut capturer un Pokémon de son choix (jusqu'à 6 maximum).
S'il est proche du X sur la MAP, alors il peut défier en arène un Pokémon aléatoire.

Il faut compléter les fichiers.cpp / récrire les .hpp au lieu de tout mettre dans les .hpp.

Il y a un problème d'encapsulaton avec les classes d'états car les fonctions sont définies et appelées dans Map.hpp qui est supposé gérer uniquement l'affichage des matrices map.
Il faut transvaser ces fonctions de combat et d'Explordanger dans leur classe respective d'Etat.
