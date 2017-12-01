/*
 * 
 * This class will move the movement motors by treating them as a servo
 * The motors work independently from each other
 * 100 = stopped motor
 * 150 = full speed backward
 * 50 = full speed forward
 * 
 */
 #include <AFMotor.h>
 #include <Servo.h>

String readString;
AF_Stepper motor(48, 2);
Servo rightSide;
Servo leftSide;
int nRightSideSpeed = 100;
int nLeftSideSpeed = 100;

void setup()
{
  Serial.begin(9600);
  rightSide.writeMicroseconds(1500);
  rightSide.attach(7);
  leftSide.attach(8);

  motor.setSpeed(100);

  Serial.println("servo-test-22-dual-input");
}

void loop()
{
  while(Serial.available())
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  if(readString.length() > 0)
  {
    Serial.println(readString);
    
    if(readString == "w")
    {
      Serial.print("going forward");
      nRightSideSpeed -= 1;
      nLeftSideSpeed -= 1;
    }
    else if(readString == "x")
    {
      Serial.print("stopping");
      nRightSideSpeed = 100;
      nLeftSideSpeed = 100;
    }
    else if(readString == "s")
    {
      Serial.print("going backward");
      nRightSideSpeed += 1;
      nLeftSideSpeed += 1;
    }
    else if(readString == "d")
    {
      Serial.print("going right");
      nRightSideSpeed -= 1;
      nLeftSideSpeed += 1;
    }
    else if(readString == "a")
    {
      Serial.print("going left");
      nRightSideSpeed += 1;
      nLeftSideSpeed -= 1;
    }
    else if(readString == "m")
    {
      Serial.println("Rotate Storage");
      motor.step(200/12, FORWARD, SINGLE);  
    }
    else if(readString == "l")
    {
      Serial.println("Rotate Arm");
      motor.step(200/12, FORWARD, SINGLE); 
    }

  rightSide.write(nRightSideSpeed);
  leftSide.write(nLeftSideSpeed);
  

  readString="";
  }
}

