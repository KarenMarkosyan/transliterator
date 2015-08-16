#include "testwordstotexts.h"

testWordsToTexts::testWordsToTexts(QObject *parent) : QObject(parent)
{

}

void testWordsToTexts::test_data()
{
    QTest::addColumn<QString> ("text");
    QTest::addColumn<void*> ("wordList");
    QTest::addColumn<void*> ("resTexts");

    QStringList *resTexts = new QStringList;
    QList<Word> *wordList = new QList<Word>;
    Word w;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "ис" << "из";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();

    resTexts->append("вис ис Спарта!");
    resTexts->append("вис ис спарта!");
    resTexts->append("вис из Спарта!");
    resTexts->append("Вис из спарта!");
    resTexts->append("Вис ис Спарта!");
    resTexts->append("Вис ис спарта!");
    resTexts->append("Вис из Спарта!");
    resTexts->append("Вис из спарта!");
    QTest::newRow("oneStringOnlyLetters") << "This is Sparta!" << (void*)wordList << (void*)resTexts;
    //-----------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "ис" << "из";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();


    resTexts->append("вис ис\nСпарта!");
    resTexts->append("вис ис\nспарта!");
    resTexts->append("вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    resTexts->append( "Вис ис\nСпарта!");
    resTexts->append("Вис ис\nспарта!");
    resTexts->append("Вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    QTest::newRow("someString") << "This is\nSparta!" << (void*)wordList << (void*)resTexts;
    //-------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "ис" << "из";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();

    resTexts->append("вис ис\nСпарта!");
    resTexts->append("вис ис\nспарта!");
    resTexts->append("вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    resTexts->append("Вис ис\nСпарта!");
    resTexts->append("Вис ис\nспарта!");
    resTexts->append("Вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    QTest::newRow("someString") << "This is\nSparta!" << (void*)wordList << (void*)resTexts;
    //---------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "??" << "из";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();


    resTexts->append("вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    resTexts->append("Вис из\nСпарта!");
    resTexts->append("Вис из\nспарта!");
    QTest::newRow("someString") << "This is\nSparta!" << (void*)wordList << (void*)resTexts;
    //-------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "??" << "из";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();


    resTexts->append("вис из Спарта!");
    resTexts->append("Вис из спарта!");
    resTexts->append("Вис из Спарта!");
    resTexts->append("Вис из спарта!");
    QTest::newRow("oneStringAndHaveWrongWords ") << "This is Sparta!" << (void*)wordList << (void*)resTexts;
    //--------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "Вис";
    wordList->append(w);
    w.translations.clear();
    w.original = "is";
    w.position = 5;
    w.translations << "??";
    wordList->append(w);
    w.translations.clear();
    w.original = "Sparta";
    w.position = 8;
    w.translations << "Спарта" << "спарта";
    wordList->append(w);
    w.translations.clear();

    resTexts->append("вис ?? Спарта!");
    resTexts->append("Вис ?? спарта!");
    resTexts->append("Вис ?? Спарта!");
    resTexts->append("Вис ?? спарта!");
    QTest::newRow("haveNotTranslitWithoutWrongWords") << "This is Sparta!" << (void*)wordList << (void*)resTexts;
    //-----------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;
    w.original = "This";
    w.position = 0;
    w.translations << "вис" << "?ис";
    wordList->append(w);
    w.translations.clear();

    resTexts->append("вис");
    QTest::newRow("oneWordAndHaveWrongWords  ") << "This" << (void*)wordList << (void*)resTexts;
    //------------------------------------
    resTexts = new QStringList;
    wordList = new QList<Word>;

    resTexts->append("@#$%^&*");
    QTest::newRow("oneStringSpaces") << "“@#$%^&*”" << (void*)wordList << (void*)resTexts;
}

void testWordsToTexts::test()
{
    QFETCH(QString, text);
    QFETCH(void*, wordList);
    QFETCH(void*, resTexts);

    QList<Word> wL = *(QList<Word>*)wordList;
    delete (QList<Word>*)wordList;
    QStringList rT = *(QStringList*)resTexts;
    delete (QStringList*)resTexts;
    QStringList res;
    wordsToTexts(text, wL, res);
    QVERIFY2(res == rT, "INVALID RESULT");
}

