#include "pch.h"
#include "StepAction.h"
#include "Field.h"


void StepAction::initialStepAction( int sizeX, int sizeY, Field field )
{
   this -> field = field;
   this -> sizeX = sizeX;
   this -> sizeY = sizeY;
}

Field StepAction::getField()
{
   return field;
};
void StepAction::changeFlag( int x, int y )
{
   field.changeFlag( x, y );
}

int StepAction::square(int x, int y , char type )
{
   int localAmountOfType = 0;
   for( int j = ( x - 1 ); j <= ( x + 1 ); ++j )
   {
      for( int i = ( y - 1 ); i <= ( y + 1 ); ++i )
      {
         if( ( i >= 0 ) && ( i < sizeY ) && ( j >= 0 ) && ( j < sizeX ) )
         {
            if( type == 'f' )
            {
               if( field.isFlag( y, x ) )
               {
                  ++localAmountOfType;
               }
            }
         }
      }
   }
   return localAmountOfType;
};
void StepAction::tryOpen( int x, int y, char type )
{
   if( field.isFlag( x, y ) )
   {
      field.changeFlag( x, y );
   }
   else
   {
      if( field.isOpened( x, y ) )
      {
         if( field.getValue( x, y ) == square( x, y, 'f' ) )
         {
            openCells( x, y );
         }
      }
      else
      {
         openCells( x, y );
      }
   }
}
void StepAction::openCells( int x, int y )
{
   
   if( field.getValue( x, y ) != 0 )
   {
      if( !field.isOpened( x, y ) )
      {
         field.setOpened( x, y );
      }
   }
   else
   {
      for( int j = ( y - 1 ); j <= ( y + 1 ); ++j )
      {
         for( int i = ( x - 1 ); i <= ( x + 1 ); ++i )
         {
            if( ( i >= 0 ) && ( i < sizeX ) && ( j >= 0 ) && ( j < sizeY ) )
            {
               if( !( ( i == x ) && ( j == y ) ) )
               {
                  if( !field.isOpened( i, j ) && !field.isFlag( i, j ))
                  {
                     field.setOpened( i, j );
                     openCells( i, j );
                  }
               }
            }
         }
      }
   }
};
void StepAction::performAction( int x, int y, char currentAction )
{
   if( currentAction == 'f' )
   {
      field.changeFlag( x, y );
   }
   else
   {
      tryOpen( x, y , '\0');
   }
};