
int datareceived[5] {0,0,0,0};          // To store byte from phone
int in_byte = 0;
int array_index = 0;
int l_prev=0,r_prev=0; // previous status of mouse left and right click 
void setup() {
Serial.begin (9600); // starts the serial monitor
}
 int height=0,width=0;
void loop() {
  int clicks=0;
  int sensitivity=20;       // you can adjust the sensitivity
  int xpos=0,ypos=0;
if (Serial.available() > 0) {  //recieve byte from phone
  in_byte= Serial.read(); //store in byte into a variable
  if (in_byte == (255)) { // if the variable is 0 stet the array inxed to 0.
    array_index = 0;
  }
  datareceived[array_index] = in_byte;  //store number into array
  array_index = array_index +1;
  
if(datareceived[1]>=110)
xpos=map(datareceived[1],110,172,0,sensitivity);       // When moved right
if(datareceived[1]<=70)
xpos=map(datareceived[1],60,1,0,-sensitivity);        // When moved left
if(datareceived[2]>=110)
ypos=map(datareceived[2],110,255,0,sensitivity);     // When moved down
if(datareceived[2]<=60)
ypos=map(datareceived[2],70,1,0,-sensitivity);       // When moved up


if(datareceived[3]==1 && l_prev==0)      // TO recognise a single button press
  clicks=1;
else if(datareceived[3]==2 && r_prev==0)
clicks=2;
else if(datareceived[3]==3 || datareceived[3]==4)
clicks=datareceived[3];  //  scroll

l_prev=datareceived[3];
r_prev=datareceived[3];

if(xpos!=0 or ypos!=0 or clicks!=0)       // when either of the joystick is moved or the button is pressed or scrolled
{
height=height+ypos;
width=width+xpos;
//Setup resolution according to your PC/Laptop this will follows as mentioned below
//19-inch screen (standard ratio): 1280 x 1024 pixels.
//20-inch screen (standard ratio): 1600 x 1200 pixels.
//22-inch screen (widescreen): 1680 x 1050 pixels.
//24-inch screen (widescreen): 1900 x 1200 pixels.
if(height>=1050)
height=1050;
if(height<=0)
height=0;
if(width>=1920)
width=1920;
if(width<=0)
width=0;
Serial.print(width);
Serial.print(":");
Serial.print(height);
Serial.print(":");
Serial.println(clicks);
clicks=0;
}
}
}
