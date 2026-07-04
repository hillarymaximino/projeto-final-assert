#include "LedPwm.h"
#include "Bsp.h"
static u8 duty[3] = {0,0,0};
static u8 active_led = 1;

void LedPwm_SelectLED(u8 led) { active_led = led; }
void LedPwm_UpdateDuty(u8 percent) { duty[active_led-1] = percent; Bsp_SetPWM(active_led, percent * 10); }
u8 LedPwm_GetDuty(u8 led) { return duty[led-1]; }
