#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define getSRand( )   ( ( double ) rand( ) / ( double ) RAND_MAX )              
#define getRand( x )  ( int ) ( ( x ) * getSRand( ) )    

#define NAME_SIZE      20

struct object
{
   char name[ NAME_SIZE ];

   int  maxhitpoints;
   int  hitpoints;
   int  damage;
   int  dexterity;

   void (*fight)( struct object *hero1, struct object *hero2 );
   void (*debug)( struct object *hero );
   void (*free)( struct object *hero );

};

typedef struct object object;

object *create_object( char *name, int hitpoints, int damage, int dex );

