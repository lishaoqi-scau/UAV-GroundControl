//Public API. Powered by AnyCAD.

#ifndef _APIGeomBase_H_
#define _APIGeomBase_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  geometry base class.
    */
   class AnyPlatformAPI_API GeomBase
   {
      DECLARE_APIOBJECT(GeomBase)
   public:
        /**
        * Test if valid.
        */
      virtual bool IsValidGeomey () const;
        /**
        * Use TopoShape to initialize the geometry.
        * @param topoShape the TopoShape
        * @return true if ok.
        */
      virtual bool Initialize (const TopoShape& topoShape) ;
   };//GeomBase;
}}//API

#endif //_APIGeomBase_H_