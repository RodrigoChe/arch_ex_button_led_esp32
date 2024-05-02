/******************************************************************************
* @file   : digital_io_adapter.h
* @brief  : Description of Digital IO peripheral interface.
* @author : Rodrigo D. Pechoneri.
*****************************************************************************/

#ifndef DIGITAL_IO_ADAPTER_H
#define DIGITAL_IO_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef void*          variant_t;
typedef uint8_t        pin_t;
typedef variant_t      port_t;

/*!* @brief Digital output states, High or low*/
typedef enum {
    digital_io_low  = 0U, /*!< DigitalIoLow  */
    digital_io_high = 1U, /*!< DigitalOutput */
} digital_io_state_t;

/*!* @brief Digital IO types */
typedef enum {
    digital_input,  /*!< Digital Input */
    digital_output, /*!< Digital Output */
} digital_io_type_t;

/*!
 * @typedef digital_io_t
 * @brief digital_io_t structure, used internally by the module.
 */
typedef struct {
    port_t          port;   /*!< HAL Port */
    pin_t           pin;    /*!< HAL Pin */
    digital_io_type_t type; /*!< Digital IO Type */
} digital_io_t, *p_digital_io_t;

/*!
 * @typedef return_codes_t
 * @brief Pointer to the DigitalIO structure, used internally by the module.
 */
typedef enum {
    return_success = 0,
    return_error,
    return_invalid_input,
} return_codes_t;

/*!
* @name Initialization and deinitialization
* @{
*/

/*!
 * @brief Initializes the DigitalIO in output mode.
 * @param dio           DigitalIO reference
 * @param initial_state Default output value
 * @return RETURN_SUCCESS or a specific error code.
 */
return_codes_t digital_io_initialize(p_digital_io_t dio, digital_io_state_t initial_state);

/*!
 * @brief Deinitializes the DigitalIO reference.
 * @param dio  DigitalIO reference
 * @return RETURN_SUCCESS or a specific error code.
 */
return_codes_t digital_io_deinitialize(p_digital_io_t dio);

/*!
 * @brief Writes to the digital output.
 * @param dio    DigitalIO reference
 * @param state  State to be written
 * @return RETURN_SUCCESS or a specific error code.
 */
return_codes_t digital_io_write(p_digital_io_t dio, digital_io_state_t state);

/*!
 * @brief Reads the state of a digital output.
 * @param dio    DigitalIO reference
 * @param state  Pointer where the current output state will be saved
 * @return RETURN_SUCCESS or a specific error code.
 */
return_codes_t digital_io_read(p_digital_io_t dio, digital_io_state_t* p_state);

/*!
 * @brief Toggles the output.
 * @param dio    DigitalIO reference
 * @return RETURN_SUCCESS or a specific error code.
 */
return_codes_t digital_io_toggle(p_digital_io_t dio);

/* @} */
#ifdef __cplusplus
}
#endif

#endif /* DIGITAL_IO_ADAPTER_H */
/*** end of file ***/