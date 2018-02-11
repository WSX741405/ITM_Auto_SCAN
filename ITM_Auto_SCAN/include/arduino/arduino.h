#ifndef ARDUINO
#define ARDUINO

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

	~Arduino()
	{
		delete _tserial;
	}

	void SendData(char data)
	{
		_tserial->sendChar(data);
	}

	void SendData(char* dataPtr, int len)
	{
		_tserial->sendArray(dataPtr, len);
	}

	char* ReceiveData()
	{
		char* dataPtr = new char[2]();
		dataPtr[1] = '\0';
		dataPtr[0] = _tserial->getChar();
		return dataPtr;
	}

	char* ReceiveData(int len)
	{
		char* dataPtr = new char[len + 1]();
		dataPtr[len] = '\0';
		_tserial->getArray(dataPtr, len);
		return dataPtr;
	}

	int ReceiveDataNumberOfBytes()
	{
		return _tserial->getNbrOfBytes();
	}

private:
	Tserial* _tserial;
};

#endif