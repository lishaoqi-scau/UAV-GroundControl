//Public API. Powered by AnyCAD.

#ifndef _APIPointCloudNode_H_
#define _APIPointCloudNode_H_

#include "core/APIObjectDef.h"

#include "inc/APICustomizedSceneNode.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Text Node -since R2014UR1.
    */
   class AnyPlatformAPI_API PointCloudNode
      : public CustomizedSceneNode
   {
      DECLARE_APISUPER(PointCloudNode, CustomizedSceneNode)
   public:
        /**
        * Set Points. Each point has x,y,z.
        * @param buffer the points buffer.
        */
      void SetPoints (const FloatList& buffer) ;
        /**
        * Set color (r[0,1],g[0,1],b[0,1]) for each point.
        * @param buffer the points buffer.
        */
      void SetColors (const FloatList& buffer) ;
        /**
        * Compute bbox if you don't have the information.
        */
      void ComputeBBox () ;
   };//PointCloudNode;
}}//API

#endif //_APIPointCloudNode_H_