//Public API. Powered by AnyCAD.

#ifndef _APILineNode_H_
#define _APILineNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Line Node, which can be used to display line. -since R2015.
    */
   class AnyPlatformAPI_API LineNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(LineNode, GroupSceneNode)
   public:
        /**
        * Set line points.
        * @param start the start point.
        * @param end the end point.
        */
      void Set (const Vector3& start, const Vector3& end) ;
        /**
        * Set if to show the value text.
        * @param bShow if true the text is visible.
        */
      void SetShowText (bool bShow) ;
        /**
        * Set start point.
        * @param pt the start point.
        */
      void SetStartPt (const Vector3& pt) ;
        /**
        * Get the start point.
        * @return the point.
        */
      Vector3 GetStartPt () const;
        /**
        * Set end point.
        * @param pt the end point.
        */
      void SetEndPt (const Vector3& pt) ;
        /**
        * Get the end point.
        * @return the point.
        */
      Vector3 GetEndPt () const;
   };//LineNode;
}}//API

#endif //_APILineNode_H_