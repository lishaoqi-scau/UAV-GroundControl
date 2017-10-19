//Public API. Powered by AnyCAD.

#ifndef _APIView3d_H_
#define _APIView3d_H_

#include "core/APIObjectDef.h"

#include "inc/APIView.h"

namespace AnyCAD{ namespace API
{
   class RenderWindow;
   class Vector2;
   class Vector3;
   class Renderer;
   class SceneManager;
   class ContextMenu;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  Present the 3d view, which can be attached to HWND and Qt Widget.
    */
   class AnyPlatformAPI_API View3d
      : public View
   {
      DECLARE_APISUPER(View3d, View)
   public:
        /**
        * Get Render View
        * @return Renderer
        */
      Renderer GetRenderer () const;
        /**
        * Get Scene Manager
        * @return SceneManager
        */
      SceneManager GetSceneManager () const;
        /**
        * Set the standard camera
        * @param viewType by EnumStandardView
        */
      void SetStandardView (int viewType) ;
        /**
        * Show all the objects in the view
        */
      void FitAll () ;
        /**
        * Show or hide the coordinate axis
        * @param bShow if to show the axis
        */
      void ShowCoordinateAxis (bool bShow) ;
        /**
        * Connect to handle the document events.
        * @param bConnect true to handle the events
        */
      void ConnectDocumentEvents (bool bConnect) ;
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
        * Show Context Menu
        * @param menuContext the context
        */
      virtual bool OnContextMenu (const ContextMenu& menuContext) ;
        /**
        * Button down message
        * @param nTimerId the timer id
        */
      virtual int OnTimer (int nTimerId) ;
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
   };//View3d;
}}//API

#endif //_APIView3d_H_