//Public API. Powered by AnyCAD.

#ifndef _APIIntersectionLineCurve_H_
#define _APIIntersectionLineCurve_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   class Ray;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Intersection testing for line and curve.
    */
   class AnyPlatformAPI_API IntersectionLineCurve
   {
      DECLARE_APIOBJECT(IntersectionLineCurve)
   public:
        /**
        * Initialize the algorithm with edge
        * @param curve must be edge
        */
      void SetCurve (const TopoShape& curve) ;
        /**
        * Intersection test by ray
        * @param ray the ray.
        * @return true if intersected.
        */
      bool Perform (const Ray& ray) ;
        /**
        * Intersection test by curve
        * @param curve the curve.
        * @return true if intersected.
        */
      bool Perform (const TopoShape& curve) ;
        /**
        * Get the intersection point count
        * @return the count.
        */
      int GetPointCount () const;
        /**
        * Get the point by index
        * @param idx the index. start from 1.
        * @return the Point.
        */
      Vector3 GetPoint (int idx) const;
        /**
        * Get parameter by index
        * @param idx the index. start from 1.
        * @return the parameter.
        */
      Real GetParameter (int idx) const;
        /**
        * Get the square distance by index
        * @param idx the index. start from 1.
        * @return the squre distance.
        */
      Real GetSquareDistance (int idx) const;
        /**
        * The nearest intersection point.
        * @return the point.
        */
      Vector3 GetNearestPoint () const;
   };//IntersectionLineCurve;
}}//API

#endif //_APIIntersectionLineCurve_H_