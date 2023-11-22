/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

namespace UI {

class Ui_Mainwindow
{
public:

    void setupUi(QWidget *UI__Mainwindow)
    {
        if (UI__Mainwindow->objectName().isEmpty())
            UI__Mainwindow->setObjectName(QString::fromUtf8("UI__Mainwindow"));
        UI__Mainwindow->resize(400, 300);

        retranslateUi(UI__Mainwindow);

        QMetaObject::connectSlotsByName(UI__Mainwindow);
    } // setupUi

    void retranslateUi(QWidget *UI__Mainwindow)
    {
        UI__Mainwindow->setWindowTitle(QCoreApplication::translate("UI::Mainwindow", "Mainwindow", nullptr));
    } // retranslateUi

};

} // namespace UI

namespace UI {
namespace Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace Ui
} // namespace UI

#endif // UI_MAINWINDOW_H
