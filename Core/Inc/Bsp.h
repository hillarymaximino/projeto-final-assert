/**
 * @file           : Bsp.h
 * @brief          : Interface da Camada de Abstração de Hardware (BSP)
 */
#ifndef BSP_H
#define BSP_H

#include "main.h"
#include "typedefs.h"

#define ADC_TIMEOUT_MS 10
#define UART_TIMEOUT_MS 100
#define TEMPO_1_SEGUNDO 200

void Bsp_Init(void);
uint16_t Bsp_ReadADC(void);
void Bsp_SetPWM(uint8_t ch, uint16_t duty);
void Bsp_UART_Send(char* msg);

u8 Bsp_Check5msFlag(void);
u8 Bsp_Check1sFlag(void);
void Bsp_StartListening(void);

#endif /* BSP_H */
