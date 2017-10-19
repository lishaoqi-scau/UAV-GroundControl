//Public API. Powered by AnyCAD.

#ifndef _APIEntitySceneNode_H_
#define _APIEntitySceneNode_H_

#include "core/APIObjectDef.h"

#include "inc/APISceneNode.h"

namespace AnyCAD{ namespace API
{
   class RenderableEntity;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Entity Scene Node.
    */
   class AnyPlatformAPI_API EntitySceneNode
      : public SceneNode
   {
      DECLARE_APISUPER(EntitySceneNode, SceneNode)
   public:
        /**
        * Set the render able Entity
        * @param pEntity the entity to display
        * @return void
        */
      void SetEntity (const RenderableEntity& pEntity) ;
        /**
        * Get the Entity
        * @return the entity
        */
      RenderableEntity GetEntity () const;
   };//EntitySceneNode;
}}//API

#endif //_APIEntitySceneNode_H_