#pragma once

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include "ui_MainWindow.h"
#include "ui/Viewer.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	void InitialVtkWidget();

	Viewer* _viewer;
	QVTKWidget* _widget;
	Ui::MainWindowClass ui;
};
