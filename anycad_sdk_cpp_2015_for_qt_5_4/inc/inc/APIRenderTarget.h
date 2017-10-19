//Public API. Powered by AnyCAD.

#ifndef _APIRenderTarget_H_
#define _APIRenderTarget_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Viewport;
   class SceneEnvironment;
   class Vector2;
   class Frustum;
   class Camera;
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The render target.
    */
   class AnyPlatformAPI_API RenderTarget
   {
      DECLARE_APIOBJECT(RenderTarget)
   public:
        /**
        * Get the view port.
        * @return the view port.
        */
      Viewport GetViewport () const;
        /**
        * Get Camera
        * @return Camera
        */
      Camera GetCamera () const;
        /**
        * Get Environment
        * @return Environment
        */
      SceneEnvironment GetEnviornment () const;
        /**
        * Save the scene as image. -since R2014UR1 @ param fileName the image file name.
        * @return true if ok.
        */
      bool CaptureImage (const String& fileName) ;
   };//RenderTarget;
}}//API

#endif //_APIRenderTarget_H_