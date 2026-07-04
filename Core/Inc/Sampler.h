/**
 * @file Sampler.h
 * @brief Responsável pela média aritmética das amostras.
 */
#ifndef SAMPLER_H
#define SAMPLER_H

#include "typedefs.h"

void Sampler_AddSample(u16 sample);
u8 Sampler_GetAveragePercent(void);

#endif
