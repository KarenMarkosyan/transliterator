#include "testtexttowords.h"

testTextToWords::testTextToWords(QObject *parent) : QObject(parent)
{
    
}

void testTextToWords::test_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<void*> ("idealWords");

    Word word;
    QList<Word>* words = new QList<Word>;

    word.original = "This";
    word.position = 2;
    words->append(word);
    word.original = "i23s";
    word.position = 7;
    words->append(word);
    word.original = "just";
    word.position = 12;
    words->append(word);
    word.original = "a";
    word.position = 17;
    words->append(word);
    word.original = "letter";
    word.position = 19;
    words->append(word);
    word.original = "It";
    word.position = 26;
    words->append(word);
    word.original = "means";
    word.position = 29;
    words->append(word);
    word.original = "nothing";
    word.position = 35;
    words->append(word);
    QTest::newRow("wordsspaces") << "$%This i23s just a letter\nIt means nothing$%^" << (void*)words;

    words = new QList<Word>;
    word.original = "Thisi23sjustaletter";
    word.position = 0;
    words->append(word);
    word.original = "Itmeansnothing";
    word.position = 20;
    words->append(word);
    QTest::newRow("words") << "Thisi23sjustaletter\nItmeansnothing" << (void*)words;

    words = new QList<Word>;
    QTest::newRow("spaces") << "!@#$%^&*(\n><?/.,’;" << (void*)words;

}

void testTextToWords::test()
{

    QFETCH(QString, text);
    QFETCH(void*, idealWords);
    QList<Word> words;
    QList<Word> wordsWordsPointer = *(QList<Word> *)idealWords;
    delete (QList<Word> *)idealWords;
    textToWords(text, words);
    QVERIFY2(words == wordsWordsPointer, "INVALID OUTPUT");
}

