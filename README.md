# PM_TZXDuino_V1.16
Poor Man's TZXDuino

This is a version of TZXDuino (https://www.facebook.com/Arduitape) that makes use of an Arduino Uno and two cheap off the shelf shields, instead of the custom PCB, It also requires minimal soldering.

## Requirements:
* Arduino Uno
* Data Logger Shield
* LCD Keypad Shield
* NPN General purpose transistor (I used a BC547B)
* 100Ohm resistor
* 3.5mm mono audio jack

## Step 1 - Modify the LCD Shield
TZXDuino makes use of the Arduino PORTB (GPIO 8,9,10,11,12,13) and the LCD Keypad Shield uses two of these pins, 8 (RS) and 9 (Enable) this means we need to rewire the LCD Keypad shield to use different pins.

Since the buttons on the LCD Keypad Shield uses pin A0 for the 5 buttons I decided to use A1 as "RS" and A2 as "Enable".
I used a small blade to cut the original traces that went to pin 8 and 9 and used some patch wire to connect them to pin A1 and A2.
![pmtzxduino1](https://user-images.githubusercontent.com/2756871/131915963-b6185e3b-1a44-49a5-a702-0ea02403f3ca.png)

## Step 2 - Transistor Audio Amplifier
1. Connect the 100Ohm resistor between GPIO 9 and the base of the transistor. (note: in the image below I used two resistors to make up the 100ohm as I did not have a 100ohm resistor in stock)
2. Connect the emitter of the transistor to the center pin of the 3.5mm audio jack
3. Connect the collector of the transistor to +5v
4. Connect the outer side/ground of the 3.5mm audio jack to ground of the arduino
![pcmtzxduino3](https://user-images.githubusercontent.com/2756871/131916535-8ab56604-9297-4eac-8e45-49abd296ad84.jpg)
![pmtzxduino2](https://user-images.githubusercontent.com/2756871/131916600-62ae0ee9-b4d3-4acd-8034-e7aa4f751124.jpg)

## Step 3 - Done!
* Connect the Arduino and the two shields together 
* Upload the TZXDuino sketch from this repository
* Pop in an SD Card with your favourite TZX files

I have tested multiple games for the ZX Spectrum and ZX81 and they loaded 100% every time.

You can get the ZXDuino instruction manual and additional information from http://arduitape.blogspot.com/ .

![pmtzxduino4](https://user-images.githubusercontent.com/2756871/131917648-020da501-8fe6-46c1-8695-878b9354f6f6.jpg)
