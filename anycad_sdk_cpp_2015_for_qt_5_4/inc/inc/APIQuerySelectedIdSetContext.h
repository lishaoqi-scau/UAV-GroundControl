//Public API. Powered by AnyCAD.

#ifndef _APIQuerySelectedIdSetContext_H_
#define _APIQuerySelectedIdSetContext_H_

#include "core/APIObjectDef.h"

#include "inc/APIQuerySelectionContext.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The context to query the multi-selected ids.
    */
   class AnyPlatformAPI_API QuerySelectedIdSetContext
      : public QuerySelectionContext
   {
      DECLARE_APISUPER(QuerySelectedIdSetContext, QuerySelectionContext)
   public:
        /**
        * Get the selected ids.
        * @return the ElemetIdSet.
        */
      ElementIdSet GetIds () const;
   };//QuerySelectedIdSetContext;
}}//API

#endif //_APIQuerySelectedIdSetContext_H_