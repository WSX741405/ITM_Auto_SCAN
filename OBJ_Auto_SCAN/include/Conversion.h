#ifndef CONVERSION
#define CONVERSION

class TypeConversion
{
public:
	static std::string Int2String(int number)
	{
		std::string str = std::to_string(number);
		return str;
	}

	static std::string QString2String(QString qs)
	{
		std::string str = qs.toLocal8Bit().constData();
		return str;
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
};

#endif