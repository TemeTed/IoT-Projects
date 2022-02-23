
# ESP based IoT-Projects
                                
  The project uses ESP module Arduino Uno for controlling and monitoring actuators using a web interface. The program has two portions: one for the Arduino and the other for ESP module.           
                
                Instruction on How to use the ESP8266-1 Wi-Fi module
 The pin lay out diagram for the module is as shown in the figure
![image](https://user-images.githubusercontent.com/46483761/155377738-afde1bab-97ac-44f0-ab6b-afd2387bbd92.png)

Step 1: Setting up the Arduino IDE
 -Open file – preferences and paste the following link in the additional plate manager URL field
          http://arduino.esp8266.com/stable/package_esp8266com_index.json
          
-Go to tools-board-board manager write ESP8266, and download the required packages
If successfully installed the ESP will show up in the board list

Step 2: Setting up the board

-Connect the module with Arduino as shown in the figure below

![image](https://user-images.githubusercontent.com/46483761/155378165-3d4781d2-d08e-41a0-902b-4c5173db1747.png)

The reset pin of Arduino is grounded so that it functions only as a programmer board for the ESP
module.
It is recommended to use a separate 3.3v source , as the Wi-Fi module requires more power
than the UNO can provide

Step3: Checking the board (only for new out of package modules)

-Install a blank sketch on the Arduino board

-Connect the ESP module as shown in the figure above

-Open the serial monitor and select NL & CR

-Select the baud rate either 115200 or 9600 depending on the setting of the firmware

-On the serial monitor write the command AT. If the response is OK then the module is working fine
Open examples-ESP8266

Step 4: Uploading programs to the board

-Press the push button and while it is pressed, connect the Arduino to the USB port of the PC.

-When the boards are up and running release the push button. This sets the ESP module in a
programming mode.

-Open the IDE and select Generic ESP8266 module from the tools menu-Set the Builtin LED to 1, in the tools menu and select the right port number

-Open Examples-ESP8266-Blink

-Press the push button switch and upload the sketch. Release the switch when the code is fully
uploaded.

-If everything goes well the blue LED on the ESP board blinks at a regular interval

That's all, the ESP module is now set up and ready to go!


