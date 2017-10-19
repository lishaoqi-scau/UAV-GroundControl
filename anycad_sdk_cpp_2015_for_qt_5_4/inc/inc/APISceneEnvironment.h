//Public API. Powered by AnyCAD.

#ifndef _APISceneEnvironment_H_
#define _APISceneEnvironment_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class WorkingPlane;
   class Camera;
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The environment settings -since R2014UR1.
    */
   class AnyPlatformAPI_API SceneEnvironment
   {
      DECLARE_APIOBJECT(SceneEnvironment)
   public:
        /**
        * Get Top Color of the Background
        * @return Color
        */
      ColorValue GetTopColor () const;
        /**
        * Set Top Color of the Background
        * @param clr the color
        * @return void
        */
      void SetTopColor (const ColorValue& clr) ;
        /**
        * Get Middle Color of the Background
        * @return Color
        */
      ColorValue GetMiddleColor () const;
        /**
        * Set Middle Color of the Background
        * @param clr the color
        * @return void
        */
      void SetMiddleColor (const ColorValue& clr) ;
        /**
        * Get Bottom Color of the Background
        * @return Color
        */
      ColorValue GetBottomColor () const;
        /**
        * Set Bottom Color of the Background
        * @param clr the color
        * @return void
        */
      void SetBottomColor (const ColorValue& clr) ;
        /**
        * Set highlight color.
        * @param clr the color
        */
      void SetHighlightColor (const ColorValue& clr) ;
        /**
        * Get highlight color.
        * @return the color
        */
      ColorValue GetHighlightColor () const;
        /**
        * Set selection color.
        * @param clr the color
        */
      void SetSelectedColor (const ColorValue& clr) ;
        /**
        * Get selection color.
        * @return the color
        */
      ColorValue GetSelectedColor () const;
   };//SceneEnvironment;
}}//API

#endif //_APISceneEnvironment_H_