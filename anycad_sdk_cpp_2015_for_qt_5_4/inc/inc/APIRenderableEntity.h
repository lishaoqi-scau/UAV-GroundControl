//Public API. Powered by AnyCAD.

#ifndef _APIRenderableEntity_H_
#define _APIRenderableEntity_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class AABox;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The entity which can be rendered.
    */
   class AnyPlatformAPI_API RenderableEntity
   {
      DECLARE_APIOBJECT(RenderableEntity)
   public:
        /**
        * Set id
        * @param id the tag can used as check condition
        */
      void SetId (int id) ;
        /**
        * Get the id
        * @return the id.
        */
      int GetId () const;
        /**
        * Get the Bounding Box
        * @return the bounding box
        */
      AABox GetBBox () const;
        /**
        * Get the Entity Type Face, Edge, Vertex, Text
        * @return EnumRenderFlags
        */
      virtual int GetEntityType () const;
   };//RenderableEntity;
}}//API

#endif //_APIRenderableEntity_H_