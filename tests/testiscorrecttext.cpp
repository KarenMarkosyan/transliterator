#include "testiscorrecttext.h"

testIsCorrectText::testIsCorrectText(QObject *parent) : QObject(parent)
{

}

void testIsCorrectText::test_data()
{
    QTest::addColumn <QString> ("text");
    QTest::addColumn <bool> ("result");
    QTest::newRow("correct input text") << "$%This i23s just a letter\nIt means nothing$%^" << true;
    QTest::newRow("correct input text") << "$%This i23s just a letter\nПривет мир!$%^" << false;
}

void testIsCorrectText::test()
{
    QFETCH(QString, text);
    QFETCH(bool, result);
    QVERIFY2(result == isCorrectText(text), "TEST FAILD!");
}

