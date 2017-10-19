//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeProperty_H_
#define _APITopoShapeProperty_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Get the Geometry property.
    */
   class AnyPlatformAPI_API TopoShapeProperty
   {
      DECLARE_APIOBJECT(TopoShapeProperty)
   public:
        /**
        * Set the TopoShape to compute
        * @param shape the TopoShape
        */
      void SetShape (const TopoShape& shape) ;
        /**
        * Compute the length of all edges.
        * @return the length
        */
      Real EdgeLength () const;
        /**
        * Compute the area of all surfaces.
        * @return the area
        */
      Real SurfaceArea () const;
        /**
        * Compute the volume of all solids.
        * @return the volume.
        */
      Real SolidVolume () const;
        /**
        * Compute center of the mass.
        * @return the center position.
        */
      Vector3 CenterOfMass () const;
   };//TopoShapeProperty;
}}//API

#endif //_APITopoShapeProperty_H_