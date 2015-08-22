#include "testanalyze.h"

testAnalyze::testAnalyze(QObject *parent) : QObject(parent)
{

}

void testAnalyze::test_data()
{
    QStringList rulesList;
    QTest::addColumn<QStringList> ("rules");
    QTest::addColumn<void*> ("resWord");

    Word *res = new Word;
    res->original = "this";
    res->position = 0;
    res->translations<< "тхис" << "тх?" << "т?с" << "т?" << "?ис" << "??" << "?с" << "?";
    rulesList<< "a а"
             << "б b"
             << "в v"
             << "г g"
             << "д d"
             << "e e"
             << "ё yo"
             << "ж zh"
             << "з z"
             << "и i"
             << "й iy"
             << "к k"
             << "л l"
             << "м m"
             << "н n"
             << "o о"
             << "п p"
             << "р r"
             << "с s"
             << "т t"
             << "у u"
             << "ф f"
             << "х h"
             << "ц c"
             << "ч ch"
             << "ш sh"
             << "ы y"
             << "ь ‘"
             << "э e"
             << "ю yu"
             << "я ya";
    QTest::newRow("oneTraslate ") << rulesList
                                  << (void*)res;
    res = new Word;
    res->original = "pasha";
    res->position = 0;
    res->translations<< "пасха" << "пас?" << "паша" << "па?" << "п?ха" << "п??" << "п?а" << "п?" << "?сха" << "?с?" << "?ша" << "??" << "?ха" << "??" << "?а" << "?";
    QTest::newRow("oneTraslate ") << rulesList
                                  << (void*)res;
    res = new Word;
    res->original = "pass";
    res->position = 0;
    res->translations<< "?а??" << "?а?" << "???" << "??" << "???" << "??" << "??" << "?";
    rulesList.clear();
    rulesList << "a аb"
              << "б bc"
              << "в cd"
              << "г abc";
    QTest::newRow("manyTranslates") << rulesList << (void*)res;

    res = new Word;
    res->original = "abcd";
    res->position = 0;
    res->translations<< "?а??" << "????" << "??в" << "?б?" << "??" << "а??" << "ав" << "г?" << "?";
    rulesList.clear();
    rulesList << "a а"
              << "б b";

    QTest::newRow("manyTranslates") << rulesList
                                    << (void*)res;
}

void testAnalyze::test()
{
    QFETCH(QStringList, rules);
    QFETCH(void*, resWord);
    Word rW = *(Word*)resWord;
    Word input;
    input.original = rW.original;
    input.position = rW.position;
    delete (Word*)resWord;
    analyze(input, createRulesMap(rules));
    QVERIFY2(input == rW, "INVALID RESULT");
}

