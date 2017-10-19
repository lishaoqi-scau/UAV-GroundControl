//Public API. Powered by AnyCAD.

#ifndef _APICommand_H_
#define _APICommand_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Editor;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  the base command class.
    */
   class AnyPlatformAPI_API Command
   {
      DECLARE_APIOBJECT(Command)
   public:
   };//Command;
}}//API

#endif //_APICommand_H_