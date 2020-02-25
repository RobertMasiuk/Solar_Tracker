/* Robert Masiuk
   Test Program
*/
int photoresistor1 = A0;
//int photoresistor2 = A1;
int photoresistor3 = A2;
int photoresistor4 = A3;

int optimum = 13;
int sensorValuePhotoresistor1 = 0;
int sensorValuePhotoresistor2 = 0;
int sensorValuePhotoresistor3 = 0;
int sensorValuePhotoresistor4 = 0;

int total = 0;


void setup() {

  pinMode(optimum, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  sensorValuePhotoresistor1 = analogRead(photoresistor1);
  sensorValuePhotoresistor2 = analogRead(photoresistor2);
  sensorValuePhotoresistor3 = analogRead(photoresistor3);
  sensorValuePhotoresistor4 = analogRead(photoresistor4);

  total = sensorValuePhotoresistor1 + sensorValuePhotoresistor2 + sensorValuePhotoresistor3 + sensorValuePhotoresistor4;

  total = total / 4;
  Serial.println(total);
  if (sensorValuePhotoresistor1 >= 180) {
    Serial.println("test");
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
