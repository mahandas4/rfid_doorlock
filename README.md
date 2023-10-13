# rfid_doorlock
RFID Scanning verification with servo control
RFID Door Lock Program with Servo Motor, Arduino Uno, and MFRC522

This project is a simple RFID door lock system that can be easily integrated into your home or office. It uses an Arduino Uno, an MFRC522 RFID module, 
and a servo motor to control the locking and unlocking of a door. 
This README will guide you through setting up and using the system.

Table of Contents

Requirements
Installation
Circuit Diagram
Usage
Contributing
License
Requirements

You'll need the following components:

Arduino Uno (or compatible board)
MFRC522 RFID module
Servo motor
Jumper wires
Breadboard or PCB for circuit assembly
5V power supply
RFID cards or key fobs
Installation

Setting up the Arduino IDE:
Make sure you have the Arduino IDE installed on your computer. If you don't, download and install it from Arduino's official website.
Installing Required Libraries:
Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries, and search for the following libraries. Install them if they are not already installed:
MFRC522 by Github Community: This library is essential for working with the RFID module.
Servo by Arduino: This library is required for controlling the servo motor.
Hardware Assembly:
Connect the components according to the circuit diagram provided
Circuit Diagram


Usage

Upload the Arduino Sketch:
Open the RFID_Door_Lock.ino sketch in the Arduino IDE and upload it to your Arduino Uno.
Assign RFID Cards:
Open the Arduino IDE's serial monitor. You should see a message instructing you to scan your RFID card or key fob. Hold your card near the RFID module and scan it. The card's UID (Unique ID) will be displayed on the serial monitor.
Configuring Allowed Cards:
Edit the allowedCards array in the Arduino sketch and add the UID of the cards or key fobs you want to grant access. Use the following format:
cpp
Copy code
  byte allowedCards[][4] = {
    {0x11, 0x22, 0x33, 0x44}, // Replace with your card's UID
    // Add more cards if needed
  };
Test the RFID Door Lock:
Once you have uploaded the sketch and configured the allowed cards, you can test your RFID door lock. Present one of the allowed cards to the RFID module, and the servo motor should unlock the door. Present an unregistered card, and the door should remain locked.
Security Considerations:
Remember to secure your Arduino and RFID module to prevent unauthorized access. You can further enhance security by encrypting communication between the RFID module and the Arduino.
