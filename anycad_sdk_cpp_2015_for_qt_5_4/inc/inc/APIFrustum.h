//Public API. Powered by AnyCAD.

#ifndef _APIFrustum_H_
#define _APIFrustum_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   class AABox;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Frustum.
    */
   class AnyPlatformAPI_API Frustum
   {
      DECLARE_APIOBJECT(Frustum)
   public:
        /**
        * Test if the bbox is visible in the frustum
        * @param bbox the bounding box
        * @return true if visible.
        */
      bool IsVisible (const AABox& bbox) const;
        /**
        * Test if the pt is visible in the frustum
        * @param pt the point.
        * @return true if visible.
        */
      bool IsVisible (const Vector3& pt) const;
   };//Frustum;
}}//API

#endif //_APIFrustum_H_