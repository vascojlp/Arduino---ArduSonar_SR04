 /*
 Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 11;    //Trig - green Jumper
int echoPin = 12;    //Echo - yellow Jumper
long duration, cm, inches;
int val = 0;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
 
 
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  if(cm >= 0 && cm <= 400 ) {
    val = map(cm, 0, 400, 0, 1023);
    analogWrite(3, val);
    }else {
      val = 0;
    analogWrite(3, val);
    }
  
  if(cm > 400){
    Serial.println("OUT OF RANGE !!!");
    } else {
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(duration);
  Serial.print(" ,");
  Serial.print(val);
  Serial.println();
  }
  
  
  
  delay(50);
}
