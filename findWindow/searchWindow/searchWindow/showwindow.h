#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include <QGroupBox>

namespace Ui {
class showWindow;
}

class showWindow : public QGroupBox
{
    Q_OBJECT

public:
    explicit showWindow(QWidget *parent = nullptr);
    void posUpdate(QString posLabelText);
    ~showWindow();

private:
    Ui::showWindow *ui;

signals:
    void windowBack();

};

#endif // SHOWWINDOW_H
