//Public API. Powered by AnyCAD.

#ifndef _APIPointStyle_H_
#define _APIPointStyle_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderStyle.h"

namespace AnyCAD{ namespace API
{
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The point style.
    */
   class AnyPlatformAPI_API PointStyle
      : public RenderStyle
   {
      DECLARE_APISUPER(PointStyle, RenderStyle)
   public:
        /**
        * Set Point Size
        * @param pointSize the point size
        */
      void SetPointSize (Real pointSize) ;
        /**
        * Get Line Width
        * @return float
        */
      Real GetPointSize () const;
        /**
        * Set the marker
        * @param name the marker name
        */
      void SetMarker (const String& name) ;
        /**
        * Get the marker. Default is empty.
        * @return the marker name.
        */
      String GetMarker () const;
   };//PointStyle;
}}//API

#endif //_APIPointStyle_H_