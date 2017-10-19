//Public API. Powered by AnyCAD.

#ifndef _APISceneNode_H_
#define _APISceneNode_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class PointStyle;
   class LineStyle;
   class AABox;
   class Matrix4;
   class FaceStyle;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The scene node.
    */
   class AnyPlatformAPI_API SceneNode
   {
      DECLARE_APIOBJECT(SceneNode)
   public:
        /**
        * Get Id
        * @return int
        */
      int GetId () const;
        /**
        * Set Id
        * @param nId the id.
        * @return void
        */
      void SetId (int nId) ;
        /**
        * Get Name
        * @return the Name
        */
      String GetName () const;
        /**
        * Set Name
        * @param name the name
        * @return void
        */
      void SetName (const String& name) ;
        /**
        * Set Visible
        * @param bVisible visible if true
        * @return void
        */
      void SetVisible (bool bVisible) ;
        /**
        * Is Visible
        * @return bool
        */
      bool IsVisible () const;
        /**
        * Is Pick able
        * @return bool
        */
      bool IsPickable () const;
        /**
        * Set the node pick able.
        * @param enabled true of false
        * @return void
        */
      void SetPickable (bool enabled) ;
        /**
        * Is filterable
        * @return bool
        */
      bool IsFilterable () const;
        /**
        * Set the node filterable.
        * @param enabled true of false
        * @return void
        */
      void SetFilterable (bool enabled) ;
        /**
        * Test if the node size is fixed.
        * @return bool
        */
      bool IsFixedSize () const;
        /**
        * Set the node fixed size. If true, the size of node is fixed when scaling the view.
        * @param enabled true of false
        * @return void
        */
      void SetFixedSize (bool enabled) ;
        /**
        * Set Local BBox
        * @param bbox the bounding box.
        * @return void
        */
      void SetBBox (const AABox& bbox) ;
        /**
        * Get Local BBox
        * @return bbox
        */
      AABox GetBBox () const;
        /**
        * Set Transform
        * @param trf the transform
        */
      void SetTransform (const Matrix4& trf) ;
        /**
        * Get Transform
        * @return Matrix4
        */
      Matrix4 GetTransform () const;
        /**
        * Set Point Style
        * @param pointStyle the point style
        * @return void
        */
      void SetPointStyle (const PointStyle& pointStyle) ;
        /**
        * Get Point Style
        * @return the point style
        */
      PointStyle GetPointStyle () const;
        /**
        * Set Line/Edge Style
        * @param lineStyle the line style
        * @return void
        */
      void SetLineStyle (const LineStyle& lineStyle) ;
        /**
        * Get Line Style
        * @return the line style
        */
      LineStyle GetLineStyle () const;
        /**
        * Set Face Style
        * @param faceStyle the face style
        * @return void
        */
      void SetFaceStyle (const FaceStyle& faceStyle) ;
        /**
        * Get Face Style
        * @return the face style
        */
      FaceStyle GetFaceStyle () const;
   };//SceneNode;
}}//API

#endif //_APISceneNode_H_