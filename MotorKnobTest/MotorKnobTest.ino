/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 2048

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 10, 9, 11);

// the previous reading from the analog input
int previous = 0;
int sensorValue =0;
int val;
int checker;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
  Serial.begin(9600);
}

void loop() {
  // get the sensor value
  sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  val = map(sensorValue, 67, 993, 0, STEPS);
  
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.setSpeed(15);
//  if(val-previous <0){
//    checker = -1*(val-previous);
//  }
  
 // if(checker > 10){
  stepper.step(val-previous);
 // previous = val;
  //}
  
  Serial.print("    ");
  Serial.print(val);
  Serial.print("    ");
  Serial.println(val-previous);
  delay(10);

  // remember the previous value of the sensor
  previous = val;
}
