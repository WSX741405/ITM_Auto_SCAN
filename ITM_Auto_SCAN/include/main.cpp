#include "ui/MainWindow.h"
#include <QtWidgets/QApplication>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
