#ifndef AnyPlatformQtInclude_h__
#define AnyPlatformQtInclude_h__

#ifdef  AnyPlatformQt_EXPORTS
#define AnyPlatformQtAPI __declspec(dllexport)
#else
#define AnyPlatformQtAPI __declspec(dllimport)
#endif

/**
 * @defgroup QtUi QtUi
*/

#include "AnyPlatformAPI.h"
#pragma warning( disable: 4251 )

#include "core/APIObjectDef.h"
#include "core/APIMath.h"
#include "core/APIString.h"
#include "core/APIGlobalInstance.h"
#include "core/APIEnums.h"
#include "core/APIDownCast.h"
#include "inc/APIClassPtrDef.h"
#include "inc/APIInputEvent.h"
#include "inc/APIView3d.h"
#include "inc/APIRenderer.h"
#include "inc/APISceneManager.h"
#include "inc/APISceneEnvironment.h"
#include "inc/APITopoShape.h"
#include "inc/APIEntitySceneNode.h"

#endif // AnyPlatformQtInclude_h__

