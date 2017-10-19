//Public API. Powered by AnyCAD.

#ifndef _APIQueryMultiShapeContext_H_
#define _APIQueryMultiShapeContext_H_

#include "core/APIObjectDef.h"

#include "inc/APIQuerySelectionContext.h"

namespace AnyCAD{ namespace API
{
   class QuerySelectedShapeContext;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The context to query the multi selected shape.
    */
   class AnyPlatformAPI_API QueryMultiShapeContext
      : public QuerySelectionContext
   {
      DECLARE_APISUPER(QueryMultiShapeContext, QuerySelectionContext)
   public:
        /**
        * Get the selected count.
        * @return the count.
        */
      int GetCount () const;
        /**
        * Get the sub context by index.
        * @param idx the index [0,
        * @return the QuerySelectedShapeContext
        */
      QuerySelectedShapeContext GetSubContext (int idx) const;
   };//QueryMultiShapeContext;
}}//API

#endif //_APIQueryMultiShapeContext_H_