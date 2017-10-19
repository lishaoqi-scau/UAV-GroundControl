//Public API. Powered by AnyCAD.

#ifndef _APISceneReader_H_
#define _APISceneReader_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class GroupSceneNode;
   /**
    * @ingroup Exchange
    * @author AnyCAD
    * @brief
    *  The 3d file reader. The models are only used for visualization purpose. -since R2015UR1.
    */
   class AnyPlatformAPI_API SceneReader
   {
      DECLARE_APIOBJECT(SceneReader)
   public:
        /**
        * Get the model from file.
        * @param fileName the file name.
        * @return the group node which contains the model.
        */
      GroupSceneNode LoadFile (const String& fileName) ;
   };//SceneReader;
}}//API

#endif //_APISceneReader_H_