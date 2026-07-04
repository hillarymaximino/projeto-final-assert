/**
  * @file           : Button.c
  * @brief          : Módulo de controle do estado lógico do sistema
  */
#include "Button.h"

static u8 active = SISTEMA_ATIVO;

void Button_Toggle(void) {
    if (active == SISTEMA_ATIVO) {
        active = SISTEMA_PAUSADO;
    } else {
        active = SISTEMA_ATIVO;
    }
}

u8 Button_GetState(void) {
    return active;
}
