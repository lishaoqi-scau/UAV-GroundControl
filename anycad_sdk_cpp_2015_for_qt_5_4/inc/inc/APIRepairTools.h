//Public API. Powered by AnyCAD.

#ifndef _APIRepairTools_H_
#define _APIRepairTools_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class ShapeProcessSettings;
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Repair tool.
    */
   class AnyPlatformAPI_API RepairTools
   {
      DECLARE_APIOBJECT(RepairTools)
   public:
        /**
        * Remove extra edges from shape.
        * @param shape the shape.
        * @return the new shape.
        */
      TopoShape RemoveExtraEdges (const TopoShape& shape) ;
        /**
        * Check if shape is self intersected.
        * @param shape the Shape to check.
        * @param level the level of checking shape on self-interference.
        * @return true if self intersection.
        */
      bool IsSelfIntersection (const TopoShape& shape, int level) ;
        /**
        * Glue faces
        * @param shape the compound shape to be glued.
        * @param tolerance the maximum distance between two faces, which can be considered as coincident
        * @param keepNonSolid allows to throw away non-solids from the result, if false.
        * @return the glued result.
        */
      TopoShape GlueFaces (const TopoShape& shape, Real tolerance, bool keepNonSolid) ;
        /**
        * Glue edges
        * @param shape the compound shape to be glued.
        * @param tolerance the maximum distance between two faces, which can be considered as coincident
        * @param keepNonSolid allows to throw away non-solids from the result, if false.
        * @return the glued result.
        */
      TopoShape GlueEdges (const TopoShape& shape, Real tolerance, bool keepNonSolid) ;
        /**
        * Unites on a given shape all faces sharing the same surface.
        * @param shape a compound or a single solid.
        * @param tolerance the maximum distance between two faces.
        * @return the result.
        */
      TopoShape UnionFaces (const TopoShape& shape, Real tolerance) ;
        /**
        * Removes the vertices from a given wire, provided that the junction of two adjacent edges is C1 continuous (i.e. the edges have equal tangents at the junction).
        * @param wire the wire.
        * @return the new edge.
        */
      TopoShape FuseCollinearEdgesWithinWire (const TopoShape& wire) ;
        /**
        * Removes all shared faces from a compound to obtain one or more bigger solids from a set of smaller solids. Only shared faces will be removed. Coincident but not shared faces will stay as is, use Glue Faces or Partition before Remove Internal Faces if you need to remove them.
        * @param shape the compound or solids
        * @return the new shape.
        */
      TopoShape RemoveInternalFaces (const TopoShape& shape) ;
        /**
        * Sew face or shells
        * @param shape is a list of faces or shells to be sewn
        * @param tolerance the precision
        * @param allowNonManifold is true if allows non-manifold sewing.
        * @return the new shell or face.
        */
      TopoShape Sewing (const TopoShape& shape, Real tolerance, bool allowNonManifold) ;
        /**
        * Removes holes with free boundaries on a selected shell or face
        * @param shape the face to be filled.
        * @param wireIds the ids of the wire. Empty for all.
        * @return the new shape.
        */
      TopoShape SuppressHoles (const TopoShape& shape, const UIntList& wireIds) ;
        /**
        * Removes all internal wires or specified internal wires from user specified shapes.
        * @param shape the shape to move
        * @param wireIds the wire ids.
        * @return the new shape.
        */
      TopoShape SuppressInternalWires (const TopoShape& shape, const UIntList& wireIds) ;
        /**
        * Closes an open contour and modifies the underlying face (if needed) in accordance with user specified mode.
        * @param shape the shape
        * @param wireIds the wire ids
        * @param byCommonVertexOrNewEdge the mode.
        * @return the new shape.
        */
      TopoShape CloseContour (const TopoShape& shape, const UIntList& wireIds, bool byCommonVertexOrNewEdge) ;
        /**
        * Splits an edge in two new edges in accordance with the specified mode (by length or by parameter)
        * @param shape which contains an edge to be divided
        * @param edgeId the ID of the edge to be divided, if it is = -1, then Shape should be an edge itself.
        * @param aValue is a value of parameter on edge or length parameter, depending on IsByParameter.
        * @param isByParameter specifying operation mode.
        * @return the edges.
        */
      TopoShape DivideEdge (const TopoShape& shape, int edgeId, Real aValue, bool isByParameter) ;
        /**
        * Shape Processing is useful not only on invalid shapes, but also on the shapes, that are classified as valid by the Check functionality. Use it, if an operation (for example, Partition) fails.
        * @param shape the shape to process
        * @param settings the options.
        * @return the fixed shape.
        */
      TopoShape ProcessShape (const TopoShape& shape, const ShapeProcessSettings& settings) ;
   };//RepairTools;
}}//API

#endif //_APIRepairTools_H_