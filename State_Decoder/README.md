[![MCHP](./../images/microchip.png)](https://www.microchip.com)

# State Decoder

In this code example, the CCL's LUT0 and LUT1 are configured to decode the presence of the `b'10110` pattern on the input pins. A circuit composed of LUT0 and LUT1 is implemented to trigger its output when the inputs are in the form of the given pattern.

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

## Setup
The ATMEGA4809 Xplained Pro Development Board is used as test platform.

<br><img src="../images/atmega4809_xplainedpro.jpg" height="300">

The following configurations must be made for this project:

System clock: 3.33 MHz (default)

CCL:
-   CCL enabled
-   LUT0:
    -   LUT0-IN0: IN0
    -   LUT0-IN1: IN1
    -   LUT0-IN2: LINK
    -   Truth table = 0x40
    -   Output enabled
    -   LUT0 enabled
-   LUT1:
    -   LUT1-IN0: IN0
    -   LUT1-IN1: IN1
    -   LUT1-IN2: IN2
    -   Truth table = 0x20
    -   LUT1 enabled

| Pin |  Configuration    |
| :-: | :---------------: |
| PA0 (LUT0-IN0) |   Digital input  |
| PA1 (LUT0-IN1) |   Digital input  |
| PC0 (LUT1-IN0) |   Digital input  |
| PC1 (LUT1-IN1) |   Digital input  |
| PC2 (LUT1-IN2) |   Digital input  |
| PA3 (LUT0-OUT) |   Digital output  |

 ## Operation
 1. Connect the board to the PC.

 2. Open the atmega4809-getting-started-with-ccl-studio.atsln solution in Microchip Studio.

 3. Set the **State_Decoder** project as start-up project. Right click on the project in the **Solution Explorer** tab and click **Set as StartUp Project**.

<br><img src="../images/Start_Up_Project.PNG" height="500">

 4. Build the **State_Decoder** project: Right click on the **atmega4809-getting-started-with-ccl-studio** solution and select **Build Solution**.

<br><img src="../images/Build_Solution.PNG"  height="500">

 5. Select the **ATMEGA4809 Xplained Pro** in the Connected Hardware Tool section of the project settings:
   - Right click on the project and click **Properties**
   - Click on the **Tool** tab
   - Select the **ATMEGA4809 Xplained Pro** (click on the **SN**) in the **Selected debugger/programmer** section, and save (CTRL + S):

<br><img src="../images/Select_Tool.PNG" height="500">

 6. Program the project to the board: Click on the **Debug** tab and click **Start Without Debugging**.

<br><img src="../images/Start_Without_Debugging.PNG" height="500">

## Demo

The pattern that needs to be decoded is `b'10110`:

| Pin | Value |
| :-: | :-: |
| PC2 (LUT1_IN2) | `1` - HIGH |
| PC1 (LUT1_IN1) | `0` - LOW  |
| PC0 (LUT1_IN0) | `1` - HIGH |
| PA1 (LUT0_IN1) | `1` - HIGH |
| PA0 (LUT0_IN0) | `0` - LOW  |

The picture below shows how the output (PA3) goes high when the pattern is detected on the input pins.

<br><img src="images/demo.png" width ="700">

## Summary

This code example shows how to configure the CCL peripheral to implement a state decoder.
