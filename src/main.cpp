#define I2C0_SDA 21
#define I2C0_SCL 22
#define I2C1_SDA 18
#define I2C1_SCL 19

#include <Arduino.h>
#include <tft_io.hpp>
#include <ssd1306.hpp>
#include <gfx.hpp>
using namespace arduino;
using namespace gfx;

using bus0_t = tft_i2c_ex<0,
                            I2C0_SDA,
                            I2C0_SCL>;
using bus1_t = tft_i2c_ex<1,
                            I2C1_SDA,
                            I2C1_SCL>;

using dsp0_t = ssd1306<128,64,bus0_t,3>;
using dsp1_t = ssd1306<128,64,bus1_t,0>;

using color_t = color<typename dsp0_t::pixel_type>;

dsp0_t dsp0;
dsp1_t dsp1;

void setup()
{
  Serial.begin(115200);
  draw::filled_rectangle(dsp0,dsp0.bounds(),color_t::black);
  draw::filled_rectangle(dsp1,dsp1.bounds(),color_t::white);
}
void loop() {
  
}
