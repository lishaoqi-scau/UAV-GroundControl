//Public API. Powered by AnyCAD.

#ifndef _APIPickHelper_H_
#define _APIPickHelper_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class SceneNode;
   class Vector2;
   class Vector3;
   class Renderer;
   class TopoShape;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The pick helper class.
    */
   class AnyPlatformAPI_API PickHelper
   {
      DECLARE_APIOBJECT(PickHelper)
   public:
        /**
        * Initialize the pick helper.
        * @param renderer the target renderer
        */
      void Initialize (const Renderer& renderer) ;
        /**
        * Perform the picking.
        * @param cx the x of screen.
        * @param cy the y of screen.
        * @return true if selecting something.
        */
      bool Pick (int cx, int cy) ;
        /**
        * Perform the picking.
        * @param mousePosition the mouse position on screen.
        * @return true if selecting something.
        */
      bool Pick (const Vector2& mousePosition) ;
        /**
        * Get the selected node.
        * @return the SceneNode.
        */
      SceneNode GetSceneNode () const;
        /**
        * Get the selected geometry.
        * @return the TopoShape.
        */
      TopoShape GetGeometry () const;
        /**
        * Get the point position of the selected shape..
        * @return the position.
        */
      Vector3 GetPointOnShape () const;
   };//PickHelper;
}}//API

#endif //_APIPickHelper_H_