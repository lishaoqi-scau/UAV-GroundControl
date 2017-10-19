//Public API. Powered by AnyCAD.

#ifndef _APIQuerySelectedEntityContext_H_
#define _APIQuerySelectedEntityContext_H_

#include "core/APIObjectDef.h"

#include "inc/APIQuerySelectionContext.h"

namespace AnyCAD{ namespace API
{
   class SceneNode;
   class Matrix4;
   class RenderableEntity;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The context to query the selected entity.
    */
   class AnyPlatformAPI_API QuerySelectedEntityContext
      : public QuerySelectionContext
   {
      DECLARE_APISUPER(QuerySelectedEntityContext, QuerySelectionContext)
   public:
        /**
        * Test if is empty
        * @return true if empty.
        */
      bool IsEmpty () const;
        /**
        * Get the root node id
        * @return the Id
        */
      int GetNodeId () const;
        /**
        * Get the id of the sub instance.
        * @return the id
        */
      int GetSubNodeId () const;
        /**
        * Get the sub node.
        * @return the SceneNode
        */
      SceneNode GetSubNode () const;
        /**
        * Get the root node.
        * @return the SceneNode
        */
      SceneNode GetRootNode () const;
        /**
        * Get the entity.
        * @return the RenderableEntity
        */
      RenderableEntity GetEntity () const;
        /**
        * Get the index of the sub entity.
        * @return the index
        */
      int GetSubEntityIndex () const;
        /**
        * Get the Type of the sub entity. Type: Face = 0x0001, Edge = 0x0002, Vertex = 0x0004, Text = 0x0008,
        * @return the type
        */
      int GetSubEntityType () const;
        /**
        * Get the id chain which contains the sub entity.
        * @return the index
        */
      IntList GetIds () const;
        /**
        * Compute the global transform.
        * @return the Matrix4
        */
      Matrix4 ComputeGlobalTransform () const;
   };//QuerySelectedEntityContext;
}}//API

#endif //_APIQuerySelectedEntityContext_H_