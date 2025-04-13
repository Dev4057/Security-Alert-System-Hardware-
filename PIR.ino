#include <LiquidCrystal.h>

// LCD pin setup: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Pin Definitions
const int pirPin = 2;         // PIR sensor output
const int trigPin = 3;        // Ultrasonic TRIG
const int echoPin = 4;        // Ultrasonic ECHO
const int buzzerPin = 5;      // Buzzer
const int ledPin = 6;         // LED (optional)

// Variables
long duration;
int distance;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.begin(16, 2);               // Initialize LCD 16x2
  lcd.print("System Armed");      // Show startup message
  delay(2000);
  lcd.clear();
}

void loop() {
  int motion = digitalRead(pirPin);
  
  if (motion == HIGH) {
    // Motion Detected!
    digitalWrite(ledPin, HIGH);

    // Trigger Ultrasonic Pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Calculate Distance
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    // Show alert on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INTRUDER ALERT!");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");

    // Buzzer logic
    if (distance < 50) {
      tone(buzzerPin, 1000);  // Louder/continuous
    } else {
      tone(buzzerPin, 500);   // Softer
    }

    delay(3000); // Stay active for 3 seconds

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    lcd.clear();
    lcd.print("System Idle...");
    delay(1000);
  } else {
    // No Motion
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Idle...");
    delay(1000);
  }
}
