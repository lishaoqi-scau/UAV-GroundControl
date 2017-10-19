//Public API. Powered by AnyCAD.

#ifndef _APIRenderResource_H_
#define _APIRenderResource_H_

#include "core/APIObjectDef.h"

#include "inc/APIObject.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The rendering resource.
    */
   class AnyPlatformAPI_API RenderResource
      : public Object
   {
      DECLARE_APISUPER(RenderResource, Object)
   public:
        /**
        * Set name.
        * @param strName the name.
        */
      void SetName (const String& strName) ;
        /**
        * Get name.
        * @return name.
        */
      String GetName () const;
   };//RenderResource;
}}//API

#endif //_APIRenderResource_H_