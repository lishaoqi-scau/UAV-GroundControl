//Public API. Powered by AnyCAD.

#ifndef _APIBrepTools_H_
#define _APIBrepTools_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Matrix4;
   class TopoShape;
   class Vector3;
   class Coordinate3;
   class TopoShapeGroup;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  TopoShape construction tools, such as 2d/3d primitive, boolean, features and so on.
    */
   class AnyPlatformAPI_API BrepTools
   {
      DECLARE_APIOBJECT(BrepTools)
   public:
        /**
        * Read TopoShape from file
        * @param strFile the full file path
        * @return the TopoShape object created
        */
      TopoShape LoadFile (const String& strFile) ;
        /**
        * Save TopoShapeGroup as file
        * @param shapeGroup the shapes to save
        * @param strFileName the full file path
        * @return true if save successfully.
        */
      bool SaveFile (const TopoShapeGroup& shapeGroup, const String& strFileName) ;
        /**
        * Read TopoShape from buffer
        * @param buffer the buffer.
        * @return the TopoShape. Null if failed.
        */
      TopoShape LoadBuffer (const CharBuffer& buffer) ;
        /**
        * Save TopoShape as buffer
        * @param shape the shape to save
        * @return the buffer. Empty if failed.
        */
      CharBuffer SaveBuffer (const TopoShape& shape) ;
        /**
        * Convert TopoShapeGroup as Json
        * @param meshGroup the meshes to save
        * @param precision the precision of mesh
        * @return the json string.
        */
      String ToJson (const TopoShapeGroup& meshGroup, Real precision) ;
        /**
        * Create point
        * @param position The point position.
        * @return the TopoShape object created
        */
      TopoShape MakePoint (const Vector3& position) ;
        /**
        * Create Line
        * @param start The start point
        * @param end The end point
        * @return the TopoShape object created
        */
      TopoShape MakeLine (const Vector3& start, const Vector3& end) ;
        /**
        * Create Circle
        * @param center the center
        * @param radius the radius
        * @param dir the direction
        * @return the TopoShape object created
        */
      TopoShape MakeCircle (const Vector3& center, double radius, const Vector3& dir) ;
        /**
        * Create Ellipse
        * @param center the center
        * @param majorRadius the major radius
        * @param minorRadius the minor radius
        * @param dir the direction
        * @return the TopoShape object created
        */
      TopoShape MakeEllipse (const Vector3& center, double majorRadius, double minorRadius, const Vector3& dir) ;
        /**
        * Create Arc
        * @param start the start point
        * @param end the end point
        * @param center the center
        * @param dir the dir of the circle
        * @return the TopoShape object created
        */
      TopoShape MakeArc (const Vector3& start, const Vector3& end, const Vector3& center, const Vector3& dir) ;
        /**
        * Create Arc
        * @param center the center
        * @param radius the radius.
        * @param startAngle the start angle
        * @param endAngle the end angle
        * @param dir the normal
        * @return the TopoShape object created
        */
      TopoShape MakeArc (const Vector3& center, Real radius, Real startAngle, Real endAngle, const Vector3& dir) ;
        /**
        * Create Arc by three points
        * @param start the start point
        * @param end the end point
        * @param middle the middle point
        * @return the TopoShape object created
        */
      TopoShape MakeArc3Pts (const Vector3& start, const Vector3& end, const Vector3& middle) ;
        /**
        * Create Arc from Ellipse
        * @param center the center
        * @param majorRadius the major radius
        * @param minorRadius the minor radius
        * @param startAngle the start angle
        * @param endAngle the end angle
        * @param dir the normal
        * @return the TopoShape object created
        */
      TopoShape MakeEllipseArc (const Vector3& center, Real majorRadius, Real minorRadius, Real startAngle, Real endAngle, const Vector3& dir) ;
        /**
        * Create Spline
        * @param pts the points list
        * @return the TopoShape object created
        */
      TopoShape MakeSpline (const Vector3List& pts) ;
        /**
        * Create spiral/spring curve.
        * @param radius the radius.
        * @param interval the interval
        * @param count the loop count
        * @param coord the local coordinate.
        * @return the spiral curve.
        */
      TopoShape MakeSpiralCurve (Real radius, Real interval, Real count, const Coordinate3& coord) ;
        /**
        * Create Polyline
        * @param pts the points list
        * @return the TopoShape object created
        */
      TopoShape MakePolyline (const Vector3List& pts) ;
        /**
        * Create Polygon
        * @param pts the points list
        * @return the TopoShape object created
        */
      TopoShape MakePolygon (const Vector3List& pts) ;
        /**
        * Create Polygon with radius
        * @param pts the points list
        * @param radius the round angle radius
        * @return the TopoShape object created
        */
      TopoShape MakePolygon (const Vector3List& pts, Real radius) ;
        /**
        * Create rectangle with radius
        * @param len the length
        * @param width the width
        * @param radius the round angle radius
        * @param coord the local coordinate.
        * @return the TopoShape object created
        */
      TopoShape MakeRectangle (Real len, Real width, Real radius, const Coordinate3& coord) ;
        /**
        * Create mesh shell
        * @param pts the points list
        * @return the TopoShape object created
        */
      TopoShape MakeMeshShell (const Vector3List& pts) ;
        /**
        * Connect several edges/wires to be one wire
        * @param edges can be edges or wires
        * @return the TopoShape object created
        */
      TopoShape MakeWire (const TopoShapeGroup& edges) ;
        /**
        * Connect edge to be wire
        * @param edge the edge
        * @return the wire object created
        */
      TopoShape MakeWire (const TopoShape& edge) ;
        /**
        * Fill the planar and closed wire with face
        * @param wire must be closed and planar
        * @return the face created
        */
      TopoShape MakeFace (const TopoShape& wire) ;
        /**
        * Add hole to the face.
        * @param face the face to add hole.
        * @param hole should be closed wire or edge.
        * @return the new face with hole.
        */
      TopoShape AddHole (const TopoShape& face, const TopoShape& hole) ;
        /**
        * Fill the planar face
        * @param origion center position
        * @param dir the direction
        * @param minU the min value of U
        * @param maxU the max value of U
        * @param minV the min value of V
        * @param maxV the max value of V
        * @return the face created
        */
      TopoShape MakePlaneFace (const Vector3& origion, const Vector3& dir, Real minU, Real maxU, Real minV, Real maxV) ;
        /**
        * Make surface from points (M * N)
        * @param arrPoints the points. the size of points is equal M*N.
        * @param m the row length. M >= 1
        * @param n the column length. N >=1
        * @return the face created
        */
      TopoShape MakeSurfaceFromPoints (const Vector3List& arrPoints, int m, int n) ;
        /**
        * Fill the polygon. May not be planar.
        * @param polygon the vertices of the polygon.
        * @return the face.
        */
      TopoShape FillFace (const Vector3List& polygon) ;
        /**
        * Combine many faces to be shell
        * @param faces the faces that the shell has
        * @return the TopoShape object created
        */
      TopoShape MakeShell (const TopoShapeGroup& faces) ;
        /**
        * Combine many faces and shells to be solid
        * @param faceShells the shells
        * @return the TopoShape object created
        */
      TopoShape MakeSolid (const TopoShapeGroup& faceShells) ;
        /**
        * Combine many TopoShapes
        * @param shapes the shapes
        * @return the TopoShape object created
        */
      TopoShape MakeCompound (const TopoShapeGroup& shapes) ;
        /**
        * Create Sphere
        * @param center the center
        * @param radius > 0
        * @return the TopoShape object created
        */
      TopoShape MakeSphere (const Vector3& center, double radius) ;
        /**
        * Create Box
        * @param start the start point
        * @param dir the direction
        * @param size > 0
        * @return the TopoShape object created
        */
      TopoShape MakeBox (const Vector3& start, const Vector3& dir, const Vector3& size) ;
        /**
        * Create Box
        * @param start the start point
        * @param end the end point
        * @param width > 0
        * @param height > 0
        * @return the TopoShape object created
        */
      TopoShape MakeBox (const Vector3& start, const Vector3& end, double width, double height) ;
        /**
        * Create Cylinder Solid
        * @param center the center
        * @param dir the direction
        * @param radius > 0
        * @param height > 0
        * @param degree [0~360]
        * @return the TopoShape object created
        */
      TopoShape MakeCylinder (const Vector3& center, const Vector3& dir, double radius, double height, double degree) ;
        /**
        * Create Cone
        * @param center the center
        * @param dir the direction
        * @param radius > 0
        * @param height > 0
        * @param radiusTop >=0
        * @param degree [0~360]
        * @return the TopoShape object created
        */
      TopoShape MakeCone (const Vector3& center, const Vector3& dir, double radius, double height, double radiusTop, double degree) ;
        /**
        * Create Tube
        * @param center the center
        * @param dir the direction
        * @param radius the inner radius. (> 0)
        * @param thickness the thickness. (>0)
        * @param len the length.(> 0)
        * @return the TopoShape object created
        */
      TopoShape MakeTube (const Vector3& center, const Vector3& dir, double radius, double thickness, double len) ;
        /**
        * Make half face: an infinite solid, limited by a surface.
        * @param face Face or Shell
        * @param refPoint specifies the side of the surface where the matter of the half-space is located.
        * @return the half space object
        */
      TopoShape MakeHalfSpace (const TopoShape& face, const Vector3& refPoint) ;
        /**
        * Fuse two TopoShapes (A+B)
        * @param pShapeA A
        * @param pShapeB B
        * @return the TopoShape object created
        */
      TopoShape BooleanAdd (const TopoShape& pShapeA, const TopoShape& pShapeB) ;
        /**
        * Cut A from B (A-B)
        * @param pShapeA A
        * @param pShapeB B
        * @return the TopoShape object created
        */
      TopoShape BooleanCut (const TopoShape& pShapeA, const TopoShape& pShapeB) ;
        /**
        * Get the common part of two TopoShapes
        * @param pShapeA A
        * @param pShapeB B
        * @return the TopoShape object created
        */
      TopoShape BooleanCommon (const TopoShape& pShapeA, const TopoShape& pShapeB) ;
        /**
        * Get the common part of two TopoShapes
        * @param pShape the shape to be slitted
        * @param splitter the splitter tool
        * @return the TopoShape object created
        */
      TopoShape MakeSplit (const TopoShape& pShape, const TopoShape& splitter) ;
        /**
        * Get the common part of two TopoShapes
        * @param pShape the shape to be slitted
        * @param splitters the splitter tool group
        * @return the TopoShape object created
        */
      TopoShape MakeSplit (const TopoShape& pShape, const TopoShapeGroup& splitters) ;
        /**
        * Get the section edges of the body and the plane
        * @param pBody the body
        * @param pos the position of the plane
        * @param dir the direction of the plane
        * @return the edges compound
        */
      TopoShape BodySection (const TopoShape& pBody, const Vector3& pos, const Vector3& dir) ;
        /**
        * Get the section edge of two surfaces
        * @param pSurfA must be face
        * @param pSurfB must be face
        * @return the TopoShape object created
        */
      TopoShape SurfaceSection (const TopoShape& pSurfA, const TopoShape& pSurfB) ;
        /**
        * Extrude
        * @param pShape can be edge/wire or planar face
        * @param height >0
        * @param dir the direction
        * @return the TopoShape object created
        */
      TopoShape Extrude (const TopoShape& pShape, double height, const Vector3& dir) ;
        /**
        * Extrude a TopoShape with a Axis
        * @param pShape can be edge/wire or planar face
        * @param position the position of the Axis
        * @param dir the direction of the Axis
        * @param degree the revoled angle (0, 360]
        * @return the TopoShape object created
        */
      TopoShape Revol (const TopoShape& pShape, const Vector3& position, const Vector3& dir, double degree) ;
        /**
        * Fillet all edges of the body
        * @param pShape Body
        * @param radius the filleted radius
        * @return the TopoShape object created
        */
      TopoShape Fillet (const TopoShape& pShape, double radius) ;
        /**
        * Fillet the edges of the body
        * @param shape Body
        * @param edgeIdx the index of the edges
        * @param radius the radius of each edge.
        * @return the TopoShape object created
        */
      TopoShape MakeFillet (const TopoShape& shape, const IntList& edgeIdx, const FloatList& radius) ;
        /**
        * Chamfer all edges of the body
        * @param pShape the body
        * @param dis1 >0
        * @param dis2 >0
        * @return the TopoShape object created
        */
      TopoShape Chamfer (const TopoShape& pShape, double dis1, double dis2) ;
        /**
        * Chamfer the edges of the body
        * @param shape the body
        * @param edgeIdx the index of the edges
        * @param dis1 the dis of each edges
        * @param dis2 the dis2 of each edges
        * @return the TopoShape object created
        */
      TopoShape MakeChamfer (const TopoShape& shape, const IntList& edgeIdx, const FloatList& dis1, const FloatList& dis2) ;
        /**
        * Make Loft.
        * @param shapes the edges or wires
        * @param bSolid true to make solid.
        * @return the TopoShape object created
        */
      TopoShape MakeLoft (const TopoShapeGroup& shapes, bool bSolid) ;
        /**
        * Make Loft.
        * @param wire1 the first wires
        * @param wire2 the second wire
        * @param bSolid true to make solid
        * @return the TopoShape object created
        */
      TopoShape MakeLoft (const TopoShape& wire1, const TopoShape& wire2, bool bSolid) ;
        /**
        * Sweep TopoShapes
        * @param section the section profile
        * @param path the sweep path, must be wire
        * @return the ATopoShapePtr object created
        */
      TopoShape Sweep (const TopoShape& section, const TopoShape& path) ;
        /**
        * Make Pipe Mode: TM_Transformed, TM_RightCorner, TM_RoundCorner
        * @param section the section face
        * @param path the sweep path, must be wire
        * @param mode the transition mode
        * @return the ATopoShapePtr object created
        */
      TopoShape MakePipe (const TopoShape& section, const TopoShape& path, int mode) ;
        /**
        * Project Curve on plane -since R2014UR1
        * @param shape should be edge or wire
        * @param planePosition the plane position
        * @param planeDir the direction of the plane
        * @param projDir the direction of projection
        * @return the new TopoShape
        */
      TopoShape ProjectOnPlane (const TopoShape& shape, const Vector3& planePosition, const Vector3& planeDir, const Vector3& projDir) ;
        /**
        * Project Curve on Surface -since R2014UR1
        * @param curve should be edge.
        * @param surface should be face.
        * @return the new curve.
        */
      TopoShape ProjectOnSurface (const TopoShape& curve, const TopoShape& surface) ;
        /**
        * Mirror TopoShape by line
        * @param pShape the input shape
        * @param startPt the start point
        * @param endPt the end point
        * @return the TopoShape object created
        */
      TopoShape MakeMirror (const TopoShape& pShape, const Vector3& startPt, const Vector3& endPt) ;
        /**
        * Move TopoShape
        * @param pShape the shape
        * @param vec the distance
        * @return the TopoShape object created
        */
      TopoShape Translate (const TopoShape& pShape, const Vector3& vec) ;
        /**
        * Scale TopoShape
        * @param pShape the shape
        * @param center the center
        * @param scale >0 the scale size
        * @return the TopoShape object created
        */
      TopoShape Scale (const TopoShape& pShape, const Vector3& center, double scale) ;
        /**
        * Rotate TopoShape
        * @param pShape the shape
        * @param dir the axis to rotate
        * @param degree the degree to rotate
        * @return the TopoShape object created
        */
      TopoShape Rotation (const TopoShape& pShape, const Vector3& dir, double degree) ;
        /**
        * Rotate TopoShape along the axis -since R2014UR1
        * @param pShape the shape
        * @param axisPos the axis position
        * @param axisDir the axis direction
        * @param degree the degree to rotate
        * @return the TopoShape object created
        */
      TopoShape Rotation (const TopoShape& pShape, const Vector3& axisPos, const Vector3& axisDir, double degree) ;
        /**
        * Transform TopoShape
        * @param pShape the shape
        * @param trf the transform
        * @return the TopoShape object created
        */
      TopoShape Transform (const TopoShape& pShape, const Matrix4& trf) ;
        /**
        * Transform TopoShape
        * @param pShape the shape
        * @param coord the local coordinate.
        * @return the TopoShape object created
        */
      TopoShape Transform (const TopoShape& pShape, const Coordinate3& coord) ;
        /**
        * Make road line shape
        * @param start the start point
        * @param end the end point
        * @param width the width
        * @param height the height
        * @param heightMiddle the middle height
        * @param bSolid if make solid.
        * @return the TopoShape object created
        */
      TopoShape MakeRoad (const Vector3& start, const Vector3& end, double width, double height, double heightMiddle, bool bSolid) ;
        /**
        * Create disk
        * @param radius the radius
        * @param height the height
        * @param position the location.
        * @return the disk.
        */
      TopoShape MakeDish (Real radius, Real height, const Vector3& position) ;
   };//BrepTools;
}}//API

#endif //_APIBrepTools_H_