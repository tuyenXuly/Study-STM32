#include "Servo.h"

long map(long x,long in_min,long in_max,long out_min,long out_max){
 return (x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min;
}
void servo_write(Servo *servo,uint8_t goc){
 //goc 0-180
 //CCR 1000-2000 ( tren thuc te thi se tu 544-2400)
  uint16_t ccr =map(goc,0,180,544,2400);
	switch(servo -> channel ){
		case TIM_CHANNEL_1:
		  servo -> htim ->Instance -> CCR1 = ccr;
			break;
		case TIM_CHANNEL_2:
		  servo -> htim  ->Instance -> CCR2 = ccr;
			break;
		case TIM_CHANNEL_3:
		  servo -> htim ->Instance -> CCR3 = ccr;
			break;
		case TIM_CHANNEL_4:
		  servo -> htim ->Instance -> CCR4= ccr;
			break;
	}		
}
void servo_init(Servo *sv,TIM_HandleTypeDef *htim,uint16_t channel){
  sv->htim = htim;
  sv->channel =channel;
	HAL_TIM_PWM_Start(htim,channel);
}