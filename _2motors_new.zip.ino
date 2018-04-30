

// Setup Motor A (front and rear) pins
//int enableA = 1;
//#include<NewPing.h>
#include <Wire.h>
int pinA1 = 2;//control forward
int pinA2 = 3;//control backware

int pinB1 = 4;//control forward
int pinB2 = 5;//control backward

// Setup Ultrasonic Sensor pins
#define trigPin 7
#define echoPinF 8
#define echoPinL 9
#define echoPinR 10
#define echoPinB 11

void setup() {
//  // The setup code goes here and runs once only
//  // Configure the pin modes for each drive motor
 //  pinMode (enableA, OUTPUT);

   pinMode (pinA1, OUTPUT);
   pinMode (pinA2, OUTPUT);
//   pinMode (enableB, OUTPUT);
   pinMode (pinB1, OUTPUT);
   pinMode (pinB2, OUTPUT);
//   // Configure the pin modes for the Ultrasonic Sensor
   pinMode(trigPin, OUTPUT);
   pinMode(echoPinF, INPUT);
//left
   pinMode(trigPin, OUTPUT);
   pinMode(echoPinL, INPUT);
//right
   pinMode(trigPin, OUTPUT);
   pinMode(echoPinR, INPUT);
//back

   Serial.begin (9600);


}
void loop() {
  // Main code goes here and will run repeatedly:
  car(); // function keeps moving car forward while distance of objects in front are > 15cm away
  //avoid(); // function makes car go back, turn slightly right to move forward in new direction
}
// Create motor functions
void motorAforward() {
 digitalWrite (pinA1, LOW);
 digitalWrite (pinA2, HIGH);




}
void motorBforward() {
 digitalWrite (pinB1, HIGH);
 digitalWrite (pinB2, LOW);

}
void motorAbackward() {
 digitalWrite (pinA1, HIGH);
 digitalWrite (pinA2, LOW);
}
void motorBbackward() {
 digitalWrite (pinB1, LOW);
 digitalWrite (pinB2, HIGH);
}
void motorAstop() {
 digitalWrite (pinA1, HIGH);
 digitalWrite (pinA2, HIGH);
}
void motorBstop() {
 digitalWrite (pinB1, HIGH);
 digitalWrite (pinB2, HIGH);
}
void motorAcoast() {
 digitalWrite (pinA1, LOW);
 digitalWrite (pinA2, LOW);
}
void motorBcoast() {
 digitalWrite (pinB1, LOW);
 digitalWrite (pinB2, LOW);
}


// Setup movement functions
void forward (int duration) {
 motorAforward();
 motorBforward();
 delay (duration);
}
void backward (int duration) {
 motorAbackward();
 motorBbackward();
 delay (duration);
}
void right (int duration) {
 motorAbackward();
 motorBforward();
 delay (duration);
}
void left (int duration) {
 motorAforward();
 motorBbackward();
 delay (duration);
}
void coast (int duration) {
 motorAcoast();
 motorBcoast();
 delay (duration);
}
void breakRobot (int duration) {
 motorAstop();
 motorBstop();
 delay (duration);
}

// Setup Ultrasonic Sensor distance measuring
int distance(int echoPin) {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);///!!!!!!!!
  delayMicroseconds(60);
  distance = duration*0.034/2;//incm
 // Serial.println(duration);
  //Serial.println(distance);
  return distance;

}
// Setup the main car function

void car() {
  while(true)
  {
     Serial.print('F');
    Serial.println(distance(echoPinF));
    Serial.print('R');
     Serial.println(distance(echoPinR));
     Serial.print('L');
   Serial.println(distance(echoPinL));
        Serial.print('B');
   Serial.println(distance(echoPinB));

 //  int value= distance(echoPinB);
   //if(value<100){
   //      Serial.println(value);
   // Serial.print(" ");
   //}
   //||distance(echoPinF)<=0)&&(distance((echoPinL)>10)||(distance(echoPinL)<=0))&&(distance((echoPinR)>10)||(distance(echoPinR))<=0)

 if(distance(echoPinF)>20){
       motorAforward();
       motorBforward();

   }else {

       backward(100);
      right(260);
   }
  
         //backward(100);
    }
}
// Go back and turn slightly right to move car in new direction
// This function only runs if an obstacle within 15cm is detected


