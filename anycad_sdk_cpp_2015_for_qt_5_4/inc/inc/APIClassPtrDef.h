#include <memory>
#pragma once
namespace AnyCore{


   class AMatrixBuilder;
   typedef std::shared_ptr<AMatrixBuilder> AMatrixBuilderPtr;

   class AApplication;
   typedef std::shared_ptr<AApplication> AApplicationPtr;

   class AEventListener;
   typedef std::shared_ptr<AEventListener> AEventListenerPtr;

   class AObject;
   typedef std::shared_ptr<AObject> AObjectPtr;

   class ATopoShape;
   typedef std::shared_ptr<ATopoShape> ATopoShapePtr;

   class ATopoShapeGroup;
   typedef std::shared_ptr<ATopoShapeGroup> ATopoShapeGroupPtr;

   class ABrepTools;
   typedef std::shared_ptr<ABrepTools> ABrepToolsPtr;

   class ATopoShapeProperty;
   typedef std::shared_ptr<ATopoShapeProperty> ATopoShapePropertyPtr;

   class ATopoExplor;
   typedef std::shared_ptr<ATopoExplor> ATopoExplorPtr;

   class AEntity;
   typedef std::shared_ptr<AEntity> AEntityPtr;

   class AEntityGroup;
   typedef std::shared_ptr<AEntityGroup> AEntityGroupPtr;

   class AIntersectionLineCurve;
   typedef std::shared_ptr<AIntersectionLineCurve> AIntersectionLineCurvePtr;

   class AIntersectionLineSurface;
   typedef std::shared_ptr<AIntersectionLineSurface> AIntersectionLineSurfacePtr;

   class AGeomBase;
   typedef std::shared_ptr<AGeomBase> AGeomBasePtr;

   class AGeomCurve;
   typedef std::shared_ptr<AGeomCurve> AGeomCurvePtr;

   class AGeomCurve2d;
   typedef std::shared_ptr<AGeomCurve2d> AGeomCurve2dPtr;

   class AGeomCircle;
   typedef std::shared_ptr<AGeomCircle> AGeomCirclePtr;

   class AGeomSurface;
   typedef std::shared_ptr<AGeomSurface> AGeomSurfacePtr;

   class AFaceTriangulation;
   typedef std::shared_ptr<AFaceTriangulation> AFaceTriangulationPtr;

   class ALoopsBuilder;
   typedef std::shared_ptr<ALoopsBuilder> ALoopsBuilderPtr;

   class AMeasureResult;
   typedef std::shared_ptr<AMeasureResult> AMeasureResultPtr;

   class AMeasureTools;
   typedef std::shared_ptr<AMeasureTools> AMeasureToolsPtr;

   class APrimitive2dTools;
   typedef std::shared_ptr<APrimitive2dTools> APrimitive2dToolsPtr;

   class AAdvFeatureTools;
   typedef std::shared_ptr<AAdvFeatureTools> AAdvFeatureToolsPtr;

   class AShapeProcessSettings;
   typedef std::shared_ptr<AShapeProcessSettings> AShapeProcessSettingsPtr;

   class ARepairTools;
   typedef std::shared_ptr<ARepairTools> ARepairToolsPtr;

   class AInputEvent;
   typedef std::shared_ptr<AInputEvent> AInputEventPtr;

   class AContextMenu;
   typedef std::shared_ptr<AContextMenu> AContextMenuPtr;

   class AView;
   typedef std::shared_ptr<AView> AViewPtr;

   class AView3d;
   typedef std::shared_ptr<AView3d> AView3dPtr;

   class AEditor;
   typedef std::shared_ptr<AEditor> AEditorPtr;

   class ACustomEditor;
   typedef std::shared_ptr<ACustomEditor> ACustomEditorPtr;

   class ACommand;
   typedef std::shared_ptr<ACommand> ACommandPtr;

   class ACamera;
   typedef std::shared_ptr<ACamera> ACameraPtr;

   class AFrustum;
   typedef std::shared_ptr<AFrustum> AFrustumPtr;

   class AViewport;
   typedef std::shared_ptr<AViewport> AViewportPtr;

   class ARenderStyle;
   typedef std::shared_ptr<ARenderStyle> ARenderStylePtr;

   class ALineStyle;
   typedef std::shared_ptr<ALineStyle> ALineStylePtr;

   class AFaceStyle;
   typedef std::shared_ptr<AFaceStyle> AFaceStylePtr;

   class APointStyle;
   typedef std::shared_ptr<APointStyle> APointStylePtr;

   class ARenderTarget;
   typedef std::shared_ptr<ARenderTarget> ARenderTargetPtr;

   class ARenderWindow;
   typedef std::shared_ptr<ARenderWindow> ARenderWindowPtr;

   class ASceneNode;
   typedef std::shared_ptr<ASceneNode> ASceneNodePtr;

   class ARenderResource;
   typedef std::shared_ptr<ARenderResource> ARenderResourcePtr;

   class AMaterial;
   typedef std::shared_ptr<AMaterial> AMaterialPtr;

   class APhongMaterial;
   typedef std::shared_ptr<APhongMaterial> APhongMaterialPtr;

   class ATexture;
   typedef std::shared_ptr<ATexture> ATexturePtr;

   class ATopoShapeConvert;
   typedef std::shared_ptr<ATopoShapeConvert> ATopoShapeConvertPtr;

   class AGroupSceneNode;
   typedef std::shared_ptr<AGroupSceneNode> AGroupSceneNodePtr;

   class ASceneNodeCast;
   typedef std::shared_ptr<ASceneNodeCast> ASceneNodeCastPtr;

   class AWorkingPlane;
   typedef std::shared_ptr<AWorkingPlane> AWorkingPlanePtr;

   class AAnimator;
   typedef std::shared_ptr<AAnimator> AAnimatorPtr;

   class AAnimation;
   typedef std::shared_ptr<AAnimation> AAnimationPtr;

   class ATransformAnimator;
   typedef std::shared_ptr<ATransformAnimator> ATransformAnimatorPtr;

   class AEntitySceneNode;
   typedef std::shared_ptr<AEntitySceneNode> AEntitySceneNodePtr;

   class ASceneManager;
   typedef std::shared_ptr<ASceneManager> ASceneManagerPtr;

   class ASceneNodeIterator;
   typedef std::shared_ptr<ASceneNodeIterator> ASceneNodeIteratorPtr;

   class ASceneEnvironment;
   typedef std::shared_ptr<ASceneEnvironment> ASceneEnvironmentPtr;

   class ARenderableEntity;
   typedef std::shared_ptr<ARenderableEntity> ARenderableEntityPtr;

   class ARenderableGroupEntity;
   typedef std::shared_ptr<ARenderableGroupEntity> ARenderableGroupEntityPtr;

   class ARenderableGeometry;
   typedef std::shared_ptr<ARenderableGeometry> ARenderableGeometryPtr;

   class AQuerySelectionContext;
   typedef std::shared_ptr<AQuerySelectionContext> AQuerySelectionContextPtr;

   class AQuerySelectedEntityContext;
   typedef std::shared_ptr<AQuerySelectedEntityContext> AQuerySelectedEntityContextPtr;

   class AQuerySelectedShapeContext;
   typedef std::shared_ptr<AQuerySelectedShapeContext> AQuerySelectedShapeContextPtr;

   class AQuerySelectedElementContext;
   typedef std::shared_ptr<AQuerySelectedElementContext> AQuerySelectedElementContextPtr;

   class AQuerySelectedIdSetContext;
   typedef std::shared_ptr<AQuerySelectedIdSetContext> AQuerySelectedIdSetContextPtr;

   class AQueryMultiShapeContext;
   typedef std::shared_ptr<AQueryMultiShapeContext> AQueryMultiShapeContextPtr;

   class ACustomizedSceneNode;
   typedef std::shared_ptr<ACustomizedSceneNode> ACustomizedSceneNodePtr;

   class ATextNode;
   typedef std::shared_ptr<ATextNode> ATextNodePtr;

   class AImageNode;
   typedef std::shared_ptr<AImageNode> AImageNodePtr;

   class APointNode;
   typedef std::shared_ptr<APointNode> APointNodePtr;

   class ALineNode;
   typedef std::shared_ptr<ALineNode> ALineNodePtr;

   class AGridNode;
   typedef std::shared_ptr<AGridNode> AGridNodePtr;

   class ARectangleGridNode;
   typedef std::shared_ptr<ARectangleGridNode> ARectangleGridNodePtr;

   class APointCloudNode;
   typedef std::shared_ptr<APointCloudNode> APointCloudNodePtr;

   class ARenderer;
   typedef std::shared_ptr<ARenderer> ARendererPtr;

   class ACameraOperator;
   typedef std::shared_ptr<ACameraOperator> ACameraOperatorPtr;

   class ACoordinateWidget;
   typedef std::shared_ptr<ACoordinateWidget> ACoordinateWidgetPtr;

   class AAxesWidget;
   typedef std::shared_ptr<AAxesWidget> AAxesWidgetPtr;

   class AArrowWidget;
   typedef std::shared_ptr<AArrowWidget> AArrowWidgetPtr;

   class AText3dNode;
   typedef std::shared_ptr<AText3dNode> AText3dNodePtr;

   class AGridHeadNode;
   typedef std::shared_ptr<AGridHeadNode> AGridHeadNodePtr;

   class AGridLineNode;
   typedef std::shared_ptr<AGridLineNode> AGridLineNodePtr;

   class APickHelper;
   typedef std::shared_ptr<APickHelper> APickHelperPtr;

   class AFont;
   typedef std::shared_ptr<AFont> AFontPtr;

   class AFontManager;
   typedef std::shared_ptr<AFontManager> AFontManagerPtr;

   class AFontDecomposer;
   typedef std::shared_ptr<AFontDecomposer> AFontDecomposerPtr;

   class AFontLoopDecomposer;
   typedef std::shared_ptr<AFontLoopDecomposer> AFontLoopDecomposerPtr;

   class AFontEdgeDecomposer;
   typedef std::shared_ptr<AFontEdgeDecomposer> AFontEdgeDecomposerPtr;

   class AFontGeometryDecomposer;
   typedef std::shared_ptr<AFontGeometryDecomposer> AFontGeometryDecomposerPtr;

   class AParameterValue;
   typedef std::shared_ptr<AParameterValue> AParameterValuePtr;

   class AParameterString;
   typedef std::shared_ptr<AParameterString> AParameterStringPtr;

   class AParameterInteger;
   typedef std::shared_ptr<AParameterInteger> AParameterIntegerPtr;

   class AParameterDouble;
   typedef std::shared_ptr<AParameterDouble> AParameterDoublePtr;

   class AParameterVector3;
   typedef std::shared_ptr<AParameterVector3> AParameterVector3Ptr;

   class AParameterBoolean;
   typedef std::shared_ptr<AParameterBoolean> AParameterBooleanPtr;

   class AParameterColor;
   typedef std::shared_ptr<AParameterColor> AParameterColorPtr;

   class AParameterValueCast;
   typedef std::shared_ptr<AParameterValueCast> AParameterValueCastPtr;

   class AParameterCreator;
   typedef std::shared_ptr<AParameterCreator> AParameterCreatorPtr;

   class AParameterValueSet;
   typedef std::shared_ptr<AParameterValueSet> AParameterValueSetPtr;

   class AElement;
   typedef std::shared_ptr<AElement> AElementPtr;

   class AElementTable;
   typedef std::shared_ptr<AElementTable> AElementTablePtr;

   class APropertiesElement;
   typedef std::shared_ptr<APropertiesElement> APropertiesElementPtr;

   class ALayerElement;
   typedef std::shared_ptr<ALayerElement> ALayerElementPtr;

   class AInstanceElement;
   typedef std::shared_ptr<AInstanceElement> AInstanceElementPtr;

   class ATypeElement;
   typedef std::shared_ptr<ATypeElement> ATypeElementPtr;

   class ARenderableInstance;
   typedef std::shared_ptr<ARenderableInstance> ARenderableInstancePtr;

   class ARenderableType;
   typedef std::shared_ptr<ARenderableType> ARenderableTypePtr;

   class AAssetType;
   typedef std::shared_ptr<AAssetType> AAssetTypePtr;

   class AGroupType;
   typedef std::shared_ptr<AGroupType> AGroupTypePtr;

   class AEntityType;
   typedef std::shared_ptr<AEntityType> AEntityTypePtr;

   class AScriptElement;
   typedef std::shared_ptr<AScriptElement> AScriptElementPtr;

   class ADocument;
   typedef std::shared_ptr<ADocument> ADocumentPtr;

   class ADocumentChangeArgs;
   typedef std::shared_ptr<ADocumentChangeArgs> ADocumentChangeArgsPtr;

   class AUndoTransaction;
   typedef std::shared_ptr<AUndoTransaction> AUndoTransactionPtr;

   class AParameterUI;
   typedef std::shared_ptr<AParameterUI> AParameterUIPtr;

   class AParameterUISet;
   typedef std::shared_ptr<AParameterUISet> AParameterUISetPtr;

   class ADocumentMetadata;
   typedef std::shared_ptr<ADocumentMetadata> ADocumentMetadataPtr;

   class ADocViewManager;
   typedef std::shared_ptr<ADocViewManager> ADocViewManagerPtr;

   class AStyleElement;
   typedef std::shared_ptr<AStyleElement> AStyleElementPtr;

   class ACompoundElement;
   typedef std::shared_ptr<ACompoundElement> ACompoundElementPtr;

   class ARenderableElement;
   typedef std::shared_ptr<ARenderableElement> ARenderableElementPtr;

   class AGeomElement;
   typedef std::shared_ptr<AGeomElement> AGeomElementPtr;

   class APointElement;
   typedef std::shared_ptr<APointElement> APointElementPtr;

   class ACurveElement;
   typedef std::shared_ptr<ACurveElement> ACurveElementPtr;

   class ALineElement;
   typedef std::shared_ptr<ALineElement> ALineElementPtr;

   class ASurfaceElement;
   typedef std::shared_ptr<ASurfaceElement> ASurfaceElementPtr;

   class APlannarElement;
   typedef std::shared_ptr<APlannarElement> APlannarElementPtr;

   class APolygonElement;
   typedef std::shared_ptr<APolygonElement> APolygonElementPtr;

   class ACircleElement;
   typedef std::shared_ptr<ACircleElement> ACircleElementPtr;

   class AEllipseElement;
   typedef std::shared_ptr<AEllipseElement> AEllipseElementPtr;

   class AArcElement;
   typedef std::shared_ptr<AArcElement> AArcElementPtr;

   class ASplineElement;
   typedef std::shared_ptr<ASplineElement> ASplineElementPtr;

   class AGridElement;
   typedef std::shared_ptr<AGridElement> AGridElementPtr;

   class ATieLineElement;
   typedef std::shared_ptr<ATieLineElement> ATieLineElementPtr;

   class ATieCircleElement;
   typedef std::shared_ptr<ATieCircleElement> ATieCircleElementPtr;

   class ATieEllipseElement;
   typedef std::shared_ptr<ATieEllipseElement> ATieEllipseElementPtr;

   class ATieArcElement;
   typedef std::shared_ptr<ATieArcElement> ATieArcElementPtr;

   class ATiePolygonElement;
   typedef std::shared_ptr<ATiePolygonElement> ATiePolygonElementPtr;

   class ATieSplineElement;
   typedef std::shared_ptr<ATieSplineElement> ATieSplineElementPtr;

   class AGridItemElement;
   typedef std::shared_ptr<AGridItemElement> AGridItemElementPtr;

   class AGridItemByLine;
   typedef std::shared_ptr<AGridItemByLine> AGridItemByLinePtr;

   class AGridItemByArc;
   typedef std::shared_ptr<AGridItemByArc> AGridItemByArcPtr;

   class AGridItemByOffset;
   typedef std::shared_ptr<AGridItemByOffset> AGridItemByOffsetPtr;

   class AGridLabelElement;
   typedef std::shared_ptr<AGridLabelElement> AGridLabelElementPtr;

   class AGridPointElement;
   typedef std::shared_ptr<AGridPointElement> AGridPointElementPtr;

   class AReferencePlane;
   typedef std::shared_ptr<AReferencePlane> AReferencePlanePtr;

   class ASectionPlane;
   typedef std::shared_ptr<ASectionPlane> ASectionPlanePtr;

   class ALevelPlane;
   typedef std::shared_ptr<ALevelPlane> ALevelPlanePtr;

   class ADBView;
   typedef std::shared_ptr<ADBView> ADBViewPtr;

   class ADBViewTable;
   typedef std::shared_ptr<ADBViewTable> ADBViewTablePtr;

   class ATypeCast;
   typedef std::shared_ptr<ATypeCast> ATypeCastPtr;

   class AComponentManager;
   typedef std::shared_ptr<AComponentManager> AComponentManagerPtr;

   class ATopoDataExchangeStl;
   typedef std::shared_ptr<ATopoDataExchangeStl> ATopoDataExchangeStlPtr;

   class ATopoDataExchangeStep;
   typedef std::shared_ptr<ATopoDataExchangeStep> ATopoDataExchangeStepPtr;

   class ATopoDataExchangeIges;
   typedef std::shared_ptr<ATopoDataExchangeIges> ATopoDataExchangeIgesPtr;

   class ATopoShapeReader;
   typedef std::shared_ptr<ATopoShapeReader> ATopoShapeReaderPtr;

   class ATopoShapeReaderManager;
   typedef std::shared_ptr<ATopoShapeReaderManager> ATopoShapeReaderManagerPtr;

   class ATopoShapeReaderContext;
   typedef std::shared_ptr<ATopoShapeReaderContext> ATopoShapeReaderContextPtr;

   class ASceneReader;
   typedef std::shared_ptr<ASceneReader> ASceneReaderPtr;
}