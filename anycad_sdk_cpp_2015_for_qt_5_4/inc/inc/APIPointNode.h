//Public API. Powered by AnyCAD.

#ifndef _APIPointNode_H_
#define _APIPointNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Point Node, which can be used to display point. -since R2015.
    */
   class AnyPlatformAPI_API PointNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(PointNode, GroupSceneNode)
   public:
        /**
        * Set point value.
        * @param pt the point value.
        */
      void SetPoint (const Vector3& pt) ;
        /**
        * Get the value.
        * @return the point value.
        */
      Vector3 GetPoint () const;
        /**
        * Set if to show the value text.
        * @param bShow if true the text is visible.
        */
      void SetShowText (bool bShow) ;
   };//PointNode;
}}//API

#endif //_APIPointNode_H_