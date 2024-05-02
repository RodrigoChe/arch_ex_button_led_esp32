/******************************************************************************
 * @file   : led.c
 * @brief  : Implementation of the LED component interface.
 * @author : Rodrigo D. Pechoneri
 *****************************************************************************/

#include "led.h"

// Inicializa o LED
return_codes_t led_initialize(led_t *p_led) {
    p_led->led_io.type = digital_output;
    return (digital_io_initialize(&p_led->led_io, p_led->led_state));
}

// Liga o LED
return_codes_t led_turn_on(led_t *p_led) {
    p_led->led_state = digital_io_high;
    return (digital_io_write(&p_led->led_io, p_led->led_state));
}

// Desliga o LED
return_codes_t led_turn_off(led_t *p_led) {
    p_led->led_state = digital_io_low;
    return (digital_io_write(&p_led->led_io, p_led->led_state));
}

// Alterna o estado do LED
return_codes_t led_toggle(led_t *p_led) {
    p_led->led_state = (p_led->led_state == digital_io_high) ? digital_io_low : digital_io_high;
    return (digital_io_write(&p_led->led_io, p_led->led_state));
}

// Inicializa o controlador do LED
return_codes_t led_controller_initialize(led_controller_t *p_controller) {
    p_controller->p_turn_on = led_turn_on;
    p_controller->p_turn_off = led_turn_off;
    p_controller->p_toggle = led_toggle;
    return (return_success);
}