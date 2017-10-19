//Public API. Powered by AnyCAD.

#ifndef _APILoopsBuilder_H_
#define _APILoopsBuilder_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShapeGroup;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Connect the edges to wires, and sort the closed wires to build faces with holes.
    */
   class AnyPlatformAPI_API LoopsBuilder
   {
      DECLARE_APIOBJECT(LoopsBuilder)
   public:
        /**
        * Initialize the builder.
        * @param edgeList the list of 3d edges.
        * @return false if invalid inputs.
        */
      bool Initialize (const TopoShapeGroup& edgeList) ;
        /**
        * Build faces with holes.
        * @return the face list.
        */
      TopoShapeGroup BuildFacesWithHoles () const;
        /**
        * Build connected wires.
        * @return the wire/edge list.
        */
      TopoShapeGroup BuildWires () const;
   };//LoopsBuilder;
}}//API

#endif //_APILoopsBuilder_H_