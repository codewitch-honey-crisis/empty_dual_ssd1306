#define I2C_SDA 21
#define I2C_SCL 22

#include <Arduino.h>
#include <tft_io.hpp>
#include <ssd1306.hpp>
#include <gfx.hpp>
using namespace arduino;
using namespace gfx;

using bus_t = tft_i2c_ex<0,
                            I2C_SDA,
                            I2C_SCL>;

using dsp0_t = ssd1306<128,64,bus_t,3,1,0x3d>;
using dsp1_t = ssd1306<128,64,bus_t,0,1,0x3c>;

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
