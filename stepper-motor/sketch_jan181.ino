/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
int g;


 
void setup() {
  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
if(g<400) 
{for(int x = 0; x < 200; x++,g<400,g++)
 {

  
   Serial.println("clockwise");
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation

    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
   }  
   delay(1000); // One second delay
   }else
  {  for(int x = 0; x < 400; x++,g>400,g--)
  {Serial.println("counterclockwise");
    digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation

      digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);                                                                                                                                                                                                                                                                                                                                                                                                                             
    delayMicroseconds(500);
    }
  
    delay(1000);} 


  


 }
 
 
 
 
 
 
 

  
      
    


