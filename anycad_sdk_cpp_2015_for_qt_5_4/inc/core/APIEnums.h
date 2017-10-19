#pragma once
namespace AnyCAD { namespace API 
{
  /**
   * Shape Type
   */
	enum EnumTopoShapeType
	{
		Topo_COMPOUND,
		Topo_COMPSOLID,
		Topo_SOLID,
		Topo_SHELL,
		Topo_FACE,
		Topo_WIRE,
		Topo_EDGE,
		Topo_VERTEX,
		Topo_SHAPE
	};
  /**
   * Standard View
   * The standard camera position.
   */
   enum EnumStandardView
   {
       SV_Invalid = 0,
       SV_ISO  = 0x0001,
       SV_Front = 0x0002,
       SV_Back = 0x0004,
       SV_Top = 0x0008,
       SV_Bottom = 0x0010,
       SV_Left = 0x0020,
       SV_Right = 0x0040,
   };

  /**
   * Display style
   */
   enum EnumDisplayStyle
   {
      DS_Face        = 0x0001,
      DS_Wireframe    = 0x0002,
      DS_Realistic    = 0x0004,

      DS_Vertex       = 0x0008,
      DS_Edge         = 0x0010,
      
      DS_ShadeEdge    = DS_Face | DS_Edge,
   };

  /**
   * Redraw hint
   */
   enum EnumRedrawHintType
   {
       RHT_Normal = 0x0001,
       RHT_Camera = 0x0002,
       RHT_Select = 0x0004,
       RHT_LoadScene = 0x0010,
   };

  /**
   * Rendering/Picking flags.
   */
   enum EnumRenderFlags
   {
      RF_None        = 0,
      RF_Face        = 0x0001,
      RF_Edge        = 0x0002,
      RF_Vertex      = 0x0004,
      RF_Text        = 0x0008,
      RF_BBox        = 0x0010,
      RF_HlrEdge     = 0x0020,
      RF_SceneNode   = 0x0100,
      RF_GroupSceneNode = 0x0200,
      RF_Default     = RF_Face | RF_Edge | RF_Vertex | RF_Text,
   };

  /**
   * Picking flags.
   */
   enum EnumSnapFlags
   {
       SF_None,
       SF_TopoVertex = 0x0001,
       SF_OnGrid  = 0x0002,
       SF_CrossPointOnGrid = 0x0004,
       SF_ToInteger = 0x0010
   };
}}