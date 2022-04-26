    
#include <stdio.h>
#include <pico/stdlib.h>

void main () {

  stdio_init_all();
  gpio_init(1); // LED Azul
  gpio_init(2); // LED Amarillo
  gpio_init(28);  // Boton 1
  gpio_init(27);   // Boton 2

  gpio_set_dir(1,true);
  gpio_set_dir(28,false);

  gpio_set_dir(2,true);
  gpio_set_dir(27,false);

  while (true) {

    if (gpio_get(28)) {
      gpio_put(1,true);
    }
    else {
      gpio_put(1,false);
    }

    if (gpio_get(27)) {
      if (gpio_get(2)) {
        gpio_put(2,false);
      }
      else {
        gpio_put(2,true);
      }
    }
    sleep_ms(500);
  }
}