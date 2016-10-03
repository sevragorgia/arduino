const int redPin = 9;
const int bluePin = 10;
const int greenPin = 11;

const int redSensorPin = A0;
const int blueSensorPin = A1;
const int greenSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup(){

   Serial.begin(9600);
   pinMode(redPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(greenPin, OUTPUT);
}


void loop(){

  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  Serial.print("Raw/transformed sensor Values \t R: ");
  Serial.print(redSensorValue);
  Serial.print("/");
  Serial.print(redValue);  
  Serial.print("\t B: ");
  Serial.print(blueSensorValue);
  Serial.print("/");
  Serial.print(blueValue);  
  Serial.print("\t G: ");
  Serial.print(greenSensorValue);
  Serial.print("/");
  Serial.println(greenValue);  

  
  
  analogWrite(redPin, redValue);
  analogWrite(bluePin, blueValue);
  analogWrite(greenPin, greenValue);
  
}




