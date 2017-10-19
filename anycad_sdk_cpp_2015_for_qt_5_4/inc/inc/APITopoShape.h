//Public API. Powered by AnyCAD.

#ifndef _APITopoShape_H_
#define _APITopoShape_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class AABox;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Topology representation for Geometry objects.
    */
   class AnyPlatformAPI_API TopoShape
   {
      DECLARE_APIOBJECT(TopoShape)
   public:
        /**
        * Get the Shape type
        * @return the TopoShapeShapeType
        */
      int GetShapeType () const;
        /**
        * Get the Bounding box
        * @return the Bounding box
        */
      AABox GetBBox () const;
        /**
        * Get the sub shape
        * @param idx the index
        * @param type : Face(1), Edge(2), Vertex(4)
        * @return the sub TopoShape
        */
      TopoShape GetSubShape (int idx, int type) const;
   };//TopoShape;
}}//API

#endif //_APITopoShape_H_