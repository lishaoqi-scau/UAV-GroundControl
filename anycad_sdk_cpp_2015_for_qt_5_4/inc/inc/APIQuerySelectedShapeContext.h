//Public API. Powered by AnyCAD.

#ifndef _APIQuerySelectedShapeContext_H_
#define _APIQuerySelectedShapeContext_H_

#include "core/APIObjectDef.h"

#include "inc/APIQuerySelectedEntityContext.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   class Ray;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The context to query the selected shape.
    */
   class AnyPlatformAPI_API QuerySelectedShapeContext
      : public QuerySelectedEntityContext
   {
      DECLARE_APISUPER(QuerySelectedShapeContext, QuerySelectedEntityContext)
   public:
        /**
        * Get the selected master TopoShape
        * @return the TopoShape
        */
      TopoShape GetGeometry () const;
        /**
        * Get the selected sub TopoShape
        * @return the TopoShape
        */
      TopoShape GetSubGeometry () const;
        /**
        * If has geometry selected.
        * @return true if has.
        */
      bool HasPointOnGeometry () const;
        /**
        * Compute the intersect point.
        * @param ray the intersection ray.
        * @return the nearest point.
        */
      Vector3 GetIntersectPoint (const Ray& ray) const;
   };//QuerySelectedShapeContext;
}}//API

#endif //_APIQuerySelectedShapeContext_H_