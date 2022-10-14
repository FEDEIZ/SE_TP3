/** @file main.c

/** \brief Introducing sample to the use of ciaa board with a simple project
 **   
 **  This sample is part of the EITI course called Embedded Systems. This program turn on and off 
 **  different leds of the boards with different buttons

 ** | RV | YYYY.MM.DD | Author      | Changes description                     |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0
 ** 
 **

/* === Headers files inclusions =============================================================== */


#include "bsp.h" /** \brief Here we include the headers to use a HAL module for this board */
#include <stdbool.h>

/* === Macros definitions ====================================================================== */



/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */
/**
 * This program has four different linking leds. 
 * 1) The blue led remain on while the first button is pressed
 * 2) The red led toggle whith consecutive second button event 
 * 3) The yellow led can be turn on with a third button and off with the fourth button
 * 4) The green led blink beetween 5 cicles program 
 */
int main(void) {

    int divisor  = 0;
    //bool current_state, last_state = false;

    board_t board = BoardCreate();

    

    while (true) {

        if (!DigitalInputGetState(board->boton_prueba)) {
            DigitalOutputActivate(board->led_azul);
        } else {
            DigitalOutputDeactivate(board->led_azul);
        }

        
        
        
        if (DigitalInputHasChanged(board->boton_cambiar)) {
            DigitalOutputToggle(board->led_rojo);
        }
        
         
         
         
        if (DigitalInputHasActivated(board->boton_prender)) {
            DigitalOutputActivate(board->led_amarillo);
        }
        
        
        
        if (DigitalInputHasActivated(board->boton_apagar)) {
            DigitalOutputDeactivate(board->led_amarillo);
        }
        

        divisor++;
        if (divisor == 5) {
            divisor = 0;
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
