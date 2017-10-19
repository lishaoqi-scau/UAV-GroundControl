//Public API. Powered by AnyCAD.

#ifndef _APILineStyle_H_
#define _APILineStyle_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderStyle.h"

namespace AnyCAD{ namespace API
{
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The line/edge style.
    */
   class AnyPlatformAPI_API LineStyle
      : public RenderStyle
   {
      DECLARE_APISUPER(LineStyle, RenderStyle)
   public:
        /**
        * Set Line Width
        * @param fWidth the width
        */
      void SetLineWidth (Real fWidth) ;
        /**
        * Get Line Width
        * @return float
        */
      Real GetLineWidth () const;
        /**
        * Set Line pattern factor.
        * @param patternFactor the pattern factor.
        */
      void SetPatternFactor (Real patternFactor) ;
        /**
        * Get Line pattern factor.
        * @return the pattern factor.
        */
      Real GetPatternFactor () const;
        /**
        * Set Line pattern.
        * @param style the style pattern.
        */
      void SetPatternStyle (int style) ;
        /**
        * Get Line pattern.
        * @return the style pattern.
        */
      int GetPatternStyle () const;
   };//LineStyle;
}}//API

#endif //_APILineStyle_H_