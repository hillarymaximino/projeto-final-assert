/**
  * @file           : Sampler.c
  * @brief          : Módulo de amostragem e processamento de sinal analógico
  */
#include "Sampler.h"

static u32 buffer[MAX_AMOSTRAS];
static u8 idx = 0;

void Sampler_AddSample(u16 sample) {
    buffer[idx++] = sample;
    if(idx >= MAX_AMOSTRAS) {
        idx = 0;
    }
}

u8 Sampler_GetAveragePercent(void) {
    u32 sum = 0;
    for(int i = 0; i < MAX_AMOSTRAS; i++) {
        sum += buffer[i];
    }
    return (u8)((sum / MAX_AMOSTRAS) * 100 / RESOLUCAO_ADC_MAX);
}
