#ifndef TESTISCORRECTTEXT_H
#define TESTISCORRECTTEXT_H

#include <QObject>
#include <QTest>

#include <analyze.h>

class testIsCorrectText : public QObject
{
    Q_OBJECT
public:
    explicit testIsCorrectText(QObject *parent = 0);

signals:

public slots:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TESTISCORRECTTEXT_H
