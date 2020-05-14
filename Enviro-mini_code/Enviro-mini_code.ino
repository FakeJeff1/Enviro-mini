/**************************************************************************
Enviro-mini Code rev 1.0
 **************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
const int dht_pin = 2;
DHT dht11(dht_pin, DHT11);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
}

void loop() {
  display.clearDisplay();
  //clear display
  beginInterface();
  //reads sensor
  float temp1 = dht11.readTemperature();
  float humid1 = dht11.readHumidity();

//value positions
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(80,20);
  display.print((int)temp1);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(80,40);
  display.print((int)humid1);
  
  display.display();
  delay(20000); //currently updates the screen every 20 seconds
}

void beginInterface(void){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(9,0);
  display.print("ENVIRONMENT SENSOR");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,20);
  display.print("TEMP:");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(110,20);
  display.print("C");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(110,40);
  display.print("%");
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,40);
  display.print("HUMID:");
  
  display.display();
}
