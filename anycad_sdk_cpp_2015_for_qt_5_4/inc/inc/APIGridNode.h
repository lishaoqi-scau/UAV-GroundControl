//Public API. Powered by AnyCAD.

#ifndef _APIGridNode_H_
#define _APIGridNode_H_

#include "core/APIObjectDef.h"

#include "inc/APIGroupSceneNode.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   class ColorValue;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Grid Node. -since R2015.
    */
   class AnyPlatformAPI_API GridNode
      : public GroupSceneNode
   {
      DECLARE_APISUPER(GridNode, GroupSceneNode)
   public:
        /**
        * Set the number of the bigger cells.
        * @param cx count of direction X.
        * @param cy count of direction Y.
        */
      void SetCellCount (int cx, int cy) ;
        /**
        * Get the count of each bigger cell.
        * @return the count.
        */
      Vector2 GetCellCount () const;
        /**
        * Set the size of each bigger cell.
        * @param cellSize size of X and Y.
        */
      void SetCellSize (const Vector2& cellSize) ;
        /**
        * Get the size of each bigger cell.
        * @return the size.
        */
      Vector2 GetCellSize () const;
        /**
        * Set the number of the smaller cells.
        * @param cx size of X.
        * @param cy size of Y.
        */
      void SetSubCellCount (int cx, int cy) ;
        /**
        * Get the size of each sub cell.
        * @return the size.
        */
      Vector2 GetSubCellSize () const;
        /**
        * Get the count of each sub cell.
        * @return the count.
        */
      Vector2 GetSubCellCount () const;
        /**
        * Set the large grid color
        * @param clr the ColorValue
        */
      virtual void SetCellColor (const ColorValue& clr) ;
        /**
        * Get large grid color
        * @return the ColorValue.
        */
      ColorValue GetCellColor () const;
        /**
        * Set the small grid color
        * @param clr the ColorValue
        */
      virtual void SetSubCellColor (const ColorValue& clr) ;
        /**
        * Get small grid color
        * @return the ColorValue.
        */
      ColorValue GetSubCellColor () const;
        /**
        * Apply the changes.
        */
      virtual void Update () ;
   };//GridNode;
}}//API

#endif //_APIGridNode_H_