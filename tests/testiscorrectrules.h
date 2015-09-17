#ifndef TESTISCORRECTRULES_H
#define TESTISCORRECTRULES_H

#include <QObject>
#include <QTest>

#include <analyze.h>

class testIsCorrectRules : public QObject
{
    Q_OBJECT
public:
    explicit testIsCorrectRules(QObject *parent = 0);

signals:

public slots:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TESTISCORRECTRULES_H
