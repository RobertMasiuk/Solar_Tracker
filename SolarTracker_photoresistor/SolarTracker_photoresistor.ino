/* Robert Masiuk
   Test Program
*/
int photoresistor1 = A0;
int photoresistor2 = A1;
int photoresistor3 = A2;
int photoresistor4 = A3;

int optimum = 13;
int sensorValuePhotoresistor1 = 0;
int sensorValuePhotoresistor2 = 0;
int sensorValuePhotoresistor3 = 0;
int sensorValuePhotoresistor4 = 0;

int axisXPlus = 10;
int axisXMinus = 11;

int sensitiveness;

int total = 0;


void setup() {

  pinMode(optimum, OUTPUT);
  pinMode(axisXPlus, OUTPUT);
  pinMode(axisXMinus, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  sensorValuePhotoresistor1 = analogRead(photoresistor1);
  sensorValuePhotoresistor2 = analogRead(photoresistor2);
  sensorValuePhotoresistor3 = analogRead(photoresistor3);
  sensorValuePhotoresistor4 = analogRead(photoresistor4);

  //  total = sensorValuePhotoresistor1 + sensorValuePhotoresistor2 + sensorValuePhotoresistor3 + sensorValuePhotoresistor4;
  //
  //  total = total / 4;
  //  Serial.println(total);
  //  if (sensorValuePhotoresistor1 >= 180) {
  //    Serial.println("test");
  //    digitalWrite(optimum, HIGH);
  //  }
  //  if (sensorValuePhotoresistor1 >= 180) {
  //    Serial.println("test");
  //    digitalWrite(optimum, HIGH);
  //  }
  //

  // ONE AXIS PIN ANALOG 3&1
  sensitiveness = 30;
  if (sensorValuePhotoresistor2 >= 150 || sensorValuePhotoresistor4 >= 150)// CHECK "IF DAY, DO"
  {
    Serial.print(" TEST ");
    
    if (sensorValuePhotoresistor2 >= (sensorValuePhotoresistor4 + sensitiveness)) {
      digitalWrite(axisXPlus, LOW);
      digitalWrite(axisXMinus, HIGH);
      digitalWrite(optimum, LOW);
        delay(100);
    }
    else if(sensorValuePhotoresistor4 >= (sensorValuePhotoresistor2 + sensitiveness)) {
      digitalWrite(axisXPlus, HIGH);
      digitalWrite(axisXMinus, LOW);
      digitalWrite(optimum, LOW);
        delay(100);
    }
  
  

  }

     if((sensorValuePhotoresistor2 - sensitiveness) <= sensorValuePhotoresistor4 <= (sensorValuePhotoresistor2 + sensitiveness)) {
      digitalWrite(axisXPlus, LOW);
      digitalWrite(axisXMinus, LOW);
      digitalWrite(optimum, HIGH);
    }



  Serial.print(sensorValuePhotoresistor1);
  Serial.print(" | ");
  Serial.print(sensorValuePhotoresistor2);
  Serial.print(" | ");
  Serial.print(sensorValuePhotoresistor3);
  Serial.print(" | ");
  Serial.println(sensorValuePhotoresistor4);
  delay(100);
  digitalWrite(optimum, LOW);

}
