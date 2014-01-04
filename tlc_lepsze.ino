#include <Tlc5940.h>

/*
 *  TLC5940, arduino UNO
 *
 *      OUT1 |1     28| OUT channel 0
 *      OUT2 |2     27|-> GND (VPRG)
 *      OUT3 |3     26|-> SIN (pin 11)
 *      OUT4 |4     25|-> SCLK (pin 13)
 *        .  |5     24|-> XLAT (pin 9)
 *        .  |6     23|-> BLANK (pin 10)
 *        .  |7     22|-> GND
 *        .  |8     21|-> VCC (+5V)
 *        .  |9     20|-> 2K Resistor -> GND
 *        .  |10    19|-> +5V (DCPRG)
 *        .  |11    18|-> GSCLK (pin 3)
 *        .  |12    17|-> SOUT
 *        .  |13    16|-> XERR
 *      OUT14|14    15| OUT channel 15
 *      
 */
 
void setup() {
  Tlc.init();

}

void loop() {
    int direction = 1;
      for (int channel = 0; channel < NUM_TLCS * 16; channel += direction) {

    
    Tlc.clear();

  
    if (channel == 0) {
      direction = 1;
    } else {
      Tlc.set(channel - 1, 1000);
    }
    Tlc.set(channel, 4095);
    if (channel != NUM_TLCS * 16 - 1) {
      Tlc.set(channel + 1, 1000);
    } else {
      direction = -1;
    }

    
    Tlc.update();

    delay(75);
  }
  
}
