#ifndef BOOK_H
#define BOOK_H

#include <QObject>

struct BookInfo{
    char rfid[50];
    char book_title[50];
    char book_author[50];
    int book_x;
    int book_y;
    int book_z;
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
