import RPi.GPIO as GPIO
import time
import tkinter as tk
relay=7

GPIO.setmode(GPIO.BOARD)
GPIO.setup(relay,GPIO.OUT)

GPIO.output(relay,True)

master=tk.Tk()
master.title("Controle da Tranca")
master.geometry("300x100")

locklabel = tk.Label(master, text="porta fechada", fg="green")
locklabel.grid(row=1, column=1)

def abrirporta():
    locklabel = tk.Label(master, text="porta aberta", fg="red")
    locklabel.grid(row=1, column=1)
    locklabel.update()
    GPIO.output(relay,False)
    time.sleep(4)
    locklabel = tk.Label(master, text="porta fechada", fg="green")
    locklabel.grid(row=1, column=1)
    locklabel.update()
    GPIO.output(relay,True)

lockbutton = tk.Button(master, text="Abrir Porta", bg="blue", command=abrirporta)
lockbutton.grid(row=0, column=1)

master.mainloop()
