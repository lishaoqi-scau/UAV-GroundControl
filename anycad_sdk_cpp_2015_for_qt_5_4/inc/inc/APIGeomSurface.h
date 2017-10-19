//Public API. Powered by AnyCAD.

#ifndef _APIGeomSurface_H_
#define _APIGeomSurface_H_

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
    *  BSpline surface tool that can be used to construct BSpline and get BSpline information.
    */
   class AnyPlatformAPI_API GeomSurface
      : public GeomBase
   {
      DECLARE_APISUPER(GeomSurface, GeomBase)
   public:
        /**
        * Test if valid.
        */
      virtual bool IsValidGeomey () const;
        /**
        * Use TopoShape to initialize the geometry, must be surface.
        * @param topoShape the TopoShape
        * @return true if ok.
        */
      virtual bool Initialize (const TopoShape& topoShape) ;
        /**
        * Get the surface type. enum EnumSurfaceType:
        * @return the point.
        */
      int GetType () const;
        /**
        * tolerance.
        */
      Real Tolerance () const;
        /**
        * The first u parameter.
        */
      Real FirstUParameter () const;
        /**
        * The last u parameter.
        */
      Real LastUParameter () const;
        /**
        * The first v parameter.
        */
      Real FirstVParameter () const;
        /**
        * The last v parameter.
        */
      Real LastVParameter () const;
        /**
        * Continuity. enum: C0 = 0, G1, C1, G2, C2, C3, CN
        */
      int UContinuity () const;
        /**
        * Continuity. enum: C0 = 0, G1, C1, G2, C2, C3, CN
        */
      int VContinuity () const;
        /**
        * Is Closed.
        */
      bool IsUClosed () const;
        /**
        * Is Closed.
        */
      bool IsVClosed () const;
        /**
        * Is Periodic.
        */
      bool IsUPeriodic () const;
        /**
        * Is Periodic.
        */
      bool IsVPeriodic () const;
        /**
        * The period.
        */
      Real UPeriod () const;
        /**
        * The period.
        */
      Real VPeriod () const;
        /**
        * Computes the point of parameter U and V on the surface.
        * @param u the parameter u
        * @param v the parameter v
        * @return the point.
        */
      Vector3 Value (Real u, Real v) const;
        /**
        * Computes the normal of parameter U and V on the surface.
        * @param u the parameter u
        * @param v the parameter v
        * @return the normal.
        */
      Vector3 GetNormal (Real u, Real v) const;
        /**
        * Computes the point of parameter U on the surface.
        * @param u the parameter
        * @param v the parameter v
        * @return the point.
        */
      Vector3 D0 (Real u, Real v) const;
        /**
        * Computes the point and derivative of parameter U on the surface.
        * @param u the parameter
        * @param v the parameter v
        * @return the point and D1U, D1V. Empty if not C1
        */
      Vector3List D1 (Real u, Real v) const;
        /**
        * Computes the point and derivative of parameter U on the surface.
        * @param u the parameter
        * @param v the parameter v
        * @return the point, the D1U, D1V, D2U, D2V, D2UV. Empty if not C2.
        */
      Vector3List D2 (Real u, Real v) const;
        /**
        * Computes the point and derivative of parameter U on the surface.
        * @param u the parameter
        * @param v the parameter v
        * @return the point, the D1U, D1V, D2U, D2V, D2UV, D3U, D3V, D3UUV, D3UVV. Empty if not C3.
        */
      Vector3List D3 (Real u, Real v) const;
        /**
        * The returned vector gives the value of the derivative for the order of derivation N.
        * @param u the parameter
        * @param v the parameter v
        * @param nu the order of derivation
        * @param nv the order of derivation
        * @return the vector. Return zero if not CN or N < 1.
        */
      Vector3 DN (Real u, Real v, int nu, int nv) const;
   };//GeomSurface;
}}//API

#endif //_APIGeomSurface_H_