#pragma once


/**
* @ingroup MFC
* @brief
* The view 3d control for MFC control.
*/
class ANYPLATFORMMFC_API AuWindow3d : public CStatic
{
	DECLARE_DYNAMIC(AuWindow3d)

public:
	AuWindow3d();
	virtual ~AuWindow3d();

protected:
	DECLARE_MESSAGE_MAP()
    virtual void PreSubclassWindow();

    afx_msg void OnPaint();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnDestroy();

protected:
    AnyCAD::API::View3d m_View3d;
};


