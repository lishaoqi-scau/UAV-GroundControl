//Public API. Powered by AnyCAD.

#ifndef _APIMatrixBuilder_H_
#define _APIMatrixBuilder_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Coordinate3;
   class Matrix4;
   class Vector3;
   /**
    * @ingroup Common
    * @author AnyCAD
    * @brief
    *  Build matrix -Since R2014UR1.
    */
   class AnyPlatformAPI_API MatrixBuilder
   {
      DECLARE_APIOBJECT(MatrixBuilder)
   public:
        /**
        * Construct translate/move matrix.
        * @return the Matrix4
        */
      Matrix4 MakeTranslate (Real tx, Real ty, Real tz) ;
        /**
        * Construct translate/move matrix.
        * @return the Matrix4
        */
      Matrix4 MakeTranslate (const Vector3& offset) ;
        /**
        * Construct scale matrix.
        * @return the Matrix4
        */
      Matrix4 MakeScale (Real tx, Real ty, Real tz) ;
        /**
        * Construct scale matrix.
        * @return the Matrix4
        */
      Matrix4 MakeScale (const Vector3& offset) ;
        /**
        * Construct rotation matrix.
        * @return the Matrix4
        */
      Matrix4 MakeRotation (Real angle, const Vector3& axis) ;
        /**
        * Construct rotation matrix.
        * @param fromDir the start direction.
        * @param toDir the end direction.
        * @return the Matrix4
        */
      Matrix4 RotationTo (const Vector3& fromDir, const Vector3& toDir) ;
        /**
        * Multiply two matrix.
        * @return the Matrix4
        */
      Matrix4 Multiply (const Matrix4& left, const Matrix4& right) ;
        /**
        * Get world matrix from local coordinate.
        * @param coord the local coordinate.
        * @return the Matrix4
        */
      Matrix4 ToWorldMatrix (const Coordinate3& coord) ;
   };//MatrixBuilder;
}}//API

#endif //_APIMatrixBuilder_H_