#include "ui/MainWindow.h"
#include "flexx/Flexx.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	_viewer = new Viewer();
	ui.setupUi(this);
	InitialVtkWidget();
}

void MainWindow::InitialVtkWidget()
{
	_widget = new QVTKWidget(this->centralWidget());
	_widget->setGeometry(QRect(30, 30, 370, 370));

	_widget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_widget->GetInteractor(), _widget->GetRenderWindow());
	_widget->update();
}