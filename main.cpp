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
#else
#include "fusion.h"
#endif
#include <iostream>
int main(int argc, char *argv[])
{
//    char argv[4][80] = {
//        "progName",
//        "input.txt",
//        "rules1.txt",
//        "output.txt"
//    };
    #ifdef QT_DEBUG
  //  testig();
    #endif
    QCoreApplication a(argc, argv1);
    if (argc < 4){
       std::cout << "Incorrect number of arguments\nIt started with standard values";
    }
    else{
        QString text;
        RulesMap rules;
        if (!readText(QString(argv[1]), text)){
           std::cout << "Can not open file: " << argv[1];
           return a.exec();
        }
        if (!readRules(QString(argv[2]), rules)){
           std::cout << "Can not open file: " << argv[2];
           return a.exec();
        }
        if (!isCorrectText(text)){
            std::cout << "Invalid input text!";
            return a.exec();
        }
        if (!isCorrectRules(rules)){
            std::cout << "Invalid input rules!";
            return a.exec();
        }
        QList<Word> words;
        textToWords(text, words);
        analyzeAllWords(words, rules);
        QList<QString> texts;
        wordsToTexts(text, words, texts);
        if (writeTexts(QString(argv[3]), texts)){
            std::cout << "Translation completed!";
        }
        else {
            std::cout << "Can not open output file: " << argv[3];
            return a.exec();
        }
    }
    return a.exec();
}
