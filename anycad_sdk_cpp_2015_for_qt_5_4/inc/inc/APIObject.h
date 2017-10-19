//Public API. Powered by AnyCAD.

#ifndef _APIObject_H_
#define _APIObject_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Common
    * @author AnyCAD
    * @brief
    *  TODO:
    */
   class AnyPlatformAPI_API Object
   {
      DECLARE_APIOBJECT(Object)
   public:
        /**
        * Get the class id.
        * @return the class id.
        */
      String GetObjectClassId () const;
        /**
        * Get the class id of the parent class.
        * @return the class id.
        */
      StringList ListParentClassIds () const;
   };//Object;
}}//API

#endif //_APIObject_H_