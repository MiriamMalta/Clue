# Clue
###### botón de inicio
###### botón de instrucciones
###### botón de settings
###### la primera vez que se inicia el juego se pregunta el nombre del usuario
######      si el usuario lo quiere cambiar, se cambia en settings
###### la primera vez que se inicia el juego se muestran las instrucciones
###### al iniciar se habla de la situación que se encuentra el personaje (introducciñon con voz ,3)
###### la primera vez que se inicia el juego se muestran un tutorial -> en duda
One suspect, one room, one weapon.
Mr. Boddy is found death in one of the rooms of his mansion.
All you need to do is answer who killed them, where and with what weapon.

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·
## How to install

In Linux(Ubuntu):
>sudo apt install build-essential git

>sudo apt install cmake

>sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
Then go to usr/local/lib and: 

>cd /usr/local/lib
>git clone https://github.com/raysan5/raylib.git raylib
>cd raylib
>sudo mkdir build && cd build
>sudo cmake -DSHARED=ON -DSTATIC=ON ..
>sudo make
>sudo make install

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·

# Requerimientos 
## Requerimientos funcionales

| Area | Requirement | Notes | Pruebas | Done? |
|-|-|-|-|-|
| Graficos | Mostrar Menu de Inicio | De la siguiente manera (inserte imagen) | Revisar que se cree la instancia de ventana | No |
| Graficos | Mostrar Tablero | De la siguiente manera (inserte imagen) | Revisar que se cree la instancia de ventana | No |
| Graficos | Mostrar personajes en Tablero | De la siguiente manera (inserte imagen) | Revisar que se cree la instancia de los personajes | No |

| Mecanicas |  |  |  | No |
| Manejo de Datos |  |  |  | No |
| Eventos |  |  |  | No |
| Graficos |  |  |  | No |


- [ ] Mecanica de movimiento => move(int, int)
- [ ] Mecanica de los dados => int dice(int) // (1234142214213) success: 5,6,4,3,2,1 || fail: 12, -1, 0
- [ ] Mecanica de movimiento
- [ ] Mecanica de movimiento
- [ ] Mecanica de movimiento

## Requerimientos no funcionales

### Sprites
- [ ] Mapa de clue tipo "The Skeld"
- [ ] Pantalla de Shhh
- [ ] Pantalla de Winner
- [ ] Pantalla de Loser
- [ ] Pantalla de Funado
- [ ] Main Menu
- [ ] Load
- [ ] Settings
- [ ] Credits
- [ ] HUD
- [ ] Notebook
- [ ] Loader
- [ ] Sprite Carta Reactor
- [ ] Sprite Carta Navigation
- [ ] Sprite Carta Shields
- [ ] Sprite Carta Medbay
- [ ] Sprite Carta Weapons
- [ ] Sprite Carta Upper Engine
- [ ] Sprite Carta Lower Engine
- [ ] Sprite Carta Electrical
- [ ] Sprite Carta Storage
- [ ] Sprite Carta Cafeteria
- [ ] Sprite Carta Yellow Astronaut
- [ ] Sprite Carta Red Astronaut
- [ ] Sprite Carta Purple Astronaut
- [ ] Sprite Carta Green Astronaut
- [ ] Sprite Carta White Astronaut
- [ ] Sprite Carta Blue Astronaut
- [ ] Sprite Carta Gun Shot
- [ ] Sprite Carta Stabbing
- [ ] Sprite Carta Neck snap
- [ ] Sprite Carta Throat Saber
- [ ] Sprite Carta Funado
- [ ] Sprite Carta Disconected from the server
- [ ] Spritesheet Yellow Astronaut
- [ ] Spritesheet Red Astronaut
- [ ] Spritesheet Purple Astronaut
- [ ] Spritesheet Green Astronaut
- [ ] Spritesheet White Astronaut
- [ ] Spritesheet Blue Astronaut

## Animaciones
- [ ] Deaths

### Botones que envian a otras ventanas
- [ ] New Game -> Ventana de Opciones de nuevo juego
- [ ] New Game Options -> Ventana de Shhh(inicio de juego)
- [ ] Load -> Ventana de Carga
- [ ] Settings -> Ventana de Opciones
- [ ] Credits -> Ventana de Creditos

- [ ] Quit Game -> Main Menu
- [ ] Save Game -> Ventana de Guardado
- [ ] Load Game -> Juego Cargado
- [ ] Options -> Ventana de Settings
- [ ] Restart -> Volver a iniciar el juego desde el inicio
- [ ] Cancel -> Volver al Juego


### Funciones o Mecanicas
- [ ] SaveGame()
- [ ] LoadGame()
- [ ] SetGame()
- [ ] FillPackage()
- [ ] Accusation(player,character, weapon, place)
- [ ] Suggestion(self,character, weapon, place)
- [ ] GenerateTurnGameList()
- [ ] Movement()
- [ ] Teletransport()
- [ ] EnterRoom()
- [ ] ExitRoom()
- [ ] CalculateRandomMovements()
- [ ] HatONames()

### Estructuras necesarias
- [ ] GameState
- [ ] GameInitialState
- [ ] GameHistory
- [ ] Board
- [ ] Player
- [ ] Notebook
- [ ] Accusations



· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·



## Base Information

######      sprite en forma de carta manejable
The mansion has 10 rooms.
- Hall -> Reactor
- Ballroom -> Navigation
- Conservatory -> Shields
- Dining Room -> Medbay
- Kitchen -> Weapons
- Lounge -> Upper Engine
- Study -> Lower Engine
- Library -> Electrical
- Billiard Room -> Storage
- Pool -> Cafeteria

###### Sprites por hacer
######      sprite en forma de figuras movibles por el juego sobre el tablero
######      sprite en forma de carta manejable
There are 6 suspects for the murder
- Colonel Mustard
- Miss Scarlet
- Professor Plum
- Mr. Green
- Mrs. White
- Mrs. Peacock

###### Sprites por hacer
######      sprite en forma de figuras movibles por el juego y los usuarios sobre el tablero
######      sprite en forma de carta manejable
There are 6 weapons
- Rope
- Lead Pipe
- Knife
- Wrench
- Candlestick
- Revolver

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·

## Before the Game Starts
###### mecánica de elegir personaje: cartas que seleccionar/clickear? 
######      mostrar personajes y el usuario elige el que desea 
######      el personaje seleccionado es la pieza que el usuario juega
######      el usuario es capaz de mover su personaje solamente
You choose one of the six characters, all represented with a color related to their names. 
- Colonel Mustard -> yellow
- Miss Scarlet -> red
- Professor Plum -> purple
- Mr. Green -> green
- Mrs. White -> white 
- Mrs. Peacock -> blue

###### mecánica de inicio
######      mostrar tablero
######      mostrar a todos los personajes en el tablero
######      mostrar a todas las armas puestas random en el tablero
######      mostrar el sobre en medio < explicado posteriormente >
######            el sobre ya debe de incluir las cartas correspondientes
######      mostrar cuaderno en el lado derecho
######            poder manipular el cuaderno en cualquier momento
######      mostrar el botón de "accusation" en cualquier momento
######      mostrar la existencia de otras personas/AI
All the characters are to be present on the board, whether they represent a player or not. They all start at a specific place on the map.

###### mecánica de inicio
######      mostrar a todas las armas puestas random en el tablero
All weapons will be randomly placed on a room. 

###### Sprites por hacer
######      ROOMS:
######            sprite en forma de el tablero
######            sprite en forma de carta manejable
######      WEAPONS:
######            sprite en forma de figuras movibles por el juego sobre el tablero
######            sprite en forma de carta manejable
######      SUSPECTS:
######            sprite en forma de figuras movibles por el juego y los usuarios sobre el tablero
######            sprite en forma de carta manejable
There are 21 total cards divided in three groups: suspects with 6 cards, Rooms with 9 cards and Weapons with 6 cards. Each card representing the already mentioned suspects, rooms and weapons. 

###### mecánica del inicio
######      mecánica del sobre
######            contiene una carta que indica el personaje 'culpable' (random)
######            contiene una carta que indica el arma 'culpable' (random)
######            contiene una carta que indica el lugar 'culpable' (random)
######            el sobre se muestra al centro del tablero
######            el contenido del sobre solo se muestra después de una "accusation"
######            el sobre NO es clickeable ni interactivo
In the middle of the map there is be an enveloped with the marking "Case File Confidential”, it is placed at the center of the map. This envelope holds the information about the murderer, the crime scene and the murder weapon. These are randomly selected. 

###### mecánica del inicio
######      mecánica del sobre
######      mecánica de repartir cartas
######            el resto de las cartas que NO estan incluidas en el sobre son distribuidas entre los participantes
######            las cartas se dividen lo más equitativamente posible entre los personajes
######            se muestran las cartas del usuario en su 'mano' (parte inferior del tablero)
######            las cartas son interactivas
######            si se selecciona una carta sin estar en "suggestion", nada pasa
The cards for the remaining suspects, rooms and weapons are shuffled and distributed as equally as possible (as there are 18 cards left) among all the players. 

###### mecánica del inicio
######      mecánica del cuaderno
######            mostrar cuaderno en el lado derecho de la pantalla
######            cuaderno interactivo
######            se puede manipular el cuaderno en cualquier momento
######            mostrar las secciones necesarias
######            – – – – – – – – – – – – – – – – – – – – – – –
######            | SUSPECTS                                  |
######            |   Professor Plum     [X]  [ ]  [ ]  [ ]   |
######            |   Colonel Mustard    [ ]  [ ]  [ ]  [ ]   |
######            | WEAPONS                                   |
######            |   Lead Pipe          [ ]  [ ]  [ ]  [ ]   |
######            |   Candlestick        [ ]  [ ]  [ ]  [ ]   |
######            | ROOMS                                     |
######            |   Conservatory       [X]  [ ]  [ ]  [ ]   |
######            |   Library            [X]  [ ]  [ ]  [ ]   |
######            – – – – – – – – – – – – – – – – – – – – – – –
######            esto es independiente del juego, lo que sea tachado o no NO afecta en nada el juego
######            el juego no lee las decisiones del jugador
######      2) mecánica del AI -> Roberto
######            Roberto es capaz de saber cuales son sus cartas
You will also be provided with a notebook that has all the characters, all the rooms and all the weapons with some boxes you can cross off when you consider they are *guilty*. It is advisable to cross off one’s cards upon receiving them as, if in your hand, they are not in the envelope. 

**For example:**

Suspects
- [x] Professor Plum
- you can cross this because you have this card in you hand and *you know* the envelope cannot contain it.
- [ ] Mrs. Peacock 
- you decide not to cross this because you *do not know* if this card is in someone else's hand or in the envelope.

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·

## Game Play
Now the game starts!

###### mecánica de juego :D
######      mecánica del turnos
######            primero inicia la pieza roja o la correspondiente a _Miss Scarlett_
######            si no hay _Miss Scarlett_, el orden es aleatorio
######            el resto se mueve con las manecilals del reloj: clock-wise
Miss Scarlett opens the game, the turns continue clockwise around the board. If no one chose Miss Scarlett, the choice is random. 

###### mecánica de juego :D
######      mecanica de movimiento
######            mecánica de tirar dados // minijuego de clickear rapido para crear la semilla de random
######            en cada turno, el usuario 'tira el dado'
######            el usuario se puede mover cierto número de casillas dadas por el dado
######            el usuario se mueve con las teclas < ^ v >
######            el movimiento es adelante, atrás, derecha e izquierda
######            el movimiento NO es en diagonal
######            NO puedes pasar sobre otro personaje
######            NO puedes pasar a través de otro personaje
######            NO puedes pasar dos veces por la misma casilla
######            existencia de paredes -> no puedes cruzar una pared
######            existencia de puertas -> puedes cruzar una puerta
######                  limites: no puedes cruzar la puerta si hay otro personaje adentro
######                  limites: no puedes cruzar la puerta si hay un usuario adelante de la puerta
######            existencia de cuartos -> puedes estar dentro de un cuarto
######                  un cuarto, aunque compuesto de varias casillas, se toma en cuenta como 1
######                  no puedes moverte dentro de un cuarto -> sus casillas no son casillas 'usables'
######                  adentro de un cuarto puedes hacer una "suggestion" < explicado posteriormente >
######                  un cuarto puede contener un mínimo de 0 armas y un máximo de 6 armas
######                  un cuarto puede contener un mínimo de 0 usuarios/personajes y un máximo de 6 personajes
######                        cuando se llama una "suggestion", se mete al personaje llamado
######                        este es la única instancia donde el cuarto puede contener a más de 1 personaje
######                        el usuario llamado puede llamar a una "suggestion"
######                  si el usuario esta en un cuarto, o pasa por un "Secret Passage" o se sale
######                  el usuario NO puede permanecer en un cuarto depués de una "suggestion"
######                  el usuario NO puede permanecer en un cuarto depués de su turno
######                  el usuario NO puede entrar dos veces al mismo cuarto en el mismo turno 
######                        a menos que sea llamado por una "suggestion"
######                  existencia de "Secret Passages"
######                        ciertas casillas que te transportan a otras casillas
######                        las casillas receptoras estan del lado opuesto del tablero
######                        requiere turno
######                        no se necesita tirar dados
######                        al pasar por un "Secret Passage" ingresas a otro cuarto
######                        misma reglas del cuarto
######            el área del sobre es tomada como pared
######            2) mecánica del AI -> Roberto
######                  Roberto es capaz de moverse según un dado random individual
######                  Roberto es capaz de entrar a cuartos
######                  Roberto es capaz de impedir que el usuario entre a un cuarto
######                  Roberto es capaz de llamar a una "suggestion"
######                  Roberto es capaz de seguir las reglas de movimiento

On each turn, a player will try to reach a different room of the mansion to investigate.

###### mecánica de juego :D
######      mecanica de movimiento
######            mecánica de tirar dados // minijuego de clickear rapido para crear la semilla de random
######                  existencia de "Secret Passages"
To move your character, you need to either roll the die or use a Secret Passage when in a corner room.

###### mecánica de juego :D
######      mecanica de movimiento
######            el usuario se puede mover cierto número de casillas dadas por el dado
######            el usuario se mueve con las teclas < ^ v >
######            el movimiento es adelante, atrás, derecha e izquierda
######            el movimiento NO es en diagonal
If you roll the die, you move however many spaces the die says. Your character can move horizontally or vertically, forward or backward, but never diagonally.

###### mecánica de juego :D
######      mecanica de movimiento
######                  existencia de "Secret Passages"
######                        ciertas casillas que te transportan a otras casillas
######                        requiere turno
######                        no se necesita tirar dados
If you move through a Secret Passage, you don't need to roll the dice, you just move to the other room, ending your movement.

###### mecánica de juego :D
######      mecanica de movimiento
######            NO puedes pasar dos veces por la misma casilla
######                  no puedes entrar dos veces al mismo cuarto en el mismo turno
You are not allowed to enter the same room twice on the same turn nor pass through a square more than two times in the same turn.

###### mecánica de juego :D
######      mecanica de movimiento
######            NO puedes pasar sobre otro personaje
######            NO puedes pasar a través de otro personaje
######            existencia de puertas -> puedes cruzar una puerta
######                  limites: no puedes cruzar la puerta si hay un usuario adelante de la puerta
######            existencia de cuartos -> puedes estar dentro de un cuarto
######                  si el usuario esta en un cuarto, o pasa por un "Secret Passage" o se sale
######                  el usuario NO puede permanecer en un cuarto depués de una "suggestion"
######                  el usuario NO puede permanecer en un cuarto depués de su turno
######                  el usuario NO puede entrar dos veces al mismo cuarto en el mismo turno
You are not allowed to jump or pass through another character. This includes if the character is blocking an entrance to a room. You also cannot get out of a room if all the entrances are blocked. If this were to happen, you need to wait until someone moves and un-blocks a door. 

###### mecánica de juego :D
######      mecanica de movimiento
######            existencia de puertas -> puedes cruzar una puerta
######                  limites: no puedes cruzar la puerta si hay otro personaje adentro
If the room you are trying to enter already has someone inside, you cannot do in. 

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·

### Suggestion

###### mecánica de juego :D
######      mecanica de "suggestion"
######            adentro de un cuarto puedes hacer una "suggestion"
######            mecánica de elegir sospechoso [ ] [X] [ ] [ ] [ ] [ ]
######            mecánica de elegir arma       [ ] [ ] [ ] [ ] [X] [ ]
######            el cuarto elegido es donde el usuario se encuentra
######            aparecera: 
######                  "The crime was committed by **Mrs. Peacock** in the **library** with a **wrench**".
######            ... con las opciones elegidas por el usuario
######            la pieza del personaje seleccionado entra al cuarto donde esta el usuario
######            la pieza del arma seleccionada se mete al cuarto donde esta el usuario
######            el resto de los usuarios te enseñaran sus cartas
######                  empieza el de la izquierda -> clock-wise
######                  botón de "continuar"
######                  si el usuario NO tiene ninguna carta de las mencionadas
######                        el botón "continuar" se podrá presionar
######                        ninguna carta se podrá seleccionar
######                  si el usuario SÍ tiene alguna carta de las mencionadas
######                        el botón "continuar" NO se podrá presionar hasta seleccionar una carta
######                        se podrán seleccionar SOLO las cartas mencionadas
######                        se tendrá que seleccionar 1 carta de las mencioandas
######                              si solo se tiene 1, se muestra esa 1
######                              si se tiene más de 1, el usuario elige cual enseñar
######                              se puede enseñar cartas ya enseñadas
######                        después de seleccionar la carta se presiona el botón de "continuar"
######                        solo se muestra la carta al que hizo la "suggestion"
######            mecánica de poder ver las cartas de otros usuarios
######            se usa para saber que cartas NO estan en el sobre
######            se puede hacer una "accusation" en cualquier momento < explicado posteriormente >
######            si eres un sospechoso y estas en el cuarto
######                  puedes decidir hacer una "suggestion"
######                  o puedes tirar los dados y salir del cuarto
######            2) mecánica del AI -> Roberto
######                  Roberto es capaz de mostrar cartas al usuario
######                  Roberto es capaz de ver cartas y tomarlas en cuenta
######                  Roberto es capaz de saber si tiene cartas o no
######                  Roberto es capaz de tratar de ganar
######                  Roberto es capaz de seguir las reglas de "suggestion"

###### mecánica de juego :D
######      mecanica de "suggestion"
######            adentro de un cuarto puedes hacer una "suggestion"
######            mecánica de elegir sospechoso [ ] [X] [ ] [ ] [ ] [ ]
######            mecánica de elegir arma       [ ] [ ] [ ] [ ] [X] [ ]
######            el cuarto elegido es donde el usuario se encuentra
######            aparecera: 
######                  "The crime was committed by **Mrs. Peacock** in the **library** with a **wrench**".
######            ... con las opciones elegidas por el usuario
When you enter a room, you can make a suggestion by naming a suspect, murder weapon and the room *you just entered*.

> "The crime was committed by **Mrs. Peacock** in the **library** with a **wrench**".

###### mecánica de juego :D
######      mecanica de "suggestion"
######            la pieza del personaje seleccionado entra al cuarto donde esta el usuario
######            la pieza del arma seleccionada se mete al cuarto donde esta el usuario
Both the suspect and the weapon are moved into the room you entered.

###### mecánica de juego :D
######      mecanica de "suggestion"
######            el resto de los usuarios te enseñaran sus cartas
######                  botón de "continuar"
######                  si el usuario SÍ tiene alguna carta de las mencionadas
######                        el botón "continuar" NO se podrá presionar hasta seleccionar una carta
######                        se podrán seleccionar SOLO las cartas mencionadas
######                        se tendrá que seleccionar 1 carta de las mencioandas
######                              si solo se tiene 1, se muestra esa 1
######                              si se tiene más de 1, el usuario elige cual enseñar
######                              se puede enseñar cartas ya enseñadas
######                        después de seleccionar la carta se presiona el botón de "continuar"
######                        solo se muestra la carta al que hizo la "suggestion"
######            mecánica de poder ver las cartas de otros usuarios
Then your opponents (starting by your left) must – if possible – prove that your suggestion is false by showing you, and **only you** one card that matches your suggestion. If one player hold more than one of the suggested cards they have to chose which card to show, they must show one but only one. 

###### mecánica de juego :D
######      mecanica de "suggestion"
######            el resto de los usuarios te enseñaran sus cartas
######                  botón de "continuar"
######                  si el usuario NO tiene ninguna carta de las mencionadas
######                        el botón "continuar" se podrá presionar
######                        ninguna carta se podrá seleccionar
If the player can't disprove, the next player must try it, until all players have passed.

###### mecánica de juego :D
######      mecanica de "suggestion"
######            se usa para saber que cartas NO estan en el sobre
You use this to mark as many boxes as you can to be certain who is and is not *guilty*.

###### mecánica de juego :D
######      mecanica de "suggestion"
If no one is able to prove your suggestion false, you may either end your turn or make an accusation.

###### mecánica de juego :D
######      mecanica de "suggestion"
######            si eres un sospechoso y estas en el cuarto
######                  puedes decidir hacer una "suggestion"
######                  o puedes tirar los dados y salir del cuarto
Once your turn ends the suspect, when their turn happens, can chose to stay in that room or roll the dice. 

###### mecánica de juego :D
######      mecanica de movimiento
######            existencia de cuartos -> puedes estar dentro de un cuarto
######                  un cuarto puede contener un mínimo de 0 armas y un máximo de 6 armas
######                  un cuarto puede contener un mínimo de 0 usuarios/personajes y un máximo de 6 personajes
######                        cuando se llama una "suggestion", se mete al personaje llamado
######                        este es la única instancia donde el cuarto puede contener a más de 1 personaje
######                        el usuario llamado puede llamar a una "suggestion"
######                  si el usuario esta en un cuarto, o pasa por un "Secret Passage" o se sale
######                  el usuario NO puede permanecer en un cuarto depués de una "suggestion"
######                  el usuario NO puede permanecer en un cuarto depués de su turno
######                  el usuario NO puede entrar dos veces al mismo cuarto en el mismo turno
######                        a menos que sea llamado por una "suggestion"
There is no limit to the number of weapons that a room holds, yet one room cannot hold more than two people (the one who made a suggestion and the suspect) -> change. 

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·

### Accusing

###### mecánica de juego :D
######      mecanica de "accusation"
######            se puede hacer en cualquier momento durante el juego
######            solo se puede hacer una vez durante todo el juego
######            una vez hecha se gana o se pierde el juego
######            mecánica de elegir sospechoso [ ] [X] [ ] [ ] [ ] [ ]
######            mecánica de elegir arma       [ ] [ ] [ ] [ ] [ ] [X]
######            mecánica de elegir cuarto     [ ] [ ] [ ] [X] [ ] [ ]
######            aparecera: 
######                  "I accuse **Mrs. Peacock** of committing the crime in the **library** with the **wrench**".
######            ... con las opciones elegidas por el usuario
######            después de hecha la "accusation" se abrirá el sobre
######                  si el sobre SÍ contiene las cartas que el usuario dijo, se gana el juego
######                  si el sobre NO contiene las cartas que el usuario dijo, se pierde el juego
######            2) mecánica del AI -> Roberto
######                  Roberto es capaz de llamar una "accusation"
######                  Roberto es capaz de asumir cuales cartas estan en el sobre
######                  Roberto es capaz de tratar de ganar
######                  Roberto es capaz de seguir las reglas de "accusation"

###### mecánica de juego :D
######      mecanica de "accusation"
######            se puede hacer en cualquier momento durante el juego
######            mecánica de elegir sospechoso [ ] [X] [ ] [ ] [ ] [ ]
######            mecánica de elegir arma       [ ] [ ] [ ] [ ] [ ] [X]
######            mecánica de elegir cuarto     [ ] [ ] [ ] [X] [ ] [ ]
######            aparecera: 
######                  "I accuse **Mrs. Peacock** of committing the crime in the **library** with the **wrench**".
######            ... con las opciones elegidas por el usuario
If you think you have solved the crime, you can end your turn at any time during the game by making an accusation and name your suspicions elements.

> "I accuse **Mrs. Peacock** of committing the crime in the **library** with the **wrench**".

###### mecánica de juego :D
######      mecanica de "accusation"
######            una vez hecha se gana o se pierde el juego
######            después de hecha la "accusation" se abrirá el sobre
######                  si el sobre SÍ contiene las cartas que el usuario dijo, se gana el juego
######                  si el sobre NO contiene las cartas que el usuario dijo, se pierde el juego
Then, the contents of the envelope will be shown to you. If you are correct, Congratulations! You won! If not, you lose.

###### mecánica de juego :D
######      mecanica de "accusation"
######            solo se puede hacer una vez durante todo el juego
You are only able to make **one** accusation per game, so make sure you are *certain* that you are right. 

###### ROBERTO
You need to be faster than the rest or they might find the killer sooner! 

· - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - · - ·


# Installation of needed libraries

## Raylib

> Raylib is a simple and easy-to-use library to enjoy videogames programming. Raylib is highly inspired by Borland BGI graphics lib and by XNA framework. Do you want to see all functions available in raylib? [Check cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)

> NOTE for ADVENTURERS: raylib is a programming library to enjoy videogames programming; no fancy interface, no visual helpers, no auto-debugging... just coding in the most pure spartan-programmers way. Are you ready to learn? Jump to [code examples!](http://www.raylib.com/examples.html)

> Raylib at https://www.raylib.com/

## libmpeg2

> http://bedroomcoders.co.uk/using-libmpeg2-with-raylib/

## ulfius

> https://github.com/babelouest/ulfius