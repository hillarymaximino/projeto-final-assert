#include "SerialCmd.h"
#include "LedPwm.h"
#include <string.h>
void SerialCmd_Parse(char* buf) {
    if(strstr(buf, "LED1")) LedPwm_SelectLED(1);
    else if(strstr(buf, "LED2")) LedPwm_SelectLED(2);
    else if(strstr(buf, "LED3")) LedPwm_SelectLED(3);
}
