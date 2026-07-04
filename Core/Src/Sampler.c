#include "Sampler.h"
static u32 buffer[100];
static u8 idx = 0;
void Sampler_AddSample(u16 sample) { buffer[idx++] = sample; if(idx >= 100) idx = 0; }
u8 Sampler_GetAveragePercent(void) {
    u32 sum = 0;
    for(int i=0; i<100; i++) sum += buffer[i];
    return (u8)((sum / 100) * 100 / 4095);
}
