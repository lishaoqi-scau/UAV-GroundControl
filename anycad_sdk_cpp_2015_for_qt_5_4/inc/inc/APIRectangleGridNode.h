//Public API. Powered by AnyCAD.

#ifndef _APIRectangleGridNode_H_
#define _APIRectangleGridNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGridNode.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Rectangle Grid Node. -since R2015.
    */
   class AnyPlatformAPI_API RectangleGridNode
      : public GridNode
   {
      DECLARE_APISUPER(RectangleGridNode, GridNode)
   public:
        /**
        * Apply the changes.
        */
      virtual void Update () ;
   };//RectangleGridNode;
}}//API

#endif //_APIRectangleGridNode_H_