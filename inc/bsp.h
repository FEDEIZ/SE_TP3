#ifndef BSP_H
#define BSP_H

/** @file bsp.h
 ** | RV | YYYY.MM.DD | Author      | Changes description                     |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0

/** \brief Headers for the bsp.c file
 **
 ** Declaring the type struct for the board whith his pointer and boardCreate function
 **

 ** @{ */

/* === Headers files inclusions ================================================================ */

#include "digital.h"
#include "ciaa.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
 
/* === Public data type declarations =========================================================== */
 

typedef struct board_s {
 digital_output_t led_azul;
 digital_output_t led_rojo;
 digital_output_t led_amarillo;
 digital_output_t led_verde;

digital_input_t boton_prueba;
digital_input_t boton_cambiar;
digital_input_t boton_prender;
digital_input_t boton_apagar;
} const * const board_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

board_t BoardCreate(void);


/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif   /* BSP_H */