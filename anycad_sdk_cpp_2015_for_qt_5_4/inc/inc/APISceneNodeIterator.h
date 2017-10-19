//Public API. Powered by AnyCAD.

#ifndef _APISceneNodeIterator_H_
#define _APISceneNodeIterator_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class SceneNode;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  To iterate the scene node in the scene. Usage: SceneNodeIterator itr = ...; while(itr.More()) { SceneNode node = itr.Next(); .... }.
    */
   class AnyPlatformAPI_API SceneNodeIterator
   {
      DECLARE_APIOBJECT(SceneNodeIterator)
   public:
        /**
        * Test if has more node
        * @return true if has more.
        */
      bool More () const;
        /**
        * Move to the next position.
        * @return the current node.
        */
      SceneNode Next () ;
   };//SceneNodeIterator;
}}//API

#endif //_APISceneNodeIterator_H_