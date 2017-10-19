#ifndef AnyPlatformAPI_h__
#define AnyPlatformAPI_h__

#ifdef  AnyPlatformAPI_EXPORTS

#define AnyPlatformAPI_API __declspec(dllexport)
#else
#define AnyPlatformAPI_API __declspec(dllimport)
#endif

/**
 * @defgroup Common The Common Package
*/
/**
 * @defgroup Geometry The Geometry Package
*/
/**
 * @defgroup Document The Document Package
*/
/**
 * @defgroup View The View Package
*/
/**
 * @defgroup Render The Render Package
*/
/**
 * @defgroup Exchange The Exchange Package
*/
#endif // AnyPlatformAPI_h__