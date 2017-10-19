
#pragma once

/**
* @ingroup MFC
* @brief
* The application utility class.
*/
class ANYPLATFORMMFC_API AuWinAppImpl
{
public:
    static BOOL InitInstance(HINSTANCE hInstance);
    static int ExitInstance();

    static AnyCAD::API::String UnicodeToUTF8(const CString& str);
    static CString UTF8ToUnicode(const AnyCAD::API::String& str);

    static AnyCAD::API::String UnicodeToANSI(const CString& str);
    static CString ANSIToUnicode(const AnyCAD::API::String& str);
};

/**
* @ingroup MFC
* @brief
* The template class for CWinApp.
*/
template<typename TWinApp>
class AuWinApp : public TWinApp
{
public:
	virtual BOOL InitInstance() override
    {
        TWinApp::InitInstance();

        return AuWinAppImpl::InitInstance(m_hInstance);
    }
	virtual int ExitInstance() override
    {
        if(AuWinAppImpl::ExitInstance() == 0)
            return 0;

        return AuWinAppImpl::ExitInstance();
    }
};


inline CString __UISTR(const AnyCAD::API::String& str)
{
    return AuWinAppImpl::UTF8ToUnicode(str);
}

inline AnyCAD::API::String __UISTR(const CString& str)
{
    return AuWinAppImpl::UnicodeToUTF8(str);
}