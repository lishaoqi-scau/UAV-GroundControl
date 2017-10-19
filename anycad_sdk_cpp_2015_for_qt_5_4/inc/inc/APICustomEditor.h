//Public API. Powered by AnyCAD.

#ifndef _APICustomEditor_H_
#define _APICustomEditor_H_

#include "core/APIObjectDef.h"

#include "inc/APIEditor.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   class SceneNode;
   class Vector2;
   class Document;
   class Renderer;
   class InputEvent;
   class View3d;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  The user defined editor.
    */
   class AnyPlatformAPI_API CustomEditor
      : public Editor
   {
      DECLARE_APISUPER(CustomEditor, Editor)
   public:
        /**
        * Get the Renderer
        * @return the Renderer
        */
      Renderer GetRenderer () ;
        /**
        * Get the Document
        * @return the Document
        */
      Document GetDocument () ;
        /**
        * Mouse Button down event.
        * @param evt the mouse/key event.
        */
      virtual void OnButtonDownEvent (const InputEvent& evt) ;
        /**
        * Mouse Button up event.
        * @param evt the mouse/key event.
        */
      virtual void OnButtonUpEvent (const InputEvent& evt) ;
        /**
        * Mouse move event.
        * @param evt the mouse/key event.
        */
      virtual void OnMouseMoveEvent (const InputEvent& evt) ;
        /**
        * Begin to run the editor.
        */
      virtual void OnStartEvent () ;
        /**
        * Before to exit the editor.
        */
      virtual void OnExitEvent () ;
        /**
        * Exit the editor.
        * @param exitCode the exiting code.
        */
      void Exit (int exitCode) ;
        /**
        * Convert screen point to 3d point.
        * @param screenPt the screen point.
        * @return the 3d point.
        */
      Vector3 ToWorldPoint (const Vector2& screenPt) ;
        /**
        * Show the node temporarily. The node will be removed after exiting the editor.
        * @param node the temporary node.
        */
      void ShowTempNode (const SceneNode& node) ;
        /**
        * Remove the temporary node by id.
        * @param id the id of the temporary node.
        */
      void RemoveTempNode (int id) ;
        /**
        * Remove all the temporary nodes.
        */
      void RemoveAllTempNodes () ;
        /**
        * Notify to change the mouse position.
        * @param pos the world position.
        */
      void NotifyMousePosition (const Vector3& pos) ;
   };//CustomEditor;
}}//API

#endif //_APICustomEditor_H_