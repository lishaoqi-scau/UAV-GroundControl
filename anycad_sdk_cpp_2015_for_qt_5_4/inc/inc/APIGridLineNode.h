//Public API. Powered by AnyCAD.

#ifndef _APIGridLineNode_H_
#define _APIGridLineNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The grid Line Node, which hold the header. -since R2015UR2.
    */
   class AnyPlatformAPI_API GridLineNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(GridLineNode, GroupSceneNode)
   public:
        /**
        * Set line points.
        * @param start the start point.
        * @param end the end point.
        */
      void SetLine (const Vector3& start, const Vector3& end) ;
        /**
        * Set if to show the value text.
        * @param bShow if true the text is visible.
        */
      void SetShowHead (bool bShow) ;
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
        /**
        * Set the head text
        * @param text the string.
        */
      void SetHeadText (const String& text) ;
        /**
        * Update the grid line.
        */
      void Update () ;
   };//GridLineNode;
}}//API

#endif //_APIGridLineNode_H_