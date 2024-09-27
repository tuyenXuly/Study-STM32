#include "temperature_cli.h"
#include <stdint.h>
#include "print_cli.h"
#include <stdlib.h>
void getTemp(char **argv,uint8_t argv_num)
{
  print_cli("nhiet do la : %d\n",35);
}
void setTempMax(char **argv,uint8_t argv_num)
{
	if(argv_num != 3 ){
	  print_cli("command error");
		return ;
	}
	uint8_t channel = atoi(argv[1]);
	uint8_t temp = atoi(argv[2]);
	if(channel > 5){
	  print_cli("channel error");
		return ;
	}
	if(temp>100){
	  print_cli("temp error");
		return ;
	}
  print_cli("lenh cai dat nhiet do max channel %d ,temp %d\n");
}
void setTempMin(char **argv,uint8_t argv_num)
{
	if(argv_num != 3 ){
	  print_cli("command error");
		return ;
	}
	uint8_t channel = atoi(argv[1]);
	uint8_t temp = atoi(argv[2]);
	if(channel > 5){
	  print_cli("channel error");
		return ;
	}
	if(temp>100){
	  print_cli("temp error");
		return ;
	}
  print_cli("lenh cai dat nhiet do min channel\n");
}
	