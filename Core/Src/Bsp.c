#include "Bsp.h"
#include <string.h>
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart3;

u16 Bsp_ReadADC(void) {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
    return HAL_ADC_GetValue(&hadc1);
}
void Bsp_SetPWM(u8 ch, u16 duty) {
    TIM_HandleTypeDef *htim = &htim4;
    u32 channel = (ch == 1) ? TIM_CHANNEL_1 : (ch == 2) ? TIM_CHANNEL_2 : TIM_CHANNEL_3;
    __HAL_TIM_SET_COMPARE(htim, channel, duty);
}
void Bsp_UART_Send(char* msg) { HAL_UART_Transmit(&huart3, (u8*)msg, strlen(msg), 100); }
