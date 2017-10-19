#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/APIBrepTools.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->connect(ui->actionSphere, SIGNAL(triggered(bool)), this, SLOT(createSphere()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSphere()
{
    using namespace AnyCAD::API;
    auto sphere = GlobalInstance::brepTools.MakeSphere(Vector3::ZERO, 50);
    ui->centralWidget->ShowGeometry(sphere, 100, 1);
}
