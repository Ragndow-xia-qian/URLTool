/**
  ******************************************************************************
  * @file           : InfoPopup.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#include <string_view>

#include <QMessageBox>
#include <QString>

#include "Headers/InfoPopup.h"

namespace Message {
    void InfoPopup::popup(std::string_view s) {
        auto message = QString::fromStdString(std::string(s));
        QMessageBox::information(nullptr, "提示", message);
    }
} // Message