# Interrupt Summary

## Table of contents
- [Hardware Interrupt](#Hardware-Interrupt)
- [None Hardware Interrupt intro](#None-Hardware-Interrupt-intro)
- [None Hardware Interrupt Code](#None-Hardware-Interrupt-Code).

## Hardware Interrupt

<span style="font-size: 16px">
The only pins that takes interrupt on Arduino UNO is

- Pin 2 → Interrupt 0
- Pin 3 → Interrupt 1


you can attach the interrupt using the following

1- `attachInterrupt(PortNumber, ISR, Mode)`
- Port number: is for the number of prt represent the pin
- ISR: the function that will access when interrupt happens
- Mode: Falling, rising or both edges

2- `digitalPinToInterrupt(PinNO.)` <br/>
to give the exact port based on the pin

#### EX): 
`attachInterrupt(digitalPinToInterrupt(2), light, FALLING);`
</span>

## None Hardware Interrupt intro

you can connect another pins to make them a valid interrupt <br/>
note: They won't be normal hardware interrupt.<br/>
### How Non-Hardware Interrupts Work?

A **non-hardware interrupt** works by continuously checking for changes in a pin’s state in software, instead of relying on dedicated interrupt hardware. This is typically done using **polling** or **Pin Change Interrupts (PCI).**


### 1. Polling Method
Polling is when the microcontroller constantly checks the state of a pin inside the `loop()` function. If a change is detected, it executes the corresponding action.

#### How It Works
- The program repeatedly reads the state of a pin.
- If a change is detected, a function is called to handle it.
- This method is slower than hardware interrupts because the program must **constantly check the pin**.

#### Downsides of Polling
- **Inefficient**: The CPU wastes time checking a pin even when it hasn’t changed.
- **Slower Response**: The program may not detect changes instantly, especially if other tasks are running.


### 2. Pin Change Interrupts (PCI)
The **Arduino Uno** has a feature called **Pin Change Interrupts (PCI)** that allows **any digital pin** to trigger an interrupt, but it's handled differently from **hardware interrupts**.

#### How It Works
- Instead of **dedicated** hardware interrupts for each pin (like pins 2 & 3), PCI uses **interrupt groups**.
- A group of pins (e.g., D0–D7) share a single interrupt **vector**.
- When **any** pin in that group changes, the program must check which one triggered the interrupt.

#### Why PCI is Not a True Hardware Interrupt
- **Slower than dedicated hardware interrupts** (pins 2 & 3).
- **Shared interrupt vector** means multiple pins can trigger the same interrupt, so you must manually check which pin changed.
- Still faster than polling, but **not as instant** as a true hardware interrupt.


### 3. Timer-Based Software Interrupts
If a precise timing-based action is needed, **timers** can be used to periodically check inputs without relying on hardware interrupts.

#### How It Works
- A timer is set up to trigger at specific intervals.
- Inside the timer function, the program checks for changes in the pin state.
- This allows "interrupt-like" behavior without a dedicated hardware interrupt.

## None Hardware Interrupt Code

### Arduino Ports
Arduino has three main ports

![arduino_ports](./img/img.png)

#### 1- Port B
![arduino_ports](./img/img_1.png)

#### 2- Port C
![arduino_ports](./img/img_2.png)

#### 3- Port D
![arduino_ports](./img/img_3.png)

### How to enable PCI

#### 1- Enable the **PCI** for the port
![arduino_ports](./img/img_4.png)

#### 2- Enable the **PCI** for the pins
![arduino_ports](./img/img_5.png)

##### Example for Port B
![arduino_ports](./img/img_6.png)

### 3- Define ISR
![arduino_ports](./img/img_7.png)

##### Example for Port B
![arduino_ports](./img/img_8.png)

### 4- Change interrupt flag
![arduino_ports](./img/img_9.png)
