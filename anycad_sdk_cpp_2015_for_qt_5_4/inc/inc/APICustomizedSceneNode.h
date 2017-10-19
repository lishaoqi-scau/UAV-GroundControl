//Public API. Powered by AnyCAD.

#ifndef _APICustomizedSceneNode_H_
#define _APICustomizedSceneNode_H_

#include "core/APIObjectDef.h"

#include "inc/APISceneNode.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Customized SceneNode.
    */
   class AnyPlatformAPI_API CustomizedSceneNode
      : public SceneNode
   {
      DECLARE_APISUPER(CustomizedSceneNode, SceneNode)
   public:
   };//CustomizedSceneNode;
}}//API

#endif //_APICustomizedSceneNode_H_