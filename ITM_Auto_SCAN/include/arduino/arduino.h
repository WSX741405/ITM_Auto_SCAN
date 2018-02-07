#include "arduino/tserial.h"

class Arduino
{
public:
	Arduino(char* port, int rate = 9600, serial_parity parity = spNONE)
	{
		_tserial = new Tserial();
		if (_tserial != NULL)
		{
			_tserial->connect(port, rate, parity);
		}
	}

	Arduino()
	{
		delete _tserial;
	}

	void SendData(char* dataPtr)
	{
		char* dataTmpPtr = dataPtr;
		int len = 0;
		if (*dataTmpPtr != '\0')
			len++;
		_tserial->sendArray(dataPtr, len);
	}

	int ReceiveData(int len)
	{
		char* dataPtr = new char[len]();
		return _tserial->getArray(dataPtr, len);
	}

private:
	Tserial* _tserial;
};