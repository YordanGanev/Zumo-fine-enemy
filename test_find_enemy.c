#include <stdint.h>
#include <stdbool.h>

#define FRONT_LEFT  1
#define FRONT_RIGHT 2
#define ENEMY_ERROR 10 //cm

#define WAY_ONE 1
#define WAY_TWO 2
#define CLOSE_DIST 3

int detect;
int sensor_values[100];
int front_sens_difference;

int main(){
  detect = WAY_ONE;
  while(1){
    switch(detect){
    case WAY_ONE:
      if(sensor_values[FRONT_LEFT] ^ sensor_values[FRONT_RIGHT])
  			front_sens_difference = sensor_values[FRONT_LEFT] - sensor_values[FRONT_RIGHT];
  		break;
  	case WAY_TWO:
  	  (sensor_values[FRONT_LEFT] ^ sensor_values[FRONT_RIGHT]) ? (front_sens_difference = sensor_values[FRONT_LEFT] - sensor_values[FRONT_RIGHT]) : (front_sens_difference = 0);
      break;
    case CLOSE_DIST:
      if(sensor_values[FRONT_LEFT] ^ sensor_values[FRONT_RIGHT]) && (sensor_values[FRONT_LEFT]<45 )|| sensor_values[FRONT_RIGHT]<45){
        front_sens_difference = sensor_values[FRONT_LEFT] - sensor_values[FRONT_RIGHT]; //or 60
      } else {
        front_sens_difference = 0;
      }
      break;
  }
}
