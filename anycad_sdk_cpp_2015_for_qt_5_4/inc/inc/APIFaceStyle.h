//Public API. Powered by AnyCAD.

#ifndef _APIFaceStyle_H_
#define _APIFaceStyle_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderStyle.h"

namespace AnyCAD{ namespace API
{
   class Texture;
   class Material;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The face style.
    */
   class AnyPlatformAPI_API FaceStyle
      : public RenderStyle
   {
      DECLARE_APISUPER(FaceStyle, RenderStyle)
   public:
        /**
        * Set Material
        * @param material the material data
        * @return void
        */
      void SetMaterial (const Material& material) ;
        /**
        * Get Material
        * @return const AMaterialPtr&
        */
      Material GetMaterial () const;
        /**
        * Set Transparent
        * @param bEnable if true enable the transparent effect
        */
      void SetTransparent (bool bEnable) ;
        /**
        * Is Transparent
        * @return bool
        */
      bool IsTransparent () const;
        /**
        * Set texture.
        * @param idx the index of texture channel.
        * @param pTex the texture.
        */
      void SetTexture (int idx, const Texture& pTex) ;
        /**
        * Get texture
        * @param idx the channel index.
        * @return the Texture.
        */
      Texture GetTexture (int idx) const;
   };//FaceStyle;
}}//API

#endif //_APIFaceStyle_H_