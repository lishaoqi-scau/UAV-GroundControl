
#pragma once

#include "inc/APIDocument.h"

/**
* @ingroup MFC
* @brief
* The data management class.
*/
class ANYPLATFORMMFC_API AuDocument : public CDocument
{
protected:
	AuDocument();
	DECLARE_DYNCREATE(AuDocument)


public:
    /**
    * Set the document type used by your project.
    * @param docType the type id.
    */
    static void SetDocumentType(const AnyCAD::API::String& docType);

    /**
    * Get the Document.
    * @return the document.
    */
    AnyCAD::API::Document& GetDocument(){return m_Document;}

public:
    // SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);

public:
	virtual ~AuDocument();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    AnyCAD::API::Document m_Document;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void Serialize(CArchive& ar);
    virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
    virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
    virtual BOOL OnNewDocument();
};
