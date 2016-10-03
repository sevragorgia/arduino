//project 1 with Male. 20160723

int switchState = 0;

void setup(){

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop(){

  int boton = digitalRead(2);
  
  if(boton == 1){
  
      digitalWrite(3, HIGH);//Led rojo

      digitalWrite(4, HIGH);//Led amarillo

      digitalWrite(5, HIGH);//Led verde
      
      delay(600000);
    }else{
      digitalWrite(3, LOW);//Led rojo

      digitalWrite(4, LOW);//Led amarillo

      digitalWrite(5, LOW);//Led verde
  }
  
  
}



