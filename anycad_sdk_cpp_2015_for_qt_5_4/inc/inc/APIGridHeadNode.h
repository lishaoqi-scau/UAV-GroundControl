//Public API. Powered by AnyCAD.

#ifndef _APIGridHeadNode_H_
#define _APIGridHeadNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The grid line head Node, which can be used to display line. -since R2015UR2.
    */
   class AnyPlatformAPI_API GridHeadNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(GridHeadNode, GroupSceneNode)
   public:
        /**
        * Set the text to show.
        * @param text the text string.
        */
      void SetText (const String& text) ;
        /**
        * Update the grid head.
        */
      void Update () ;
        /**
        * Set radius.
        * @param radius the head radius.
        */
      void SetRadius (Real radius) ;
        /**
        * Get the radius.
        * @return the head radius.
        */
      Real GetRadius () const;
   };//GridHeadNode;
}}//API

#endif //_APIGridHeadNode_H_