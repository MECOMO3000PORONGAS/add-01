#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  stdio_init_all();

  const int ledazul = 1;
  const int ledamarillo = 2;
  const int pulsador1 = 28;
  const int pulsador2 = 27;
  gpio_init (ledazul);
  gpio_set_dir (ledazul, true);

  gpio_init (ledamarillo);
  gpio_set_dir (ledamarillo, true);

  gpio_init (pulsador1);
  gpio_set_dir (pulsador2, true);

  gpio_init (pulsador2);
  gpio_set_dir (pulsador2, true);

  while(true) {
    
    if (gpio_get (pulsador2)) {
      if (gpio_get(ledazul)) {
        gpio_put(ledazul,false);
      }
      else {
        gpio_put(ledazul,true);
      }
      
    }
    
    if (gpio_get(pulsador1)) {
      gpio_put(ledamarillo, true);
    }
    else {
      gpio_put(ledamarillo, false);
    }

    sleep_ms(250);
  }
}