//Public API. Powered by AnyCAD.

#ifndef _APIFontGeometryDecomposer_H_
#define _APIFontGeometryDecomposer_H_

#include "core/APIObjectDef.h"

#include "inc/APIFontLoopDecomposer.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   class TopoShape;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font geometry decomposer.
    */
   class AnyPlatformAPI_API FontGeometryDecomposer
      : public FontLoopDecomposer
   {
      DECLARE_APISUPER(FontGeometryDecomposer, FontLoopDecomposer)
   public:
        /**
        * Build as Face
        * @return the face shape
        */
      TopoShape BuildFaces () ;
        /**
        * Build as Solid
        * @param thinckness the thickness of the body.
        * @return the Solid
        */
      TopoShape BuildSolids (Real thinckness) ;
   };//FontGeometryDecomposer;
}}//API

#endif //_APIFontGeometryDecomposer_H_