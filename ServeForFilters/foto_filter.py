#!/usr/bin/env python
# -*- coding: utf-8 -*-
import Image
image = Image.open("logo.jpg")
import ImageEnhance

def image_crop(src):

    width, height = src.size   # Get dimensions
    left = width/26
    top = height/26
    right = width
    bottom = height/2
    src.crop((left, top, right, bottom)).save("2.jpg")
    left = width/26
    top = height/2
    right = width
    bottom = height
    src.crop((left, top, right, bottom)).save("3.jpg")

 
i=1
def image_overlay(src, color, alpha=0.5):

    overlay = Image.new(src.mode, src.size, color)
    bw_src = ImageEnhance.Color(src).enhance(0.0)
    print "func"
    return Image.blend(bw_src, overlay, alpha)

image_crop(image)
img1 = Image.open("2.jpg")
img2 = Image.open("3.jpg")
image_overlay(img2,"#FFFF00").save("3.jpg")
image_overlay(img1,"#0000FF").save("2.jpg")
img1 = Image.open("2.jpg")
img2 = Image.open("3.jpg")
new_im = Image.new('RGB', (400,400))
new_im.paste(img1, (80,100))
new_im.paste(img2,(80,178))

new_im.save("43.jpg")
print "hello world"
