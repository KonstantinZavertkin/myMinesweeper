#pragma once
#include "Field.h"
#include <iostream>

class StepAction
{
private:
   Field field;
   int sizeX;
   int sizeY;
   char currentAction;
   int getAmountOfFlagsInSquare( int x, int y );
   void tryOpen( int x, int y );
public:
   void initialStepAction( int sizeX, int sizeY, Field field );
   void performAction( int x, int y, char currentAction );
   void changeFlag( int x, int y );
   void openCells( int x, int y );
   Field getField();
};

