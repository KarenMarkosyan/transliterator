#include <QCoreApplication>
#ifdef QT_DEBUG

#include <tests/testanalyze.h>
#include <tests/testiscorrectrules.h>
#include <tests/testiscorrecttext.h>
#include <tests/testtexttowords.h>
#include <tests/testwordstotexts.h>
void testig(){ // Запускает тестирования
    QTest::qExec(new testAnalyze);
    QTest::qExec(new testIsCorrectRules);
    QTest::qExec(new testIsCorrectText);
    QTest::qExec(new testTextToWords);
    QTest::qExec(new testWordsToTexts);
}
#endif

int main(int argc, char *argv[])
{
    #ifdef QT_DEBUG
    testig();
    #endif
    QCoreApplication a(argc, argv);

    return a.exec();
}
