//#include <NewPing.h> 
#include <LiquidCrystal.h>

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

int WATERPUMP=7;
 float soilsensor=A0;
float output_value;
int LED1=13;
//int sensor_value=250;
float sensor_value=250;
// NewPing sonar(sensor_value); 

void setup() {

  lcd.begin(16,2);
    Serial.begin(9600);
    //Serial.println("READING FROM THE SENSOR..");
  //delay(2000);
  pinMode(LED1,OUTPUT);
  pinMode(WATERPUMP,OUTPUT);
  pinMode(soilsensor,INPUT);
}


void loop() {
  
  output_value=analogRead(soilsensor);
  output_value=map(output_value,550,0,0,100);;
             Serial.print("MOISTURE:");
             Serial.print(output_value);
             Serial.print("%");
             Serial.println(".......");
            delay(1000);
            /*lcd.setCursor(0,0);
      lcd.print("MOISTURE=");
      lcd.setCursor(9,0);
      lcd.print(output_value);*/
      lcd.setCursor(10,0);
   lcd.print(output_value);









      
  /*lcd.setCursor(1,0);
  lcd.print("MOISTURE=");
  
  lcd.setCursor(1,1);
  lcd.print(output_value);
   delay(1000);*/
  
  if(output_value<30)
    { 
      digitalWrite(WATERPUMP,HIGH);
      digitalWrite(LED1,HIGH);
     /* lcd.setCursor(1,1);
     lcd.print("PUMP up");
      lcd.setCursor(9,0);
       lcd.print(output_value); 
       delay(1000);*/
       delay(20);
    
    lcd.setCursor(0,0);
    lcd.print("MOTOR up"); 
    
    lcd.setCursor(0,1);
    lcd.print("got MOIS    ");  
    
     //delay(1000);
   
    }     
    else
{
     digitalWrite(WATERPUMP,LOW);   
     digitalWrite(LED1,LOW);
     //lcd.setCursor(1,1);
     //lcd.print("PUMP down");
      //lcd.setCursor(9,0);
       //lcd.print(output_value);




       lcd.setCursor(0,0);
      lcd.print("MOT down");
      lcd.setCursor(0,1);
      lcd.print("full Mois");
     
     
    //delay(1000);
}
}
