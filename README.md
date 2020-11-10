# Clue
###### poner un inicio, hablar de la situación que se encuentra el personaje
###### introducción? tutorial? instrucciones? 
One suspect, one room, one weapon.
Mr. Boddy is found death in one of the rooms of his mansion.
All you need to do is answer who killed them, where and with what weapon.


## Base Information
###### (sprites por hacer[son un mapa y son una carta])
The mansion has 9 rooms.
- Hall
- Study
- Library
- Billiard Room
- Conservatory
- Ballroom
- Kitchen
- Dining Room
- Lounge

###### (sprites por hacer[son un mapa y son una carta])
There are 6 suspects for the murder
- Colonel Mustard
- Miss Scarlet
- Professor Plum
- Mr. Green
- Mrs. White
- Mrs. Peacock

###### (sprites por hacer[son un mapa y son una carta])
There are 6 weapons
- Rope
- Lead Pipe
- Knife
- Wrench
- Candlestick
- Revolver


## Before the Game Starts
###### mecánica de elegir personaje: cartas que seleccionar/clickear? 
You choose one of the six characters, all represented with a color related to their names. 
- Colonel Mustard -> yellow
- Miss Scarlet -> red
- Professor Plum -> purple
- Mr. Green -> green
- Mrs. White -> white 
- Mrs. Peacock -> blue

###### mecánica de inicio (jugadores en inicio, armas en cuartos random, sobre)
All the characters are to be present on the board, whether they represent a player or not. They all start at a specific place on the map.

###### mecánica de inicio (jugadores en inicio, armas en cuartos random, sobre)
All weapons will be randomly placed on a room. 

###### (sprites por hacer [carta])
There are 21 total cards divided in three groups: suspects with 6 cards, Rooms with 9 cards and Weapons with 6 cards. Each card representing the already mentioned suspects, rooms and weapons. 

###### mecánica de inicio (jugadores en inicio, armas en cuartos random, sobre)
###### mecánica de elegir que es culable: personaje, arma y lugar (random)
In the middle of the map there is be an enveloped with the marking "Case File Confidential”, it is placed at the center of the map. This envelope holds the information about the murderer, the crime scene and the murder weapon. These are randomly selected. 

###### mecánica de elegir que es culable: personaje, arma y lugar (random) 
The cards for the remaining suspects, rooms and weapons are shuffled and distributed as equally as possible (as there are 18 cards left) among all the players. 

###### mecánica de el cuaderno para el jugador
###### mecánica que el AI sepa que sus cartas no son culpables
You will also be provided with a notebook that has all the characters, all the rooms and all the weapons with some boxes you can cross off when you consider they are *guilty*. It is advisable to cross off one’s cards upon receiving them as, if in your hand, they are not in the envelope. 

**For example:**

Suspects
- [x] Professor Plum
- you can cross this because you have this card in you hand and *you know* the envelope cannot contain it.
- [ ] Mrs. Peacock 
- you decide not to cross this because you *do not know* if this card is in someone else's hand or in the envelope.


## Game Play
Now the game starts!

###### escoger el personaje de los usuarios
###### turnos se mueven como las manecillas del reloj
###### el orden de los personajes puede se aleatorioe
Miss Scarlett opens the game, the turns continue clockwise around the board. If no one chose Miss Scarlett, the choice is random. 

###### mecanica de movimiento
###### mecánica de turnos
###### existencia de cuartos // espacios donde el personaje puede entrar (puertas) y donde no puede entrar (pared)
On each turn, a player will try to reach a different room of the mansion to investigate. 

###### existencia de cuartos // espacios donde el personaje puede entrar (puertas) y donde no puede entrar (pared)
###### mecánica de movimiento
###### mecánica de tirar dados // minijuego de clickear rapido para crear la semilla de random
To move your character, you need to either roll the die or use a Secret Passage when in a corner room.

###### mecánica de movimiento (adelante, atras, derecha, izquierda)
If you roll the die, you move however many spaces the die says. Your character can move horizontally or vertically, forward or backward, but never diagonally.

###### mecánica de movimiento (adelante, atras, derecha, izquierda)
###### existencia de cuartos // espacios donde el personaje puede entrar (puertas) y donde no puede entrar (pared)
###### existencia de casillas que te transportan a otras casillas
If you move through a Secret Passage, you don't need to roll the dice, you just move to the other room, ending your movement.

###### mecánica de checar donde estan los otros jugadores
###### mecánica de movimiento (adelante, atras, derecha, izquierda)
###### mecánica de pasar por una casilla más de dos veces
###### mecánica de no pasar sobre otro personaje
You are not allowed to enter the same room twice on the same turn nor pass through a square more than two times in the same turn.

###### mecánica de checar donde estan los otros jugadores
###### mecánica de movimiento (adelante, atras, derecha, izquierda)
###### mecánica de no pasar sobre otro personaje
You are not allowed to jump or pass through another character. This includes if the character is blocking an entrance to a room. You also cannot get out of a room if all the entrances are blocked. If this were to happen, you need to wait until someone moves and un-blocks a door. 

###### mecánica de checar donde estan los otros jugadores
###### mecánica de movimiento (adelante, atras, derecha, izquierda)
###### mecánica de no entrar a un cuarto que este ocupado
If the room you are trying to enter already has someone inside, you cannot do in. 


### Sugestions

###### mecánica de sugestion / acusación
######      mecánica que cuando entres a un lugar, te aparezca la opción
######      mecánica de elegir sospechoso [] [], arma [] [] y lugar [] []
When you enter a room, you can make a suggestion by naming a suspect, murder weapon and the room *you just entered*.

> "The crime was committed by **Mrs. Peacock** in the **library** with a **wrench**".

######      mecánica de que las piezas necesarias se muevan
Both the suspect and the weapon are moved into the room you entered.

######      mecánica en que los integrantes te muestren 1 carta
Then your opponents (starting by your left) must – if possible – prove that your suggestion is false by showing you, and **only you** one card that matches your suggestion.

If the player can't disprove, the next player must try it, until all players have passed.

If one player hold more than one of the suggested cards they have to chose which card to show, they must show one but only one. 

######      mecánica de poder usar el cuaderno con cuadritos
######      mecánica de poder mostrar una carta a una sugerencia
######      mecánica de que el AI toma en cuentas sus cartas y las mostradas para ganar 
You use this to mark as many boxes as you can to be certain who is and is not *guilty*.

If no one is able to prove your suggestion false, you may either end your turn or make an accusation.

Once your turn ends the suspect, when their turn happens, can chose to stay in that room or roll the dice. 

There is no limit to the number of weapons that a room holds, yet one room cannot hold more than two people (the one who made a suggestion and the suspect). 


### Accusing

###### mecánica de accusation / declaración
######      mecánica que en cualquier momento puedas llamar esta función
######      mecánica de elegir sospechoso [] [], arma [] [] y lugar [] []
If you think you have solved the crime, you can end your turn at any time during the game by making an accusation and name your suspicions elements.

> "I accuse **Mrs. Peacock** of committing the crime in the **library** with the **wrench**".

######      mecánica de ver el sobre
Then, the contents of the envelope will be shown to you. 

######      mecánica de terminar el juego: ganar o perder
If you are correct, Congratulations! You won! If not, you lose.

######      mecánica única (solo se puede 1 vez)
You are only able to make **one** accusation per game, so make sure you are *certain* that you are right. 

######      mecánica de que el AI trate de ganar 
You need to be faster than the rest or they might find the killer sooner! 

# Requerimientos funcionales
- [  ] Mecanica de movimiento => move(int, int)
- [ ] Mecanica de los dados => int dice(int) // (1234142214213) success: 5,6,4,3,2,1 || fail: 12, -1, 0
- [ ] Mecanica de movimiento
- [ ] Mecanica de movimiento
- [ ] Mecanica de movimiento

# Requerimientos no funcionales

- [ ] Sprites
- [ ] Textos interesantes(de colores)
- [ ] Mecanica de movimiento

# Installation of needed libraries

## Allegro

> Allegro is a cross-platform library mainly aimed at video game and multimedia programming. It handles common, low-level tasks such as creating windows, accepting user input, loading data, drawing images, playing sounds, etc. and generally abstracting away the underlying platform. However, Allegro is not a game engine: you are free to design and structure your program as you like. 
> Allegro at https://liballeg.org/

