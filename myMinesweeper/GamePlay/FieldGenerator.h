#pragma once
#include <vector>
#include "Cell.h"

using namespace std;

class FieldGenerator
{
private:
   vector<vector<Cell>> arrayOfCells;
   Cell cell;
   int sizeX;
   int sizeY;
   int amountOfBombs;
   int calcBombsInSquare( int x, int y );
   
public:
   FieldGenerator( int x, int y, int amount );
   void prepareArray();
   void putBombs();
   void calcAmountOfBombsAround();
   vector<vector<Cell>> getField();
};

