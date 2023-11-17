/**
  ******************************************************************************
  * @file           : InfoPopup.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#ifndef OPENURLTOOL_INFOPOPUP_H
#define OPENURLTOOL_INFOPOPUP_H

#include <string_view>

#include "Headers/PopupTemplate.h"

namespace Message {

    class InfoPopup: public PopupTemplate<void> {
    public:
        void popup(std::string_view s) override;
    };

} // Message

#endif //OPENURLTOOL_INFOPOPUP_H
