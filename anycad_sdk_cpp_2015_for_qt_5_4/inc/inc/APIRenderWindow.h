//Public API. Powered by AnyCAD.

#ifndef _APIRenderWindow_H_
#define _APIRenderWindow_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderTarget.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The render window.
    */
   class AnyPlatformAPI_API RenderWindow
      : public RenderTarget
   {
      DECLARE_APISUPER(RenderWindow, RenderTarget)
   public:
   };//RenderWindow;
}}//API

#endif //_APIRenderWindow_H_