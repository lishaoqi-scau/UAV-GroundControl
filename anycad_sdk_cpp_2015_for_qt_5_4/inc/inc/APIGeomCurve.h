//Public API. Powered by AnyCAD.

#ifndef _APIGeomCurve_H_
#define _APIGeomCurve_H_

#include "core/APIObjectDef.h"

#include "inc/APIGeomBase.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector3;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  BSpline Curve tool that can be used to construct BSpline and get BSpline information.
    */
   class AnyPlatformAPI_API GeomCurve
      : public GeomBase
   {
      DECLARE_APISUPER(GeomCurve, GeomBase)
   public:
        /**
        * Test if valid.
        */
      virtual bool IsValidGeomey () const;
        /**
        * Use TopoShape to initialize the geometry, must be Edge.
        * @param topoShape the TopoShape
        * @return true if ok.
        */
      virtual bool Initialize (const TopoShape& topoShape) ;
        /**
        * Get the curve type. enum EnumCurveType
        * @return the point.
        */
      int GetType () const;
        /**
        * Is 3D Curve.
        */
      bool Is3DCurve () const;
        /**
        * Is 3D Curve on surface.
        */
      bool IsCurveOnSurface () const;
        /**
        * tolerance.
        */
      Real Tolerance () const;
        /**
        * The first parameter.
        */
      Real FirstParameter () const;
        /**
        * The last parameter.
        */
      Real LastParameter () const;
        /**
        * Continuity. enum: C0 = 0, G1, C1, G2, C2, C3, CN
        */
      int Continuity () const;
        /**
        * Is Closed.
        */
      bool IsClosed () const;
        /**
        * Is Periodic.
        */
      bool IsPeriodic () const;
        /**
        * The period.
        */
      Real Period () const;
        /**
        * Computes the point of parameter U on the curve.
        * @param u the parameter
        * @return the point.
        */
      Vector3 Value (Real u) const;
        /**
        * Computes the point of parameter U on the curve.
        * @param u the parameter
        * @return the point.
        */
      Vector3 D0 (Real u) const;
        /**
        * Computes the point and derivative of parameter U on the curve.
        * @param u the parameter
        * @return the point and the first derivative. Empty if not C1
        */
      Vector3List D1 (Real u) const;
        /**
        * Computes the point and derivative of parameter U on the curve.
        * @param u the parameter
        * @return the point, the first and second derivative. Empty if not C2.
        */
      Vector3List D2 (Real u) const;
        /**
        * Computes the point and derivative of parameter U on the curve.
        * @param u the parameter
        * @return the point, the first, the second and the third derivative. Empty if not C3.
        */
      Vector3List D3 (Real u) const;
        /**
        * The returned vector gives the value of the derivative for the order of derivation N.
        * @param u the parameter
        * @param n the order of derivation
        * @return the vector. Return zero if not CN or N < 1.
        */
      Vector3 DN (Real u, int n) const;
        /**
        * Split the curve to equal parts.
        * @param length the length of each part.
        * @param tolerance the tolerance
        * @return the parameters of each part.
        */
      FloatList SplitByUniformLength (Real length, Real tolerance) const;
        /**
        * Get the start point position.
        * @return the start point.
        */
      Vector3 GetStartPoint () const;
        /**
        * Get the end point position.
        * @return the end point.
        */
      Vector3 GetEndPoint () const;
   };//GeomCurve;
}}//API

#endif //_APIGeomCurve_H_