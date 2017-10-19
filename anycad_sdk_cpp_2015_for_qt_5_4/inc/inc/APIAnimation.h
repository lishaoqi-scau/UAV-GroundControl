//Public API. Powered by AnyCAD.

#ifndef _APIAnimation_H_
#define _APIAnimation_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The animation base class.
    */
   class AnyPlatformAPI_API Animation
   {
      DECLARE_APIOBJECT(Animation)
   public:
        /**
        * Set Name
        * @param name the name
        */
      void SetName (const String& name) ;
        /**
        * Get Name
        * @return the name
        */
      String GetName () const;
   };//Animation;
}}//API

#endif //_APIAnimation_H_