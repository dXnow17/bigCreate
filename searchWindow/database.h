#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

class DataBase : public QMainWindow
{
    Q_OBJECT
public:
    explicit DataBase(QWidget *parent = nullptr);
    void dbBuild();
    bool ok;

signals:
};

#endif // DATABASE_H
