/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */


#include "bsp.h"
#include <stdbool.h>

/* === Macros definitions ====================================================================== */



/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

int main(void) {

    int divisor  = 0;
    //bool current_state, last_state = false;

    board_t board = BoardCreate();

    

    while (true) {

        //(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, TEC_1_GPIO, TEC_1_BIT) == 0)
        if (!DigitalInputGetState(board->boton_prueba)) {
            DigitalOutputActivate(board->led_azul);
            //Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, true);
        } else {
            DigitalOutputDeactivate(board->led_azul);
            //Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, false);
        }

        
        /*Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, TEC_2_GPIO, TEC_2_BIT)*/ 
        
        
        if (DigitalInputHasChanged(board->boton_cambiar)) {
            DigitalOutputToggle(board->led_rojo);
            //Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT);
        }
        
         
         
         
         //Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, TEC_3_GPIO, TEC_3_BIT) == 0)
        if (DigitalInputHasActivated(board->boton_prender)) {
            DigitalOutputActivate(board->led_amarillo);
            //Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, true);
        }
        
        
        
        //Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, TEC_4_GPIO, TEC_4_BIT) == 0)
        if (DigitalInputHasActivated(board->boton_apagar)) {
            DigitalOutputDeactivate(board->led_amarillo);
            //Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, false);
        }
        

        divisor++;
        if (divisor == 5) {
            divisor = 0;
            //Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT);
            DigitalOutputToggle(board->led_verde);
        }

        for (int index = 0; index < 100; index++) {
            for (int delay = 0; delay < 25000; delay++) {
                __asm("NOP");
            }
        }
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
