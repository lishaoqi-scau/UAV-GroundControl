//Public API. Powered by AnyCAD.

#ifndef _APICamera_H_
#define _APICamera_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Matrix4;
   class Vector3;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Camera.
    */
   class AnyPlatformAPI_API Camera
   {
      DECLARE_APIOBJECT(Camera)
   public:
        /**
        * Set the view matrix
        * @param eyePos the camera position
        * @param targetPos the target (center) position
        * @param up the up direction
        * @return void
        */
      void LookAt (const Vector3& eyePos, const Vector3& targetPos, const Vector3& up) ;
        /**
        * Get view matrix
        * @return the matrix.
        */
      Matrix4 ViewMatrix () const;
        /**
        * Get Position
        * @return the position.
        */
      Vector3 Position () const;
        /**
        * Get Direction
        * @return the direction.
        */
      Vector3 Direction () const;
        /**
        * Get Up
        * @return the up.
        */
      Vector3 Up () const;
        /**
        * Get right
        * @return the right.
        */
      Vector3 Right () const;
        /**
        * Get target position
        * @return the target.
        */
      Vector3 Target () const;
   };//Camera;
}}//API

#endif //_APICamera_H_