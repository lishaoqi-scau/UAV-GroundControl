//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeReaderManager_H_
#define _APITopoShapeReaderManager_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShapeReader;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  The TopoShape Reader. -since R2014UR1.
    */
   class AnyPlatformAPI_API TopoShapeReaderManager
   {
      DECLARE_APIOBJECT(TopoShapeReaderManager)
   public:
        /**
        * Find the shape reader by name.
        * @return the TopoShapeReader.
        */
      TopoShapeReader FindReader (const String& name) const;
   };//TopoShapeReaderManager;
}}//API

#endif //_APITopoShapeReaderManager_H_