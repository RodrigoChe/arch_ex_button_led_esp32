/******************************************************************************
 * @file   : digital_io_adapter.c
 * @brief  : Implementation of Digital IO Peripheral interface.
 * @author : Rodrigo D. Pechoneri
 *****************************************************************************/
#include <Arduino.h>

#include "digital_io_adapter.h"

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_initialize(p_digital_io_t dio, digital_io_state_t initial_state)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
        if (dio->type == digital_output)
        {
            /* GPIO init configuration structure */
            pinMode(dio->pin, OUTPUT);
            /* GPIO output initial state */
            digitalWrite(dio->pin, (initial_state == digital_io_low) ? LOW : HIGH);
        }
        else if (dio->type == digital_input)
        {
            pinMode(dio->pin, INPUT);
        }
        else
        {
            return (return_error);
        }
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_deinitialize(p_digital_io_t dio)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
        // deinint pin arduino framework?
    }
    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_write(p_digital_io_t dio, digital_io_state_t state)
{
    if ((NULL == dio) || (dio->type != digital_output))
    {
        return (return_invalid_input);
    }
    else
    {
        digitalWrite(dio->pin, state);
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_read(p_digital_io_t dio, digital_io_state_t *p_state)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
        int state = digitalRead(dio->pin);
        *p_state = (state == LOW) ? digital_io_low : digital_io_high;
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_toggle(p_digital_io_t dio)
{
    static uint8_t state = LOW;
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
        if (state == LOW)
        {
            state = HIGH;
            digitalWrite(dio->pin, state);
        }
        else
        {
            state = LOW;
            digitalWrite(dio->pin, state);
        }
    }

    return (return_success);
}

/*** end of file ***/