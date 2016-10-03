#include <LiquidCrystal.h>;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;

int switchState = 0;

int prevSwitchState = 0;

int reply;

void setup(){

  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  lcd.print("Frage die");

  lcd.setCursor(0,1);

  lcd.print("Kristallkugel!");
}


void loop(){

  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Die Kugel sagt:");
      
      lcd.setCursor(0,1);
 
      switch(reply){
      
        case 0:
          lcd.print("Ja");
          break;
        case 1:
          lcd.print("Ganz bestimmt");
          break;
        case 2:
          lcd.print("Gewiss");
          break;
        case 3:
          lcd.print("Gut Aussichten");
          break;        
        case 4:
          lcd.print("Nicht sicher");
          break;    
        case 5:
          lcd.print("Frag nochmal");
          break;        
        case 6:
          lcd.print("Zweifelhaft");
          break;        
        case 7:
          lcd.print("Nein");
          break;        
      }
    }
  }
  prevSwitchState = switchState;
}


