//Public API. Powered by AnyCAD.

#ifndef _APIPrimitive2dTools_H_
#define _APIPrimitive2dTools_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Vector2;
   class TopoShapeGroup;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Create 2d geometry on XOY plane, such as line, polyline, circle, arc, BSpline.
    */
   class AnyPlatformAPI_API Primitive2dTools
   {
      DECLARE_APIOBJECT(Primitive2dTools)
   public:
        /**
        * Make 2d line
        * @param startPt the start position
        * @param endPt the end position.
        * @return the line shape.
        */
      TopoShape MakeLine (const Vector2& startPt, const Vector2& endPt) ;
        /**
        * Make 2d polyline.
        * @param points the point list.
        * @return the shape.
        */
      TopoShape MakePolyline (const Vector2List& points) ;
        /**
        * Make 2d polygon.
        * @param points the points.
        * @return the shape.
        */
      TopoShape MakePolygon (const Vector2List& points) ;
        /**
        * Make 2d spline.
        * @param points the point list.
        * @return the shape.
        */
      TopoShape MakeSpline (const Vector2List& points) ;
        /**
        * Make 2d circle.
        * @param centerPt the center point.
        * @param radius the radius of the circle.
        * @return the shape.
        */
      TopoShape MakeCircle (const Vector2& centerPt, Real radius) ;
        /**
        * Make 2d circle arc.
        * @param centerPt the center point.
        * @param radius the radius of the circle.
        * @param startPt the start position.
        * @param endPt the end position.
        * @return the shape.
        */
      TopoShape MakeArc (const Vector2& centerPt, Real radius, const Vector2& startPt, const Vector2& endPt) ;
        /**
        * Make 2d circle arc.
        * @param centerPt the center point.
        * @param radius the radius of the circle.
        * @param startAngle the start angle.
        * @param endAngle the end angle.
        * @return the shape.
        */
      TopoShape MakeArc (const Vector2& centerPt, Real radius, Real startAngle, Real endAngle) ;
        /**
        * Make 2d ellipse arc.
        * @param centerPt the center point.
        * @param majorPt the major position.
        * @param ratio the ratio of major radius and minor radius.
        * @param startAngle the start angle.
        * @param endAngle the end angle.
        * @return the shape.
        */
      TopoShape MakeEllipseArc (const Vector2& centerPt, const Vector2& majorPt, Real ratio, Real startAngle, Real endAngle) ;
        /**
        * Make 2d ellipse arc.
        * @param centerPt the center point.
        * @param majorR the major radius.
        * @param minorR the minor radius.
        * @param startAngle the start angle.
        * @param endAngle the end angle.
        * @return the shape.
        */
      TopoShape MakeEllipseArc (const Vector2& centerPt, Real majorR, Real minorR, Real startAngle, Real endAngle) ;
        /**
        * Convert 2d curve to 2d BSpline.
        * @param curve the 2d curve.
        * @return the shape.
        */
      TopoShape ToBSplineCurve (const TopoShape& curve) ;
        /**
        * Convert multi 2d curve to 2d BSpline.
        * @param curves the 2d curve list.
        * @return the shape.
        */
      TopoShape ToBSplineCurve (const TopoShapeGroup& curves) ;
   };//Primitive2dTools;
}}//API

#endif //_APIPrimitive2dTools_H_