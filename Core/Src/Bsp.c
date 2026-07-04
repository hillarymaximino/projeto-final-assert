/**
  * @file           : Bsp.c
  * @brief          : Camada de Abstração de Hardware (BSP)
  */
#include "Bsp.h"
#include "Button.h"
#include "SerialCmd.h"
#include <string.h>

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart1;

static volatile u8 flag_5ms = 0;
static volatile u8 flag_1s = 0;
static volatile u32 counter_1s = 0;

static uint8_t rx_data;
static char rx_buffer[20];
static uint8_t rx_index = 0;

u16 Bsp_ReadADC(void) {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, ADC_TIMEOUT_MS);
    return HAL_ADC_GetValue(&hadc1);
}

void Bsp_SetPWM(u8 ch, u16 duty) {
    TIM_HandleTypeDef *htim = &htim4;
    u32 channel = (ch == 1) ? TIM_CHANNEL_1 : (ch == 2) ? TIM_CHANNEL_2 : TIM_CHANNEL_3;
    __HAL_TIM_SET_COMPARE(htim, channel, duty);
}

void Bsp_UART_Send(char* msg) {
    HAL_UART_Transmit(&huart1, (u8*)msg, strlen(msg), UART_TIMEOUT_MS);
}

u8 Bsp_Check5msFlag(void) {
    if(flag_5ms) {
        flag_5ms = 0;
        return 1;
    }
    return 0;
}

u8 Bsp_Check1sFlag(void) {
    if(flag_1s) {
        flag_1s = 0;
        return 1;
    }
    return 0;
}

void Bsp_StartListening(void) {
    HAL_UART_Receive_IT(&huart1, &rx_data, 1);
}

// NOVA FUNÇÃO À PROVA DE BALAS (Não precisa de Enter do Termite)
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {
        rx_buffer[rx_index++] = rx_data;
        rx_buffer[rx_index] = '\0'; // Fecha a string automaticamente

        // Manda analisar instantaneamente, sem esperar o "Enter" chegar
        if (strstr(rx_buffer, "LED1") || strstr(rx_buffer, "LED2") || strstr(rx_buffer, "LED3") ||
            strstr(rx_buffer, "led1") || strstr(rx_buffer, "led2") || strstr(rx_buffer, "led3")) {

            SerialCmd_Parse(rx_buffer); // O comando foi validado e acionado!
            rx_index = 0;               // Esvazia o buffer para o próximo comando
            rx_buffer[0] = '\0';
        }
        else if (rx_index >= 19 || rx_data == '\n' || rx_data == '\r') {
            rx_index = 0; // Limpa se o usuário digitar lixo
            rx_buffer[0] = '\0';
        }

        // Rearma o ouvido para a próxima letra
        HAL_UART_Receive_IT(&huart1, &rx_data, 1);
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM6) {
        flag_5ms = 1;
        counter_1s++;
        if (counter_1s >= TEMPO_1_SEGUNDO) {
            flag_1s = 1;
            counter_1s = 0;
        }
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_1) {
        Button_Toggle();
    }
}
