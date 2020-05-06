#include <TheThingsNetwork.h>

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

//set your APPEUI and your APPkey
const char *appEui = "70B3D57ED002BDA0";
const char *appKey = "A2E0583ED71E1AE0EC90874B64851885";
// Device Address (MSB)
const char *devAddr = "26011C70";
// Network Session Key (MSB)
const char *nwkSKey = { 0xF5, 0x6C, 0x71, 0xE2, 0x02, 0x23, 0xEA, 0x03, 0x90, 0x28, 0x98, 0xDF, 0xE2, 0x1F, 0x3D, 0x47 };
// Application Session Key (MSB)
const char *appSKey = { 0xB6, 0x9E, 0x7B, 0x12, 0x05, 0xF1, 0x46, 0x47, 0xA9, 0x78, 0x77, 0x2F, 0x94, 0x44, 0x40, 0xC7 };

#define loraSerial Serial1
#define debugSerial Serial

//replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

/*// Network Session Key (MSB)
uint8_t NwkSkey[16] = "F56C71E20223EA03902898DFE21F3D47"; // MSB

// Application Session Key (MSB)
uint8_t AppSkey[16] = "B69E7B1205F14647A978772F944440C7"; // MSB

// Device Address (MSB)
uint8_t DevAddr[4] = "26011C70"; // msb*/

// Données à envoyer vers TTN (payload)
unsigned char loraData[4] = {"    "};

// délai entre deux émissions
const unsigned int sendInterval = 300;

TheThingsNetwork ttn(loraSerial, Serial, freqPlan);

void setup() {
  // put your setup code here, to run once:
  loraSerial.begin(57600); //serial port to computer
  debugSerial.begin(9600); //serial port to radio

    //wait a maximum of ten seconds from the Serial monitor
  while (!debugSerial && millis() < 10000);

 

  debugSerial.println("--STATUS");
  ttn.showStatus();
}

void loop() {
  // put your main code here, to run repeatedly:

}
