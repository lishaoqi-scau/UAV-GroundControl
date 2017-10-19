//Public API. Powered by AnyCAD.

#ifndef _APIMaterial_H_
#define _APIMaterial_H_

#include "core/APIObjectDef.h"

#include "inc/APIRenderResource.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The material.
    */
   class AnyPlatformAPI_API Material
      : public RenderResource
   {
      DECLARE_APISUPER(Material, RenderResource)
   public:
   };//Material;
}}//API

#endif //_APIMaterial_H_