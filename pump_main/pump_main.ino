
#define GREEN 7
#define BLUE 6
#define YELLOW 5
#define RED 4

#define CLOSED LOW
#define OPEN HIGH
#define SOLENOID_DELAY 2
#define FLUSH_TIME 10

void setup() {
  Serial.begin(9600);
  
  //initialize default signal states
  digitalWrite(RED, OPEN);
  digitalWrite(YELLOW, OPEN);
  digitalWrite(BLUE, CLOSED);
  digitalWrite(GREEN, CLOSED);
  
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  flush_filter(RED);
  flush_filter(YELLOW);
  waitSec(300 - (6*SOLENOID_DELAY + 2*FLUSH_TIME));
}

void waitSec(int nSecs){
  for(int i=0;i<nSecs;i++){
    delay(1000);
  } 
}

/** 
 Additional wait time: 3*SOLENOID_DELAY + FLUSH_TIME seconds 
 Pre/Post-conditions: BLUE, GREEN --> closed, RED, YELLOW --> open
 **/
void flush_filter(int main_valve){
  
  int flush_valve = (main_valve == RED) ? GREEN : BLUE;
  
  digitalWrite(main_valve, CLOSED);
  waitSec(SOLENOID_DELAY);
  digitalWrite(flush_valve, OPEN);
    
  waitSec(FLUSH_TIME);
    
  digitalWrite(flush_valve, CLOSED);
  waitSec(SOLENOID_DELAY);
  digitalWrite(main_valve, OPEN);
  
  waitSec(SOLENOID_DELAY);
}
