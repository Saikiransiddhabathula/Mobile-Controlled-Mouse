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
![image](/UI.jpeg)


