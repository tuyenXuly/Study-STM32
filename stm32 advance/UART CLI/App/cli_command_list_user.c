#include "cli_type.h"
#include "temperature_cli.h"
#include <stddef.h>
cli_command_t list_command[]={
   {"getTemp",getTemp,"doc nhiet do"},
	 {"setTempMax",setTempMax,"cai dat nguong nhiet do lon nhat"},
	 {"setTempMin",setTempMin,"cai dat nguong nhiet do nho nhat"},
   {NULL , NULL , NULL}
};