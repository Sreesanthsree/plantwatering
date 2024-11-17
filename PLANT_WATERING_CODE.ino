#include <Wire.h>
#include <ds3231.h>
struct ts t; 
//wake1
const int wake_HOUR1 = 6;
const int wake_MINUTE1 = 0;
const int wake_SECOND1 = 0;
//wake2
const int wake_HOUR2 = 18; 
const int wake_MINUTE2 = 0;
const int wake_SECOND2 = 0;
//wake3


const int wake_HOUR3 = 9; 
const int wake_MINUTE3 = 0;
const int wake_SECOND3 = 0; 


//light
const int lightOnH = 18;
const int lightOffH = 22; 




int interval = 20000; //interval 
#define button 3 //button to 3
#define Valve 12 // valve to 12
//#define fish_Valve 10
#define light_Pin 11 
int buttonstate;


void setup() {
   Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  pinMode(Valve,OUTPUT);
  pinMode(button,INPUT);
//  pinMode(fish_Valve,OUTPUT);
  pinMode(light_Pin,OUTPUT);
}


void loop() {
DS3231_get(&t);
// printVALUES();
mannual();

/*if(t.hour==wake_HOUR1 &&t.min==wake_MINUTE1 &&t.sec==wake_SECOND1)
{
    Serial.println("On.......1...");
    digitalWrite(Valve,HIGH);
    digitalWrite(13,HIGH);
    delay(interval);
    digitalWrite(13,LOW);
    digitalWrite(Valve,LOW);
}
else if(t.hour==wake_HOUR3 &&t.min==wake_MINUTE3 &&t.sec==wake_SECOND3)
{
    digitalWrite(fish_Valve,HIGH);
    delay(1000);
    digitalWrite(fish_Valve,LOW);
  }

else */
if(t.hour==wake_HOUR2 &&t.min==wake_MINUTE2 &&t.sec==wake_SECOND2)
{
    Serial.println("On........2...");
    digitalWrite(Valve,HIGH);
    delay(interval);
    digitalWrite(Valve,LOW);
}
else{
    digitalWrite(Valve,LOW);
}


 if(t.hour>=lightOnH && t.hour<=lightOffH)
{
digitalWrite(light_Pin,HIGH);
}
else{
digitalWrite(light_Pin,LOW);
} 


delay(1000);


}

//print values
void printVALUES(){
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
}
//button function 
void mannual(){
  buttonstate = digitalRead(button);
  if(buttonstate==HIGH){
    digitalWrite(Valve,HIGH);
    delay(20000);
    digitalWrite(Valve,LOW);
  }
}
