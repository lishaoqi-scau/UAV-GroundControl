//Public API. Powered by AnyCAD.

#ifndef _APIIntersectionLineSurface_H_
#define _APIIntersectionLineSurface_H_

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
    *  Intersection testing for line and surface.
    */
   class AnyPlatformAPI_API IntersectionLineSurface
   {
      DECLARE_APIOBJECT(IntersectionLineSurface)
   public:
        /**
        * Initialize the algorithm with surface
        * @param surface must be face
        */
      void SetSurface (const TopoShape& surface) ;
        /**
        * Intersection test by ray
        * @param ray the ray.
        * @return true if intersected.
        */
      bool Perform (const Ray& ray) ;
        /**
        * Intersection test by curve
        * @param curve the curve.
        * @param startParam the start parameter which can be -INF
        * @param endParam the end parameter which can be +INF
        * @return true if intersected.
        */
      bool Perform (const TopoShape& curve, Real startParam, Real endParam) ;
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
        * Get u parameter by index
        * @param idx the index. start from 1.
        * @return the u.
        */
      Real GetParameterU (int idx) const;
        /**
        * Get v parameter by index
        * @param idx the index. start from 1.
        * @return the v.
        */
      Real GetParameterV (int idx) const;
        /**
        * The parameter for the line
        * @param idx the index. start from 1.
        * @return the parameter on line.
        */
      Real GetParameterW (int idx) const;
        /**
        * The nearest intersection point.
        * @return the point.
        */
      Vector3 GetNearestPoint () const;
   };//IntersectionLineSurface;
}}//API

#endif //_APIIntersectionLineSurface_H_