//Public API. Powered by AnyCAD.

#ifndef _APIMeasureTools_H_
#define _APIMeasureTools_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   class MeasureResult;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Measure tool.
    */
   class AnyPlatformAPI_API MeasureTools
   {
      DECLARE_APIOBJECT(MeasureTools)
   public:
        /**
        * Compute the minimal distance between shape 1 and shape 2.
        * @param shape1 the first shape.
        * @param shape2 the second shape.
        * @return the measure result.
        */
      MeasureResult ComputeMinDistance (const TopoShape& shape1, const TopoShape& shape2) ;
        /**
        * Compute the minimal distance between shape 1 and shape 2 for singular cases.
        * @param shape1 the first shape.
        * @param shape2 the second shape.
        * @return the measure result.
        */
      MeasureResult ComputeMinDistanceSingular (const TopoShape& shape1, const TopoShape& shape2) ;
        /**
        * Find the nearest edge to the point. Return null if more than one edge.
        * @param shape the shape which has edges.
        * @param point the point.
        * @return the edge.
        */
      TopoShape FindEdgeNearPoint (const TopoShape& shape, const Vector3& point) ;
   };//MeasureTools;
}}//API

#endif //_APIMeasureTools_H_