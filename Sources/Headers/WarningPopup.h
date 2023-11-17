/**
  ******************************************************************************
  * @file           : WarningPopup.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#ifndef OPENURLTOOL_WARNINGPOPUP_H
#define OPENURLTOOL_WARNINGPOPUP_H

#include <string_view>

#include "Headers/PopupTemplate.h"

namespace Message {

    class WarningPopup: public PopupTemplate<void> {
    public:
        void popup(std::string_view s) override;
    };

} // Message

#endif //OPENURLTOOL_WARNINGPOPUP_H
