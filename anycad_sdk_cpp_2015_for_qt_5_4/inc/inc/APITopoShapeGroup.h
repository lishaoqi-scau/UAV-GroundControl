//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeGroup_H_
#define _APITopoShapeGroup_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  A group of TopoShape.
    */
   class AnyPlatformAPI_API TopoShapeGroup
   {
      DECLARE_APIOBJECT(TopoShapeGroup)
   public:
        /**
        * Set id.
        * @param id the id.
        */
      void SetId (int id) ;
        /**
        * Get id.
        * @return the id.
        */
      int GetId () const;
        /**
        * Add TopoShape to Group
        * @return the index of the TopoShape
        */
      int Add (const TopoShape& pTopoShape) ;
        /**
        * Get the TopoShape by index
        * @return the TopoShape. Return null if it doesn't exist.
        */
      TopoShape GetTopoShape (int idx) const;
        /**
        * Get the TopoShape by index
        * @return the TopoShape. Return null if it doesn't exist.
        */
      TopoShape GetAt (int idx) const;
        /**
        * Clear the group
        */
      void Clear () ;
        /**
        * Get the number of the TopoShape
        * @return the number of the TopoShape
        */
      int Size () const;
   };//TopoShapeGroup;
}}//API

#endif //_APITopoShapeGroup_H_