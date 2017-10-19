#pragma once


#ifdef AnyPlatformMFC_EXPORTS
#define ANYPLATFORMMFC_API __declspec(dllexport)
#else
#define ANYPLATFORMMFC_API __declspec(dllimport)
#endif

/**
 * @defgroup MFC The MFC Package
*/