//Public API. Powered by AnyCAD.

#ifndef _APISceneManager_H_
#define _APISceneManager_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class SceneNode;
   class SceneNodeIterator;
   class AABox;
   class QuerySelectionContext;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  Manage the scene nodes.
    */
   class AnyPlatformAPI_API SceneManager
   {
      DECLARE_APIOBJECT(SceneManager)
   public:
        /**
        * Get the global bounding box
        * @return the BBox
        */
      AABox GetBBox () const;
        /**
        * Compute the global bounding box
        * @return void
        */
      void ComputeBBox () ;
        /**
        * Iterate the scene node in the scene.
        * @return the SceneNodeIterator
        */
      SceneNodeIterator NewSceneNodeIterator () const;
        /**
        * Add Node
        * @param pNode the node to be showed in 3d world
        * @return void
        */
      void AddNode (const SceneNode& pNode) ;
        /**
        * Add Node 2d
        * @param pNode the node to be showed in 2d world
        * @return void
        */
      void AddNode2d (const SceneNode& pNode) ;
        /**
        * Clear Nodes
        * @return void
        */
      void ClearNodes () ;
        /**
        * Clear Nodes in 2d world.
        * @return void
        */
      void ClearNodes2d () ;
        /**
        * Remove Node
        * @param pNode to removed from 3d world.
        * @return void
        */
      void RemoveNode (const SceneNode& pNode) ;
        /**
        * Remove Node 2d
        * @param pNode to removed from 2d world.
        * @return void
        */
      void RemoveNode2d (const SceneNode& pNode) ;
        /**
        * Find Node
        * @param nId the node id.
        * @return SceneNode
        */
      SceneNode FindNode (const ElementId& nId) const;
        /**
        * Find Node 2d
        * @param nId the node id.
        * @return SceneNode
        */
      SceneNode FindNode2d (const ElementId& nId) const;
        /**
        * Select Node
        * @param pNode selected the node
        * @return void
        */
      void SelectNode (const SceneNode& pNode) ;
        /**
        * Select the node by id
        * @param id the id.
        */
      void SelectNodeById (const ElementId& id) ;
        /**
        * Select the child node by id chain.
        * @param idChain the id chain from root to leaf node.
        */
      void SelectChildNodeById (const IntList& idChain) ;
        /**
        * Get the Selected Node
        * @return ASceneNodePtr
        */
      SceneNode GetSelectedNode () const;
        /**
        * Query the selection set.
        * @param context the query selection context.
        */
      void QuerySelection (const QuerySelectionContext& context) const;
        /**
        * Query the highlight selection set.
        * @param context the query selection context.
        */
      void QueryHighlight (const QuerySelectionContext& context) const;
   };//SceneManager;
}}//API

#endif //_APISceneManager_H_