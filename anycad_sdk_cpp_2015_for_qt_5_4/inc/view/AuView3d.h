#pragma once

namespace AnyCAD {namespace API
{
	class TopoShape;
	class SceneNode;
    class EntitySceneNode;
}
}

/**
* @ingroup MFC
* @brief
* The view 3d control for MFC CView.
*/
class ANYPLATFORMMFC_API AuView3d : public CView
{
	DECLARE_DYNCREATE(AuView3d)

public:
    /**
    * Set the background.
    * @param topClr the top color
    * @param midClr the middle color
    * @param bottomClr the bottom color
    */
    void SetBackgoundColor(const AnyCAD::API::ColorValue& topClr, const AnyCAD::API::ColorValue& midClr, const AnyCAD::API::ColorValue& bottomClr);

    /**
    * Binding the geometry to SceneNode and show it in scene.
    * @param geometry the TopoShape object.
    * @param id the id of the shape. You can use this id to find the SceneNode.
    * @param accurate the tolerance for visualize the geometry.
    * @return the EntitySceneNode binding with the geometry.
    *  
    */
	AnyCAD::API::EntitySceneNode  ShowGeometry(const AnyCAD::API::TopoShape& geometry, int id, float accurate = 0.2);
	
    /**
    * Add the scene node to the scene.
    * @param node the node to show.
    */
    void ShowSceneNode(const AnyCAD::API::SceneNode& node);

    /**
    * Find the scene node by id.
    * @param id the id of the geometry or scene node.
    * @return the SceneNode. Please test if the scene node is valid before using the object returned.
    */
    AnyCAD::API::SceneNode FindSceneNode(int id) const;
    
    /**
    * Remove the node from the scene.
    * @param node the scene node to be removed.
    */
    void RemoveSenceNode(const AnyCAD::API::SceneNode& node);

    virtual void OnChangeCursor (const AnyCAD::API::String& commandId, const AnyCAD::API::String& cursorHint);

protected:
    AuView3d();        
    virtual ~AuView3d();

protected:
    AnyCAD::API::View3d m_View3d;
    bool m_bInitialized;
    bool m_bHandleMouseMessage;
public:
	virtual void OnDraw(CDC* pDC);     
    virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnDestroy();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


