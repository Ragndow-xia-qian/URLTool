/**
  ******************************************************************************
  * @file           : AskPopup.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#include <string_view>

#include <QMessageBox>
#include <QString>

#include "Headers/AskPopup.h"

namespace Message {
    bool AskPopup::popup(std::string_view s) {
        auto message = QString::fromStdString(std::string(s));
        return QMessageBox::question(nullptr, "询问", message) == QMessageBox::Yes;
    }
} // Message