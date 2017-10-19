//Public API. Powered by AnyCAD.

#ifndef _APICameraOperator_H_
#define _APICameraOperator_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class AABox;
   class Viewport;
   class Camera;
   class Vector3;
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The camera operator.
    */
   class AnyPlatformAPI_API CameraOperator
   {
      DECLARE_APIOBJECT(CameraOperator)
   public:
        /**
        * Along Z-Axis, View center as the rotate center
        * @param cx the x offset.
        * @param cy the y offset.
        */
      void Rotation (int cx, int cy) ;
        /**
        * Along Z-Axis.
        * @param cx the x offset.
        * @param cy the y offset.
        * @param pivot the center
        */
      void Rotation (int cx, int cy, const Vector3& pivot) ;
        /**
        * Move the camera.
        * @param cx the x offset.
        * @param cy the y offset.
        */
      void Pan (int cx, int cy) ;
        /**
        * Zoom the view.
        * @param delta the offset.
        */
      void Zoom (int delta) ;
        /**
        * Zoom under the mouse position.
        * @param delta the offset.
        * @param mousePos the mouse position.
        */
      void Zoom (int delta, const Vector2& mousePos) ;
        /**
        * Zoom the view to fit the bbox.
        * @param bbox the bounding box.
        * @param scale the scale to adjust the fit. (0, 100]
        */
      void FitAll (const AABox& bbox, Real scale) ;
        /**
        * Zoom the view to fit the rectangle.
        * @param startPt the start position.
        * @param endPt the end position.
        */
      void FitRectangle (const Vector2& startPt, const Vector2& endPt) ;
   };//CameraOperator;
}}//API

#endif //_APICameraOperator_H_