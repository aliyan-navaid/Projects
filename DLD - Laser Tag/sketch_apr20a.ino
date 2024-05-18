#include <LiquidCrystal.h>
#define BUZZER_PIN 13

const int sensorPin = A0; // Analog pin connected to the light sensor
int sensorValue = 0;
int health = 16;

// Define the pins connected to your LCD module
const int rs = 12;        // Register Select (RS) pin
const int en = 11;        // Enable (E) pin
const int d4 = 5;        // Data pin D4
const int d5 = 4;        // Data pin D5
const int d6 = 3;        // Data pin D6
const int d7 = 2;        // Data pin D7

// Set the number of columns and rows on your LCD
const int cols = 16;     // Number of columns on the LCD
const int rows = 2;      // Number of rows on the LCD

// Initialize the LiquidCrystal library with the pins above
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void printHealthBars()
{
  return;
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  // Set up the LCD's number of columns and rows
  lcd.begin(cols, rows);
  
  // Print a message to the LCD
  lcd.print("Hello, World!");
  lcd.clear();

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  sensorValue = analogRead(sensorPin);
  lcd.clear();
  if (sensorValue <= 1000)
  {
    health--;
    tone(BUZZER_PIN, 1000);
    delay(100);
    noTone(BUZZER_PIN);
    while (health==0) {
      lcd.clear();
      tone(BUZZER_PIN, 1000);
      lcd.write("You've lost!");
      delay(250);

    }
  }
  for (int i=0;i<health;i++) {
    lcd.write(219);
  }
  //lcd.print(health);
  delay(400);

  
}
