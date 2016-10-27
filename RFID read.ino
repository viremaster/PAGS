#include <arduino.h>
#include <rfid.h>
#include <MFRC522.h>
#include <SPI.h>
#include <MATH.h>

#define RST_PIN   9     // Configurable, see typical pin layout above
#define SS_PIN    10    // Configurable, see typical pin layout above

MFRC522 mfrc(SS_PIN,RST_PIN);

void setup() {
   Serial.begin(9600);
   pinMode(6, OUTPUT);
   sound(50);
   sound(50);
   sound(50);
   SPI.begin();    
   mfrc.PCD_Init(); /*initializes the PCD */
}

void loop() {
  char UID[4];
  char ID = "17619822231";
  if ( ! mfrc.PICC_IsNewCardPresent() || ! mfrc.PICC_ReadCardSerial() ) {
    delay(50);
    return;}
  sound(50);
  Serial.print(F("Card ID:"));
  for (byte i = 0; i < mfrc.uid.size; i++) {
    Serial.print(mfrc.uid.uidByte[i],DEC);
    UID[i] = fabs((mfrc.uid.uidByte[i],DEC));

    }
      Serial.print("  ");
      Serial.print(UID[0],HEX);
      Serial.print(UID[1],HEX);
      Serial.print(UID[2],HEX);
      Serial.print(UID[3],HEX);
      if (UID == ID){
      sound(50);
      sound(50);
      sound(50);
      sound(50);
  } 
  Serial.println();
  sound(50);
  delay(2000);
}

void sound(unsigned char delayms){
  analogWrite(6, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(6, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  
