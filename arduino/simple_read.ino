#include "SPI.h"
#include "MFRC522.h"

#define RST_PIN  9 // RES pin
#define SS_PIN  10 // SDA (SS) pin

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
   Serial.begin(9600);
   SPI.begin();
   mfrc522.PCD_Init();
   delay(4);
   mfrc522.PCD_DumpVersionToSerial();
   Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
   // Look for new cards
   if ( ! rfid.PICC_IsNewCardPresent()) {
      return;
   }

   if ( ! rfid.PICC_ReadCardSerial()) {
      return;
   }

   // Show some details of the PICC (that is: the tag/card)
   rfid.PICC_DumpToSerial(&(rfid.uid));
}