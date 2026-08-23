#include <stdint.h>
#include "platform.h"
#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

timerHardware_t timerHardware[] = {
    DEF_TIM(TMR4, CH1, PB6,  TIM_USE_OUTPUT_AUTO, 0, 0), // Motor 1
    DEF_TIM(TMR4, CH2, PB7,  TIM_USE_OUTPUT_AUTO, 0, 0), // Motor 2
    DEF_TIM(TMR3, CH3, PB0,  TIM_USE_OUTPUT_AUTO, 0, 0), // Motor 3
    DEF_TIM(TMR3, CH4, PB1,  TIM_USE_OUTPUT_AUTO, 0, 0), // Motor 4
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
