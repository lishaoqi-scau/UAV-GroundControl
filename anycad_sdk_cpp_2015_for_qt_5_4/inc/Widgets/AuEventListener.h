#ifndef AuEventListener_h__
#define AuEventListener_h__

#pragma once

#include "inc/APIEventListener.h"

namespace AnyCAD { namespace QtUi {
/**
* @ingroup QtUi
* @brief
* The default implementation for EventListener.
*/
class AnyPlatformQtAPI AuEventListener : AnyCAD::API::EventListener
{
public:
      virtual ~AuEventListener();

      /**
      * Override to provide the main widget.
      * @return the main QWidget
      */
      virtual QWidget* GetWidget() { return nullptr; }

      //Internal methods.
      virtual AnyCAD::API::String OnGetOpenFileName (const AnyCAD::API::String& caption, const AnyCAD::API::String& filter) override;
      virtual AnyCAD::API::String OnGetSaveFileName (const AnyCAD::API::String& caption, const AnyCAD::API::String& defaultName, const AnyCAD::API::String& filter) override;
      virtual int OnExecuteEventLoop(long loopId) override;
      virtual void OnExitLoopEvent(long loopId, int code) override;
};

}}

#endif // AuEventListener_h__