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

	void SendData(char* dataPtr, int len)
	{
		char* dataTmpPtr = dataPtr;
		_tserial->sendArray(dataPtr, len);
	}

	char* ReceiveData(int len)
	{
		char* dataPtr = new char[len]();
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