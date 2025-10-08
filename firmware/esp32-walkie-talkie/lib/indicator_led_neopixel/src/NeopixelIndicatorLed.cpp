#include "NeopixelIndicatorLed.h"

#ifdef LED_TYPE_NEOPIXEL

NeopixelIndicatorLed::NeopixelIndicatorLed()
{
  pStrip_a = new Adafruit_NeoPixel(1, PIN_LED_INDICATOR, NEO_GRB + NEO_KHZ800);
  pStrip_a->begin();
  pStrip_a->show(); 
}

void NeopixelIndicatorLed::set_led_rgb(uint32_t color)
{
  pStrip_a->setPixelColor(0, color);
  pStrip_a->show();
}

#endif
