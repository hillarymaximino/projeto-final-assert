/**
 * @file           : Sampler.h
 * @brief          : Interface do módulo de amostragem e filtragem analógica
 */
#ifndef SAMPLER_H
#define SAMPLER_H

#include "typedefs.h"

#define MAX_AMOSTRAS 100
#define RESOLUCAO_ADC_MAX 4095

void Sampler_AddSample(u16 sample);
u8 Sampler_GetAveragePercent(void);

#endif /* SAMPLER_H */
