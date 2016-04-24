#include "pch.h"

#include "FieldGenerator.h"


using namespace std;

void FieldGenerator::prepareArray()
{
   Cell cell;
   vector<Cell> emptyVector;
   for( int i = 0; i < sizeX; ++i )
      emptyVector.push_back( cell );
   for( int j = 0; j < sizeY; ++j )
      arrayOfCells.push_back( emptyVector );
};
void FieldGenerator::putBombs()
{
   int currentAmount = 0;
   int x, y;
   while( currentAmount < amountOfBombs )
   {
      x = rand() % sizeX;
      y = rand() % sizeY;
      if( !arrayOfCells[y][x].isBomb() )
      {
         arrayOfCells[y][x].putBomb();
         currentAmount++;
      }
   };
};
int FieldGenerator::calcBombsInSquare( int x, int y )
{
   int localAmountOfBombs = 0;
   for( int j = ( x - 1 ); j <= ( x + 1 ); ++j )
   {
      for( int i = ( y - 1 ); i <= ( y + 1 ); ++i )
      {
         if( ( i >= 0 ) && ( i < sizeY ) && ( j >= 0 ) && ( j < sizeX ) )
         {
            if( arrayOfCells[i][j].isBomb() )
               ++localAmountOfBombs;
         }
      }
   }
   return localAmountOfBombs;
};
void FieldGenerator::calcAmountOfBombsAround()
{
   for( int i = 0; i < sizeX; ++i )
   {
      for( int j = 0; j < sizeY; ++j )
      {
         arrayOfCells[j][i].setNumOfBombsAround( calcBombsInSquare( i, j ) );
      }
   }
};
FieldGenerator::FieldGenerator( int sizeX, int sizeY, int amountOfBombs )
{
   this -> sizeX = sizeX;
   this -> sizeY = sizeY;
   this -> amountOfBombs = amountOfBombs;

}
vector<vector<Cell>> FieldGenerator::getField()
{
   return arrayOfCells;
}


