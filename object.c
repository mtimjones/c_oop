#include "object.h"

void object_debug( struct object *this )                                        
{
   printf( "--------\n");
   printf( "%s (%p)\n", this->name, this );
   printf( "   Max HP %d\n", this->maxhitpoints );
   printf( "   HP %d %s\n", this->hitpoints, ( !this->hitpoints ) ? "dead" : "" );
   printf( "   Damage %d, Dexterity %d\n", this->damage, this->dexterity );
   printf( "--------\n");
                                                                                
   return;                                                                      
}                                                                               

void object_fight( struct object *attacker, struct object *defender )
{
   int sum = attacker->dexterity + defender->dexterity;
   int rng = getRand( sum );                                                    
                                                                                
   if ( rng < attacker->dexterity )
   {                                                                            
      defender->hitpoints -= attacker->damage;
      if ( defender->hitpoints < 0 ) defender->hitpoints = 0;
      printf( "%s attacks: %s takes %d damage.\n", 
               attacker->name, defender->name, attacker->damage );
   }                                                                            
   else                                                                         
   {                                                                            
      printf( "%s defends attack from %s\n", defender->name, attacker->name );
   }                                                                            

   return;
}

void object_free( struct object *obj )
{
   free( ( void * ) obj );
}
                                                                                
object *create_object( char *name, int hitpoints, int damage, int dex )
{                                                                               
   struct object *obj = calloc( sizeof( object ), 1 );                          
                                                                                
   obj->debug = object_debug;                                                   
   obj->fight = object_fight;
   obj->free  = object_free;
                                                                                
   strcpy( obj->name, name );                                                   
   obj->maxhitpoints = hitpoints;
   obj->hitpoints = hitpoints;                                                  
   obj->damage = damage;
   obj->dexterity = dex;
                                                                                
   return obj;                                                                  
}
