//Public API. Powered by AnyCAD.

#ifndef _APIShapeProcessSettings_H_
#define _APIShapeProcessSettings_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  The shape processing settings.
    */
   class AnyPlatformAPI_API ShapeProcessSettings
   {
      DECLARE_APIOBJECT(ShapeProcessSettings)
   public:
        /**
        * Corrects invalid shapes.
        * @param tolerance3d work tolerance for detection of the problems and correction of them.
        * @param maxTolerance maximal possible tolerance of the shape after correction.
        */
      void FixShape (double tolerance3d, double maxTolerance) ;
        /**
        * removes small faces, such as spots and strips.
        * @param tolerance defines minimum possible face size.
        */
      void FixFaceSize (double tolerance) ;
        /**
        * removes edges, which merge with neighbouring edges.
        * @param tolerance defines minimum possible distance between two parallel edges.
        */
      void DropSmallEdges (double tolerance) ;
        /**
        * splits faces based on conical surfaces, surfaces of revolution and cylindrical surfaces in segments using a certain angle.
        * @param angle the central angle of the resulting segments (i.e. we obtain two segments if Angle=180, four if Angle=90, etc).
        * @param maxTolerance maximum possible tolerance among the resulting segments.
        */
      void SplitAngle (double angle, double maxTolerance) ;
        /**
        * splits closed faces in segments. The number of segments depends on the number of splitting points.
        * @param nbSplitPoints the number of splitting points.
        */
      void SplitClosedFaces (int nbSplitPoints) ;
        /**
        * splits shapes to reduce continuities of curves and surfaces. Parametric Continuity : C0, C1, C2, CN Geometric Continuity: G1, G2
        * @param tolerance3d 3D tolerance for correction of geometry.
        * @param surfaceContinuity required continuity for surfaces.
        * @param curveContinuity required continuity for curves.
        */
      void SplitContinuity (double tolerance3d, const String& surfaceContinuity, const String& curveContinuity) ;
        /**
        * converts curves and surfaces to Bsplines and processes them with the following parameters:
        * @param SurfaceMode approximation of surfaces if restriction is necessary.
        * @param Curve3dMode conversion of any 3D curve to BSpline and approximation.
        * @param Curve2dMode conversion of any 2D curve to BSpline and approximation.
        * @param tolerance3d defines the possibility of surfaces and 3D curves approximation with the specified parameters.
        * @param tolerance2d defines the possibility of surfaces and 2D curves approximation with the specified parameters.
        * @param RequiredDegree required degree of the resulting BSplines.
        * @param RequiredNbSegments required maximum number of segments of resultant BSplines.
        * @param Continuity3d continuity of the resulting surfaces and 3D curves.
        * @param Continuity2d continuity of the resulting 2D curves.
        */
      void BsplineRestriction (bool SurfaceMode, bool Curve3dMode, bool Curve2dMode, double tolerance3d, double tolerance2d, bool RequiredDegree, int RequiredNbSegments, const String& Continuity3d, const String& Continuity2d) ;
        /**
        * converts curves and surfaces of any type to Bezier curves and surfaces.
        * @param SurfaceMode if checked in, allows conversion of surfaces.
        * @param Curve3dMode if checked in, allows conversion of 3D curves.
        * @param Curve2dMode if checked in, allows conversion of 2D curves.
        * @param MaxTolerance defines tolerance for detection and correction of problems.
        */
      void ToBezier (bool SurfaceMode, bool Curve3dMode, bool Curve2dMode, double MaxTolerance) ;
        /**
        * fixes edges of 2D and 3D curves not having the same parameter.
        * @param tolerance3d defines tolerance for fixing of edges.
        */
      void SameParameter (double tolerance3d) ;
   };//ShapeProcessSettings;
}}//API

#endif //_APIShapeProcessSettings_H_