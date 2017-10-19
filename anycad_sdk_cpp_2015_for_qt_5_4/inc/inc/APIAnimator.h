//Public API. Powered by AnyCAD.

#ifndef _APIAnimator_H_
#define _APIAnimator_H_

#include "core/APIObjectDef.h"

namespace AnyCAD{ namespace API
{
   class AABox;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The animator to control the animation state.
    */
   class AnyPlatformAPI_API Animator
   {
      DECLARE_APIOBJECT(Animator)
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
        * Enable the animator
        * @param bEnabled true or false
        */
      void SetEnabled (bool bEnabled) ;
        /**
        * Get enable status
        * @return true if enabled.
        */
      bool IsEnabled () const;
        /**
        * Enable the animator to loop running
        * @param bLoop true or false
        */
      virtual void EnableLoop (bool bLoop) ;
        /**
        * Get loop status
        * @return true if enabled.
        */
      virtual bool IsLoopEnabled () const;
        /**
        * Get running status
        * @return true if paused.
        */
      virtual bool IsPaused () const;
        /**
        * Active the animation
        * @return true if successfully.
        */
      virtual bool ActiveAnimation (const String& animation) ;
        /**
        * Active the animation by index
        * @return true if successfully.
        */
      virtual bool ActiveAnimationByIndex (int nChannel) ;
        /**
        * Set the tick range
        * @param start the start position.
        * @param end the end position
        */
      virtual void SetFrameSpan (int start, int end) ;
        /**
        * Get the next action script name
        * @return the script name.
        */
      String GetNextActionScriptName () const;
        /**
        * Set the next action when the animation is finished.
        * @param val the next action script name.
        */
      void SetNextActionScriptName (const String& val) ;
        /**
        * Get the bounding box of the child node
        * @param name the node name.
        * @return the bounding box.
        */
      virtual AABox GetNodeBBox (const String& name) const;
   };//Animator;
}}//API

#endif //_APIAnimator_H_