/**************************************************************************/
/*! 
    @file     readMifare.pde
    @author   Adafruit Industries
	@license  BSD (see license.txt)

    This example will wait for any ISO14443A card or tag, and
    depending on the size of the UID will attempt to read from it.
   
    If the card has a 4-byte UID it is probably a Mifare
    Classic card, and the following steps are taken:
   
    - Authenticate block 4 (the first block of Sector 1) using
      the default KEYA of 0XFF 0XFF 0XFF 0XFF 0XFF 0XFF
    - If authentication succeeds, we can then read any of the
      4 blocks in that sector (though only block 4 is read here)
	 
    If the card has a 7-byte UID it is probably a Mifare
    Ultralight card, and the 4 byte pages can be read directly.
    Page 4 is read by default since this is the first 'general-
    purpose' page on the tags.


This is an example sketch for the Adafruit PN532 NFC/RFID breakout boards
This library works with the Adafruit NFC breakout 
  ----> https://www.adafruit.com/products/364
 
Check out the links above for our tutorials and wiring diagrams 
These chips use SPI or I2C to communicate.

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

*/
/**************************************************************************/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

// If using the breakout with SPI, define the pins for SPI communication.
#define PN532_SCK  (2)
#define PN532_MOSI (3)
#define PN532_SS   (4)
#define PN532_MISO (5)
//#define rxPin 0
//#define txPin 1
int counter;

// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield

// Uncomment just _one_ line below depending on how your breakout or shield
// is connected to the Arduino:

// Use this line for a breakout with a software SPI connection (recommended):
//Adafruit_PN532 nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

// Use this line for a breakout with a hardware SPI connection.  Note that
// the PN532 SCK, MOSI, and MISO pins need to be connected to the Arduino's
// hardware SPI SCK, MOSI, and MISO pins.  On an Arduino Uno these are
// SCK = 13, MOSI = 11, MISO = 12.  The SS line can be any digital IO pin.
//Adafruit_PN532 nfc(PN532_SS);

// Or use this line for a breakout or shield with an I2C connection:
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
// also change #define in Adafruit_PN532.cpp library file
   #define Serial SerialUSB
#endif

void setup(void) {
  #ifndef ESP8266
    while (!Serial); // for Leonardo/Micro/Zero
  #endif
  Serial.begin(115200);
  Serial.println("");
  Serial.println("What a Beautiful Day for golfing at: Town and Country Golf Club!");
  Serial.println("It is currently 78 degrees and no rain is expected within the next 5 hours");
  Serial.println("Please select a golf club when ready");
  Serial.println("");
  Serial.println("---Caddie Recommendation---");
  Serial.println("479 Yards, use your 10.0 DEGREE DRIVER");
  Serial.println("");
  pinMode(13, OUTPUT); //Set the LED pin as an output
  pinMode(0,INPUT); //Set the RX pin of the arduino as an input
  pinMode(1,OUTPUT); //Set the TX pin of the arduino as an output
//  Serial.begin(9600); //Start the UART Serial communication
  delay(2000); // Wait 2 seconds - this allows the photon to power up as well before the Arduino trying to take commands

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  //Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
 // Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
 // Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
  
  Serial.println("Waiting for club selection for SHOT #1 of HOLE #1...");
}

int f1;
void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  int yards;
  int yardage;
  int yardage1;
  int yardage2;
  int yardage3;
  char recoClub;
  int putts;
  int score;
	

success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) 
  {
    Serial.println("You have selected your DRIVER for your first shot");
            uint8_t data[16];
    
        // If you want to write something to block 4 to test with, uncomment
    // the following line and this text should be read back in a minute
        //memcpy(data, (const uint8_t[]){ 'a', 'd', 'a', 'f', 'r', 'u', 'i', 't', '.', 'c', 'o', 'm', 0, 0, 0, 0 }, sizeof data);
        // success = nfc.mifareclassic_WriteDataBlock (4, data);

        // Try to read the contents of block 4
        success = nfc.mifareclassic_ReadDataBlock(4, data);
  

//    int counter;
//    if (uidLength == 4)
//    {

//  counter = 0;
 //   while (counter <8)
recoClub="Driver";
     for (counter = 0; counter <= 7; counter++)
      {  
        
 //       counter++;      
        if (counter ==0) 
        {
          Serial.println("");
          Serial.println("------- Caddie Tips -------");
          Serial.println("");
          Serial.print("--Hazards--");
	  Serial.print(13,HIGH);
          Serial.print(1,
          yardage = 579;
          Serial.print("There is water on the left side starting at approximately ");
          Serial.print(yardage);
          Serial.print(" yards ahead.");
          Serial.println("");
          Serial.println("--Recommended Position--");
	        Serial.println("Position A would be a 235 - 255 yard shot on the RIGHT side of the fairway.");
          Serial.println("");
          Serial.println("--Weather Factors--");
          Serial.println("Slight Southern Breeze at 4 MPH -- not a factor");
          Serial.println("");
          delay(5000);
        }
             if (counter == 2)
                {
                  yards = 245;
                  Serial.print("Your DRIVER went:");
                  Serial.println(yards);
                  //Serial.print("this is the 2nd thing");
                  Serial.print("Remaining Yards to the Hole:");
                  Serial.println(yardage - yards);
                  yardage1 = (yardage - yards);
                  Serial.println("Recommended club: 3 Wood");
                  Serial.println("-------- waiting for selection ---------");
//                  recoClub = (recoClub);
//                  Serial.print(recoClub);
                  Serial.println("");
                  delay(5000);
                }
                       else if (counter ==3)
                        {
                          Serial.println("You have selected your: 3 Wood");
                          Serial.println("Position A: Right side of fairway");
                          Serial.print("Target Distance: ");
                          Serial.println(yardage1);
                          Serial.println("-------- computing ---------");
                          Serial.println("");
                          delay(5000);
                        }
                         else if (counter ==4)
                          {
                                yards = 215;
                                Serial.print("Your 3 Wood went:");
                                Serial.println(yards);
                                Serial.print("Remaining Yards to the Hole:");
                                Serial.println(yardage1 - yards);
                                yardage2 = (yardage1 - yards);
                                Serial.println("Recommended club: Pitching Wedge");
                                Serial.println("-------- waiting for selection ---------");
                                delay(5000);
                                Serial.println("");
                          }
                            if (counter == 5)
                            {
                                Serial.println("You have selected your: Lob Wedge");
                                Serial.println("Not the recommended club, dummy");
                                Serial.println("Position A: Green, next to the hole");
                                Serial.print("Target Distance: ");
                                Serial.println(yardage2);
                                Serial.println("-------- computing ---------");
                                Serial.println("");
                                delay(5000);
                            }
                              if (counter == 6)
                              {
                                yards = 101;
                                Serial.print("Your ill-advised decision of the Lob Wedge went:");
                                Serial.println(yards);
                                Serial.print("Remaining Yards to the Hole:");
                                Serial.println(yardage2 - yards);
                                yardage3 = (yardage2 - yards);
                                Serial.println("Recommended club: Putter");
                                Serial.println("-------- waiting for selection ---------");
                                Serial.println("");
                                delay(5000);
                              }
                                if (counter == 7)
                                {
                                  Serial.println("You have selected your: Putter");
                                  Serial.print("Please Enter the number of putts: ");
                                  delay(2000);
                                  Serial.println("2");
                                  delay(2000);
                                  putts = 2;
                                  score = (3 + putts);
                                  Serial.print("Your score on HOLE #1 was: ");
                                  Serial.println(score);
                                  delay(1000);
                                }
                         

                                }
                            
      return 0;
        }
      }
      
    
  
//  }
//}


