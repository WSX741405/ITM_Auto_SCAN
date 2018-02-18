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
};

#endif