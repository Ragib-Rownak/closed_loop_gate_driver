# Closed-Loop P-Control Gate Driver with Arduino Nano

This project implements a **proportional (P) controller-based closed-loop gate driver** using an Arduino Nano, TLP255 optocoupler, and IRFZ44N MOSFET to control a DC motor. It reads the motor voltage via a voltage divider, calculates the error against a desired voltage set by a potentiometer, and adjusts the PWM to maintain the target voltage. This is ideal for learning **basic closed-loop motor control** and **power electronics interfacing** with Arduino.

## Components

- Arduino Nano (ATmega328)
- TLP255 Optocoupler
- IRFZ44N MOSFET
- DC Motor
- Potentiometer (for desired voltage input)
- Resistors (for voltage divider feedback)
- Breadboard & Jumper wires

## Circuit

1. **PWM Output**: Arduino Nano pin `D9` → TLP255 → IRFZ44N gate → Motor.
2. **Voltage Feedback**: Motor output → Voltage divider (R1 & R2) → Arduino Nano `A2`.
3. **Potentiometer Input**: Arduino Nano `A0` for desired voltage reference.

**Note:** Make sure the voltage divider scales the motor voltage within 0–5V for safe ADC reading.

## Code Overview

- `feedCalc(int n)` → Converts ADC reading to voltage.  
- `errorCalc()` → Calculates the error between desired and actual voltage, updates PWM via proportional control (`Kp`).  
- `loop()` → Reads potentiometer and feedback, updates PWM continuously.

### Key Variables

- `Kp` → Proportional gain for error correction (adjustable).  
- `R1`, `R2` → Voltage divider resistors.  
- `pwmVal` → PWM duty cycle output (0–255).  

## Usage

1. Connect the hardware as described above.
2. Upload the Arduino sketch to the Nano.
3. Adjust the potentiometer to set the desired motor voltage.
4. Observe the motor speed responding to the set voltage while maintaining stability.

## Notes

- Fine-tune `Kp` for your motor and load to avoid oscillations.  
- Serial prints in the code help monitor feedback and PWM response.

## License

This project is open-source and available under the [MIT License](LICENSE).

