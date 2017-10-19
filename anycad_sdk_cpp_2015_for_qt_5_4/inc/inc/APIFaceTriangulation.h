//Public API. Powered by AnyCAD.

#ifndef _APIFaceTriangulation_H_
#define _APIFaceTriangulation_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class TopoShape;
   /**
    * @ingroup Geometry
    * @author AnyCAD
    * @brief
    *  Triangulate face to mesh. -since R2014UR1.
    */
   class AnyPlatformAPI_API FaceTriangulation
   {
      DECLARE_APIOBJECT(FaceTriangulation)
   public:
        /**
        * Get tolerance.
        * @return the 2D point data.
        */
      Real GetTolerance () const;
        /**
        * Set tolerance.
        * @param tol the tolerance, should >0.
        */
      void SetTolerance (Real tol) ;
        /**
        * Perform the triangulation.
        * @param face the face.
        * @return true if done.
        */
      bool Perform (const TopoShape& face) ;
        /**
        * Get the Vertex data
        * @return the 3D points data.
        */
      FloatList GetVertexBuffer () const;
        /**
        * Get the index data. One face has 3 index.
        * @return the index buffer.
        */
      UIntList GetIndexBuffer () const;
        /**
        * Get the normal data.
        * @return the 3D normal data.
        */
      FloatList GetNormalBuffer () const;
        /**
        * Get the UV coord data.
        * @return the 2D point data.
        */
      FloatList GetTexCoordBuffer () const;
   };//FaceTriangulation;
}}//API

#endif //_APIFaceTriangulation_H_