# OBJ_Auto_Scan

## 1. Environment
>    + Visual Studio 2015(X64)
>    + QT 5.9.1
>    + PCL 1.8.0
>    + Arduino 1.8.5

## 2. Issue
>	+ QVTK widget refresh point cloud and mouse event is triggered<br/>
>	[![Youtube](https://i.ytimg.com/vi/fcoMvsVMy0s/1.jpg)](https://www.youtube.com/watch?v=fcoMvsVMy0s)<br/>
>	My solution : when the point cloud come, emit signal and use slot to update QVTK widget<br/>
> Reference : [QT Signal and Slots introduction](https://www.ibm.com/developerworks/cn/linux/guitoolkit/qt/signal-slot/)<br/>
>	+ Arduino communication is error<br/>
>	My solution : Serial.write instead of Serial.print in ino file<br/>
> Reference : [What is the difference between print and write](https://arduino.stackexchange.com/questions/10088/what-is-the-difference-between-serial-write-and-serial-print-and-when-are-they)
