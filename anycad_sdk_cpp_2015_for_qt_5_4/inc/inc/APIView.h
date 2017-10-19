//Public API. Powered by AnyCAD.

#ifndef _APIView_H_
#define _APIView_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Editor;
   class Document;
   class InputEvent;
   class ContextMenu;
   class Command;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  Present the view.
    */
   class AnyPlatformAPI_API View
   {
      DECLARE_APIOBJECT(View)
   public:
        /**
        * Set the document
        * @param pDoc the document
        */
      void SetDocument (const Document& pDoc) ;
        /**
        * Get the document
        * @return the document
        */
      Document GetDocument () const;
        /**
        * Set the view id.
        * @param viewId the view id.
        */
      void SetViewId (const ElementId& viewId) ;
        /**
        * Get the view id.
        * @return the view id.
        */
      ElementId GetViewId () const;
        /**
        * Execute the command
        * @param commandName the command identifier
        * @param parameters the parameters.
        * @return true if succeed.
        */
      bool ExecuteCommand (const String& commandName, const String& parameters) ;
        /**
        * Load the place editor to place the instance of the TypeElement  the TypeElement id.  the create method.
        */
      void LoadPlaceEditor (const ElementId& typeId, const String& createMethod) ;
        /**
        * Create the editor by id The editor should be activated using ActiveEditor method.
        * @param commandId the editor id
        * @return the Editor
        */
      Editor CreateEditor (const String& commandId) ;
        /**
        * Active the editor
        * @param pEditor the Editor
        */
      void ActiveEditor (const Editor& pEditor) ;
        /**
        * Set the default editor id.
        * @param commandId the editor id.
        */
      void SetDefaultEditorId (const String& commandId) ;
        /**
        * Get the default editor id.
        * @return the editor id.
        */
      String GetDefaultEditorId () const;
        /**
        * Destroy the view
        */
      virtual void Destroy () ;
        /**
        * Change the size of the view
        * @param nWidth the width
        * @param nHeight the height
        */
      virtual void OnSize (int nWidth, int nHeight) ;
        /**
        * Draw the view
        */
      virtual void Redraw () ;
        /**
        * Request to draw the view
        */
      virtual void RequestDraw (int nRedrawHint) ;
        /**
        * Reload the visible elements from document.
        */
      virtual void ReloadDocument () ;
        /**
        * Button down message
        * @param evt the input data
        */
      virtual int OnLButtonDown (const InputEvent& evt) ;
        /**
        * Button up message
        * @param evt the input data
        */
      virtual int OnLButtonUp (const InputEvent& evt) ;
        /**
        * Mouse move message
        * @param evt the input data
        */
      virtual int OnMouseMove (const InputEvent& evt) ;
        /**
        * Button down message
        * @param evt the input data
        */
      virtual int OnRButtonDown (const InputEvent& evt) ;
        /**
        * Button up message
        * @param evt the input data
        */
      virtual int OnRButtonUp (const InputEvent& evt) ;
        /**
        * Button down message
        * @param evt the input data
        */
      virtual int OnMButtonDown (const InputEvent& evt) ;
        /**
        * Button up message
        * @param evt the input data
        */
      virtual int OnMButtonUp (const InputEvent& evt) ;
        /**
        * Middle Button scroll message
        * @param evt the input data
        */
      virtual int OnMouseWheel (const InputEvent& evt) ;
        /**
        * key message
        * @param evt the input data
        */
      virtual int OnKeyDown (const InputEvent& evt) ;
        /**
        * key message
        * @param evt the input data
        */
      virtual int OnChar (const InputEvent& evt) ;
        /**
        * key message
        * @param evt the input data
        */
      virtual int OnKeyUp (const InputEvent& evt) ;
        /**
        * Button down message
        * @param nTimerId the timer id
        */
      virtual int OnTimer (int nTimerId) ;
        /**
        * Show Context Menu
        * @param menuContext the context
        */
      virtual bool OnContextMenu (const ContextMenu& menuContext) ;
   };//View;
}}//API

#endif //_APIView_H_