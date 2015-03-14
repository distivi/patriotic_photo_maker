#!/usr/bin/python

# need to install
# sudo apt-get install python-tk
# sudo apt-get install python-imaging-tk

from Tkinter import *
import tkFileDialog
from PIL import Image, ImageTk
import Image
import base64
import ImageEnhance
from StringIO import StringIO
import time

class Window:
	def __init__(self):
		self.selected_file_path = None
		self.setupUI()

	def run(self):
		self.root.mainloop()

	def setupUI(self):
		self.root = Tk()
		self.root.geometry("600x600")
		self.root.config(background="#FFFFFF")

		#setup label
		self.icon_size = Label(self.root)
		self.icon_size.grid(row = 1, column = 0, columnspan = 2)

		#setup buttons
		openImageButton = Button(self.root,
			text ="Open Image",
			bg="white", fg="black",
			command = self.helloCallBack)

		applyFilterButton = Button(self.root,
			text = "Apply filter",
			bg="white", fg="black",
			command = self.filterCallBack)

		openImageButton.grid(row = 0, column = 0)
		applyFilterButton.grid(row = 0, column = 1)


	# actions
	def helloCallBack(self):
		filePath = tkFileDialog.askopenfilename(filetypes=[("Image files","*.png"),("All","*")])
		self.selected_file_path = filePath
		image = Image.open(self.selected_file_path)
		photo = ImageTk.PhotoImage(image)
		self.showImage(photo)

	def filterCallBack(self):
		if self.selected_file_path:
			base64String = self.base64FromPath(self.selected_file_path)
			# TODO: send str via CORBA

			# TODO: receive filtered image's data via CORBA
			imageBase64Data = base64String# <-- instead of "base64String" should be data from callback
			filteredPhoto = self.imageFromBase64(imageBase64Data)
			self.showImage(filteredPhoto)

	def showImage(self,photo):
		self.icon = photo
		self.icon_size.image = self.icon
		self.icon_size.configure(image=self.icon)

	# encoding/decoding utilities
	def base64FromPath(self,filePath):
		with open(filePath, "rb") as imageFile:
			base64String = base64.b64encode(imageFile.read())
			return base64String

	def imageFromBase64(self,base64String):
		f = StringIO(base64.decodestring(str(base64String)))
		image = Image.open(f)
		filteredPhoto = ImageTk.PhotoImage(image)
		return filteredPhoto

#===============================================


window = Window()
window.run()







