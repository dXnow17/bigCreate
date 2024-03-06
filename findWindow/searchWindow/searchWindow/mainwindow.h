#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "showwindow.h"
#include <QtSql/QSqlDataBase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlTableModel* model_;
    QTimer *timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    showWindow * showWin = NULL;
    void timerUpdata();
    void dbSet(const QString &name);
    void dbAdd();
    void serBook();
    void showBook();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
