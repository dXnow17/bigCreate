#ifndef BOOK_H
#define BOOK_H

#include <QObject>

struct BookInfo{
    char rfid[50];
    char title[50];
    char author[50];
    int x;
    int y;
    int z;
    bool condition;//0为空闲 1为忙碌
};

class Book : public QObject
{
    Q_OBJECT
    BookInfo info;
public:
    explicit Book() {cls();}
    void cls();
    ~Book() {cls();}


signals:
};

#endif // BOOK_H
