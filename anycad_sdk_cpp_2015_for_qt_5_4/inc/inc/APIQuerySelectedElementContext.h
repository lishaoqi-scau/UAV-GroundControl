//Public API. Powered by AnyCAD.

#ifndef _APIQuerySelectedElementContext_H_
#define _APIQuerySelectedElementContext_H_

#include "core/APIObjectDef.h"

#include "inc/APIQuerySelectedShapeContext.h"

namespace AnyCAD{ namespace API
{
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  The context to query the selected element. AnyCAD Suite API.
    */
   class AnyPlatformAPI_API QuerySelectedElementContext
      : public QuerySelectedShapeContext
   {
      DECLARE_APISUPER(QuerySelectedElementContext, QuerySelectedShapeContext)
   public:
        /**
        * Get the root instance element id
        * @return the ElementId
        */
      ElementId GetInstanceId () const;
        /**
        * Get the root type element id
        * @return the ElementId
        */
      ElementId GetTypeId () const;
        /**
        * Get the sub instance element id
        * @return the ElementId
        */
      ElementId GetSubInstanceId () const;
        /**
        * Get the sub type element id
        * @return the ElementId
        */
      ElementId GetSubTypeId () const;
   };//QuerySelectedElementContext;
}}//API

#endif //_APIQuerySelectedElementContext_H_