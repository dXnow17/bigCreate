/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *timeLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QTableView *tableView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *showBtn;
    QPushButton *findBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(16);
        timeLabel->setFont(font);
        timeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeLabel, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 4, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");
        comboBox->setEnabled(true);
        comboBox->setSizeIncrement(QSize(20, 40));
        comboBox->setFont(font);
        comboBox->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font);
        lineEdit->setMaxLength(90);

        horizontalLayout->addWidget(lineEdit);

        showBtn = new QPushButton(widget);
        showBtn->setObjectName("showBtn");
        showBtn->setFont(font);

        horizontalLayout->addWidget(showBtn);

        findBtn = new QPushButton(widget);
        findBtn->setObjectName("findBtn");
        findBtn->setFont(font);

        horizontalLayout->addWidget(findBtn);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\347\225\214\351\235\242", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "2024-03-0314:01:33 Sunday", nullptr));
        lineEdit->setText(QString());
        showBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        findBtn->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
