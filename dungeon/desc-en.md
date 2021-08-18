### Task 10.4: Dungeon game (30 pts)

The recent history knows a class of terminal-based dungeon crawling
games such as [Rogue](http://en.wikipedia.org/wiki/Rogue_(video_game)),
[Nethack](http://www.nethack.org) and [Angband](http://rephial.org).
Unfortunately, development of
many of the original games has ceased by now, but this exercise tries
to revive this magnificient traditional class of games.

This exercise implements a simple poor man's version of a dungeon
crawling game. As you will notice, it lacks several features compared
to its original predecessors, but you are free to enhance the game in
various ways you like.

The given zip file contains a lot of ready written program code, so you should
download it. Many functions are already implemented, but you should implement a
few additional functions, as described below. The zip package contains the
following program modules:

  * **main.c** contains the main loop that asks a command from
    user, and triggers actions for the user's character and the
    monsters in the game.

  * **mapgen.c** generates the dungeon, including rooms and
    corridors between them.

  * **userif.c** contains functions related to interacting with the
    user: showing the visible sections of map, and acting on the user
    input. In the current configuration, player can see five squares
    far (pretty short-sighted game character), and (naturally) cannot
    see behind walls, but you can change these parameters if you want.

  * **monster.c** has the logic for monsters on the game: the game
    is turn-based: after each player movement, all monsters on the map
    are moved, based on the algorithms that you will implement. Most
    of the functions you need to implement for this exercise are in
    this file.

  * **dungeon.h** contains definitions (e.g., structures) and
    needed public function prototypes. The header does not contain all
    functions: functions that are private to a particular module, are
    not included.

The game uses a few main data structures: **Game** contains the
main game state, and links to different components, such as
two-dimensional map array, or dynamically allocated array of
monsters. The game structure also contains the player character
information. **Map** holds the pointer to two-dimensional map. This
map is allocated such that the vertical dimension (mapHeight elements)
is the first array, consisting of the rows of mapWidth
elements. **Creature** contains information of one monster, and the
Game structure contains a dynamically allocated array of these, with
numMonsters indicating the number of Creature elements in the
array.

Additional information can be found embedded with the source code,
such as descriptions of the functions. You can modify the code as you
like: add new kinds of monsters, change the way the map is presented,
add different types of characteristics for the monsters and the
player, and so on, as long as you don't modify or remove the existing
fields, that may be used by the exercise tests. The exercise tests only focus on
certain functions, as identified below. Everything else is free for
you to change.

The game can be played by running the executable that is produced by the **makefile**
The makefile contains the instructions to build the program from source files
and can be run by `make` command on command line. Initially the game doesn't
do much anything interesting, before you implment some of the missing functions.

Below is a screenshot of a game after all tasks below have been
implemented (Monster 'D' approaching character '*' from left). Current
(and max) hitpoints are shown above the command prompt.</p>

        ...
       ##.##
       #...#
       #...#  #

    ####...##..
    ..D..*.....

    ###########




    HP: 12(12)
    command &gt;

Currently the game has the following commands:

  * `n`: move north
  * `s`: move south
  * `e`: move east
  * `w`: move west
  * `q`: exit game

Input is line buffered, so you'll need to press enter after the
command. You can change or redo the command processing, if you wish
-- exercise tests will not care about that.

**a) Blocked position**

Implement function **int isBlocked(const Game \*game, int x, int y)** that
returns 0, if the given position on map is unoccupied: it is not wall,
and is not occupied by a monster. Otherwise, the function returns a
non-zero value. The function should also return non-zero value if the
given coordinates are out of bounds of the map. This function will be
useful helper in many of the other functions described below. The
function placeholder can be found in **userif.c**

**b) Create monsters**

Implement function **void createMonsters(Game \*game)** that creates
**opts.numMonsters** monsters, and places them on random positions
in game area (use <a href="http://linux.die.net/man/3/rand">rand()</a>
function to generate random numbers). You need to allocate memory for the monsters
in the field `game->monsters`. The monsters must be placed on
free positions that are not wall, and not occupied by other monsters
[e.g., !isBlocked(..)]. Initialize also other monster details, such as
name, the map sign shown on user interface, hitpoints, and so on. Each
monster must have more than 0 hitpoints, and initial HP needs to be
same as the maximum HP. Otherwise you can choose the monster details
as you will (for example, to contain random values), but name must be
set, and map sign must be an alphabetic character. The function placeholder can
be found in **monster.c**

**c) Move Towards**

Implement function **void moveTowards(const Game *game, Creature
*monst)** that moves monster **monst** one step towards player's
character. The default game logic uses this function to make the
monsters move towards the character, unless they are low on
hitpoints. The test will check the following:

  * If possible, the distance between monster and the character must
    reduce as a result of this call

  * The monster must not move more than one step on the map at a time

  * The monster must not move over wall

  * The monster must not move to same location with another monster

  * The monster must not move to same location with the character

Within these restrictions, you can implement your movement algorithm
as you will. You can assume that monsters have magical powers to
detect the player character's location irrespective of the walls. The function
placeholder can be found in **monster.c**

**d) Move Away**

Implement function **void moveAway(const Game *game, Creature *monst)**
that moves monster **monst** one step away from player's
character. The default game logic invokes this behavior when monster
is low on the hit points. The test will check the following:

  * If possible, the distance between monster and the character must
    increase as a result of this call

  * The monster must not move more than one step on the map at a time

  * The monster must not move over wall

  * The monster must not move to same location with another monster

  * The monster must not move to same location with the character

Within these restrictions, you can implement your movement algorithm
as you will. The function placeholder can be found in **monster.c**

**e) Monster action**

<b>void monsterAction(Game *game)</b> is the function that will invoke
an action for every monster still alive in the game. For each monster,
if monster is in adjacent location with the character, it should try
to attack the character. Otherwise, the monster should invoke the
movement action (for example, moveTowards or moveAway). If monster is
dead (HP==0 or less), no action is taken.

Function pointers <b>attack</b> and <b>move</b> in <b>Creature</b>
structure determine the action to be taken. Use these functions to
invoke either of these monster actions, following the above logic. If
either of the function pointers is NULL, the respective action is
ignored. The function placeholder can be found in **monster.c**

Note that you should have specified valid attack and movement
behaviors (i.e., function pointers) when creating monsters. The game
template provides one attack behavior, but you can define more as you
will