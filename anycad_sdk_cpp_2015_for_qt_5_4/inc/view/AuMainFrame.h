
#pragma once

#include "inc/APIEventListener.h"

/**
* @ingroup MFC
* @brief
* The CFrameWnd utility class.
*/
class ANYPLATFORMMFC_API AuMainFrameImpl
{
public:
    /**
    * Get the active view.
    * @return the view.
    */
    static CView* GetActiveView();

    /**
    * Get the active document.
    * @return the document.
    */
    static CDocument* GetActiveDocument();

public:
    // Internal methods.
    static AnyCAD::API::String OnGetOpenFileName(const AnyCAD::API::String& caption, const AnyCAD::API::String& filter);
    static AnyCAD::API::String OnGetSaveFileName (const AnyCAD::API::String& caption, const AnyCAD::API::String& defaultName, const AnyCAD::API::String& filter);
    static int OnExecuteEventLoop(long loopId);
    static void OnExitLoopEvent(long loopId, int code);
    static void OnChangeCursor (const AnyCAD::API::String& commandId, const AnyCAD::API::String& cursorHint);
};

/**
* @ingroup MFC
* @brief
* The template class for CMainFrame.
*/
template<typename TMainFrame>
class AuMainFrame : public TMainFrame, AnyCAD::API::EventListener
{
public:

      // Internal method.
      virtual AnyCAD::API::String OnGetOpenFileName (const AnyCAD::API::String& caption, const AnyCAD::API::String& filter) override
      {
          return AuMainFrameImpl::OnGetOpenFileName(caption, filter);
      }
      // Internal method.
      virtual AnyCAD::API::String OnGetSaveFileName (const AnyCAD::API::String& caption, const AnyCAD::API::String& defaultName, const AnyCAD::API::String& filter) override
      {
          return AuMainFrameImpl::OnGetSaveFileName(caption, defaultName, filter);
      }
      // Internal method.
      virtual int OnExecuteEventLoop(long loopId) override
      {
          return AuMainFrameImpl::OnExecuteEventLoop(loopId);
      }
      // Internal method.
      virtual void OnExitLoopEvent(long looopId, int code) override
      {
         AuMainFrameImpl::OnExitLoopEvent(looopId, code);
      }
      virtual void OnChangeCursor (const AnyCAD::API::String& commandId, const AnyCAD::API::String& cursorHint) override
      {
          AuMainFrameImpl::OnChangeCursor(commandId, cursorHint);
      }
};


