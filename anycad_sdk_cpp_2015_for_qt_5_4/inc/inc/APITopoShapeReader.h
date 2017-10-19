//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeReader_H_
#define _APITopoShapeReader_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShapeReaderContext;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  The TopoShape Reader. -since R2014UR1.
    */
   class AnyPlatformAPI_API TopoShapeReader
   {
      DECLARE_APIOBJECT(TopoShapeReader)
   public:
        /**
        * Get the Name.
        * @return the Name.
        */
      String GetName () const;
        /**
        * Read from file.
        * @param fileName the file name
        * @param context the context to collect TopoShape
        * @return false if failed.
        */
      virtual bool Read (const String& fileName, const TopoShapeReaderContext& context) ;
   };//TopoShapeReader;
}}//API

#endif //_APITopoShapeReader_H_