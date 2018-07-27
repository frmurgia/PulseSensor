

/*
<><><><><><><><><><><><><><><><><>
----------------------------------

 by frmurgia © 2017-18 MIT License

----------------------------------
<><><><><><><><><><><><><><><><><>
*/

 

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
int  contatore=0;
const int LED2 = 2; 
const int LED3 = 3; 
const int LED4 = 4; 
const int LED5 = 5; 
const int LED6 = 6; 

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 600;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                              
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() {   
  
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);



  Serial.begin(9600);          // For Serial Monitor

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
        //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
 
if (pulseSensor.sawStartOfBeat()) {  
  delay(10);// Constantly test to see if "a beat happened". 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 

;
  contatore ++;
  Serial.print(contatore);
// inserire un fade nel 13 per l'attessa

  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
         digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
    // sets the value (range from 0 to 255):
    analogWrite(LED13, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
    
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
         digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
    // sets the value (range from 0 to 255):
    analogWrite(LED13, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  
  if (contatore>13){
  if(myBPM>60&&myBPM<68){
   Serial.println("soglia 1"); 
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW); 
    delay(4000);
    digitalWrite(LED2, LOW);
      
    }
  if(myBPM>68&&myBPM<76){
   Serial.println("soglia 2");
    digitalWrite(LED2,LOW);
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW); 
    delay(4000);
    digitalWrite(LED3, LOW); 
       
    }
  if(myBPM>76&&myBPM<84){
   Serial.println("soglia 3"); 
    digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, HIGH); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
        delay(4000);
            digitalWrite(LED4, LOW);
       
    }
  if(myBPM>84&&myBPM<92){
   Serial.println("soglia 4"); 
      digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, HIGH); 
    digitalWrite(LED6, LOW);
       delay(4000);
       digitalWrite(LED5, LOW);
    
    }
  if(myBPM>92&&myBPM<100){
   Serial.println("soglia 5");
      digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6,  HIGH);
           delay(4000);
             digitalWrite(LED6, LOW);
       
    }
  if (myBPM<60){
       digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
    
   
    } if (myBPM>110){
       digitalWrite(LED2,LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
  contatore=0;
    }
  }


}
 
 

  delay(20);                     

}

  
