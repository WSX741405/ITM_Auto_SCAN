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

class RTConversion
{
public:
	static Eigen::Matrix4f RT(Eigen::Matrix<float, 3, 3, Eigen::RowMajor> r, Eigen::Vector3f t)
	{
		Eigen::Matrix4f rt;
		rt(0, 0) = r(0);
		rt(0, 1) = r(1);
		rt(0, 2) = r(2);
		rt(1, 0) = r(3);
		rt(1, 1) = r(4);
		rt(1, 2) = r(5);
		rt(2, 0) = r(6);
		rt(2, 1) = r(7);
		rt(2, 2) = r(8);

		rt(3, 0) = 0;
		rt(3, 1) = 0;
		rt(3, 2) = 0;

		rt(0, 3) = t(0);
		rt(1, 3) = t(1);
		rt(2, 3) = t(2);

		return rt;
	}

	static void RT(Eigen::Matrix<float, 3, 3, Eigen::RowMajor> &r, Eigen::Vector3f &t, Eigen::Matrix4f rt)
	{
		r(0) = rt(0, 0);
		r(1) = rt(0, 1);
		r(2) = rt(0, 2);
		r(3) = rt(1, 0);
		r(4) = rt(1, 1);
		r(5) = rt(1, 2);
		r(6) = rt(2, 0);
		r(7) = rt(2, 1);
		r(8) = rt(2, 2);
		t(0) = rt(0, 3);
		t(1) = rt(1, 3);
		t(2) = rt(2, 3);
	}
};

#endif