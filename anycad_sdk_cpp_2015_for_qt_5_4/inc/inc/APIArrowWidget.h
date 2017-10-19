//Public API. Powered by AnyCAD.

#ifndef _APIArrowWidget_H_
#define _APIArrowWidget_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The arrow widget.
    */
   class AnyPlatformAPI_API ArrowWidget
      : public GroupSceneNode
   {
      DECLARE_APISUPER(ArrowWidget, GroupSceneNode)
   public:
        /**
        * Get the direction.
        * @return dir the arrow direction.
        */
      Vector3 GetDirection () const;
        /**
        * Set the direction.
        * @param dir the arrow direction.
        */
      void SetDirection (const Vector3& dir) ;
        /**
        * Get the Position.
        * @return the position.
        */
      Vector3 GetPosition () const;
        /**
        * Set the Position.
        * @param pos the arrow position.
        */
      void SetPosition (const Vector3& pos) ;
        /**
        * Set the location and direction.
        * @param pos the position.
        * @param rotate the rotation by Euler Angles XYZ.
        */
      void SetTransform (const Vector3& pos, const Vector3& rotate) ;
   };//ArrowWidget;
}}//API

#endif //_APIArrowWidget_H_