/**
 * @file LedPwm.h
 * @brief Gerenciamento dos LEDs e PWM.
 */
#ifndef LEDPWM_H
#define LEDPWM_H

#include "typedefs.h"

void LedPwm_SelectLED(u8 led);
void LedPwm_UpdateDuty(u8 percent);
u8 LedPwm_GetDuty(u8 led);

#endif
