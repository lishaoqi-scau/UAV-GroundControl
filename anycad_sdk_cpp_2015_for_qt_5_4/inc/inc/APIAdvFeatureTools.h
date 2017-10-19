//Public API. Powered by AnyCAD.

#ifndef _APIAdvFeatureTools_H_
#define _APIAdvFeatureTools_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Advanced feature tools.
    */
   class AnyPlatformAPI_API AdvFeatureTools
   {
      DECLARE_APIOBJECT(AdvFeatureTools)
   public:
        /**
        * Add material on a solid by extruding a profile along the normal to its plane..
        * @param initShape you want to add material on. It must be a solid or a compound made of a single solid.
        * @param profile It must be a closed edge or wire and it must be planar.
        * @param height of extrusion. It is calculated from the base profile along the normal to its plane.
        * @param angle in degrees.
        * @return the common shape.
        */
      TopoShape ExtrudedBoss (const TopoShape& initShape, const TopoShape& profile, Real height, Real angle) ;
        /**
        * Remove material on a solid by extruding a profile along the normal to its plane..
        * @param initShape you want to add material on. It must be a solid or a compound made of a single solid.
        * @param profile It must be a closed edge or wire and it must be planar.
        * @param height of extrusion. It is calculated from the base profile along the normal to its plane.
        * @param angle in degrees.
        * @return the common shape.
        */
      TopoShape ExtrudedCut (const TopoShape& initShape, const TopoShape& profile, Real height, Real angle) ;
        /**
        * Create a T-Shape based on pipes
        * @param r1 - the internal radius of main pipe
        * @param w1 - the thickness of main pipe
        * @param l1 - the half-length of main pipe
        * @param r2 - the internal radius of incident pipe
        * @param w2 - the thickness of incident pipe
        * @param l2 - the half-length of main pipe
        * @return the resulting shape.
        */
      TopoShape MakePipeTShape (Real r1, Real w1, Real l1, Real r2, Real w2, Real l2) ;
        /**
        * Make the profile sweeping along the path with "S" evolution.
        * @param profile the section
        * @param path the sweeping path.
        * @param evolutionS the "S" parameters. the size should be 4 or 6.
        * @param bSolid true to make solid or shell/face.
        * @return the shape.
        */
      TopoShape MakeSweep (const TopoShape& profile, const TopoShape& path, const FloatList& evolutionS, bool bSolid) ;
        /**
        * Make the profile sweeping along the path with the evolution controlled by spline.
        * @param profile the section
        * @param path the sweeping path.
        * @param evolutionSpline the evolution spline, should be 2d BSpline.
        * @param bSolid true to make solid or shell/face.
        * @return the shape.
        */
      TopoShape MakeSweep (const TopoShape& profile, const TopoShape& path, const TopoShape& evolutionSpline, bool bSolid) ;
        /**
        * Make evolved shape.
        * @param profile the section
        * @param path the path.
        * @param joinType 0:Arc, 1:Tangent 2:Intersection.
        * @param bSolid true to make solid or shell/face.
        * @return the shape.
        */
      TopoShape MakeEvolved (const TopoShape& profile, const TopoShape& path, int joinType, bool bSolid) ;
   };//AdvFeatureTools;
}}//API

#endif //_APIAdvFeatureTools_H_