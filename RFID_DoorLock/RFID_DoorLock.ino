
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  
Servo myServo; 
 
void setup() 
{
  Serial.begin(9600);   // Initiate
  SPI.begin();      
  mfrc522.PCD_Init();   
  myServo.attach(3); 
  myServo.write(0); //servo start position
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "[VALID CARD NUMBER HERE]") 
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    delay(300);
    myServo.write(140);
    delay(100);
    myServo.write(0);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(1000);
  }
}
