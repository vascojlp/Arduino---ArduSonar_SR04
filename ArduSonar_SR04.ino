#include <NewPing.h>

 
#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   delay(50);
   unsigned int uS = sonar.ping_cm();
   Serial.print(uS);
   Serial.print("cm");
}
