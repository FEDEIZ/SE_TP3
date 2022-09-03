
#ifndef MAIN_H
#define MAIN_H

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
 
/* === Public data type declarations =========================================================== */
typedef struct digital_output_s * digital_output_t;

typedef struct digital_input_s * digital_input_t;
/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

digital_output_t DigitalOutputCreate(uint8_t gpio, uint8_t bit);
void DigitalOutputActivate(digital_output_t output);
void DigitalOutputDeactivate(digital_output_t output);
void DigitalOutputToggle(digital_output_t output);

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit);
bool DigitalInputGetState(digital_input_t input);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif   /* MAIN_H */