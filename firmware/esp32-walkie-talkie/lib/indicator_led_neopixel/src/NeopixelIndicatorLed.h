#pragma once

#include <Adafruit_NeoPixel.h>

#include "IndicatorLed.h"

#ifdef LED_TYPE_NEOPIXEL

class NeopixelIndicatorLed : public IndicatorLed
{
private:
  Adafruit_NeoPixel *pStrip_a;
  
protected:
  void set_led_rgb(uint32_t color);

public:
  NeopixelIndicatorLed();
};

#endif
