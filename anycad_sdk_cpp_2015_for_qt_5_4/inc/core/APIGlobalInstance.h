#pragma once

#include "inc/APIBrepTools.h"
#include "inc/APIMatrixBuilder.h"
#include "inc/APITopoShapeConvert.h"
#include "inc/APITopoExplor.h"
#include "inc/APIApplication.h"
#include "inc/APIFontManager.h"

namespace AnyCAD{ namespace API{

   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    The global instance
   */
   class AnyPlatformAPI_API GlobalInstance
   {
   public:
       static Application application;
       static BrepTools brepTools;
       static MatrixBuilder matrixBuilder;
       static TopoShapeConvert topoShapeConvert;
       static TopoExplor topoExplor;
       static FontManager fontManager;

   public:
       void SetConfigFileName(const String& fileName);
       /**
       * Initialize the SDK
       * @param dir the direction of the SDK.
       * @return true if succeed.
       */
       static bool Initialize(const String& dir);
       /**
       * Register the SDK
       * @param email your email.
       * @param uuid your unique id.
       * @param key your unique key.
       * @return true if succeed.
       */
       static bool RegisterSDK(const String& email, const String& uuid, const String& key);
   };
}}
