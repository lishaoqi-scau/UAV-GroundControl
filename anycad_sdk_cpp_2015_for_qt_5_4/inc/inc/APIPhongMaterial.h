//Public API. Powered by AnyCAD.

#ifndef _APIPhongMaterial_H_
#define _APIPhongMaterial_H_

#include "core/APIObjectDef.h"

#include "inc/APIMaterial.h"

namespace AnyCAD{ namespace API
{
   class ColorValue;
   class Material;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The material with phong Algorithm.
    */
   class AnyPlatformAPI_API PhongMaterial
      : public Material
   {
      DECLARE_APISUPER(PhongMaterial, Material)
   public:
        /**
        * Set Ambient
        * @param clr the color
        * @return void
        */
      void SetAmbient (const ColorValue& clr) ;
        /**
        * Get Ambient
        * @return ColorValue
        */
      ColorValue GetAmbient () const;
        /**
        * Set Diffuse
        * @param clr the color
        * @return void
        */
      void SetDiffuse (const ColorValue& clr) ;
        /**
        * Get Diffuse
        * @return the color
        */
      ColorValue GetDiffuse () const;
        /**
        * Set Specular
        * @param clr the color
        * @return void
        */
      void SetSpecular (const ColorValue& clr) ;
        /**
        * Get Specular
        * @return the color
        */
      ColorValue GetSpecular () const;
        /**
        * Set Emission
        * @param clr the color
        * @return void
        */
      void SetEmission (const ColorValue& clr) ;
        /**
        * Get Emission
        * @return the color
        */
      ColorValue GetEmission () const;
        /**
        * Set Shininess
        * @param value the shininess
        * @return void
        */
      void SetShininess (Real value) ;
        /**
        * Get Shininess
        * @return float
        */
      Real GetShininess () const;
   };//PhongMaterial;
}}//API

#endif //_APIPhongMaterial_H_