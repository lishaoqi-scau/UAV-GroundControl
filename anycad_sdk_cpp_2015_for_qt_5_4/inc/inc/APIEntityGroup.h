//Public API. Powered by AnyCAD.

#ifndef _APIEntityGroup_H_
#define _APIEntityGroup_H_

#include "core/APIObjectDef.h"

#include "inc/APIObject.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class Entity;
   class AABox;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  The entity groups.
    */
   class AnyPlatformAPI_API EntityGroup
      : public Object
   {
      DECLARE_APISUPER(EntityGroup, Object)
   public:
        /**
        * Add TopoShape to Group
        * @param pTopoShape the TopoShape
        * @return the index of the TopoShape
        */
      int AddTopoShape (const TopoShape& pTopoShape) ;
        /**
        * Get the TopoShape by index
        * @param idx the index of the TopoShape
        * @return the TopoShape. Return null if it doesn't exist.
        */
      TopoShape GetTopoShape (int idx) const;
        /**
        * Get the Entity by index
        * @param idx the index of the Entity
        * @return the Entity. Return null if it doesn't exist.
        */
      Entity GetEntity (int idx) const;
        /**
        * Set the Material for Entity
        * @param idx the index of the Entity
        * @param materialId the material id of the material
        * @return false if failed.
        */
      bool SetMaterial (int idx, const String& materialId) ;
        /**
        * Get the number of the TopoShape/Entity
        * @return the number of the TopoShape/Entity
        */
      int Size () const;
        /**
        * Clear the EntityGroup
        */
      void Clear () ;
        /**
        * Compute the bounding box
        * @return the bounding box
        */
      AABox ComputeBBox () const;
   };//EntityGroup;
}}//API

#endif //_APIEntityGroup_H_