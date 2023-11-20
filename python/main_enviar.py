# Python code transmits a byte 'A' to Arduino /Microcontroller to Blink LED
# Requires PySerial

# (c) www.xanthium.in 2022
# Rahul.S

# https://www.xanthium.in/Cross-Platform-serial-communication-using-Python-and-PySerial


import serial
import time

SerialObj = serial.Serial('COM3')  # COMxx   format on Windows

# /dev/ttyUSBx format on Linux
#
# Eg /dev/ttyUSB0
# SerialObj = serial.Serial('/dev/ttyUSB0')

SerialObj.baudrate = 9600  # set Baud rate to 9600
SerialObj.bytesize = 8  # Number of data bits = 8
SerialObj.parity = 'N'  # No parity
SerialObj.stopbits = 1  # Number of Stop bits = 1

time.sleep(3)  # Only needed for Arduino,For AVR/PIC/MSP430 & other Micros not needed
continuar=1;
numero = 0;

while continuar==1:

    print("FAVOR DE INGRESAR UN NUMERO")
    numero = input();

    BytesWritten = SerialObj.write(numero.encode('utf-8'))  # transmit 'A' (8bit) to micro/Arduino

    print('BytesWritten = ', BytesWritten)

    #print("DESEAS CONTINUAR? 1. Si / 2.NO")
    #continuar = int(input())

SerialObj.close()  # Close the port
