//Public API. Powered by AnyCAD.

#ifndef _APITextNode_H_
#define _APITextNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIEntitySceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Text Node -since R2014UR1.
    */
   class AnyPlatformAPI_API TextNode
      : public EntitySceneNode
   {
      DECLARE_APISUPER(TextNode, EntitySceneNode)
   public:
        /**
        * Set Text.
        * @param text the text string
        */
      void SetText (const String& text) ;
        /**
        * Get Text.
        * @return the text
        */
      String GetText () const;
        /**
        * Set Position.
        * @param pos the text position
        */
      void SetPosition (const Vector3& pos) ;
        /**
        * Get Position.
        * @return the position
        */
      Vector3 GetPosition () const;
        /**
        * Set Text Color.
        * @param clr the text color
        */
      void SetTextColor (const ColorValue& clr) ;
        /**
        * Get the text color.
        * @return the color
        */
      ColorValue GetTextColor () const;
   };//TextNode;
}}//API

#endif //_APITextNode_H_