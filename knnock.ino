/* knnock
  
   The circuit:
	* + connection of the piezo attached to analog in 0
	* - connection of the piezo attached to ground
	* 1-megohm resistor attached from analog in 0 to ground

   This sketch is modified from the Knock example at http://www.arduino.cc/en/Tutorial/Knock
   
   Originally created 25 Mar 2007
   by David Cuartielles <http://www.0j0.org>
   modified 30 Aug 2011
   by Tom Igoe
   
   and then modified by Edward B, November 2014
   
   This modified code is in the public domain.

 */
 
// set up patterns
int lengths[3] = {2,3,5};

// set up constants
const int ledPin = 12;      // led connected to digital pin 12
const int knockSensor = A1; // the piezo is connected to analog pin 0
const int threshold = 10;   // threshold value to decide when the detected sound is a knock or not

// set up variables
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

int timeout = 500;          // what is the timeout
int delayTime = 10;         // How long do we wait for the wave to propogate?

int patternLength = 10;     // How long should patterms be?

void record(int* pattern[])
{
  int numKnocks = 0;
  unsigned long lastKnock = millis();
  unsigned long timeSinceLastKnock = millis();
  while (timeSinceLastKnock > timeout)
  {
    sensorReading = analogRead(knockSensor);
    if (sensorReading >= threshold) {
      // register knock and add time slice to array
      numKnocks += 1;
      
      pattern[numKnocks] = (int)timeSinceLastKnock;
      
      // send the string "Knock!" back to the computer, followed by newline
      Serial.print("Knock! ");
      Serial.println(sensorReading);
      
      // wait a bit until the sound wave stops propogating and reset timeout
      delay(delayTime);
      lastKnock = millis(); // reset timeout 
    } //if
    
    timeSinceLastKnock = millis() - lastKnock;
  } //while
  
  pattern[0] = numKnocks;
  // start at 1 after last entry, pad out time with 0s
  for (int i = numKnocks + 1; i < patternLength; i++)
    pattern[i] = 0;
}

void learn()
{
  //select action channel
  int actionChannel = 12;
  
  //record
  int pattern[patternLength];
  record(pattern);
  
  //calc # of knocks
  //calc gaps
  //store 
  
}

void classify()
{
  
}

//"local" variables
int i = 0;     // used to iterate through length array

void setup() {
 pinMode(12, OUTPUT); // declare the ledPin as as OUTPUT
 pinMode(11, OUTPUT); // declare the ledPin as as OUTPUT
 Serial.begin(9600);       // use the serial port
}

void loop() {
  /*
  
  // Check for timeout
  if ((millis() - lastKnock) > timeout) {
    // If we've timed out, check if the pattern is valid
    for (i = 0; i < 3; i++) {
      if (lengths[i] == numKnocks) { //found a pattern
        Serial.println("Pattern reached!");
        switch (numKnocks) {
          case 2:
            digitalWrite(12, HIGH);
            break;
          case 3:
            digitalWrite(11, HIGH);
            break;
          case 5:
            digitalWrite(12, LOW);
            digitalWrite(11, LOW);
            break;
        }      
      } 
    }
    
    // no matter what happens, reset knocks
    numKnocks = 0;
    /*
    Serial.print("Reset - ");
    Serial.print(millis());
    Serial.print(" ");
    Serial.println(lastKnock);
    
    
    // reset timeout
    lastKnock = millis();
  }
  
  // detect knock
  sensorReading = analogRead(knockSensor);
  if (sensorReading >= threshold) {
    // send the string "Knock!" back to the computer, followed by newline
    Serial.print("Knock! ");
    Serial.println(sensorReading);
    
    // register knock and wait a bit until the sound wave stops propogating
    numKnocks += 1;
    lastKnock = millis(); // reset timeout
    delay(10); 
  } 
  
  */
  
}
