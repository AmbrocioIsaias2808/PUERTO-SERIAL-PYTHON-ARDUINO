from tkinter import *
import serial
import time
from tkinter import messagebox

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

def on_closing():
    if messagebox.askokcancel("Quit", "Do you want to quit?"):
        SerialObj.close()
        root.destroy()
def sendSerial():
    numero = varTexto.get();
    SerialObj.write(numero.encode('utf-8'))  # transmit 'A' (8bit) to micro/Arduino




root = Tk()
varTexto= StringVar()
frame = Frame(root, height=600, width=1200)
frame.pack()
label1 = Label(frame, text="INGRESA UN MENSAJE: ")
label1.grid(row=0, column=0, sticky=W, pady=10, padx=10);

text1  = Entry(frame, textvariable=varTexto)
text1.grid(row=0,column=1, sticky=W, pady=10, padx=10)

btn1 = Button(root, text="ENVIAR", padx=10, pady=5, command=sendSerial)
btn1.pack()


root.protocol("WM_DELETE_WINDOW", on_closing)

root.mainloop()
