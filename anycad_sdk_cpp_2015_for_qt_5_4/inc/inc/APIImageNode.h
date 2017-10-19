//Public API. Powered by AnyCAD.

#ifndef _APIImageNode_H_
#define _APIImageNode_H_

#include "core/APIObjectDef.h"

#include "inc/APICustomizedSceneNode.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Image Node -since R2014UR1.
    */
   class AnyPlatformAPI_API ImageNode
      : public CustomizedSceneNode
   {
      DECLARE_APISUPER(ImageNode, CustomizedSceneNode)
   public:
        /**
        * Set Image file.
        * @param fileName the full path name
        */
      void SetImage (const String& fileName) ;
        /**
        * Get Image file name.
        * @return the file name.
        */
      String GetImage () const;
        /**
        * Set width.
        * @param _Width the width of the image
        */
      void SetWidth (Real _Width) ;
        /**
        * Get the width.
        * @return the width.
        */
      Real GetWidth () const;
        /**
        * Set height.
        * @param _Height the height of the image
        */
      void SetHeight (Real _Height) ;
        /**
        * Get the height.
        * @return the height.
        */
      Real GetHeight () const;
   };//ImageNode;
}}//API

#endif //_APIImageNode_H_