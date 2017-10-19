//Public API. Powered by AnyCAD.

#ifndef _APIRenderableGroupEntity_H_
#define _APIRenderableGroupEntity_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderableEntity.h"

namespace AnyCAD{ namespace API
{
   class RenderableEntity;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The render able group entity.
    */
   class AnyPlatformAPI_API RenderableGroupEntity
      : public RenderableEntity
   {
      DECLARE_APISUPER(RenderableGroupEntity, RenderableEntity)
   public:
        /**
        * Add Entity
        * @param pEntity child entity
        * @return void
        */
      void AddEntity (const RenderableEntity& pEntity) ;
        /**
        * Get the entity count.
        * @return entity count
        */
      int GetEntityCount () const;
        /**
        * Clear the group
        * @return void
        */
      void Clear () ;
        /**
        * Get the Entity Type Face, Edge, Vertex, Text
        * @return EnumRenderFlags
        */
      virtual int GetEntityType () const;
   };//RenderableGroupEntity;
}}//API

#endif //_APIRenderableGroupEntity_H_