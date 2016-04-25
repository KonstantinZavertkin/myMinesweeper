#pragma once
#include "Field.h"

class StepAction
{
private:
   Field field;
   int sizeX;
   int sizeY;
   char currentAction;
   int square( int x, int y, char type );
   void tryOpen( int x, int y, char type );
public:
   void initialStepAction( int sizeX, int sizeY, Field field );
   void performAction( int x, int y, char currentAction );
   void changeFlag( int x, int y );
   void openCells( int x, int y );
   Field getField();
};

