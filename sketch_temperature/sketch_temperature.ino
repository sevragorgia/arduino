
const int sensorPin = A0;
const int calibrateSwitch = 2;
const int calibrateLED = 6;

const float baselineTemp = 25.0;//room temperature

//define own function to print to serial
void print2Serial(int raw, float volt, float temp);

void setup(){

   Serial.begin(9600);
   
   for(int pinNumber = 2; pinNumber<7; pinNumber++){
   
     if(pinNumber == 2){
       pinMode(pinNumber, INPUT);
     }else{
       pinMode(pinNumber, OUTPUT);
       digitalWrite(pinNumber, LOW);   
     }
   }
}

void print2Serial(int raw, float volt, float temp){

  Serial.print("Sensor value: ");
  Serial.print(raw);
    
  Serial.print(", Volts: ");
  Serial.print(volt);
  
  Serial.print(", degrees C: ");

  Serial.println(temp);
}

void loop (){

  int sensorVal = analogRead(sensorPin);
  int calibrateSwitchVal = digitalRead(calibrateSwitch);
  
  if(calibrateSwitchVal == HIGH){//if user press calibrate button turn led on and listen sensor for 5 seconds
    
    digitalWrite(calibrateLED, HIGH);
    //more code to come maybe with a function.
    delay(5000);
    digitalWrite(calibrateLED, LOW);
  
  }else{//we are in measuring mode
  
    float voltage = (sensorVal/1024.0)*5.0;
    float temperature = (voltage - 0.5)*100;
    
    print2Serial(sensorVal, voltage, temperature);
    
    //for the time being keep this here. Move to function later.
    
      if(temperature < baselineTemp){
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }else if(temperature >= baselineTemp && temperature < baselineTemp+5){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);  
    }else if(temperature >= baselineTemp+5 && temperature < baselineTemp+10){
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);  
    }else if(temperature >= baselineTemp+10){
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);  
    }
  }
  delay(1);
}






  


