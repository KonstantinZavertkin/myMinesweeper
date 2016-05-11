#include "pch.h"
#include "MinesweeperGame.h"
#include "Field.h"
#include "StepAction.h"

void MinesweeperGame::initializeField( int sizeX, int sizeY, int amountOfBombs )
{
   gameOver = false;
   Field field;
   field.createField( sizeX, sizeY, amountOfBombs );
   this -> field = field;
   StepAction stepAction;
   stepAction.initialStepAction( sizeX, sizeY, field );
   this -> stepAction = stepAction;
};
void MinesweeperGame::performStep( int x, int y, char action )
{
   stepAction.performAction( x, y, action );
   field = stepAction.getField();
};
bool MinesweeperGame::isGameOver()
{
   return gameOver;
};
Field MinesweeperGame::getField()
{
   return field;
};
