/* motion.ino
 * Lafe Spietz, Imaad Syed
 * Reviewed on 4/19/2021
 * This is the program that controls the motion stage. In order to run this, compile and upload to the Arduino, and then use the joystick and buttons.
 *
*/

int delayus = 150;//delayMicroseconds(delayus);

//connect these pins to the MP6500 stepper motor control board:
int dirPin3 = 8;
int stepPin3 = 9;
int enPin3 = 10;
int dirPin1 = 5;
int stepPin1 = 6;
int enPin1 = 7;
int dirPin2 = 3;
int stepPin2 = 4;
int enPin2 = A0;

void setup() { 
    pinMode(11,INPUT); 
    pinMode(12,INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);

    pinMode(dirPin1,OUTPUT);
    pinMode(stepPin1,OUTPUT);
    pinMode(enPin1,OUTPUT);
    pinMode(dirPin2,OUTPUT);
    pinMode(stepPin2,OUTPUT);
    pinMode(enPin2,OUTPUT);
    pinMode(dirPin3,OUTPUT);
    pinMode(stepPin3,OUTPUT);
    pinMode(enPin3,OUTPUT);

    digitalWrite(dirPin1,LOW);
    digitalWrite(stepPin1,LOW);
    digitalWrite(enPin1,HIGH);
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(enPin2,HIGH);
    digitalWrite(dirPin3,LOW);
    digitalWrite(stepPin3,LOW);
    digitalWrite(enPin3,HIGH);
    
    Serial.begin(9600);
}

// read inputs and move motors accordingly
void loop() {

  if((abs(analogRead(A5) - 511) - 500) > 0){
      if((analogRead(A5) - 511) > 0){
        moveDown(20);
        delay(10);
       } else if ((analogRead(A5) - 511) < 0) {
        moveUp(20);
        delay(10);
      }  
  }
  if((abs(analogRead(A4) - 511) - 500) > 0){
      if((analogRead(A4) - 511) > 0){
        moveRight(20);
        delay(10);
      } else if((analogRead(A4) - 511) < 0){
        moveLeft(25);
        delay(5);
      }  
  }
  
  if(digitalRead(11) == HIGH){
    moveAway(7);
    delay(7);
  } else if(digitalRead(12) == HIGH){
    moveTowards(10);
    delay(5);
  }

 
}

// methods for moving stepper motors in different directions

// STEPPER 1
void moveLeft(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin1,HIGH);   
}

// STEPPER 1
void moveRight(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin1,HIGH);   
}

// STEPPER 2
void moveDown(int nSteps){
      digitalWrite(dirPin3,LOW);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin1,HIGH);   
}

// STEPPER 2
void moveUp(int nSteps){
     digitalWrite(dirPin3,HIGH);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin3,HIGH);    
}

// STEPPER 3
void moveAway(int nSteps){
     digitalWrite(dirPin2,LOW);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0; index < nSteps; index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}

// STEPPER 3
void moveTowards(int nSteps){
     digitalWrite(dirPin2,HIGH);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0; index < nSteps; index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}
