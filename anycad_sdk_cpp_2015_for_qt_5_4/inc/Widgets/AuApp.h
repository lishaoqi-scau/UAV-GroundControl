
#pragma once

#include "inc/APIEventListener.h"

namespace AnyCAD { namespace QtUi {

/**
* @ingroup QtUi
* @brief
* The utility methods.
*/
class AnyPlatformQtAPI AuApp
{
public:
    /**
    * Initialize the application.
    * @return false if failed.
    */
    static bool Initializ();

    /**
    * Convert QString to String.
    * @return the string.
    */
    static AnyCAD::API::String ToString(const QString& str);
};


#define UISTR(str) AuApp::ToString(str)

}}