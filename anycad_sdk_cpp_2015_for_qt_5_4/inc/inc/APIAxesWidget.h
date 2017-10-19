//Public API. Powered by AnyCAD.

#ifndef _APIAxesWidget_H_
#define _APIAxesWidget_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Coordinate3;
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The axis widget.
    */
   class AnyPlatformAPI_API AxesWidget
      : public GroupSceneNode
   {
      DECLARE_APISUPER(AxesWidget, GroupSceneNode)
   public:
        /**
        * Set the local coordinate
        * @param coord the coordinate
        */
      void SetCoordinate (const Coordinate3& coord) ;
        /**
        * Get the local coordinate.
        * @return the coordinate
        */
      Coordinate3 GetCoordinate () const;
        /**
        * Get the position.
        * @return the position
        */
      Vector3 GetPosition () const;
        /**
        * Show the arrow.
        * @param nType by EnumAxesType.
        * @param bShow true to show.
        */
      void ShowArrow (int nType, bool bShow) ;
        /**
        * Show all the arrow.
        * @param bShow true to show.,
        */
      void ShowArrows (bool bShow) ;
        /**
        * Set the text of the arrow.
        * @param nType by EnumAxesType.
        * @param text the text string.
        */
      void SetArrowText (int nType, const String& text) ;
        /**
        * Set to left hand coordinate system.
        */
      void EnableLeftHandCS () ;
   };//AxesWidget;
}}//API

#endif //_APIAxesWidget_H_