#include "pch.h"
#include "Cell.h"

Cell::Cell()
{
   opened = false;
   flag = false;
   bomb = false;
};
bool Cell::isBomb()
{
   return bomb;
};
bool Cell::isFlag()
{
   return flag;
};
bool Cell::isOpened()
{
   return opened;
};
int Cell::getNumOfBombsAround()
{
   return amountOfBombsAround;
};
void Cell::putBomb()
{
   bomb = true;
};
void Cell::changeFlag()
{
   flag = !flag;
};
void Cell::setOpened()
{
   opened = true;
};
void Cell::setNumOfBombsAround( int amount )
{
   amountOfBombsAround = amount;
};
