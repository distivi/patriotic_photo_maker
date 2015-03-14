#!/usr/bin/python

import Tkinter
top = Tkinter.Tk()

def helloCallBack():
   print "Success"

B = Tkinter.Button(top, text ="Hello", command = helloCallBack)

B.pack()

top.mainloop()
