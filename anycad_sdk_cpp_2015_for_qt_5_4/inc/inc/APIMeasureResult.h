//Public API. Powered by AnyCAD.

#ifndef _APIMeasureResult_H_
#define _APIMeasureResult_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  The measure operation result.
    */
   class AnyPlatformAPI_API MeasureResult
   {
      DECLARE_APIOBJECT(MeasureResult)
   public:
        /**
        * Test if it's valid. If not, the other data are meaningless.
        * @return if valid
        */
      bool IsDone () const;
        /**
        * Get the distance.
        * @return the distance.
        */
      Real GetDistance () const;
        /**
        * Get the point on the first shape.
        * @return the position.
        */
      Vector3 GetPointOnShape1 () const;
        /**
        * Get the point on the second shape.
        * @return the position.
        */
      Vector3 GetPointOnShape2 () const;
   };//MeasureResult;
}}//API

#endif //_APIMeasureResult_H_