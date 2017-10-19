//Public API. Powered by AnyCAD.

#ifndef _APITransformAnimator_H_
#define _APITransformAnimator_H_

#include "core/APIObjectDef.h"

#include "inc/APIAnimator.h"

namespace AnyCAD{ namespace API
{
   class Vector3;
   class RenderableInstance;
   /**
    * @ingroup Render
    * @author AnyCAD
    * @brief
    *  The transform animator.
    */
   class AnyPlatformAPI_API TransformAnimator
      : public Animator
   {
      DECLARE_APISUPER(TransformAnimator, Animator)
   public:
        /**
        * Get moving direction.
        * @return the direction.
        */
      Vector3 GetDirection () const;
        /**
        * Set moving direction
        * @param val the direction
        */
      void SetDirection (const Vector3& val) ;
        /**
        * Get moving distance.
        * @return the distance.
        */
      double GetDistance () const;
        /**
        * Set moving distance
        * @param val the distance
        */
      void SetDistance (double val) ;
        /**
        * Get moving step.
        * @return the step.
        */
      double GetStep () const;
        /**
        * Set moving step
        * @param val the step
        */
      void SetStep (double val) ;
        /**
        * Set the next animator when it's end.
        * @param propertyId the property name. &
        * @param propertyValue the property value
        */
      void SetNextTypeAnimator (const String& propertyId, const String& propertyValue) ;
        /**
        * Active the animation
        * @return true if successfully.
        */
      virtual bool ActiveAnimation (const String& animation) ;
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
   };//TransformAnimator;
}}//API

#endif //_APITransformAnimator_H_