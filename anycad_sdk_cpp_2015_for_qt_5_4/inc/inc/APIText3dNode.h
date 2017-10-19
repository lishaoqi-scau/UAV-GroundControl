//Public API. Powered by AnyCAD.

#ifndef _APIText3dNode_H_
#define _APIText3dNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The 3d Text Node.
    */
   class AnyPlatformAPI_API Text3dNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(Text3dNode, GroupSceneNode)
   public:
        /**
        * Set Text.
        * @param text the text string
        */
      void SetText (const String& text) ;
        /**
        * Set FontName.
        * @param fontName the FontName.
        */
      void SetFontName (const String& fontName) ;
        /**
        * Get FontName.
        * @return the FontName.
        */
      String GetFontName () const;
        /**
        * Set FontSize.
        * @param fontSize the fontSize.
        */
      void SetFontSize (const Vector2& fontSize) ;
        /**
        * Set FontSize.
        * @param width the width.
        * @param height the height
        */
      void SetFontSize (int width, int height) ;
        /**
        * Get FontSize.
        * @return the FontSize.
        */
      Vector2 GetFontSize () const;
        /**
        * Set the line spacing.
        * @param space the line space.
        */
      void SetLineSpace (int space) ;
        /**
        * Get FontSize.
        * @return the FontSize.
        */
      int GetLineSpace () const;
        /**
        * Enabled to show as solid/face or outline.
        * @param bSolid if true to show solid/face, otherwise shows as edge.
        */
      void SetBuildSolid (bool bSolid) ;
        /**
        * If build the text as solid.
        * @return true if solid.
        */
      bool IsBuildSolid () const;
        /**
        * Set the solid thickness.
        * @param thickness the thickness of the solid. If <=0, shows as face.
        */
      void SetThickness (Real thickness) ;
        /**
        * Get the thickness of the text.
        * @return the thickness of the font.
        */
      Real GetThickness () const;
        /**
        * Update the node.
        */
      void Update () ;
   };//Text3dNode;
}}//API

#endif //_APIText3dNode_H_