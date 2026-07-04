/**
 * @file           : typedefs.h
 * @brief          : Definições de tipos de dados customizados do projeto
 * @details        : Padroniza e simplifica a declaração de tipos primitivos inteiros
 * de largura fixa, em conformidade com as normas do Laboratório Assert.
 */

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdint.h>

/** @brief Inteiro de 8 bits sem sinal (faixa: 0 a 255) */
typedef uint8_t u8;

/** @brief Inteiro de 16 bits sem sinal (faixa: 0 a 65535) */
typedef uint16_t u16;

/** @brief Inteiro de 32 bits sem sinal (faixa: 0 a 4294967295) */
typedef uint32_t u32;

/** @brief Inteiro de 8 bits com sinal (faixa: -128 a 127) */
typedef int8_t  s8;

/** @brief Inteiro de 16 bits com sinal (faixa: -32768 a 32767) */
typedef int16_t s16;

/** @brief Inteiro de 32 bits com sinal (faixa: -2147483648 a 2147483647) */
typedef int32_t s32;

#endif /* TYPEDEFS_H */
