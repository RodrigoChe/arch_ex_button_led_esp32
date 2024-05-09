//#include <Arduino.h>
#include "button.h"
#include "hw_map.h"
#include "led.h"

led_t ledGreen;
led_t ledRed;
led_controller_t ledActions;

button_t pushButton;
button_t pushButton2;

bool g_button_pressed = false;
uint32_t g_button_polling_freq = 0;
uint32_t g_update_led_freq = 0;
uint8_t g_pressured_counting = 0;

void setup() {
    ledGreen.led_io.pin = LED_GREEN_PIN;
    led_initialize(&ledGreen);

    ledRed.led_io.pin = LED_RED_PIN;
    led_initialize(&ledRed);

    led_controller_initialize(&ledActions);

    pushButton.button_io.pin = BUTTON_1_PIN;
    button_initialize(&pushButton);

    pushButton2.button_io.pin = BUTTON_2_PIN;
    button_initialize(&pushButton2);

    Serial.begin(9600); // opens serial port, sets data rate to 115200 bps
}

void loop() {
    g_button_polling_freq++;

    if (g_button_polling_freq == 1000) {
        g_button_pressed = button_is_pressed(&pushButton);
        if (g_button_pressed == true) {
            g_pressured_counting++;
        }
        g_button_pressed= button_is_pressed(&pushButton2);
        if (g_button_pressed  == true) {
            ledActions.toggle(&ledRed);
        }
        g_button_polling_freq = 0;
    }

    g_update_led_freq++;

    if (g_update_led_freq == 100000) {
        switch (g_pressured_counting) {
            case 1:
                ledActions.turn_on(&ledGreen);
            break;
            case 2:
                ledActions.turn_off(&ledGreen);
            break;
            case 3:
                ledActions.toggle(&ledGreen);
            break;
            case 4:
                ledActions.turn_off(&ledGreen);
                g_pressured_counting = 0;
            break;
            default:
            break;
        }
        g_update_led_freq = 0;
    }
}
