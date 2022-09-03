/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "digital.h"
#include "chip.h"

/* === Macros definitions ====================================================================== */
#ifndef OUTPUT_INSTANCES
    #define OUTPUT_INSTANCES 4
#endif

#ifndef INPUT_INSTANCES
    #define INPUT_INSTANCES 4
#endif

/* === Private data type declarations ========================================================== */
struct digital_output_s {
    uint8_t gpio;
    uint8_t bit;
    bool allocated;
};

struct digital_input_s {
    uint8_t gpio;
    uint8_t bit;
    bool allocated;
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */
static struct digital_output_s instances_output[OUTPUT_INSTANCES] = {0};

static struct digital_input_s instances_input[INPUT_INSTANCES] = {0};

/* === Private function implementation ========================================================= */
digital_output_t DigitalOutputAllocate(void){
    digital_output_t output = NULL;

    for(int index = 0 ; index < OUTPUT_INSTANCES ; index++){
        if(instances_output[index].allocated == false) {
            instances_output[index].allocated = true;
            output = &instances_output[index];
            break;
        }
    }
    return output;
}

digital_input_t DigitalInputAllocate(void){
    digital_input_t input = NULL;

    for(int index = 0 ; index < INPUT_INSTANCES ; index++){
        if(instances_input[index].allocated == false) {
            instances_input[index].allocated = true;
            input = &instances_input[index];
            break;
        }
    }
    return input;
}
/* === Public function implementation ========================================================= */


digital_output_t DigitalOutputCreate(uint8_t gpio, uint8_t bit){

    digital_output_t output = DigitalOutputAllocate();
    if(output){
        output->gpio = gpio;
        output ->bit = bit;
        Chip_GPIO_SetPinState(LPC_GPIO_PORT,output->gpio, output ->bit , false);
        Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,output->gpio, output ->bit, true);
    }

    return output;
}
void DigitalOutputActivate(digital_output_t output){
    
    if(output){
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->gpio, output->bit, true);
    }
}
void DigitalOutputDeactivate(digital_output_t output){
    
     if(output){
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->gpio, output->bit, false);
    }

}
void DigitalOutputToggle(digital_output_t output){
     
     if(output){
        Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->gpio, output->bit);
    }
}

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit){
   
   digital_input_t input = DigitalInputAllocate();
    if(input){
        input->gpio = gpio;
        input ->bit = bit;
        Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, input->gpio, input ->bit, false);
    }
    return input;
}

bool DigitalInputGetState(digital_input_t input){
    bool state = false;
    if(input){
        state = (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, input->gpio, input->bit) == 0);
    }
    return state;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
