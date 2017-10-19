//Public API. Powered by AnyCAD.

#ifndef _APIApplication_H_
#define _APIApplication_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class PhongMaterial;
   class View3d;
   class Renderer;
   /**
    * @ingroup Common
    * @author AnyCAD
    * @brief
    *  The application object.
    */
   class AnyPlatformAPI_API Application
   {
      DECLARE_APIOBJECT(Application)
   public:
        /**
        * Set the log file name.
        * @param fileName the file name.
        */
      bool SetLogFileName (const String& fileName) ;
        /**
        * Validate the License.
        */
      bool AddLicense (const String& aa, const String& bb, const String& cc, const String& dd) ;
        /**
        * Initialize the application.
        * @return true if done.
        */
      bool Initialize () ;
        /**
        * Initialize the application.
        * @param configFile the config file name
        * @return false if failed to initialize
        */
      bool Initialize (const String& configFile) ;
        /**
        * Destroy the application.
        */
      void Destroy () ;
        /**
        * List all the skybox names
        * @return the skybox name list
        */
      StringList ListSkyBoxNames () ;
        /**
        * Set Application Path
        * @param strPath the folder without postfix '/'
        * @return void
        */
      void SetApplicationPath (const String& strPath) ;
        /**
        * Get Application Library Path
        * @return the folder without postfix '/'
        */
      String GetApplicationPath () ;
        /**
        * Set Texture Library Path
        * @param strPath the folder with postfix '/'
        * @return void
        */
      void SetTextureLibraryPath (const String& strPath) ;
        /**
        * Set Model Library Path
        * @param strPath the folder with postfix '/'
        * @return void
        */
      void SetModelLibraryPath (const String& strPath) ;
        /**
        * Get Model Library Path
        * @return the folder without postfix '/'
        */
      String GetModelLibraryPath () ;
        /**
        * Create 3d Renderer
        * @param hWnd the window handle
        * @param nWidth the width
        * @param nHeight the height
        * @return the Renderer
        */
      Renderer CreateRenderer (long hWnd, int nWidth, int nHeight) ;
        /**
        * Create 3d view
        * @param hWnd the window handle
        * @param nWidth the width
        * @param nHeight the height
        * @return the View3d
        */
      View3d CreateView (long hWnd, int nWidth, int nHeight) ;
        /**
        * Find system material
        * @param name the material name.
        * @return the material
        */
      PhongMaterial FindSystemMaterial (const String& name) ;
   };//Application;
}}//API

#endif //_APIApplication_H_