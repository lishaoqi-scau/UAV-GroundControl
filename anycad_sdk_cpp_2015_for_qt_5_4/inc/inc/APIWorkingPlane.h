//Public API. Powered by AnyCAD.

#ifndef _APIWorkingPlane_H_
#define _APIWorkingPlane_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class AABox;
   class Coordinate3;
   class Vector3;
   class GridNode;
   class Ray;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The Working plane. -since R2014UR1.
    */
   class AnyPlatformAPI_API WorkingPlane
   {
      DECLARE_APIOBJECT(WorkingPlane)
   public:
        /**
        * Get the Plane origin position
        * @return the position
        */
      Vector3 GetPosition () const;
        /**
        * Set the Plane origin position
        * @param pos the position
        */
      void SetPosition (const Vector3& pos) ;
        /**
        * Set the Plane Direction
        * @param dir the direction
        */
      void SetDirection (const Vector3& dir) ;
        /**
        * Get Plane Direction
        * @return the direction.
        */
      Vector3 GetDirection () const;
        /**
        * Get X Direction
        * @return the direction.
        */
      Vector3 GetXDirection () const;
        /**
        * Get Y Direction
        * @return the direction.
        */
      Vector3 GetYDirection () const;
        /**
        * Set the local coordinate for the working plane.
        * @param coord the Coordinate3.
        */
      void SetCoordinate (const Coordinate3& coord) ;
        /**
        * Get the visual grid node of the plane.
        * @return the GridNode.
        */
      GridNode GetGridNode () const;
        /**
        * Set visual grid node for the plane.
        * @param node the GridNode.
        */
      void SetGridNode (const GridNode& node) ;
   };//WorkingPlane;
}}//API

#endif //_APIWorkingPlane_H_