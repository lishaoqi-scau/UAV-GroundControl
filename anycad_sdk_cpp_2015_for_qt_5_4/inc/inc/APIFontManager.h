//Public API. Powered by AnyCAD.

#ifndef _APIFontManager_H_
#define _APIFontManager_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Font;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font manager.
    */
   class AnyPlatformAPI_API FontManager
   {
      DECLARE_APIOBJECT(FontManager)
   public:
        /**
        * Find Font by name
        * @return the Font
        */
      Font FindFont (const String& name) ;
        /**
        * Add font for reusing.
        * @param font the Font object.
        */
      void AddFont (const Font& font) ;
        /**
        * Set the default Font by name.
        * @param name the font name.
        */
      void SetDefaultFont (const String& name) ;
        /**
        * Get default Font name.
        * @return the font name.
        */
      String GetDefaultFont () ;
        /**
        * Load font from file.
        * @param fontName the unique name of the font.
        * @param filePath the full font file name
        * @return the Font.
        */
      Font LoadFont (const String& fontName, const String& filePath) ;
        /**
        * List all the font names.
        * @return the name list.
        */
      StringList ListFontNames () ;
   };//FontManager;
}}//API

#endif //_APIFontManager_H_