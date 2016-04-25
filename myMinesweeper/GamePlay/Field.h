#pragma once
#include<vector>
#include "Cell.h"
#include "FieldGenerator.h"

using namespace std;

class Field
{
private:
   vector<vector<Cell>> field;
   int sizeX;
   int sizeY;
   int amountOfBombs;
public:
   void createField( int sizeX, int sizeY, int amountOfBombs );
   void changeFlag( int x, int y );
   void setOpened( int x, int y );
   int getValue( int x, int y );
   bool isOpened( int x, int y );
   bool isBomb( int x, int y );
   bool isFlag( int x, int y );
   vector<vector<Cell>> getField();
};

