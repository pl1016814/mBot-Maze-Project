#include <Arduino.h>
#include <MeMCore.h>
MeRGBLed led(0, 30);
MeDCMotor motor2(M2);
MeDCMotor motor1(M1);
MeUltrasonicSensor ultraSonic(PORT_3);
void fullStop()
{
  motor1.stop();
  motor2.stop(); 
}

void moveForward()
{
  motor1.run(175); // LEFT MOTOR can be an int from -255 to 255
  motor2.run(-175); // RIGHT MOTOR
  delay(750);
  fullStop();
}

void turnRight()
{
  motor1.run(-250);
  motor2.run(-250);
  delay(300);
  fullStop();
}

void turnLeft()
{
  motor1.run(250);
  motor2.run(250);
  delay(300);
  fullStop();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led.setpin(13);
  pinMode(17, INPUT);
  while(analogRead(A7) != 0);
}

void loop() {
  int dist = ultraSonic.distanceCm();
  if (dist <= 5)
  {
    turnLeft();
    //turnRight;
    //int dist = ultraSonic.distanceCm();
    //if (dist <= 10)
    //{
      //turnLeft; 
    //}
  }
  else
  {
    moveForward();
    turnRight();
    int dist = ultraSonic.distanceCm();
    if (dist <= 5)
    {
      turnLeft();
    }
  }
}

