//Public API. Powered by AnyCAD.

#ifndef _APITopoShapeReaderContext_H_
#define _APITopoShapeReaderContext_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   class ColorValue;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  The reader context to collect TopoShape. -since R2014UR1.
    */
   class AnyPlatformAPI_API TopoShapeReaderContext
   {
      DECLARE_APIOBJECT(TopoShapeReaderContext)
   public:
        /**
        * Set the surface color.
        * @param clr the color
        */
      virtual void OnSetFaceColor (const ColorValue& clr) ;
        /**
        * Set the edge color.
        * @param clr the color
        */
      virtual void OnSetEdgeColor (const ColorValue& clr) ;
        /**
        * Begin to read group.
        * @param name the group name
        */
      virtual void OnBeginGroup (const String& name) ;
        /**
        * End to read group.
        */
      virtual void OnEndGroup () ;
        /**
        * Begin to read Compound/SolidCompund/Solid/Shell TopoShape.
        * @param shape the TopoShape
        * @return true to explore sub-shapes.
        */
      virtual bool OnBeiginComplexShape (const TopoShape& shape) ;
        /**
        * End reading the complex shape.
        */
      virtual void OnEndComplexShape () ;
        /**
        * Read Face TopoShape.
        * @param shape the TopoShape
        */
      virtual void OnFace (const TopoShape& shape) ;
        /**
        * Read wire TopoShape.
        * @param shape the TopoShape
        */
      virtual void OnWire (const TopoShape& shape) ;
        /**
        * Read edge TopoShape.
        * @param shape the TopoShape
        */
      virtual void OnEdge (const TopoShape& shape) ;
        /**
        * Read point TopoShape.
        * @param shape the TopoShape
        */
      virtual void OnPoint (const TopoShape& shape) ;
   };//TopoShapeReaderContext;
}}//API

#endif //_APITopoShapeReaderContext_H_