/**
  ******************************************************************************
  * @file           : WarningPopup.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#include <string_view>

#include <QMessageBox>
#include <QString>

#include "Headers/WarningPopup.h"

namespace Message {
    void WarningPopup::popup(std::string_view s) {
        auto message = QString::fromStdString(std::string(s));
        QMessageBox::warning(nullptr, "警告", message);
    }
} // Message