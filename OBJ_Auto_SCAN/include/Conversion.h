#ifndef CONVERSION
#define CONVERSION

#include "Typedef.h"

#include <QVTKWidget.h>
#include<QMessageBox>
#include <QFileDialog>
#include<QInputDialog>
#include <QSpinBox>
#include <QCloseEvent>

class TypeConversion
{
public:
	static std::string Int2String(int number)
	{
		std::string str = std::to_string(number);
		return str;
	}

	static std::string Double2String(double number)
	{
		std::string str = std::to_string(number);
		return str;
	}

	static std::string QString2String(QString qs)
	{
		std::string str = qs.toLocal8Bit().constData();
		return str;
	}

	static double QString2Double(QString qs)
	{
		double d = qs.toDouble();
		return d;
	}

	static float QString2Float(QString qs)
	{
		float f = qs.toFloat();
		return f;
	}

	static int QString2Int(QString qs)
	{
		int i = qs.toInt();
		return i;
	}

	static int String2Int(std::string str)
	{
		int number = std::stoi(str);
		return number;
	}

	static double String2Double(std::string str)
	{
		double number = std::stod(str);
		return number;
	}
};

#endif