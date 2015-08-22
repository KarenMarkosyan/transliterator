#include "testiscorrectrules.h"

testIsCorrectRules::testIsCorrectRules(QObject *parent) : QObject(parent)
{

}

void testIsCorrectRules::test_data()
{
    QStringList rulesList;
    QTest::addColumn <QStringList> ("text");
    QTest::addColumn <bool> ("result");
    rulesList<< "а a"
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
             << "о o"
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
             << "ь `"
             << "э e"
             << "ю yu"
             << "я ya";
    QTest::newRow("correct input rule") << rulesList << true;

    rulesList.clear();
    rulesList << "a а"
              << "б б"
              << "в v";
    QTest::newRow("uncorrect input text (en)") << rulesList << false;

    rulesList.clear();
    rulesList << "a а"
              << "б b"
              << "v v";
    QTest::newRow("uncorrect input text (ru)") << rulesList << false;
}

void testIsCorrectRules::test()
{
    QFETCH(QStringList, text);
    QFETCH(bool, result);
    RulesMap m = createRulesMap(text);
    QVERIFY2(result == isCorrectRules(m), "TEST FAILD!");
}

