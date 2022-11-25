//change seconds,minutes and hours values below to the current time.

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//set alarm as false until correct parameter is reached, set out in "set alarm" below
bool alarm=false;

// seconds value.
int seconds = 0;

// minutes value.
int minutes = 55;

// hours value.
int hours = 7;

// LEDS dependant on weather conditions
int LedPin2 = 2;
int LedPin3 = 3;
int LedPin4 = 4;

// alarm buzzer
int buzzer = 5;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Current Time -  ");

  //LEDS y'all
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  
  pinMode(2, OUTPUT); //red
  pinMode(3, OUTPUT); //blue
  pinMode(4, OUTPUT); //green
 
  // Set buzzer - pin 5 as an output
  pinMode(buzzer, OUTPUT);


}

void loop() {
//Set the alarm
  if (hours = 8 && minutes = 1){
  alarm=true;}

//Time incrementation
  if(seconds < 60){
    delay(1000);
    seconds=seconds+1;
  }
  else{
    seconds=00;
  }
  
  if(seconds>59){
    minutes=minutes+1;
  }
  else{
    minutes=minutes;
  }
  
  if(minutes<60){
    minutes=minutes;
    seconds=seconds;
  }
  else{
    minutes=0;
    seconds=seconds+1;
  }

  if(hours<24){
    hours=hours;
  }
  else{
    hours=0;
  }
  while(alarm = false){
  lcd.setCursor(0, 1);
  lcd.print(seconds);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(hours);
  lcd.print("________");}

 
// LEDS dependant on weather

int temp = 300;
bool rain = false;

  if (alarm = true && (rain=false && (temp <= 400))){ 
    digitalWrite(LedPin2,HIGH);
    }
  else if(alarm = true && (rain=false && (temp<400))) {
    digitalWrite(LedPin3,HIGH);
    }
  else if(alarm = true && (rain=true)){
    digitalWrite(LedPin4,HIGH);}


// Buzzer activation
  if(alarm=true){
  lcd.clear();
  lcd.print("ALARM");
  tone(buzzer,1915);
  delay(1000); // Wait for 1000 millisecond(s)
  tone(buzzer,1700);
  delay(1000); // Wait for 1000 millisecond(s)
  tone(buzzer,1519);
  delay(1000);
  tone(buzzer,1432);
  delay(1000);
  tone(buzzer,1275);
  delay(1000);
  tone(buzzer,1136);
  delay(1000);
  tone(buzzer,1014);
  delay(1000);
  tone(buzzer,0);
  delay(1000);}
}
