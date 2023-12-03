#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define RELAY_PIN 2
#define TRIGGER_PIN  22  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     23  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(2,OUTPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(RELAY_PIN,HIGH);
}

void loop() {
  int dist=sonar.ping_cm();
  lcd.setCursor(0,0);lcd.print("Water Level:" + String(dist)+"cm ");
  if(dist==0 || dist>45){
    digitalWrite(RELAY_PIN,LOW);
    lcd.setCursor(0,1);lcd.print("Motor Running...");
  }
  else if(dist>2 && dist<15) {
    digitalWrite(RELAY_PIN,HIGH);
    lcd.setCursor(0,1);lcd.print("                ");
  }
  delay(500);
}