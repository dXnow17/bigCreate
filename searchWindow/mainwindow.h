#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "showwindow.h"
#include "database.h"
#include <QtSql/QSqlDataBase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTimer *timer;
    DataBase *dBptr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    showWindow * showWin = NULL;
    void timerUpdata();
    void serBook();
    void showBook();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
