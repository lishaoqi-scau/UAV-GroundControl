//Public API. Powered by AnyCAD.

#ifndef _APIGeomCircle_H_
#define _APIGeomCircle_H_

#include "core/APIObjectDef.h"

#include "inc/APIGeomCurve.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Circle tool that can be used to get circle information.
    */
   class AnyPlatformAPI_API GeomCircle
      : public GeomCurve
   {
      DECLARE_APISUPER(GeomCircle, GeomCurve)
   public:
        /**
        * Test if valid.
        */
      virtual bool IsValidGeomey () const;
        /**
        * Get center.
        * @return center.
        */
      Vector3 GetCenter () const;
        /**
        * Get radius.
        * @return radius.
        */
      Real GetRadius () const;
        /**
        * Get direction.
        * @return direction.
        */
      Vector3 GetDirection () const;
   };//GeomCircle;
}}//API

#endif //_APIGeomCircle_H_