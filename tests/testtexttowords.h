#ifndef TESTTEXTTOWORDS_H
#define TESTTEXTTOWORDS_H

#include <QObject>
#include <QtTest/QTest>

#include <analyze.h>
typedef QList<Word> WordsList;

class testTextToWords : public QObject
{
    Q_OBJECT
public:
    explicit testTextToWords(QObject *parent = 0);

signals:

public slots:
    
private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TESTTEXTTOWORDS_H
