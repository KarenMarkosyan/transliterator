#include <QCoreApplication>
#include "analyze.h"
#include <iostream>

int main(int argc, char *argv[])
{
    #ifdef QT_DEBUG
    //  testig();
    #endif
    QCoreApplication a(argc, argv);
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
