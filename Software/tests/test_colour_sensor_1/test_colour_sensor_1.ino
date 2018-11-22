// Define colour sensor LED pins
int ledPort = 0;

// boolean to know if the balance has been set
boolean balanceSet = false;

//place holders for colour detected
int red = 0;
int green = 0;
int blue = 0;

//floats to hold colour arrays
float colourReading;
float whiteReading;
float blackReading;


//place holder for average
int avgRead;

void setup(){
 
  //setup the outputs for the colour sensor
  pinMode(0,OUTPUT);
 
  //begin serial communication
  Serial.begin(9600);
 
}

void loop(){
    checkBalance();
    checkColour();
    printColour();
    Serial.println("");
    }

void checkBalance(){
  //check if the balance has been set, if not, set it
  if(balanceSet == false){
    setBalance();
  }
}

void setBalance(){
    //set white balance
    Serial.println("Starting white balance calibration!");
    delay(5000);                              //delay for five seconds, this gives us time to get a white sample in front of our sensor
    //scan the white sample.
    //go through each light, get a reading, set the base reading for each colour red, green, and blue to the white array
    digitalWrite(ledPort,HIGH);
    Serial.println("LEDs on");
    delay(100);
    getReading(5);          //number is the number of scans to take for average, this whole function is redundant, one reading works just as well.
    whiteReading = avgRead;
    digitalWrite(ledPort,LOW);
    Serial.println("LEDs off");
    delay(100);
    //done scanning white, now it will pulse blue to tell you that it is time for the black (or grey) sample.
    //set black balance
    Serial.println("Starting white balance calibration!");
    delay(5000);              //wait for five seconds so we can position our black sample 
    //go ahead and scan, sets the colour values for red, green, and blue when exposed to black
    digitalWrite(ledPort,HIGH);
    Serial.println("LEDs on");
    delay(100);
    getReading(5);
    blackReading = avgRead;
    digitalWrite(ledPort,LOW);
    Serial.println("LEDs off");
    delay(100);
    //set boolean value so we know that balance is set
    balanceSet = true;
    //delay another 5 seconds to allow the human to catch up to what is going on
    delay(5000);
  }

void checkColour(){
     digitalWrite(ledPort,HIGH);  //turn or the LED, red, green or blue depending which iteration
     Serial.println("LEDs on");
     delay(100);                      //delay to allow CdS to stabalize, they are slow
     getReading(5);                  //take a reading however many times
     colourReading = avgRead;       //set the current colour in the array to the average reading
     float greyDiff = whiteReading - blackReading;                    //the highest possible return minus the lowest returns the area for values in between
     colourReading = (colourReading - blackReading)/(greyDiff)*255; //the reading returned minus the lowest value divided by the possible range multiplied by 255 will give us a value roughly between 0-255 representing the value for the current reflectivity(for the colour it is exposed to) of what is being scanned
     digitalWrite(ledPort,LOW);   //turn off the current LED
     Serial.println("LEDs off");
     delay(100);
}
void getReading(int times){
    int reading;
    int tally=0;
    //take the reading however many times was requested and add them up
    for(int i = 0;i < times;i++){
    reading = analogRead(0);
    tally = reading + tally;
    delay(10);
    }
    //calculate the average and set it
    avgRead = (tally)/times;
}

//prints the colour in the colour array, in the next step, we will send this to processing to see how good the sensor works.
void printColour(){
    Serial.print("Colour reading: ");
    Serial.println(colourReading);
    //delay(2000);
}
