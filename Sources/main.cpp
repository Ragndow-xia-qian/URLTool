#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>

#include "Headers/mainwindow.h"
#include "Headers/Popup.h"
#include "Headers/InputListDiaLog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const QRect screenRect = QGuiApplication::primaryScreen()->geometry();

    Message::AskPopup ask;
    Message::ErrorPopup error;
    Message::InfoPopup info;
    Message::WarningPopup warning;

    Q_UNUSED(ask)
    Q_UNUSED(error)
    Q_UNUSED(info)
    Q_UNUSED(warning)

    UI::Mainwindow window;

    QRect windowRect = screenRect;

    windowRect.setLeft(screenRect.width() / 4);
    windowRect.setRight(screenRect.width() / 4 * 3);
    windowRect.setTop(screenRect.height() / 4);
    windowRect.setBottom(screenRect.height() / 4 * 3);

    window.setGeometry(windowRect);

    Input::InputListDialog inputList(&window);

    inputList.show();

//    window.popup(info, "我是提示内容");

    window.show();

    if (inputList.exec() == QDialog::Accepted) {
        UI::Mainwindow::exportURLList(inputList.getInputList(), inputList.getInputPosition());
    }

    return QApplication::exec();
}
