# OBJ_Auto_Scan

## 1. Environment
>    + Visual Studio 2015 (X64)
>    + QT 5.9.1
>    + PCL 1.8.0
>    + Arduino 1.8.5

## 2. Issue
>	+ QVTK widget refresh point cloud and mouse event is triggered<br/>
>	[![Youtube](https://i.ytimg.com/vi/fcoMvsVMy0s/1.jpg)](https://www.youtube.com/watch?v=fcoMvsVMy0s)<br/>
>	My solution : when the point cloud come, emit signal and use slot to update QVTK widget<br/>
>	Reference : [QT Signal and Slots introduction](https://www.ibm.com/developerworks/cn/linux/guitoolkit/qt/signal-slot/)<br/>
>
>	+ Arduino send data and receive is inconsistent<br/>
>	My solution : Serial.write instead of Serial.print in ino file<br/>
>	Reference : [What is the difference between print and write](https://arduino.stackexchange.com/questions/10088/what-is-the-difference-between-serial-write-and-serial-print-and-when-are-they)<br/>
>
>	+ How to include library to Arduino project used visual studio IDE<br/>
>	My solution : 1. [Arduino IDE for Visual Studio](https://marketplace.visualstudio.com/items?itemName=VisualMicro.ArduinoIDEforVisualStudio)<br/>
>	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. "Add Library" in top menu >> "Install Arduino Library from Zip"<br/>
>	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. "Add Library" in top menu >> "Download and Install Arduino Library" >> click library<br/>

## 3. Use Libraries
>	+ [ArduinoSTL](https://github.com/mike-matera/ArduinoSTL)<br/>