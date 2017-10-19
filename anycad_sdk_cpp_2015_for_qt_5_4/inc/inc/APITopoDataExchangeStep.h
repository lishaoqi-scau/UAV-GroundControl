//Public API. Powered by AnyCAD.

#ifndef _APITopoDataExchangeStep_H_
#define _APITopoDataExchangeStep_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class TopoShapeGroup;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  STEP file writer and reader.
    */
   class AnyPlatformAPI_API TopoDataExchangeStep
   {
      DECLARE_APIOBJECT(TopoDataExchangeStep)
   public:
        /**
        * Write to STEP file
        * @param pShapes the TopoShape.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShapeGroup& pShapes, const String& szFileName) ;
        /**
        * Write to STEP file
        * @param pShape the TopoShape.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShape& pShape, const String& szFileName) ;
        /**
        * Read from STEP file
        * @param szFileName the file name.
        * @return pShapes the TopoShape.
        */
      TopoShape Read (const String& szFileName) ;
   };//TopoDataExchangeStep;
}}//API

#endif //_APITopoDataExchangeStep_H_