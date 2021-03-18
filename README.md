[![MCHP](images/microchip.png)](https://www.microchip.com)

# Getting Started with Configurable Custom Logic (CCL) Examples (Microchip Studio)

  This repository contains examples of bare metal source code for the Configurable Custom Logic (CCL) as described in [TB3218-Getting Started with Configurable Custom Logic (CCL)](https://ww1.microchip.com/downloads/en/Appnotes/TB3218-Getting-Started-with-CCL-DS90003218.pdf) document from Microchip. The repository contains a Microchip Studio Solution with multiple projects inside:

* [<strong>Logic AND Gate:</strong>](Logic_AND_Gate) This use case shows how to configure and use the CCL peripheral to implement an AND gate with three inputs (for more details, see [<strong>Logic AND Gate</strong>](Logic_AND_Gate)).
* [<strong>State Decoder:</strong>](State_Decoder) This use case shows how to configure the CCL peripheral to decode the presence of the `b'10110` pattern on the input pins. A circuit composed of LUT0 and LUT1 is implemented to trigger its output when the inputs are in the form of the given pattern (for more details, see [<strong>State Decoder</strong>](State_Decoder)).
* [<strong>SR Latch:</strong>](SR_Latch) This use case shows how to use the CCL combinational and sequential logic to implement an SR latch. This functionality is obtained by using two adjacent LUTs connected through a sequential logic block (for more details, see [<strong>SR Latch</strong>](SR_Latch)).

## Related Documentation
More details and code examples on the ATMEGA4809 can be found at the following links:
- [TB3218 - Getting Started with Configurable Custom Logic (CCL)](https://ww1.microchip.com/downloads/en/Appnotes/TB3218-Getting-Started-with-CCL-DS90003218.pdf)
- [ATMEGA4809 Product Page](https://www.microchip.com/wwwproducts/en/ATMEGA4809)
- [ATMEGA4809 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=atmega4809)
- [ATMEGA4809 Project Examples in START](https://start.atmel.com/#examples/ATMEGA4809XplainedPro)


## Software Used
- Microchip Studio 7.0.2542 or newer [(https://www.microchip.com/mplab/microchip-studio)](https://www.microchip.com/mplab/microchip-studio)
- ATmega_DFP 1.5.362 or newer Device Pack


## Hardware Used
- ATMEGA4809 Xplained Pro [(ATMEGA4809-XPRO)](https://www.microchip.com/developmenttools/ProductDetails/ATMEGA4809-XPRO)
