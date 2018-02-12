#ifndef STRING_METHOD
#define STRING_METHOD

class StringMethod
{
public:
	/*
	static int GetStringLength(char* dataPtr)
	{
		char* dataTmpPtr = dataPtr;
		int len = 0;
		while (*dataTmpPtr != '\0')
			len++;
		return len;
	}
	*/
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