//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeConvert_H_
#define _APITopoShapeConvert_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class RenderableEntity;
   class CoordinateWidget;
   class SceneNode;
   class EntitySceneNode;
   class AxesWidget;
   class AABox;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The TopoShapeConvert.
    */
   class AnyPlatformAPI_API TopoShapeConvert
   {
      DECLARE_APIOBJECT(TopoShapeConvert)
   public:
        /**
        * Convert TopoShape to Entity.
        * @param pTopoShape the TopoShape to convert
        * @param tolerance the tolerance
        * @return RenderableEntity
        */
      RenderableEntity ToEntity (const TopoShape& pTopoShape, Real tolerance) ;
        /**
        * Convert TopoShape to node. Return GroupNode if the topoShape has sub shapes.
        * @param topoShape the TopoShape to convert
        * @param tolerance the tolerance
        * @return SceneNode, may be EntityScenenNode or GroupSceneNode.
        */
      SceneNode ToSceneNode (const TopoShape& topoShape, Real tolerance) ;
        /**
        * Convert TopoShape to node. If the TopoShape is very complex, please use ToScenenNode.
        * @param pTopoShape the TopoShape to convert
        * @param tolerance the tolerance
        * @return EntitySceneNode
        */
      EntitySceneNode ToEntityNode (const TopoShape& pTopoShape, Real tolerance) ;
        /**
        * Extract TopoShape from SceneNode. Return null if sceneNode is not type of EntitySceneNode.
        * @param sceneNode the EntitySceneNode.
        * @return TopoShape.
        */
      TopoShape ToTopoShape (const SceneNode& sceneNode) ;
        /**
        * Convert faces to node.
        * @param pTopoShape the TopoShape to convert
        * @param tolerance the tolerance
        * @return EntitySceneNode
        */
      EntitySceneNode ToFaceNode (const TopoShape& pTopoShape, Real tolerance) ;
        /**
        * Convert edge to node
        * @param pTopoShape the TopoShape to convert
        * @param tolerance the tolerance
        * @return EntitySceneNode
        */
      EntitySceneNode ToEdgeNode (const TopoShape& pTopoShape, Real tolerance) ;
        /**
        * Convert buffer to triangle mesh.
        * @param vb the vertex buffer
        * @param ib the index buffer
        * @param nb the normal buffer
        * @param texcb the UV buffer
        * @param bbox the bounding box.
        * @return the render able entity
        */
      RenderableEntity CreateFaceEntity (const FloatList& vb, const UIntList& ib, const FloatList& nb, const FloatList& texcb, const AABox& bbox) ;
        /**
        * Convert buffer to triangle mesh.
        * @param vb the vertex buffer
        * @param ib the index buffer
        * @param nb the normal buffer
        * @param cb the color buffer
        * @param bbox the bounding box.
        * @return the render able entity
        */
      RenderableEntity CreateColoredFaceEntity (const FloatList& vb, const UIntList& ib, const FloatList& nb, const FloatList& cb, const AABox& bbox) ;
        /**
        * Convert buffer to edge.
        * @param vb the vertex buffer
        * @param bbox the bounding box.
        * @return the render able entity
        */
      RenderableEntity CreateEdgeEntity (const FloatList& vb, const AABox& bbox) ;
        /**
        * Convert points to render able entity.
        * @param buffer the vertex buffer
        * @param pointSize the per point size
        * @return the render able entity
        */
      RenderableEntity CreatePointsCloud (const FloatList& buffer, Real pointSize) ;
        /**
        * Create the coordinate widget.
        * @return the CoordinateWidget
        */
      CoordinateWidget CreateCoordinateWidget () ;
        /**
        * Create the axes widget.
        * @return the AxesWidget
        */
      AxesWidget CreateAxesWidget () ;
   };//TopoShapeConvert;
}}//API

#endif //_APITopoShapeConvert_H_