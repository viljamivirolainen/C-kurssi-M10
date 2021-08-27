/* monster.c -- Implementation of monster actions
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dungeon.h"

// for defining some monster types below that can be used in the game
typedef struct
{
    char name[20];       // Name of monster
    char sign;           // character to show it on map
    unsigned int hplow;  // lowest possible initial maxhp
    unsigned int hphigh; // highest possible initial maxhp
} MonstType;

// Specifying three monster types to start with.
// Feel free to add more, or change the below
// Note that it is up to you to decide whether to use this array from createMonsters
// you may or may not use it
const MonstType types[] = {
    {"Goblin", 'G', 6, 10},
    {"Rat", 'R', 3, 5},
    {"Dragon", 'D', 15, 20}};

/* One kind of attack done by monster.
 * The attack function pointer can refer to this.
 * 
 * Parameters:
 * game: the game state
 * monst: The monster performing attack
 */
void attackPunch(Game *game, Creature *monst)
{
    printf("%s punches you! ", monst->name);
    int hitprob = 50;
    int maxdam = 4;
    if (rand() % 100 < hitprob)
    {
        printf("Hit! ");
        int dam = rand() % maxdam + 1;
        printf("Damage: %d ", dam);
        game->hp = game->hp - dam;
        if (game->hp <= 0)
            printf("You died!");
        printf("\n");
    }
    else
    {
        printf("Miss!\n");
    }
}

/* Exercise (c)
 *
 * Move monster 'monst' towards the player character.
 * See exercise description for more detailed rules.
 */
void moveTowards(const Game *game, Creature *monst)
{
    int newX;
    int newY;
    int i = 0;
    int difX1 = monst->pos.x - game->position.x;
    int difY1 = monst->pos.y - game->position.y;
    double dif1 = sqrt(pow(difX1, 2) + pow(difY1, 2));
    double dif2 = 0;
    double dDist = 0;
    double difX2 = 0;
    double difY2 = 0;
    double sDist = 0;
    while (i < 50)
    {
        newX = monst->pos.x + (rand() % 3) - 1;
        newY = monst->pos.y + (rand() % 3) - 1;
        // check että dif2-dif1, etäisyyden muutos, on negatiivinen
        difX2 = newX - game->position.x;
        difY2 = newY - game->position.y;
        dif2 = sqrt(pow(difX2, 2) + pow(difY2, 2));
        dDist = dif2 - dif1;
        sDist = sqrt(pow(newX - monst->pos.x, 2) + pow(newY - monst->pos.y, 2));
        if (sDist == 1 && dDist <= 0 && !isBlocked(game, newX, newY) && !(newX == game->position.x && newY == game->position.y))
        {
            monst->pos.x = newX;
            monst->pos.y = newY;
            break;
        }
        i++;
    }
}

/* Exercise (d)
 *
 * Move monster 'monst' away from the player character.
 * See exercise description for more detailed rules.
 */
void moveAway(const Game *game, Creature *monst)
{
    int newX;
    int newY;
    int i = 0;
    int difX1 = monst->pos.x - game->position.x;
    int difY1 = monst->pos.y - game->position.y;
    double dif1 = sqrt(pow(difX1, 2) + pow(difY1, 2));
    double dif2 = 0;
    double dDist = 0;
    double difX2 = 0;
    double difY2 = 0;
    double sDist = 0;

    while (i < 50)
    {
        newX = monst->pos.x + (rand() % 3) - 1;
        newY = monst->pos.y + (rand() % 3) - 1;
        // check että dif2-dif1, etäisyyden muutos, on positiivinen
        difX2 = newX - game->position.x;
        difY2 = newY - game->position.y;
        dif2 = sqrt(pow(difX2, 2) + pow(difY2, 2));
        dDist = dif2 - dif1;
        sDist = sqrt(pow(newX - monst->pos.x, 2) + pow(newY - monst->pos.y, 2));

        if (dDist >= 0 && sDist == 1 && !isBlocked(game, newX, newY) && !(newX == game->position.x && newY == game->position.y))
        {
            monst->pos.x = newX;
            monst->pos.y = newY;
            break;
        }
        i++;
    }
}

/* Exercise (e)
 *
 * Take action on each monster (that is alive) in 'monsters' array.
 * Each monster either attacks or moves (or does nothing if no action is specified)
 */
void monsterAction(Game *game)
{
    unsigned int i = 0;
    double difX = 0;
    double difY = 0;
    while (i < game->numMonsters)
    {
        Creature *m = &game->monsters[i];
        if (m->hp > 0)
        {
            difX = m->pos.x - game->position.x;
            difY = m->pos.y - game->position.y;
            if (1 == sqrt(pow(difX, 2) + pow(difY, 2)))
            {
                m->attack(game, m);
            }
            else
            {
                m->move(game, m);
            }

            //jos vieressä, lyö
            //muuten, liiku
        }

        i++;
    }
}

/* Exercise (b)
 *
 * Create opts.numMonsters monsters and position them on valid position
 * in the the game map. The moster data (hitpoints, name, map sign) should be
 * set appropriately (see exercise instructions) 
 */
void createMonsters(Game *game)
{
    unsigned int i = 0;
    game->numMonsters = game->opts.numMonsters;
    game->monsters = calloc(game->opts.numMonsters, sizeof(Creature));
    while (i < game->opts.numMonsters)
    {
        //randomize a monster MonstType m = rand types
        MonstType m = types[rand() % 3];
        Creature c;
        c.attack = attackPunch;

        //TODO randomize initial hp
        c.hp = m.hphigh;
        c.maxhp = m.hphigh;

        c.move = moveTowards;

        strcpy(c.name, m.name);
        c.sign = m.sign;

        //randomize a monster position x=rand y=rand
        //if position is valid !isblocked(game, x,y), reserve memory malloc(sizeof())
        int x;
        int y;
        while (1)
        {
            x = rand() % game->opts.mapWidth;
            y = rand() % game->opts.mapHeight;
            if (!isBlocked(game, x, y))
            {
                c.pos.x = x;
                c.pos.y = y;
                break;
            }
        }
        //and add the monster to game->opts & i++;
        game->monsters[i] = c;
        i++;
    }
}

/* Determine whether monster moves towards or away from player character.
 */
void checkIntent(Game *game)
{
    for (unsigned int i = 0; i < game->numMonsters; i++)
    {
        Creature *m = &game->monsters[i];
        if (m->hp <= 2)
        {
            m->move = moveAway;
        }
        else
        {
            m->move = moveTowards;
        }
        if (m->hp < m->maxhp)
            m->hp = m->hp + 0.1; // heals a bit every turn
    }
}
