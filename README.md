# arch_ex_button_led_esp32
This repo contains an example of using a layered firmware architecture made on bare metal using the Arduino framework for an ESP32 microcontroller present in DOIT devkit v1 board.

# Application that Reads Buttons and Controls LEDs to Exemplify the Use of Decoupled Layered Architecture

## Introduction
In this application, we have two buttons and two LEDs connected to GPIO pins. The buttons' reading is performed periodically around every 10 ms. One button controls turning one of the LEDs on or off, while the other button, when pressed once, lights up the second LED. Pressing it twice turns off the LED; pressing it three times toggles the LED state every 100 ms, and pressing it four times turns off the toggle state of the LED.

For the implementation of this example, we used an ESP32 MCU, DOIT devkit v1 hardware platform, Arduino framework, C language, documentation in Doxygen style, and some adapted design patterns. Specifically, Facade, State, and an extremely simple state machine in the main application or main code. Adapters were built to encapsulate the low-level framework, GPIO drivers, or HAL (Hardware Abstraction Layer) so that the application becomes as independent as possible from the hardware platform used.

From these adapters, software components are built which abstract the buttons and LEDs into independent modules. The application utilizes these components and the hardware map that defines pins and ports to achieve the final firmware behavior.

The goal here is to demonstrate with something simple that it's possible to build a testable application, emulating object-oriented programming in C, and that works independently of the hardware. Allowing the use of mocks for testing the application (this part is not yet implemented).

## Architectural scheme 
The project has the following architecture:

![Figure 1](arch_ex_button_led_esp32/docs/figs/layersFig.png)

![Figure 2](arch_ex_button_led_esp32/docs/figs/firmwareOrganigram.png)

The project file structure is as follows:
```shell
.
├── arch_ex_button_led_esp32
│   ├── docs
│   │   ├── Doxyfile
│   │   ├── figs
│   │   ├── html
│   │   └── latex
│   ├── include
│   │   ├── hw_map.h
│   │   └── README
│   ├── lib
│   │   ├── adpter_digitalio
│   │   │   ├── digital_io_adapter.c
│   │   │   └── digital_io_adapter.h
│   │   ├── component_button
│   │   │   ├── button.c
│   │   │   └── button.h
│   │   ├── component_led
│   │   │   ├── led.c
│   │   │   └── led.h
│   │   └── README
│   ├── platformio.ini
│   ├── src
│   │   ├── main.cpp
│   │   └── output
│   └── test
│       └── README
└── README.md
```

Where:

- `adapter_digitalio`: Adapters for the common interface of the used hardware.
- `component_button`: Abstraction components for a button.
- `component_led`: Software component for LED abstraction.
- `hw_map.h`: Hardware pin mapping.

To access the code documentation, go to the directory `docs/html/index.html`.

## Conclusion
As soon as possible test and mocks will be add.
Feel free to copy, modify, and share this example. Don't forget to mention the original source.

Happy coding.

