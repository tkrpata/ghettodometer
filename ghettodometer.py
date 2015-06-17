#!/usr/bin/env python

# oh god why did I write this in python
# Marcus is going to look at it
# he's going to tell me all the things I did wrong
# nooooo
# NOOOOOOOOOO

import sys

if len(sys.argv) < 3:
  print "ghettodometer.py <filename> <spoke diameter>"
  sys.exit(1)

filename = sys.argv[1]
spoke_diameter = sys.argv[2]


f = open(filename, 'r')
first = 0
last = 0
revolutions = 0

for line in f:
  print "diff: %d" % (int(line) - last)
  if not first:
    first = int(line)
  revolutions = revolutions+1
  last = int(line)

print "first %d, last %d, revolutions %d" % (first, last, revolutions)

# figure distance traveled
pi = 3.1415
circumference = float(spoke_diameter) * 2.0 * pi
distance = circumference * revolutions
km = distance / 100000

# figure elapsed time
elapsed = last - first

# figure kph
secs = elapsed / 1000.0
hours = secs / 3600
kph = km / hours

print "traveled %0.02f km in %0.02f hours (%0.02f kph)" % (km, hours, kph)
   
miles = km * 0.621371 
mph = miles / hours

print "for us silly americans, that's %0.02f miles (%0.02f mph)" % (miles, mph)
