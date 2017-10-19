//Public API. Powered by AnyCAD.

#ifndef _APITopoExplor_H_
#define _APITopoExplor_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Explor the faces.
    */
   class AnyPlatformAPI_API TopoExplor
   {
      DECLARE_APIOBJECT(TopoExplor)
   public:
        /**
        * Explore the solid of the TopoShape
        * @param topoShape the TopoShape
        * @return the compound
        */
      TopoShapeGroup ExplorCompounds (const TopoShape& topoShape) ;
        /**
        * Explore the solid of the TopoShape
        * @param topoShape the TopoShape
        * @return the solids
        */
      TopoShapeGroup ExplorSolids (const TopoShape& topoShape) ;
        /**
        * Explore the shell of the TopoShape
        * @param topoShape the TopoShape
        * @return the shells
        */
      TopoShapeGroup ExplorShells (const TopoShape& topoShape) ;
        /**
        * Explore the faces of the TopoShape
        * @param topoShape the TopoShape
        * @return the faces
        */
      TopoShapeGroup ExplorFaces (const TopoShape& topoShape) ;
        /**
        * Explore the edges of the TopoShape
        * @param topoShape the TopoShape
        * @return the edges
        */
      TopoShapeGroup ExplorEdges (const TopoShape& topoShape) ;
        /**
        * Explore the vertices of the TopoShape
        * @param topoShape the TopoShape
        * @return the vertices
        */
      TopoShapeGroup ExplorVertices (const TopoShape& topoShape) ;
        /**
        * Explore the sub shape of the TopoShape -since R2014UR1
        * @param topoShape the TopoShape
        * @return the sub TopoShape
        */
      TopoShapeGroup ExplorSubShapes (const TopoShape& topoShape) ;
   };//TopoExplor;
}}//API

#endif //_APITopoExplor_H_