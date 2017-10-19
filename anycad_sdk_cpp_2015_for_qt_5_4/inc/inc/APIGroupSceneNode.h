//Public API. Powered by AnyCAD.

#ifndef _APIGroupSceneNode_H_
#define _APIGroupSceneNode_H_

#include "core/APIObjectDef.h"

#include "inc/APISceneNode.h"

namespace AnyCAD{ namespace API
{
   class Animator;
   class SceneNode;
   class SceneNodeIterator;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Group Scene Node.
    */
   class AnyPlatformAPI_API GroupSceneNode
      : public SceneNode
   {
      DECLARE_APISUPER(GroupSceneNode, SceneNode)
   public:
        /**
        * Add Child Node
        * @param pNode the node to be added
        * @return void
        */
      void AddNode (const SceneNode& pNode) ;
        /**
        * Remove Node
        * @param nId the node id
        * @return void
        */
      void RemoveNode (int nId) ;
        /**
        * Find Node
        * @param nId the node id
        * @return the node
        */
      SceneNode FindNode (int nId) const;
        /**
        * Iterate the scene node in the group.
        * @return the SceneNodeIterator
        */
      SceneNodeIterator NewSceneNodeIterator () const;
        /**
        * Get Child Count
        * @return int
        */
      int GetCount () const;
        /**
        * Clear Children
        * @return void
        */
      void ClearAll () ;
        /**
        * Set Animator
        * @param pAnimator the animator
        */
      void SetAnimator (const Animator& pAnimator) ;
        /**
        * Get Animator
        * @return the animator
        */
      Animator GetAnimator () const;
   };//GroupSceneNode;
}}//API

#endif //_APIGroupSceneNode_H_