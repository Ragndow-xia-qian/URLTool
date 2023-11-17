/**
  ******************************************************************************
  * @file           : AskPopup.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#ifndef OPENURLTOOL_ASKPOPUP_H
#define OPENURLTOOL_ASKPOPUP_H

#include <string_view>

#include "Headers/PopupTemplate.h"

namespace Message {

    class AskPopup: public PopupTemplate<bool> {
    public:
        bool popup(std::string_view s) override;
    };

} // Message

#endif //OPENURLTOOL_ASKPOPUP_H
