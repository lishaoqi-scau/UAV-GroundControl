//Public API. Powered by AnyCAD.

#ifndef _APIFontEdgeDecomposer_H_
#define _APIFontEdgeDecomposer_H_

#include "core/APIObjectDef.h"

#include "inc/APIFontLoopDecomposer.h"

namespace AnyCAD{ namespace API
{
   class EntitySceneNode;
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font outline decomposer.
    */
   class AnyPlatformAPI_API FontEdgeDecomposer
      : public FontLoopDecomposer
   {
      DECLARE_APISUPER(FontEdgeDecomposer, FontLoopDecomposer)
   public:
        /**
        * Build as Edge Node.
        * @return the EntitySceneNode
        */
      EntitySceneNode BuildEdgeNode () const;
   };//FontEdgeDecomposer;
}}//API

#endif //_APIFontEdgeDecomposer_H_