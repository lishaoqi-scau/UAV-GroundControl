//Public API. Powered by AnyCAD.

#ifndef _APIViewport_H_
#define _APIViewport_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   class Matrix4;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Viewport.
    */
   class AnyPlatformAPI_API Viewport
   {
      DECLARE_APIOBJECT(Viewport)
   public:
        /**
        * Get x
        * @return the x.
        */
      Real GetX () const;
        /**
        * Get y
        * @return the y.
        */
      Real GetY () const;
        /**
        * Get width
        * @return the width.
        */
      Real GetWidth () const;
        /**
        * Get height
        * @return the height.
        */
      Vector2 GetSize () const;
   };//Viewport;
}}//API

#endif //_APIViewport_H_