#include<IRremote.h>
#include<LiquidCrystal.h>
#define LED_PIN1 11
#define LED_PIN2 12 
#define LED_PIN3 10
#define LED_PIN4 9
#define LCD_REG A5
#define LCD_EBL A4
#define IR_PIN 8
#define LCD_PIN1 7
#define LCD_PIN2 6
#define LCD_PIN3 5
#define LCD_PIN4 4
#define BUTTON_Z 12
#define BUTTON_O 16
#define BUTTON_T 17
#define BUTTON_TH 18
 
LiquidCrystal lcd(LCD_REG,LCD_EBL,LCD_PIN1,LCD_PIN2,LCD_PIN3,LCD_PIN4);
void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN1,OUTPUT);
   pinMode(LED_PIN2,OUTPUT);
   pinMode(LED_PIN3,OUTPUT);
   pinMode(LED_PIN4,OUTPUT);
  pinMode( LCD_PIN1,OUTPUT);
  pinMode( LCD_PIN2,OUTPUT);
  pinMode( LCD_PIN3,OUTPUT);
  pinMode( LCD_PIN4,OUTPUT);
  IrReceiver.begin(IR_PIN);
  lcd.begin(16,2);
}

void loop(){
  lcd.setCursor(0,0);
  if(IrReceiver.decode()){
    IrReceiver.resume();
    int command=IrReceiver.decodedIRData.command;
    if(command==BUTTON_Z){
      digitalWrite(LED_PIN1,HIGH);
      delay(2000);
      digitalWrite(LED_PIN1,LOW);
      lcd.println(command);
       lcd.print("toggel 1");
      Serial.println("button 0 pressed");
    }
   else if(command==BUTTON_O){
      digitalWrite(LED_PIN2,HIGH);
      delay(2000);
      digitalWrite(LED_PIN2,LOW);
      lcd.println(command);
     lcd.print("toggel 2");
      Serial.println("button 1 pressed");
    }
   else if(command==BUTTON_T){
      digitalWrite(LED_PIN3,HIGH);
      delay(2000);
      digitalWrite(LED_PIN3,LOW);
      lcd.println(command);
     lcd.print("toggel 3");
      Serial.println("button 2 pressed");
    }
    else if(command==BUTTON_TH){
      digitalWrite(LED_PIN4,HIGH);
      delay(2000);
      digitalWrite(LED_PIN4,LOW);
      lcd.println(command);
       lcd.print("toggel 4");
      Serial.println("button 3 pressed");
    }
    else{
      lcd.print("press 1,2,3");
    }
  }
}
  
