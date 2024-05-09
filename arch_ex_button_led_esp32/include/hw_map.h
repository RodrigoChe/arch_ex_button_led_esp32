/**
 * @file   hw_map.h
 * @brief  Hardware pins and peripheral map for ESP32 devkit v1 board.
 * @author Rodrigo D. Pechoneri
 */

#ifndef HW_MAP
#define HW_MAP

#include <Arduino.h>

/**
 * @defgroup HW_MAP Hardware Pin and Peripheral Map
 * @{
 */

/* Digital Outputs */

/**
 * @brief Pin number for the green LED.
 */
#define LED_GREEN_PIN   (4)

/**
 * @brief Pin number for the red LED.
 */
#define LED_RED_PIN     (2)

/* Digital Inputs */

/**
 * @brief Pin number for the first button.
 */
#define BUTTON_1_PIN    (23)

/**
 * @brief Pin number for the second button.
 */
#define BUTTON_2_PIN    (22)

/* @} */

#endif /* HW_MAP */
