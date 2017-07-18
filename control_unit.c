#include <settings.h>

#define ANGLE 0
#define ANGULAR_SPEED 1

uint16_t* state(void)
{      
  static uint16_t state[2]; // state[0] is for absolute angle
                            // state[1] is for angular speed
  state[ANGLE]         = average(angle);
  state[ANGULAR_SPEED] = average(angular_speed);
  return state;
}
uint16_t average (struct ring_bufer *this_bufer){
  uint8_t count = 0;
  while ((count++)<SIZE-1)
