//Public API. Powered by AnyCAD.

#ifndef _APIRenderer_H_
#define _APIRenderer_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class RenderWindow;
   class CameraOperator;
   class SceneNode;
   class Vector2;
   class Vector3;
   class SceneManager;
   class WorkingPlane;
   class SceneEnvironment;
   class AABox;
   class QuerySelectionContext;
   class Ray;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The render viewer, attaching the rendering engine to the display window.
    */
   class AnyPlatformAPI_API Renderer
   {
      DECLARE_APIOBJECT(Renderer)
   public:
        /**
        * Set the view type.
        * @param nType the EnumStandardView.
        */
      void SetViewType (int nType) ;
        /**
        * Get the view type.
        * @return the view type EnumStandardView.
        */
      int GetViewType () const;
        /**
        * Initialize the render view. If sceneManager is NULL, Renderer will create it automatically.
        * @param hWnd the window handle
        * @param width the view width
        * @param height the view height
        * @param sceneManager the shared scene manager.
        * @param bZUp true if z direction is (0,0,1), or it's (0,0,-1)
        * @return false if failed.
        */
      bool Initialize (long hWnd, int width, int height, const SceneManager& sceneManager, bool bZUp) ;
        /**
        * Destroy the render view.
        */
      void Destroy () ;
        /**
        * Redraw the view.
        */
      int Redraw () ;
        /**
        * Request to draw the view.
        * @param nHint default is 1. by EnumRedrawHintType
        */
      void RequestDraw (int nHint) ;
        /**
        * Resize the view.
        * @param x the start position x
        * @param y the start position y
        * @param cx the width of the view
        * @param cy the height of the view
        */
      void Resize (int x, int y, int cx, int cy) ;
        /**
        * Print the scene as PDF.
        * @param fileName the image file name.
        * @return true if ok.
        */
      bool Print (const String& fileName) ;
        /**
        * Get Render Window
        * @return RenderWindow
        */
      RenderWindow GetRenderWindow () const;
        /**
        * Get Scene Manager
        * @return SceneManager
        */
      SceneManager GetSceneManager () const;
        /**
        * Get the camera operator.
        * @return the CameraOperator
        */
      CameraOperator GetCameraOperator () const;
        /**
        * Set SkyBox by Name
        * @param strName the skybox name
        */
      void SetSkyBox (const String& strName) ;
        /**
        * Get current skybox name
        * @return the name of the SkyBox
        */
      String GetSkyBox () const;
        /**
        * Set the standard camera
        * @param viewType by EnumStandardView
        */
      void SetStandardView (int viewType) ;
        /**
        * Set the display mode
        * @param nMode the display mode. by EnumDisplayStyle
        */
      void SetDisplayMode (int nMode) ;
        /**
        * Get the display mode
        * @return the display mode.
        */
      int GetDisplayMode () const;
        /**
        * Show all the objects in the view
        */
      void FitAll () ;
        /**
        * Fit the view with the specified bounding box.
        * @param bbox the bound box to fit.
        */
      void FitBBox (const AABox& bbox) ;
        /**
        * Set the pick mode
        * @param nMode the pick mode. By EnumRenderFlags
        */
      void SetPickMode (int nMode) ;
        /**
        * Get the pick mode
        * @return the pick mode.
        */
      int GetPickMode () const;
        /**
        * Highlight the pre-selected shapes by screen position.
        * @param cx the x position
        * @param cy the y position
        * @return the count.
        */
      int Highlight (int cx, int cy) ;
        /**
        * Highlight the pre-selected shapes within the rectangle by two screen points.
        * @param startPt the start position
        * @param endPt the end position
        * @return the count.
        */
      int Highlight (const Vector2& startPt, const Vector2& endPt) ;
        /**
        * Clear the highlighted nodes.
        */
      void ClearHighlight () ;
        /**
        * Query the highlighted nodes.
        * @param context the query selection context.
        */
      void QueryHighlight (const QuerySelectionContext& context) const;
        /**
        * Select the shapes that are highlighted.
        * @param clearOld if to clear the previous selection.
        * @return the count.
        */
      int Select (bool clearOld) ;
        /**
        * Clear the selected nodes.
        */
      void ClearSelection () ;
        /**
        * Query the selection set.
        * @param context the query selection context.
        */
      void QuerySelection (const QuerySelectionContext& context) const;
        /**
        * Get the snap flags.
        * @return the flags.
        */
      int GetSnapFlags () const;
        /**
        * Set the snap flags.  the flags by EnumSnapFlags.
        */
      void SetSnapFlags (int val) ;
        /**
        * World point to screen point.
        * @param point the world point.
        * @return the screen point.
        */
      Vector2 WorldPoint2ScreenPoint (const Vector3& point) const;
        /**
        * Screen point to world point.
        * @param point the screen point.
        * @return the world point.
        */
      Vector3 ScreenPoint2WorldPoint (const Vector2& point) const;
        /**
        * Screen point to world point.
        * @param mousePos the screen point.
        * @param defaultPt the point if failed to compute the world point.
        * @return the world point.
        */
      Vector3 ProjectOnWorkingPlane (const Vector2& mousePos, const Vector3& defaultPt) const;
        /**
        * Compute the Ray based on the screen coordinate.
        * @param cx the x of screen point.
        * @param cy the y of screen point.
        * @return the Ray.
        */
      Ray ComputeScreenRay (int cx, int cy) const;
        /**
        * Compute the Ray based on the screen coordinate.
        * @param pt the screen point.
        * @return the Ray.
        */
      Ray ComputeScreenRay (const Vector2& pt) const;
        /**
        * Show or hide the working grid
        * @param bShow if to show the grid
        */
      void ShowWorkingGrid (bool bShow) ;
        /**
        * Get the working plane
        * @return the plane.
        */
      WorkingPlane GetWorkingPlane () const;
        /**
        * Get the global environment settings.
        * @return the SceneEnvironment.
        */
      SceneEnvironment GetEnvironment () const;
        /**
        * Set the coordinate node
        * @param node the node. Remove the widget nodes.
        */
      void SetCoordinateWidget (const SceneNode& node) ;
        /**
        * Remove the widget nodes.
        */
      void RemoveWidgetNode (long nId) ;
        /**
        * Add widget node
        * @param node the widget node.
        */
      void AddWidgetNode (const SceneNode& node) ;
   };//Renderer;
}}//API

#endif //_APIRenderer_H_