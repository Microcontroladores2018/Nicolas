#include "utils/commandline.h"
//#include "AccelGyro.h"

extern CommandLine cmdline;

extern int g;
extern int speed;

uint16_t cmd_info(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "Microcontroladores 2017\r\n");
	} else {
		size+=sprintf(buffer+size, "Syntax: info\r\n");
	}
	return size;
}


uint16_t cmd_getVel(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "%d\r\n",speed);
	} else {
		size+=sprintf(buffer+size, "Syntax: getVel\r\n");
	}
	return size;
}



uint16_t cmd_get(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "%d/%d\r\n",g,speed);
	} else {
		size+=sprintf(buffer+size, "Syntax: getAccelZ\r\n");
	}
	return size;
}


CommandLine cmdline({"info","get","getVel"},
					{cmd_info,cmd_get,cmd_getVel});
