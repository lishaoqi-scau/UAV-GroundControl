//Public API. Powered by AnyCAD.

#ifndef _APIEventListener_H_
#define _APIEventListener_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class DocumentChangeArgs;
   class Vector3;
   /**
    * @ingroup Common
    * @author AnyCAD
    * @brief
    *  Receive event from AnyCAD internal.
    */
   class AnyPlatformAPI_API EventListener
   {
      DECLARE_APIOBJECT(EventListener)
   public:
        /**
        * Document modified Event
        * @param args the arguments.
        */
      virtual void OnDocumentModified (const DocumentChangeArgs& args) ;
        /**
        * Select Element Event
        * @param elemIds the element ids
        */
      virtual void OnSelectElement (const ElementIdSet& elemIds) ;
        /**
        * Debugging message
        * @param msg the message
        */
      virtual void OnDebugWarning (const String& msg) ;
        /**
        * Call open file dialog to get the fileName.
        * @param caption the Title
        * @param filter the file filters
        * @return file path name
        */
      virtual String OnGetOpenFileName (const String& caption, const String& filter) ;
        /**
        * Call save file dialog to get the fileName.
        * @param caption the Title
        * @param defaultName the flleName
        * @param filter the file filters
        * @return file path name
        */
      virtual String OnGetSaveFileName (const String& caption, const String& defaultName, const String& filter) ;
        /**
        * Trace the state of the editor
        * @param commandId the id.
        * @param status 1: Enter editor. 2: Exist editor
        */
      virtual void OnTraceEditor (const String& commandId, int status) ;
        /**
        * Notify to change the cursor.
        * @param commandId the id.
        * @param cursorHint which cursor to use.
        */
      virtual void OnChangeCursor (const String& commandId, const String& cursorHint) ;
        /**
        * Notify the mouse position changed.
        * @param worldPos the position in the world space.
        */
      virtual void OnMousePositionChanged (const Vector3& worldPos) ;
        /**
        * Execute the event loop
        * @param loopId the loop id.
        * @return the exit code.
        */
      virtual int OnExecuteEventLoop (long loopId) ;
        /**
        * Exit the event loop.
        * @param loopId the loop id.
        * @param code the exit code.
        */
      virtual void OnExitLoopEvent (long loopId, int code) ;
   };//EventListener;
}}//API

#endif //_APIEventListener_H_