#include "pch.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "FieldGenerator.h"
#include "Field.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestGamePlay
{
    TEST_CLASS( CellTest )
    {
    public:
        TEST_METHOD( TestCellConstructor )
        {
           Cell cell;
           Assert::AreEqual( false, cell.isFlag(), L"message", LINE_INFO() );
           Assert::AreEqual( false, cell.isBomb(), L"message", LINE_INFO() );
           Assert::AreEqual( false, cell.isOpened(), L"message", LINE_INFO() );
        };
        TEST_METHOD( TestCellChangeFlag )
        {
           Cell cell;
           Assert::IsFalse( cell.isFlag(), L"message", LINE_INFO() );
           cell.changeFlag();
           Assert::IsTrue( cell.isFlag(), L"message", LINE_INFO() );
           cell.changeFlag();
           Assert::IsFalse( cell.isFlag(), L"message", LINE_INFO() );
           cell.changeFlag();
           Assert::IsTrue( cell.isFlag(), L"message", LINE_INFO() );
        };
        TEST_METHOD( TestCellPutBomb )
        {
           Cell cell;
           Assert::IsFalse( cell.isBomb(), L"message", LINE_INFO() );
           cell.putBomb();
           Assert::IsTrue( cell.isBomb(), L"message", LINE_INFO() );
           cell.putBomb();
           Assert::IsTrue( cell.isBomb(), L"message", LINE_INFO() );
        };
        TEST_METHOD( TestCellIsOpened )
        {
           Cell cell;
           Assert::AreEqual( false, cell.isOpened(), L"message", LINE_INFO() );
           cell.setOpened();
           Assert::AreEqual( true, cell.isOpened(), L"message", LINE_INFO() );
           cell.setOpened();
           Assert::AreEqual( true, cell.isOpened(), L"message", LINE_INFO() );
        };
        
    };
    TEST_CLASS( FieldGeneratorTest )
    {
       TEST_METHOD( TestInitializedMask)
       {
          int sizeX = 10;
          int sizeY = 10;
          int amountOfBombs = 10;
          FieldGenerator fieldGenerator( sizeX, sizeY, amountOfBombs );
          fieldGenerator.prepareArray();
          vector<vector<Cell>> field;
          field = fieldGenerator.getField();
          for( int j = 0; j < sizeY; ++j )
          {
             for( int i = 0; i < sizeX; ++i )
             {
                Assert::IsFalse( field[j][i].isOpened(), L"message", LINE_INFO() );
                Assert::IsFalse( field[j][i].isFlag(), L"message", LINE_INFO() );
             }
          };
       };
       TEST_METHOD( TestAmountOfPushedBombs )
       {
          int sizeX = 10;
          int sizeY = 10;
          int amountOfBombs = 10;
          int trueAmountOfBombs = 0;
          FieldGenerator fieldGenerator( sizeX, sizeY, amountOfBombs );
          vector<vector<Cell>> field;
          fieldGenerator.prepareArray();
          fieldGenerator.putBombs();
          field = fieldGenerator.getField();
          for( int j = 0; j < sizeY; ++j )
          {
             for( int i = 0; i < sizeX; ++i )
             {
                if( field[j][i].isBomb() )
                {
                   ++trueAmountOfBombs;
                }
             }
          };
          Assert::AreEqual( amountOfBombs, trueAmountOfBombs );
       };
       TEST_METHOD( TestCalcOfBombsAroundOfCell )
       {
          int sizeX = 10;
          int sizeY = 10;
          int amountOfBombs = 10;
          int trueAmountOfBombs;
          int checkingAmountOfBombs;

          FieldGenerator fieldGenerator( sizeX, sizeY, amountOfBombs );
          vector<vector<Cell>> field;
          fieldGenerator.prepareArray();
          fieldGenerator.putBombs();
          fieldGenerator.calcAmountOfBombsAround();
          field = fieldGenerator.getField();

          for( int j = 0; j < sizeY; j++ )
          {
             for( int i = 0; i < sizeX; i++ )
             {
                checkingAmountOfBombs = field[i][j].getNumOfBombsAround();
                trueAmountOfBombs = 0;
                for( int y = ( j - 1 ); y < ( j + 2 ); y++ )
                {
                   for( int x = ( i - 1 ); x < ( i + 2 ); x++ )
                   {
                      if( ( x >= 0 ) && ( x < sizeX ) && ( y >= 0 ) && ( y < sizeY ) )
                      {
                         if( field[x][y].isBomb() )
                         {
                            ++trueAmountOfBombs;
                         }
                      }
                   }
                }
                Assert::AreEqual( checkingAmountOfBombs, trueAmountOfBombs );
             }
          }
       };
    };
}