//Public API. Powered by AnyCAD.

#ifndef _APIRenderStyle_H_
#define _APIRenderStyle_H_

#include "core/APIObjectDef.h"

#include "inc/APIObject.h"

namespace AnyCAD{ namespace API
{
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Scene node style.
    */
   class AnyPlatformAPI_API RenderStyle
      : public Object
   {
      DECLARE_APISUPER(RenderStyle, Object)
   public:
        /**
        * Set Color
        * @param clr the color
        */
      void SetColor (const ColorValue& clr) ;
        /**
        * Set Color
        * @param r the red value
        * @param g the green value
        * @param b the blue value
        */
      void SetColor (int r, int g, int b) ;
        /**
        * Get Color
        * @return ColorValue
        */
      ColorValue GetColor () const;
   };//RenderStyle;
}}//API

#endif //_APIRenderStyle_H_