#ifndef __SERVO_H
#define __SERVO_H
#include "main.h"
typedef struct{
  TIM_HandleTypeDef *htim;
	uint16_t channel;
	int8_t goc;
}Servo;
void servo_init(Servo *sv,TIM_HandleTypeDef *htim,uint16_t channel);
void servo_write(Servo *servo,uint8_t goc);
#endif
