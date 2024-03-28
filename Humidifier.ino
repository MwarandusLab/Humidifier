#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int Fan_1 = 8;
int Fan_2 = 9;
int Fan_3 = 10;
int Fan_4 = 11;
int Fan_5 = 12;

int Fan_6 = 23;
int Fan_7 = 25;
int Fan_8 = 27;
int Fan_9 = 29;
int Fan_10 = 31;

int double_1 = 0;
int Single_1 = 0;

enum State {
  IDLE,
  OFFLINE,
  ONLINE,
  BLUETOOTH
};

State currentState = IDLE;

const int buttonPin1 = 18;
const int buttonPin2 = 19;
const int buttonPin3 = 20;

volatile boolean buttonState1 = HIGH;          // current state of the button
volatile boolean lastButtonState1 = HIGH;      // previous state of the button
volatile unsigned long lastDebounceTime1 = 0;  // last time the output pin was toggled
volatile unsigned long debounceDelay1 = 50;    // the debounce time; increase if the output flickers
volatile boolean objectDetected = false;

volatile boolean buttonState2 = HIGH;
volatile boolean lastButtonState2 = HIGH;
volatile unsigned long lastDebounceTime2 = 0;
volatile unsigned long debounceDelay2 = 50;

volatile boolean buttonState3 = HIGH;
volatile boolean lastButtonState3 = HIGH;
volatile unsigned long lastDebounceTime3 = 0;
volatile unsigned long debounceDelay3 = 50;

LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  Serial.begin(9600);
  pinMode(Fan_1, OUTPUT);
  pinMode(Fan_2, OUTPUT);
  pinMode(Fan_3, OUTPUT);
  pinMode(Fan_4, OUTPUT);
  pinMode(Fan_5, OUTPUT);
  pinMode(Fan_6, OUTPUT);
  pinMode(Fan_7, OUTPUT);
  pinMode(Fan_8, OUTPUT);
  pinMode(Fan_9, OUTPUT);
  pinMode(Fan_10, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  digitalWrite(Fan_1, HIGH);
  digitalWrite(Fan_2, HIGH);
  digitalWrite(Fan_3, LOW);
  digitalWrite(Fan_4, LOW);
  digitalWrite(Fan_5, LOW);
  digitalWrite(Fan_6, LOW);
  digitalWrite(Fan_7, LOW);
  digitalWrite(Fan_8, LOW);
  digitalWrite(Fan_9, LOW);
  digitalWrite(Fan_10, LOW);

  attachInterrupt(digitalPinToInterrupt(buttonPin1), buttonInterrupt1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), buttonInterrupt2, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), buttonInterrupt3, FALLING);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  lcd.setCursor(-3, 2);
  lcd.print("INITIALIZATION");
  delay(2000);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("BEE MULTISCENT");
  lcd.setCursor(1, 1);
  lcd.print("SMART DIFFUSER");
  lcd.setCursor(0, 3);
  lcd.print("STANDBY");
  delay(1000);
}

void loop() {
  // buttonInterrupt1();
  // buttonInterrupt2();
  // buttonInterrupt3();
  // if(double_1 == 1){

  // }else if(double_1 == 2){

  // }else if(double_1 == 2){
    
  // }else if(double_1 == 3){
    
  // }else if(double_1 == 4){
    
  // }
  
  // if(Single_1 == 1){
    
  // }else if(Single_1 == 2){
    
  // }
  // else if(Single_1 == 2){
    
  // }
}
void idle() {
  checkButtonPresses();
}
void buttonInterrupt1() {
  if (millis() - lastDebounceTime1 > debounceDelay1) {
    buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 == LOW && lastButtonState1 == HIGH && double_1 == 0) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 2);
      // lcd.print("SCENT_1: ON");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_2: ON");
      
      digitalWrite(Fan_1, HIGH);
      digitalWrite(Fan_2, HIGH);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(100);
      double_1 = 1;
    }else if (buttonState1 == LOW && lastButtonState1 == HIGH && double_1 == 1) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");

      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 2);
      // lcd.print("SCENT_3: ON");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_4: ON");
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, HIGH);
      digitalWrite(Fan_4, HIGH);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(100);
      double_1 = 2;
    }else if (buttonState1 == LOW && lastButtonState1 == HIGH && double_1 == 2) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 2);
      // lcd.print("SCENT_5: ON");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_6: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, HIGH);
      digitalWrite(Fan_6, HIGH);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      delay(100);
      // double_1 = 3;
    } else if (buttonState1 == LOW && lastButtonState1 == HIGH && double_1 == 3) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 2);
      // lcd.print("SCENT_7: ON");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_8: ON");
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, HIGH);
      digitalWrite(Fan_8, HIGH);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(100);
      double_1 = 4;
    } else if (buttonState1 == LOW && lastButtonState1 == HIGH && double_1 == 4) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 2);
      // lcd.print("SCENT_9: ON");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_10: ON");
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, HIGH);
      digitalWrite(Fan_10, HIGH);
      // delay(100);
      double_1 = 0;
    }
    lastButtonState1 = buttonState1;
    lastDebounceTime1 = millis();
  }
}

void buttonInterrupt2() {
  if (millis() - lastDebounceTime2 > debounceDelay2) {
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 0) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_1: ON");

      digitalWrite(Fan_1, HIGH);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 1;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 1) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_2: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, HIGH);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 2;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 2) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_3: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, HIGH);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 3;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 3) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_4: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, HIGH);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 4;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 4) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_5: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, HIGH);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 5;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 5) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_6: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, HIGH);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 6;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 6) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_7: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, HIGH);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 7;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 7) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_8: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, HIGH);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 8;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 8) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_9: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, HIGH);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 9;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 9) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(-4, 3);
      // lcd.print("SCENT_10: ON");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, HIGH);
      // delay(500);
      Single_1 = 10;
    } else if (buttonState2 == LOW && lastButtonState2 == HIGH && Single_1 == 10) {
      // lcd.clear();
      // lcd.setCursor(1, 0);
      // lcd.print("BEE MULTISCENT");
      // lcd.setCursor(1, 1);
      // lcd.print("SMART DIFFUSER");
      // lcd.setCursor(0, 3);
      // lcd.print("STANDBY");

      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      // delay(500);
      Single_1 = 0;
    }
    lastButtonState2 = buttonState2;
    lastDebounceTime2 = millis();
  }
}

void buttonInterrupt3() {
  if (millis() - lastDebounceTime3 > debounceDelay3) {
    buttonState3 = digitalRead(buttonPin3);
    if (buttonState3 == LOW && lastButtonState3 == HIGH && double_1 == 1) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      double_1 = 0;
    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && double_1 == 2) {
      digitalWrite(Fan_1, HIGH);
      digitalWrite(Fan_2, HIGH);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      double_1 = 1;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && double_1 == 3) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, HIGH);
      digitalWrite(Fan_4, HIGH);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      double_1 = 2;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && double_1 == 4) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, HIGH);
      digitalWrite(Fan_6, HIGH);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      double_1 = 3;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 1) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 0;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 2) {
      digitalWrite(Fan_1, HIGH);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 1;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 3) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, HIGH);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 2;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 4) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, HIGH);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 3;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 5) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, HIGH);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 4;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 6) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, HIGH);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 5;
    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 7) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, HIGH);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 6;
    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 8) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, HIGH);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 7;
    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 9) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, HIGH);
      digitalWrite(Fan_9, LOW);
      digitalWrite(Fan_10, LOW);
      Single_1 = 8;

    } else if (buttonState3 == LOW && lastButtonState3 == HIGH && Single_1 == 10) {
      digitalWrite(Fan_1, LOW);
      digitalWrite(Fan_2, LOW);
      digitalWrite(Fan_3, LOW);
      digitalWrite(Fan_4, LOW);
      digitalWrite(Fan_5, LOW);
      digitalWrite(Fan_6, LOW);
      digitalWrite(Fan_7, LOW);
      digitalWrite(Fan_8, LOW);
      digitalWrite(Fan_9, HIGH);
      digitalWrite(Fan_10, LOW);
      Single_1 = 9;
    }
    lastButtonState3 = buttonState3;
    lastDebounceTime3 = millis();
  }
}
void checkButtonPresses() {
  buttonInterrupt1();
  buttonInterrupt2();
  buttonInterrupt3();
}
