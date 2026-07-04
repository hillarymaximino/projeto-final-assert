#include "Button.h"
static u8 active = 1;
void Button_Toggle(void) { active = !active; }
u8 Button_GetState(void) { return active; }
