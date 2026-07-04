/**
 * @file           : LedPwm.h
 * @brief          : Interface de gerenciamento de canais e potência dos LEDs
 */
#ifndef LEDPWM_H
#define LEDPWM_H

#include "typedefs.h"

#define MULTIPLICADOR_PWM 10

void LedPwm_SelectLED(u8 led);
void LedPwm_UpdateDuty(u8 percent);
u8 LedPwm_GetDuty(u8 led);

#endif /* LEDPWM_H */
