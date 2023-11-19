//
// Created by 37237 on 2023/11/17.
//

#ifndef OPENURLTOOL_MAINWINDOW_H
#define OPENURLTOOL_MAINWINDOW_H

#include <string_view>

#include <QWidget>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "Headers/PopupTemplate.h"
#include "Headers/Popup.h"

namespace UI {
    QT_BEGIN_NAMESPACE
    namespace Ui { class Mainwindow; }
    QT_END_NAMESPACE

    class Mainwindow : public QWidget {
    Q_OBJECT

    public:
        explicit Mainwindow(QWidget *parent = nullptr);

        template<typename T>
        T popup(Message::PopupTemplate<T> &tool, std::string_view s);

        static void exportURLList(const QStringList &urlList, const QString &filename);

        static void openURL(const QString &url);

        ~Mainwindow() override;

    private:
        Ui::Mainwindow *ui;
    };
} // UI

#endif //OPENURLTOOL_MAINWINDOW_H
