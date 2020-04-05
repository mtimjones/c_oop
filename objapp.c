#include "object.h"

void main( void )
{
   object *knight = create_object( "Knight", 20, 5, 1 );
   object *thief = create_object( "Thief", 17, 2, 2 );

   srand( time( NULL ) );

   while ( knight->hitpoints && thief->hitpoints )
   {
      knight->fight( knight, thief );
      if ( !thief->hitpoints ) break;
      thief->fight( thief, knight );
   }

   if ( knight->hitpoints ) printf( "Knight defeats the Thief\n" );
   if ( thief->hitpoints ) printf( "Thief defeats the Knight\n" );

   knight->debug( knight );
   thief->debug( thief );

   knight->free( knight );
   thief->free( thief );

   return;
}

