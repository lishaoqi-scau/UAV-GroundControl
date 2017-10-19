//Public API. Powered by AnyCAD.

#ifndef _APICoordinateWidget_H_
#define _APICoordinateWidget_H_

#include "core/APIObjectDef.h"

#include "inc/APICustomizedSceneNode.h"

namespace AnyCAD{ namespace API
{
   class SceneNode;
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The screen coordinate widget.
    */
   class AnyPlatformAPI_API CoordinateWidget
      : public CustomizedSceneNode
   {
      DECLARE_APISUPER(CoordinateWidget, CustomizedSceneNode)
   public:
        /**
        * Set the node
        * @param node the node.
        */
      void SetNode (const SceneNode& node) ;
        /**
        * Get the size
        * @return size
        */
      Vector2 GetWidgetSize () const;
        /**
        * Set the size
        * @param sz the size
        */
      void SetWidgetSize (const Vector2& sz) ;
        /**
        * Set the position on screen by EnumWidgetPosition
        * @param sceeenPos the position.
        */
      void SetWidgetPosition (int sceeenPos) ;
        /**
        * Get the position on screen.
        * @return screen position.
        */
      int GetWidgetPosition () const;
   };//CoordinateWidget;
}}//API

#endif //_APICoordinateWidget_H_