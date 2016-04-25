// myMinesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GamePlay.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
   Field field;
   field.createField( 20, 20, 40 );
   MinesweeperGame minesweeper;
   minesweeper.initializeField(20, 20, 40);
   field = minesweeper.getField();
   
   for( int i = 0; i < 20; i++ )
   {
      cout << "| ";
      for( int j = 0; j < 20; j++ )
      {
         if( field.isFlag( j, i ) )
         {
            cout << 'f' << ' ';
         }
         else
         {
            if( field.isBomb( j, i ) )
            {
               cout << 'x' << ' ';
            }
            else
            {
               cout << field.getValue( j, i ) << ' ';
            }
         }
      }
      cout << "|" << endl;
   }
   cout << endl;
   
   /*
   stepAction.performAction(16,4,'f');
   field = stepAction.getField();
   stepAction.performAction(17,4,'f');
   field = stepAction.getField();
   stepAction.performAction(18,4,'f');
   field = stepAction.getField();
   stepAction.performAction(19,4,'f');
   field = stepAction.getField();
   stepAction.performAction(16,5,'f');
   field = stepAction.getField();
   stepAction.performAction(16,6,'f');
   field = stepAction.getField();
   stepAction.performAction(16,7,'f');
   field = stepAction.getField();
   stepAction.performAction(17,7,'f');
   field = stepAction.getField();
   stepAction.performAction(18,7,'f');
   field = stepAction.getField();
   stepAction.performAction(19,7,'f');
   field = stepAction.getField();
   stepAction.performAction(19,6,'f');
   field = stepAction.getField();
   stepAction.performAction(19,5,'f');
   field = stepAction.getField();

   stepAction.performAction(3,6,'o');
   field = stepAction.getField();
   stepAction.performAction(4,3,'o');
   field = stepAction.getField();
   stepAction.performAction(19,0,'o');
   field = stepAction.getField();
   stepAction.performAction(19,0,'o');
   field = stepAction.getField();
   stepAction.performAction(15,19,'o');
   field = stepAction.getField();
   */
   
   minesweeper.performStep(0, 0, 'q');
   field = minesweeper.getField();

   minesweeper.performStep(1, 4, 'f');
   field = minesweeper.getField();

   minesweeper.performStep(0, 3, 'q');
   field = minesweeper.getField();

   minesweeper.performStep(13, 3, 'f');
   field = minesweeper.getField();

   minesweeper.performStep(12, 4, 'q');
   field = minesweeper.getField();

   minesweeper.performStep(13, 4, 'q');
   field = minesweeper.getField();

   minesweeper.performStep(14, 4, 'q');
   field = minesweeper.getField();



   for( int i = 0; i < 20; i++ )
   {
      cout << "|";
      for( int j = 0; j < 20; j++ )
      {
         if( field.isFlag( j, i ) )
         {
            cout << 'f' << '|';
         }
         else
         {
            if( field.isOpened( j, i ) )
            {
               cout << field.getValue( j, i ) << '|';
            }
            else
            {
               cout << '_' << '|';
            }
         }
      }
      cout << endl;
   }
   cout << endl;
   

   system("pause");
	return 0;
}