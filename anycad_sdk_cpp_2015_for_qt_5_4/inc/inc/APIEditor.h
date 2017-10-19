//Public API. Powered by AnyCAD.

#ifndef _APIEditor_H_
#define _APIEditor_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class ParameterValueSet;
   class InputEvent;
   class Document;
   class ContextMenu;
   class View;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  The base eidtor class.
    */
   class AnyPlatformAPI_API Editor
   {
      DECLARE_APIOBJECT(Editor)
   public:
        /**
        * Get the editor id.
        * @param id the string id.
        */
      void SetId (const String& id) ;
        /**
        * Get the editor id
        * @return the id.
        */
      String GetId () const;
        /**
        * Get the ParameterValueSet
        * @return the ParameterValueSet
        */
      ParameterValueSet GetParameterSet () ;
        /**
        * Parse the parameters from string.
        * @param str the parameters string.
        * @return true if ok.
        */
      virtual bool ParseParameters (const String& str) ;
   };//Editor;
}}//API

#endif //_APIEditor_H_