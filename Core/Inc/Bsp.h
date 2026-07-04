/**
 * @file Bsp.h
 * @brief Interface de acesso ao hardware.
 */
#ifndef BSP_H
#define BSP_H

#include "main.h"
#include "typedefs.h"

void Bsp_Init(void);
uint16_t Bsp_ReadADC(void);
void Bsp_SetPWM(uint8_t ch, uint16_t duty);
void Bsp_UART_Send(char* msg);

#endif
