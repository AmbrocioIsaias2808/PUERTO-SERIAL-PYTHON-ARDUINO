from tkinter import *
import serial
import time
from tkinter import messagebox
import threading
import json

SerialObj = serial.Serial('COM4')  # COMxx   format on Windows

SerialObj.baudrate = 9600  # set Baud rate to 9600
SerialObj.bytesize = 8  # Number of data bits = 8
SerialObj.parity = 'N'  # No parity
SerialObj.stopbits = 1  # Number of Stop bits = 1

time.sleep(3)  # Only needed for Arduino,For AVR/PIC/MSP430 & other Micros not needed




def on_closing():
    if messagebox.askokcancel("Quit", "Do you want to quit?"):
        SerialObj.close()
        root.destroy()

def lectura_serial():
    while True:
        BytesWritten = SerialObj.readline()
        data = json.loads(BytesWritten)
        voltage.set(data["voltage"])
        color.set(data["color"])
        message.set(data["alert"])
        frame.config(bg=color.get())
        label1.config(bg=color.get())
        label2.config(bg=color.get())
        label3.config(bg=color.get())
        root.update_idletasks()
        root.update()
        time.sleep(0.1)




root = Tk()

voltage = StringVar(value="0")
color = StringVar(value="yellow")
message = StringVar(value="SIN LECTURA")

frame = Frame(root, height=600, width=1200)
frame.pack(fill='both', expand=1)
frame.config(bg=color.get())

label1 = Label(frame, text="VOLTAGE ACTUAL: ", font=("Arial Bold", 40))
label1.config(bg=color.get())
label1.grid(row=0, column=0, sticky=W, pady=10, padx=10);

label2 = Label(frame, textvariable=voltage, font=("Arial Bold", 40))
label2.config(bg=color.get())
label2.grid(row=0, column=1, sticky=W, pady=10, padx=10);

label3 = Label(frame,textvariable=message, font=("Arial Bold", 40))
label3.config(bg=color.get())
label3.grid(row=0, column=2, sticky=W, pady=10, padx=10);

x = threading.Thread(target=lectura_serial)
x.start()


root.protocol("WM_DELETE_WINDOW", on_closing)

root.mainloop()
