/**
  * @file           : SerialCmd.c
  * @brief          : Módulo interpretador e formatador de comandos da UART
  */
#include "SerialCmd.h"
#include "LedPwm.h"
#include "Button.h"
#include "Bsp.h"
#include <string.h>
#include <stdio.h>

void SerialCmd_Parse(char* buf) {
    // Verifica combinações de Maiúsculas, Minúsculas e Títulos
    if(strstr(buf, "LED1") || strstr(buf, "led1") || strstr(buf, "Led1")) {
        LedPwm_SelectLED(1);
    }
    else if(strstr(buf, "LED2") || strstr(buf, "led2") || strstr(buf, "Led2")) {
        LedPwm_SelectLED(2);
    }
    else if(strstr(buf, "LED3") || strstr(buf, "led3") || strstr(buf, "Led3")) {
        LedPwm_SelectLED(3);
    }
}

void SerialCmd_SendStatus(u8 valor_adc, u8 led1, u8 led2, u8 led3, u8 estado_sistema) {
    static char buffer_texto[150];

    sprintf(buffer_texto, "VALUE: %d%% || LED1: %d%% aceso || LED2: %d%% aceso || LED3: %d%% aceso || STATE: %s\r\n",
            valor_adc, led1, led2, led3, (estado_sistema == SISTEMA_ATIVO) ? "ON" : "OFF");

    Bsp_UART_Send(buffer_texto);
}
