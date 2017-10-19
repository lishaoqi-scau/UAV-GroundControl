//Public API. Powered by AnyCAD.

#ifndef _APITopoDataExchangeStl_H_
#define _APITopoDataExchangeStl_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class TopoShapeGroup;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  STL file writer and reader. -since R2014UR1.
    */
   class AnyPlatformAPI_API TopoDataExchangeStl
   {
      DECLARE_APIOBJECT(TopoDataExchangeStl)
   public:
        /**
        * Gets the deflection of the meshing algorithm.
        * @return the deflection.
        */
      double GetDeflection () const;
        /**
        * Write Option Sets the deflection of the meshing algorithm. Deflection is used, only if relative mode is false.
        * @param val the deflection.
        */
      void SetDeflection (double val) ;
        /**
        * Gets the coeffiecient.
        * @return the coeffiecient.
        */
      double GetCoefficient () const;
        /**
        * Write Option Sets the coeffiecient for computation of deflection through
        * @param val the coeffiecient.
        */
      void SetCoefficient (double val) ;
        /**
        * Gets the relative mode.
        * @return the mode.
        */
      bool GetRelativeMode () const;
        /**
        * Write Option If the mode returns True (default value), the
        * @param val the mode.
        */
      void SetRelativeMode (bool val) ;
        /**
        * Gets the ASCII mode.
        * @return the mode.
        */
      bool GetASCIIMode () const;
        /**
        * Write Option If the mode returns True (default value) the generated
        * @param val the mode.
        */
      void SetASCIIMode (bool val) ;
        /**
        * Write to file
        * @param pShapes the TopoShapeGroup.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShapeGroup& pShapes, const String& szFileName) ;
        /**
        * Write to STL file
        * @param pShape the TopoShape.
        * @param szFileName the file name.
        * @return true if successes.
        */
      bool Write (const TopoShape& pShape, const String& szFileName) ;
        /**
        * Read from STL file
        * @param szFileName the file name.
        * @return pShapes the TopoShape.
        */
      TopoShape Read (const String& szFileName) ;
   };//TopoDataExchangeStl;
}}//API

#endif //_APITopoDataExchangeStl_H_