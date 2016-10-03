//project 1 with Male. 20160723

int switchState = 0;

void setup(){

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop(){
  
  switchState = digitalRead(2);
  
    delay(250);
    
    digitalWrite(3, LOW);//Led azul
    digitalWrite(4, LOW);//Led amarillo
    digitalWrite(5, LOW);//Led verde

    delay(250);
    
    digitalWrite(3, HIGH);//Led azul
    digitalWrite(4, LOW);//Led amarillo
    digitalWrite(5, LOW);//Led verde


    delay(250);
    
    digitalWrite(3, LOW);//Led azul
    digitalWrite(4, HIGH);//Led amarillo
    digitalWrite(5, LOW);//Led verde
    
    delay(250);
    
    digitalWrite(3, LOW);//Led azul
    digitalWrite(4, LOW);//Led amarillo
    digitalWrite(5, HIGH);//Led verde
  
}



