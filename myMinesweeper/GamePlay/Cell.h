#pragma once

class Cell
   {
   private:
      bool opened;
      bool bomb;
      bool flag;
      int amountOfBombsAround;
   public:
      Cell();
      bool isBomb();
      bool isOpened();
      bool isFlag();
      int getNumOfBombsAround();
      void putBomb();
      void changeFlag();
      void setOpened();
      void setNumOfBombsAround( int amount );
   };

