//Public API. Powered by AnyCAD.

#ifndef _APIRenderableGeometry_H_
#define _APIRenderableGeometry_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderableEntity.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Camera;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Geometry Node.
    */
   class AnyPlatformAPI_API RenderableGeometry
      : public RenderableEntity
   {
      DECLARE_APISUPER(RenderableGeometry, RenderableEntity)
   public:
        /**
        * Set Geometry.
        * @param topoShape the TopoShape to set
        * @return void
        */
      void SetGeometry (const TopoShape& topoShape) ;
        /**
        * Get Geometry.
        * @return the TopoShape
        */
      TopoShape GetGeometry () const;
        /**
        * Get LOD factor.
        * @return the factor.
        */
      Real GetLodFactor () const;
        /**
        * Set LOD factor.
        * @param val the factor. Should >= 0.01
        */
      void SetLodFactor (Real val) ;
        /**
        * Get the Entity Type Face, Edge, Vertex, Text
        * @return EnumRenderFlags
        */
      virtual int GetEntityType () const;
   };//RenderableGeometry;
}}//API

#endif //_APIRenderableGeometry_H_