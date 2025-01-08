#include <SPI.h>
#include <MFRC522.h>

// write here the UID number in decimal
const byte bonUID[4] = {X, X, X, X};

const int green_led = 7; // green LED pin
const int red_led = 6; // red LED pin
#define RST_PIN  9 // RES pin
#define SS_PIN  10 // SDA (SS) pin

MFRC522 rfid(SS_PIN, RST_PIN);
void setup() {
    SPI.begin();
    rfid.PCD_Init();
    pinMode(green_led, OUTPUT);
    pinMode(red_led, OUTPUT);
}

void loop() {
    int acces_denied = 0; // variable to count the number of denied access
    if (rfid.PICC_IsNewCardPresent()) { // read the card or badge
        if (rfid.PICC_ReadCardSerial()) { 
            for (byte i = 0; i < rfid.uid.size; i++) { // compare the UID with the bonUID
                if (rfid.uid.uidByte[i] != bonUID[i]) {
                acces_denied++;
                }
            }
        
            if (acces_denied == 0) {// acces granted
            // turn on green LED for 2 seconds
                digitalWrite(green_led, HIGH);
                delay(2000);
                digitalWrite(green_led, LOW);            
            }
            
            else { // UID acces_denied
                // turn on red LED for 3 seconds
                digitalWrite(red_led, HIGH);
                delay(3000);
                digitalWrite(red_led, LOW);
            }
        }
    }
}