#include <NeoPixelBus.h>
#include "ESP8266WiFi.h"

// Number of leds
const uint16_t PixelCount = 16;

// Pin where data cable is connected
const uint8_t PixelPin = D1;

NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> strip(PixelCount, PixelPin);

// Define a color, 0 is min, 128 is max
// It's RVB
RgbColor pink(128, 10, 75);
HslColor hslPink(pink);


void setup() {
  // Shutdown WIFI
  WiFi.forceSleepBegin();

  // Start the led strip
  strip.Begin();
  strip.Show();
}


void loop() {

  // For every led, set the pink color
  for (int i = 0; i < PixelCount; i++) {
    strip.SetPixelColor(i, hslPink);
  }

  // Push the datas
  strip.Show();

  // Wait then loop again
  delay(1000);
}
