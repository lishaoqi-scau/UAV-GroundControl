//Public API. Powered by AnyCAD.

#ifndef _APITopoDataExchangeIges_H_
#define _APITopoDataExchangeIges_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class TopoShapeGroup;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  IGES file writer and reader.
    */
   class AnyPlatformAPI_API TopoDataExchangeIges
   {
      DECLARE_APIOBJECT(TopoDataExchangeIges)
   public:
        /**
        * Write to IGES file
        * @param pShapes the TopoShapeGroup.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShapeGroup& pShapes, const String& szFileName) ;
        /**
        * Write to IGES file
        * @param pShape the TopoShape.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShape& pShape, const String& szFileName) ;
        /**
        * Read from IGES file
        * @param szFileName the file name.
        * @return pShapes the TopoShape.
        */
      TopoShape Read (const String& szFileName) ;
   };//TopoDataExchangeIges;
}}//API

#endif //_APITopoDataExchangeIges_H_