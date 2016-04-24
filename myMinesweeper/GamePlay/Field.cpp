#include "pch.h"
#include "Field.h"


using namespace std;

Field::Field( int sizeX, int sizeY, int amountOfBombs )
{
   this -> sizeX = sizeX;
   this -> sizeY = sizeY;
   this -> amountOfBombs = amountOfBombs;

   FieldGenerator generatedField( sizeX, sizeY, amountOfBombs );
   generatedField.prepareArray();
   generatedField.putBombs();
   generatedField.calcAmountOfBombsAround();
   
}
void Field::changeFlag( int x, int y )
{
   field[y][x].changeFlag();
};
void Field::openCell( int x, int y )
{
   field[y][x].setOpened();
};
bool Field::isBomb( int x, int y )
{
   return field[y][x].isBomb();
};
bool Field::isOpened( int x, int y )
{
   return field[y][x].isOpened();
}
int Field::getValue( int x, int y )
{
   return field[y][x].getNumOfBombsAround();
}
bool Field::isFlag( int x, int y )
{
   return field[y][x].isFlag();
}
