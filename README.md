# **Mobile-Controlled-Mouse**
The purpose of this project titled “Mobile-Controlled Mouse”  is to solve the problems that raise while using normal optical/laser mouse like breakdown of wire, the optical eye may be blocked.
This can be controlled right away with your smartphone with an application built using MIT app inventor.
Which neither require any subscription to use it nor any internet connection. 

## **Abstract**
Since the interior of the mouse is dirty, an optical-mechanical mouse (mouse with a ball) can not function properly.
The optical eye can be blocked if the optical mouse (LED or laser) exhibits abnormal activity.
Hair or fuzz will obstruct the optical sensor on the mouse's foot, causing it to malfunction.
We still have to deal with other issues with mice, such as wire breakage and wireles. 

As a result, my Mobile-Controlled mouse can assist in manipulating laptop or computer screens through a smartphone application.
I'm using a smartphone as a mouse to monitor the displays of a laptop or computer.
This mouse can do everything a normal mouse can do, including scrolling, left and right clicking, and moving the cursor.

## **Requirements** 
**Hardware components**
 * Arduino UNO
 * Bluetooth Module
 * Jumper wires

**Software components**
 * Arduino Ide
 * Mouse module, pyserial module
 * IDLE (Python GUI)
 * MIT app inventor Bluetooth mouse controller application

Above application can be downloded by using the this drive link: [Download](https://drive.google.com/drive/folders/1VsLh-TkJjElhF4hPCY5LZbQA6xE7NChF?usp=sharing)

## **Working**

The project involves a smartphone application that sends the joystick's x and y axis data, scroll status, left and right click status using Bluetooth to the Arduino Uno connected to the HC-05 Bluetooth module. These data upon reception to the Arduino is manipulated to make changes in the current cursor's position to obtain a new position. The resulting data along with scroll and button status is then printed as the output that is recognized to be read by the Python sketch. The Python sketch is made to execute mouse actions using the mouse module.


![image](/Flowchart.jpg)

The smartphone application is created using the MIT-App Inventor. Creating the app is simple as you just need to add the desired blocks to build your required application. I have referred to the Tabletop robotics tutorial on making them. The main screen of the application is as follows-
Before sending the main information to the HC-05 module, the application first sends a one byte number(255) to denote the start of information. The sequence of data transfer is as follows-
1. Send '255' to denote start
2. Send 1 byte joystick x-axis value
3. Send 1 byte joystick y-axis value
4. Send status of left click, right click button and scroll status(1 byte).
The data from the application is sent every 20 milliseconds to the Arduino UNO.
<img src="/UI1.jpeg" width="300" height="500"/>

## **Arduino Side**

The data bytes from the Application is received by the Arduino with the help of HC-05 Bluetooth module. The Arduino contains the current coordinates of the cursor where The x coordinates range form 0 to 1400 and the y coordinates range from 0 to 1050. I have obtained these extreme coordinates form the python function mouse.get_position() that returns the coordinates when the cursor is moved (not used in the main sketch).
Based on the data received upon moving the joystick, the current cursor's position (x and y coordinates) is then added/subtracted with the data received by the application to move the cursor to the new desired coordinate. The final data is then printed on the Serial monitor in sequence given below.

![image](/Arduinoside.jpg)

## **Arduino Sketch**

Sketch of pin-connections between Arduino and HC-05 Bluetooth Module
![image](/pin_diagram.png)

## **Steps**

### **Step1**
To Upload the Arduino code you can use Online Arduino IDLE or install the Arduino in your device.
Upload the Arduino code into the Arduino using data transfer cable, Make sure the TX and RX pins are unplug from arduino board while uploading the code into Arduino.

### **Step2**
Install the Mouse_Bluetooth application in your Smartphone, You can download the apk file from this link -[Mouse_application](https://drive.google.com/drive/folders/1VsLh-TkJjElhF4hPCY5LZbQA6xE7NChF?usp=sharing)

### **Step3**
Open the Mouse_application and connect the HC-05 device via Bluetooth.
**Note**: Make sure the HC-05 Bluetooth module is already paired with your smartphone device, only then you can select it from the list of paired devices.

### **Step4**
Run the Python Sketch in your PC/Laptop using Python IDLE(GUI).
