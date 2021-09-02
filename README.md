# PM_TZXDuino_V1.16
Poor Man's TZXDuino

This is a version of TZX Duino that makes use of two cheap locally available of the shelve shields instead of the custom PCB.

## Requirements:
* Arduino Uno
* Data Logger Shield
* LCD Keypad Shield
* NPN General purpose transistor (I used a BC547B)
* 100Ohm resistor
* 3.5mm mono audio jack
* SD Card

## Step 1 - Modify the LCD Shield
TZX Duino makes use of the Arduino PORTB (GPIO 8,9,10,11,12,13) and the LCD Keypad Shield uses two of these pins, 8 (RS) and 9 (Enable) this means we need to rewire the LCD Keypad shield to use different pins.

Since the buttons on the LCD Keypad Shield uses pin A0 for the 5 buttons I decided to use A1 as "RS" and A2 as "Enable".
I used a small blade to cut the original traces that went to pin 8 and 9 and used some patch wire to connect them to pin A1 and A2.


## Step 2 - Transistor Audio Amplifier
I used this simple circuit ... https://bryanduxbury.com/2012/01/20/one-transistor-audio-amplifier-for-arduino-projects/
1. Connect the 100Ohm resistor between GPIO 9 and the base of the transistor
2. Connect the emitter of the transistor to the center pin of the 3.5mm audio jack
3. Connect the collector of the transistor to +5v
4. Connect the outer side/ground of the 3.5mm audio jack to ground of the arduino

## Step 3 - Done!
* Put the three shields together and plug in an SD Card with your favourite TZX files.






