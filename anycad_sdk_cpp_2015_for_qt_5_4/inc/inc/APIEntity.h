//Public API. Powered by AnyCAD.

#ifndef _APIEntity_H_
#define _APIEntity_H_

#include "core/APIObjectDef.h"

#include "inc/APIObject.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class AABox;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Hold the TopoShape and it's rendering style.
    */
   class AnyPlatformAPI_API Entity
      : public Object
   {
      DECLARE_APISUPER(Entity, Object)
   public:
        /**
        * Set TopoShape to the Entity
        * @param pTopoShape the TopoShape
        */
      void SetTopoShape (const TopoShape& pTopoShape) ;
        /**
        * Get TopoShape
        * @return the TopoShape
        */
      TopoShape GetTopoShape () const;
        /**
        * Set the Material Id
        * @param materialId the material Id
        */
      void SetMaterialId (const String& materialId) ;
        /**
        * Get the Material Id
        * @return the material Id
        */
      String GetMaterialId () const;
        /**
        * Get the Bounding box
        * @return the Bounding box
        */
      AABox GetBBox () const;
   };//Entity;
}}//API

#endif //_APIEntity_H_