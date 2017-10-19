//Public API. Powered by AnyCAD.

#ifndef _APIFont_H_
#define _APIFont_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class FontDecomposer;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The font base class.
    */
   class AnyPlatformAPI_API Font
   {
      DECLARE_APIOBJECT(Font)
   public:
        /**
        * Set Name
        * @param name the name
        */
      void SetName (const String& name) ;
        /**
        * Get Name
        * @return the name
        */
      String GetName () const;
        /**
        * Set Font File
        * @param fontFile the file name
        */
      void SetFontFile (const String& fontFile) ;
        /**
        * Get Font File Name
        * @return the name
        */
      String GetFontFile () const;
        /**
        * Decompose the outline of the character
        * @param ch the character
        * @param decomposer the decomposing algorithm
        * @return the name
        */
      bool Decompose (const wchar_t& ch, const FontDecomposer& decomposer) const;
   };//Font;
}}//API

#endif //_APIFont_H_