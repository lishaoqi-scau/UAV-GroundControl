//Public API. Powered by AnyCAD.

#ifndef _APIInputEvent_H_
#define _APIInputEvent_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class Vector2;
   /**
    * @ingroup View
    * @author AnyCAD
    * @brief
    *  Mouse & Keyboard information.
    */
   class AnyPlatformAPI_API InputEvent
   {
      DECLARE_APIOBJECT(InputEvent)
   public:
        /**
        * Set left button down.
        */
      void SetLButtonDown () ;
        /**
        * Test if left button is pressed.
        * @return true if left button is down.
        */
      bool IsLButtonDown () const;
        /**
        * Set left button down.
        */
      void SetRButtonDown () ;
        /**
        * Test if right button is pressed.
        * @return true if right button is down.
        */
      bool IsRButtonDown () const;
        /**
        * Set middle button down.
        */
      void SetMButtonDown () ;
        /**
        * Test if middle button is pressed.
        * @return true if middle button is down.
        */
      bool IsMButtonDown () const;
        /**
        * Set shift key down.
        */
      void SetShiftKeyDown () ;
        /**
        * Test if shift key is pressed.
        * @return true if shift key is down.
        */
      bool IsShiftKeyDown () const;
        /**
        * Set control key down.
        */
      void SetCtrlKeyDown () ;
        /**
        * Test if control key is pressed.
        * @return true if control key is down.
        */
      bool IsCtrlKeyDown () const;
        /**
        * Set Alt key down.
        */
      void SetAltKeyDown () ;
        /**
        * Test if Alt key is pressed.
        * @return true if Alt key is down.
        */
      bool IsAltKeyDown () const;
        /**
        * Get mouse position
        * @return the mouse position
        */
      Vector2 GetMousePosition () const;
        /**
        * Set mouse position
        * @param pos the mouse position
        */
      void SetMousePosition (const Vector2& pos) ;
        /**
        * Get key
        * @return the key
        */
      int GetKey () const;
        /**
        * Set key
        * @param nChar the key
        */
      void SetKey (int nChar) ;
        /**
        * Get mouse middle delta
        * @return the mouse middle delta
        */
      int GetDelta () const;
        /**
        * Set mouse middle delta
        * @param zDelta the mouse middle delta
        */
      void SetDelta (int zDelta) ;
   };//InputEvent;
}}//API

#endif //_APIInputEvent_H_