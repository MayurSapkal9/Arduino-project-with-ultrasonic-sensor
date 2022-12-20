  #define echoPin1 9
#define trigPin1 8
#define SOUND_SPEED 0.034
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
int RLed=10;
int GLed=11;
//int GLed=10;
//int RVal;
//int OVal;
//int GVal:
int duration1;
int distance1;

void setup() {
 
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(RLed, OUTPUT);
    pinMode(GLed, OUTPUT);
//   pinMode(GLed, OUTPUT);
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.init();
// Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Distance");
}
//void ultrasonic()
//{
//}

void loop() 
{
  //GLed=HIGH;
  
  
  //ultrasonic 1
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Front: ");
  Serial.print(distance1);
  Serial.println(" cm");
  if(distance1<5)
  {
  digitalWrite(RLed,HIGH);
  digitalWrite(GLed,LOW);
//  digitalWrite(GLed,LOW);
}
  else if( 5< distance1 <30 )
  {
  digitalWrite(RLed,LOW);
  digitalWrite(GLed,HIGH);
//  digitalWrite(GLed,LOW);
  }

else{
  digitalWrite(RLed,LOW);
  digitalWrite(GLed,LOW);
} //gitalWrite(GLed,LOW)
lcd.init();                      // initialize the lcd 
  lcd.init();
// Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print(distance1);
}
