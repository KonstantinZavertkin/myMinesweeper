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
   Field( int sizeX, int sizeY, int amountOfBombs );
   void changeFlag( int x, int y );
   void openCell( int x, int y );
   int getValue( int x, int y );
   bool isOpened( int x, int y );
   bool isBomb( int x, int y );
   bool isFlag( int x, int y );
};

