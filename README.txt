Tecnológico de Monterrey
Simulación del juego de Serpientes y Escaleras
31 de mayo del 2023

Antonio Marban Regalado
Carol Jatziry Rendon Guerrero

FUNCIONAMIENTO

Para poner en funcionamiento el juego se debe correr el archivo snakes_and_ladders.cpp_. Todas las clases estan ubicadas en la carpeta _src_. Los archivos de las clases son Board.h, Dice.h, Game.h, Ladder.h, Person.h, Player.h, Snake.h y Tile.h
En las clases se determinan atributos y metodos que describen el tablero de juego, cada casilla del tablero, numero y nombre de cada jugador, recompensas, penalizaciones y un dado de 6 caras.

La clase Snake.h y Ladder.h heredan de la clase Tile.h, la clase Board.h hace composicion de las clases Game.h, Snake.h y Ladder.h. La clase Game.h hace agregacion de las clases Dice.h y Player.h.
La clase Player.h hereda de la clase Person.h.

Se realiza un vector de apuntadores de tipo casillas y donde el vector puede estar compuesto de distintos objetos como objetos tipo serpiente u objetos tipo escalera.

REQUERIMIENTOS

Descarga completa del archivo.zip
Compilador g++
