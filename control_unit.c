#include <settings.h>
int* state(struct ring_bufer* angle,
           struct ring_bufer* angular_speed){
  static uint1_t state[2];
  
