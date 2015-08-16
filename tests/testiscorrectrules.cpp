#include "testiscorrectrules.h"

testIsCorrectRules::testIsCorrectRules(QObject *parent) : QObject(parent)
{

}

void testIsCorrectRules::test_data()
{
    QTest::addColumn <QString> ("text");
    QTest::addColumn <bool> ("result");
    QTest::newRow("correct input rule") << "a а"
                                           "б b"
                                           "в v"
                                           "г g"
                                           "д d"
                                           "e e"
                                           "ё yo"
                                           "ж zh"
                                           "з z"
                                           "и i"
                                           "й iy"
                                           "к k"
                                           "л l"
                                           "м m"
                                           "н n"
                                           "o о"
                                           "п p"
                                           "р r"
                                           "с s"
                                           "т t"
                                           "у u"
                                           "ф f"
                                           "х h"
                                           "ц c"
                                           "ч ch"
                                           "ш sh"
                                           "ы y"
                                           "ь ‘"
                                           "э e"
                                           "ю yu"
                                           "я ya"
                                        << true;

    QTest::newRow("uncorrect input text (en)") << "a а"
                                                  "б б"
                                                  "в v"
                                               << false;
    QTest::newRow("uncorrect input text (ru)") << "a а"
                                                  "б b"
                                                  "v v"
                                               << false;
}

void testIsCorrectRules::test()
{
    QFETCH(QString, text);
    QFETCH(bool, result);
    QVERIFY2(result == isCorrectRules(createRulesMap(text)), "TEST FAILD!");
}

