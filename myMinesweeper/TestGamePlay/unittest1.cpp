#include "pch.h"
#include "CppUnitTest.h"
#include "Cell.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestGamePlay
{
    TEST_CLASS( TestCell )
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
           cell.changeFlag();
           Assert::AreEqual( true, cell.isFlag(), L"message", LINE_INFO() );
           cell.changeFlag();
           Assert::AreEqual( false, cell.isFlag(), L"message", LINE_INFO() );
           cell.changeFlag();
           Assert::AreEqual( true, cell.isFlag(), L"message", LINE_INFO() );
        };
        TEST_METHOD( TestCellPutBomb )
        {
           Cell cell;
           cell.putBomb();
           Assert::AreEqual( true, cell.isBomb(), L"message", LINE_INFO() );
           cell.putBomb();
           Assert::AreEqual( true, cell.isBomb(), L"message", LINE_INFO() );
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
}