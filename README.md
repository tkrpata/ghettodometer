# Ghettodometer

## A DIY odometer for your bike
  
  
***Not to mention the fancy arduino and hardware hacking lab everyone has now. This sounds like a solved problem to me. ;)*** - Marcus Hodges

Fine, I made one then.

Commercial odometers are so nice looking and user friendly, and they work so well. This is the opposite of that.

## Build

You need (I used):  
* Arduino (Diavolino)  
* Battery power (the battery pack that came with the Diavolino kit)  
* SD card reader (Seeedstudio SD Card shield)  
* Hall effect sensor (whatever, but I got one from Adafruit for like 2 bucks which is about 4x what I should have paid but they're good folks)  
* Magnet (how do they work?)  
* Some wire probably  
* Tape or zip ties or whatever

I should mention also that if you want to be more classy (THOUGH I DON'T), pretty much every 80's 10 speed has an abandoned speedometer sensor attached to it that you can probably scavenge for freeinstead of using the magnet/sensor/wire.

![](http://i.imgur.com/T4PCyWj.jpg)

Long story short you're gonna wire up the hall effect sensor to one of the Arduino's digital pins and mount it on the bike like so. 

![](image src=http://i.imgur.com/16uPBj2.jpg)

Lookin real good there.

![](image src=http://i.imgur.com/6EvjO27.jpg)

Power switch on front. Sensor goes around back. 

![](image src=http://i.imgur.com/XLD7DF1.jpg)
![](image src=http://i.imgur.com/AoRUEmg.jpg)

Made it to my destination intact!

You can see where the sensor goes here. I didn't bother taping it down or anything, the solid core wires stay in place pretty well. 

## Operation

To operate, just switch on the Arduino (remember to insert memory card). It will create a trip file with a numeric filename, highest is most recent. File is no good by itself really, you need to post-process it, so take the SD card and stick it in your computer's memory hole.

	$ ./ghettodometer.py /Volumes/SD/13 36
	Assuming 36.00 cm from center of hub to ground...
	traveled 3.08 km in 0.21 hours (14.91 kph)
	for us silly americans, that's 1.91 miles (9.27 mph)
	
(Just measure the center of your hub to the ground to get your rolling radius.)	

