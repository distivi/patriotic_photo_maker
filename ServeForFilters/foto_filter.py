#!/usr/bin/env python
# -*- coding: utf-8 -*-
import Image
import base64
import ImageEnhance

with open("logo.jpg", "rb") as imageFile: #for example
    inputstr = base64.b64encode(imageFile.read())

image = base64.b64decode(inputstr) # Some input base64 string
filename = 'some_image.jpg'  
with open(filename, 'wb') as f:
    f.write(image)
image = Image.open("some_image.jpg")

def image_crop(src):

    width, height = src.size   # Get dimensions
    left = width/136
    top = height/136
    right = width
    bottom = height/2
    src.crop((left, top, right, bottom)).save("2.jpg")
    left = width/136
    top = height/2
    right = width
    bottom = height
    src.crop((left, top, right, bottom)).save("3.jpg")

 
i=1
def image_overlay(src, color, alpha=0.5):

    overlay = Image.new(src.mode, src.size, color)
    bw_src = ImageEnhance.Color(src).enhance(0.0)
    return Image.blend(bw_src, overlay, alpha)

width, height = image.size 
image_crop(image)
img1 = Image.open("2.jpg")
img2 = Image.open("3.jpg")
image_overlay(img2,"#FFFF00").save("3.jpg")
image_overlay(img1,"#0000FF").save("2.jpg")
img1 = Image.open("2.jpg")
img2 = Image.open("3.jpg")
width, height1 = img1.size 
new_im = Image.new('RGB', (width,height))
new_im.paste(img1, (0,0))
new_im.paste(img2,(0,height1))

new_im.save("43.jpg")

with open("43.jpg", "rb") as imageFile:
    print imageFile
    str = base64.b64encode(imageFile.read())
    # print str

