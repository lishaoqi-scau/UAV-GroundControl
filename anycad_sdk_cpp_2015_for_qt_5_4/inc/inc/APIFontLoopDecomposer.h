//Public API. Powered by AnyCAD.

#ifndef _APIFontLoopDecomposer_H_
#define _APIFontLoopDecomposer_H_

#include "core/APIObjectDef.h"

#include "inc/APIFontDecomposer.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font loop decomposer.
    */
   class AnyPlatformAPI_API FontLoopDecomposer
      : public FontDecomposer
   {
      DECLARE_APISUPER(FontLoopDecomposer, FontDecomposer)
   public:
   };//FontLoopDecomposer;
}}//API

#endif //_APIFontLoopDecomposer_H_