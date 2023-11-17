/**
  ******************************************************************************
  * @file           : PopupTemplate.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#ifndef OPENURLTOOL_POPUPTEMPLATE_H
#define OPENURLTOOL_POPUPTEMPLATE_H

#include <string_view>

namespace Message {

    template<typename T>
    class PopupTemplate {
    public:
        virtual T popup(std::string_view s) = 0;
    };

} // Message

#endif //OPENURLTOOL_POPUPTEMPLATE_H
