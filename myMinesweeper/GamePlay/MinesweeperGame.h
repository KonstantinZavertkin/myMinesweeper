#pragma once
#include "Field.h"
#include "StepAction.h"

class MinesweeperGame
{
   Field field;
   StepAction stepAction;
   int sizeX;
   int sizeY;
   int amountOfBombs;
   bool gameOver;
public:
   void initializeField( int sizeX, int sizeY, int amountOfBombs );
   void performStep( int x, int y, char action );
   bool isGameOver();
   Field getField();
};

