
#ifndef AuWindow3d_h__
#define AuWindow3d_h__

#include <QWidget>
#include <QTimer>

namespace AnyCAD { namespace QtUi {
/**
* @ingroup QtUi
* @brief
* The 3d widget control.
*/
class AnyPlatformQtAPI AuWindow3d 
    : public QWidget
{
   Q_OBJECT
public:
   AuWindow3d(QWidget* parent);
   virtual ~AuWindow3d();

   /**
   * Get the rendering view.
   * @return the View3d.
   */
   AnyCAD::API::View3d& GetView();
   /**
   * Get the renderer.
   * @return the Renderer.
   */
   AnyCAD::API::Renderer GetRenderer() const;

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

public Q_SLOTS:
   void OnDrawTimerTick();

protected:
   virtual QPaintEngine* paintEngine() const override;
   virtual void paintEvent( QPaintEvent* event ) override;
   virtual void resizeEvent(QResizeEvent * evt) override;
   virtual QSize sizeHint() const override;
   virtual QSize minimumSizeHint() const override;
   virtual void mousePressEvent(QMouseEvent *event) override;
   virtual void mouseMoveEvent(QMouseEvent *event) override;
   virtual void mouseReleaseEvent(QMouseEvent* event) override;
   virtual void wheelEvent(QWheelEvent * event) override;
   virtual void keyPressEvent(QKeyEvent * event)override;
   virtual void keyReleaseEvent(QKeyEvent * evt) override;

protected:
   AnyCAD::API::View3d m_View3d;
   QTimer m_Timer;
};

}}
#endif // AuWindow3d_h__
