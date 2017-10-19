#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mGCSDisplay = new GCSDisplay;
    mGCSDisplay->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
