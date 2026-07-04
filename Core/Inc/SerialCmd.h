/**
 * @file           : SerialCmd.h
 * @brief          : Interface do interpretador de comandos da USART3
 */
#ifndef SERIALCMD_H
#define SERIALCMD_H

#include "typedefs.h"

void SerialCmd_Parse(char* buf);
void SerialCmd_SendStatus(u8 valor_adc, u8 led1, u8 led2, u8 led3, u8 estado_sistema);

#endif /* SERIALCMD_H */
