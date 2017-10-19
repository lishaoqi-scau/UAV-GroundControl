//Public API. Powered by AnyCAD.

#ifndef _APIFontDecomposer_H_
#define _APIFontDecomposer_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font outline decomposer.
    */
   class AnyPlatformAPI_API FontDecomposer
   {
      DECLARE_APIOBJECT(FontDecomposer)
   public:
        /**
        * Get the character width.
        * @return the width.
        */
      Real GetWidth () const;
        /**
        * Get the character height.
        * @return the height.
        */
      Real GetHeight () const;
   };//FontDecomposer;
}}//API

#endif //_APIFontDecomposer_H_