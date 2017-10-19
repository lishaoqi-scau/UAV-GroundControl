//Public API. Powered by AnyCAD.

#ifndef _APITexture_H_
#define _APITexture_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderResource.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   class Matrix4;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The texture.
    */
   class AnyPlatformAPI_API Texture
      : public RenderResource
   {
      DECLARE_APISUPER(Texture, RenderResource)
   public:
        /**
        * Set image file name.
        * @param strFile the file name.
        */
      void SetFileName (const String& strFile) ;
        /**
        * Get image file name.
        * @return the file name.
        */
      String GetFileName () const;
        /**
        * Set scale.
        * @param scale the scale factor.
        */
      void SetScale (const Vector2& scale) ;
        /**
        * Get scale.
        * @return the scale factor.
        */
      Vector2 GetScale () const;
        /**
        * Move.
        * @param trans the offset factor.
        */
      void SetTranslation (const Vector2& trans) ;
        /**
        * Get translation.
        * @return the translation factor.
        */
      Vector2 GetTranslation () const;
        /**
        * Rotation.
        * @param angle the rotation factor.
        */
      void SetRotation (Real angle) ;
        /**
        * Get rotation factor.
        * @return the rotation factor.
        */
      Real GetRoation () const;
        /**
        * Update the transform after change the transform factors..
        */
      void UpdateTransform () ;
        /**
        * Get transform matrix.
        * @return the transform matrix.
        */
      Matrix4 GetTransform () const;
   };//Texture;
}}//API

#endif //_APITexture_H_