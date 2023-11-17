/**
  ******************************************************************************
  * @file           : ErrorPopup.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#include <string_view>

#include <QMessageBox>
#include <QString>

#include "Headers/ErrorPopup.h"

namespace Message {
    void ErrorPopup::popup(std::string_view s) {
        auto message = QString::fromStdString(std::string(s));
        QMessageBox::critical(nullptr, "错误", message);
    }
} // Message