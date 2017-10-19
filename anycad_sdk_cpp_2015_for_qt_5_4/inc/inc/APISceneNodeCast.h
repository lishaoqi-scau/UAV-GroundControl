//Public API. Powered by AnyCAD.

#ifndef _APISceneNodeCast_H_
#define _APISceneNodeCast_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class PointNode;
   class RenderableEntity;
   class SceneNode;
   class GroupSceneNode;
   class EntitySceneNode;
   class LineNode;
   class RenderableGeometry;
   class RenderableGroupEntity;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  Dynamic cast object.
    */
   class AnyPlatformAPI_API SceneNodeCast
   {
      DECLARE_APIOBJECT(SceneNodeCast)
   public:
        /**
        * Cast SceneNode to GroupSceneNode
        * @param pValue the SceneNode
        * @return the GroupSceneNode
        */
      GroupSceneNode ToGroupSceneNode (const SceneNode& pValue) ;
        /**
        * Cast SceneNode to EntitySceneNode
        * @param pValue the SceneNode
        * @return the EntitySceneNode
        */
      EntitySceneNode ToEntitySceneNode (const SceneNode& pValue) ;
        /**
        * Cast SceneNode to PointNode
        * @param pValue the SceneNode
        * @return the PointNode
        */
      PointNode ToPointNode (const SceneNode& pValue) ;
        /**
        * Cast SceneNode to LineNode
        * @param pValue the SceneNode
        * @return the LineNode
        */
      LineNode ToLineNode (const SceneNode& pValue) ;
        /**
        * Cast RenderableEntity to RenderableGeometry
        * @param pValue the RenderableEntity
        * @return the RenderableGeometry
        */
      RenderableGeometry ToRenderableGeometry (const RenderableEntity& pValue) ;
        /**
        * Cast RenderableEntity to RenderableGroupEntity
        * @param pValue the RenderableEntity
        * @return the RenderableGroupEntity
        */
      RenderableGroupEntity ToRenderableGroupEntity (const RenderableEntity& pValue) ;
   };//SceneNodeCast;
}}//API

#endif //_APISceneNodeCast_H_