//Created By: Aditya Bangalore.
//Date: March 28, 2020.
//This code was uploaded to the Arduino to play the seven segment display game.

#include <Metro.h> //Include a timing library that will allow for the button pin to read continuously while the seven segment display shows numbers.

#define A 13 //Assign appropriate pins to variables for each purpose.
#define B 12
#define C 11
#define D 10
#define E 9
#define F 8
#define G 7
#define DP 6
#define button 5
#define LED1 4
#define LED2 3
#define LED3 2

int present; //Create an integer that will change based on which number is displayed on the seven segment.

Metro buttonAndCheckMetro = Metro(1); //Set the interval for reading and checking the input from the button as 1 ms.
Metro gameMetro = Metro(450); //Set the interval for changing the number on the seven segment. 

void off() {  //Create a function that turns off the display. Gives the variable present a value of -1.
  present = -1;
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  present = -1;
}

void zero() {
  present = 0;  //Create a function that shows a 0 on the display. Gives the variable present a value of 0.
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  present = 0;
}

bool checkZero() {  //Creates a function to check if 0 is on the display. 0 is the key number.
  if(present == 0) {
    return true;
  }
  else {
    return false;
  }
}

void one() {  //Creates a function to display a 1 on the display. Gives the variable present a value of 1.
  present = 1;
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  present = 1;
}

void two() {  //Creates a function to display a 2 on the display. Gives the variable present a value of 2.
  present = 2;
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  present = 2;
}

void three() {  //Creates a function to display a 3 on the display. Gives the variable present a value of 3.
  present = 3;
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  present = 3;
}

void four() { //Creates a function to display a 4 on the display. Gives the variable present a value of 4.
  present = 4;
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  present = 4;
}

void five() { //Creates a function to display a 5 on the display. Gives the variable present a vlaue of 5.
  present = 5;
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  present = 5;
}

void six() {  //Creates a function to display a 6 on the display. Gives the variable present a value of 6.
  present = 6;
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  present = 6;
}

void seven() {  //Creates a function to display a 7 on the display. Gives the variable present a value of 7.
  present = 7;
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  present = 7;
}

void eight() {  //Creates a function to display an 8 on the display. Gives the variable present a value of 8.
  present = 8;
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  present = 8;
}

void nine() { //Creates a function to display a 9 on the display. Gives the variable present a value of 9.
  present = 9;
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  present = 9;
}

void earnPoint() {  //Creates an animation on the display to show the user they earned a point.
  for(int a = 1; a <= 3; a += 1) {
    digitalWrite(A, HIGH);
    delay(50);
    digitalWrite(A, LOW);
    delay(50);
    digitalWrite(B, HIGH);
    delay(50);
    digitalWrite(B, LOW);
    delay(50);
    digitalWrite(C, HIGH);
    delay(50);
    digitalWrite(C, LOW);
    delay(50);
    digitalWrite(D, HIGH);
    delay(50);
    digitalWrite(D, LOW);
    delay(50);
    digitalWrite(E, HIGH);
    delay(50);
    digitalWrite(E, LOW);
    delay(50);
    digitalWrite(F, HIGH);
    delay(50);
    digitalWrite(F, LOW);
    delay(50);
    digitalWrite(G, LOW);
    delay(50);
  }
}

void losePoint() {  //Creates an animation on the display to show the user that they lost a point.
  for(int a = 1; a <= 3; a += 1) {
    digitalWrite(A, HIGH);
    delay(100);
    digitalWrite(A, LOW);
    digitalWrite(G, HIGH);
    delay(100);
    digitalWrite(G, LOW);
    digitalWrite(D, HIGH);
    delay(100);
    digitalWrite(D, LOW);
  }
}

void firstPoint() { //Create a function to turn the first LED on.
  digitalWrite(LED1, HIGH);
}

void secondPoint() {  //Create a function to turn the second LED on.
  digitalWrite(LED2, HIGH);
}

void thirdPoint() { //Create a function to turn the third LED on.
  digitalWrite(LED3, HIGH);
}

void win() {  //Blink all three LEDs when the user wins.
  for(int b = 1; b <= 5; b += 1) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(500);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(500);
  }
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void game() { //Displays random numbers from 0 to 9.
  off();
  delay(10);
  int num = random(0,10);
  switch(num) {
    case 0:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    }
  
}

void setup() {  //Define the function of each pin (output or input). Initialize other components.
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(button, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  bool btnrdng = digitalRead(button); //tells if the button is on or off.
  bool check0 = checkZero();  //tells if 0 is on the display.

  if(buttonAndCheckMetro.check()) { //create a thread to run every 1 ms.
    Serial.println(btnrdng);  //print the button reading.
    if(check0 && btnrdng) { //If 0 is on the display and the button is pressed,
          off();  //turn off display.
          delay(50);  //wait 50 ms.
          earnPoint();  //display animation for earning a point.
          delay(100); //wait 100 ms.
          for(int a = 1; a <= 3; a += 1) {
            switch(a) {
              case 1: //when a is 1,
                if(digitalRead(LED1) == LOW) { //if LED 1 is low,
                  firstPoint(); //turn it on.
                  break;
                }
                else {
                  firstPoint(); //if LED 1 is high,
                  a = 2;  //change a to 2.
                }
              case 2: //if a is 2,
                if(digitalRead(LED2) == LOW) { //if LED 2 is low,
                  firstPoint(); //turn LED 1 on.
                  secondPoint();  //turn LED 2 on.
                  break;
                }
                else {  //if LED 2 is high,
                  firstPoint(); //turn LED 1 on.
                  secondPoint();  //turn LED 2 on.
                  a = 3;  //change a to 3.
                }
              case 3: //if a is 3,
                if(digitalRead(LED3) == LOW) { //if LED 3 is low,
                  firstPoint(); //turn LED 1 on.
                  secondPoint();  //turn LED 2 on.
                  thirdPoint(); //turn LED 3 on.
                  delay(500); //wait 500  ms.
                  win();  //blink LEDs three times. The user won!
                  break; 
                }
              }
              break;
           } 
        }
        else if (check0 == false && btnrdng){ //if the button reading is high but 0 is not displayed,
          off();  //turn off the display.
          delay(50);  //wait 50 ms.
          losePoint();  //show animation that user lost.
          off();  //turn off display.
          delay(50);  //wait 50 ms.
          if(digitalRead(LED1) && digitalRead(LED2) == LOW && digitalRead(LED3) == LOW) { //if LED 1 is on, but LED 2 and 3 are off,
            digitalWrite(LED1, LOW);  //turn off LED 1.
          }
          else if(digitalRead(LED1) && digitalRead(LED2) && digitalRead(LED3) == LOW) { //if LED 1 and 2 are on, but LED 3 is off,
            digitalWrite(LED2, LOW);  //turn off LED 2.
          }
        }
  }
  if(gameMetro.check()) { //every 450 ms,
      game(); //run the game() function (display a random number).
      }
    } 
