/**
 * @file           : Button.h
 * @brief          : Interface da lógica de estado do botão do sistema
 */
#ifndef BUTTON_H
#define BUTTON_H

#include "typedefs.h"

#define SISTEMA_ATIVO 1
#define SISTEMA_PAUSADO 0

void Button_Toggle(void);
u8 Button_GetState(void);

#endif /* BUTTON_H */
