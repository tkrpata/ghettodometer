
/*
The Marcus Hodges Ghetto Odometer
What's cool is Arduino doesn't tell time on its own so that's silly
*/

#include <limits.h>
#include <SD.h>
#include <SPI.h>

int ledPin = 13; // internal LED
int sdPin = 10; // SD card shield
int inPin = 2; // input pin for sensor

File tripFile;

void setup() {
  
  Serial.begin(9600);
    
  // set up the SD card 
  Serial.print("Initializing SD card...");
  pinMode(sdPin, OUTPUT);
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // set up the trip file
  Serial.println("Creating trip file...");
  
  unsigned long fileId = 0;
  
  // figure out the highest numbered file so far
  File root = SD.open("/");
  while(File entry =  root.openNextFile()) {
    Serial.println(entry.name());
    int fileIdTmp = strtol(entry.name(),NULL,10);
    if(fileIdTmp > fileId) {
      fileId = fileIdTmp;
    }
    entry.close();
  }  
  fileId++;

  char filename[7];
  snprintf(filename,sizeof(filename),"%u",fileId);
  Serial.println(filename);
  tripFile = SD.open(filename, FILE_WRITE);
  if (!tripFile) {
    // if the file didn't open, print an error:
    Serial.println("error opening file");
  }
  
  // Config input sensor
  pinMode(inPin, INPUT_PULLUP);
  digitalWrite(inPin, HIGH);  
}

void loop(){
  int sensorVal = digitalRead(inPin);
  if(sensorVal == 0) {
    int click = millis();
    Serial.println(click);
    // write to file
    if(tripFile) {
      tripFile.println(click); 
      tripFile.flush();
    } else {
      Serial.println("Can't find trip file");
    }
    
    while(sensorVal == 0) {
      sensorVal = digitalRead(inPin);
    }
  } else {
    //Serial.println("Off");
  }
}
 
