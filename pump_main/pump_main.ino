#define GREEN 7
#define BLUE 6
#define YELLOW 5
#define RED 4

#define CLOSED LOW
#define OPEN HIGH
#define PRESSURE_DELAY 10
#define FLUSH_TIME 30
#define REGULAR_OPERATION_TIME 300

void setup() {
	Serial.begin(9600);
	
	//initialize startup pin numbers and modes
	pinMode(RED, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);
  
	//initialize startup signal states
	digitalWrite(RED, OPEN);
	digitalWrite(YELLOW, CLOSED);
	digitalWrite(GREEN, CLOSED);
	digitalWrite(BLUE, CLOSED);
	
	wait(30); 
}

void loop() {
	digitalWrite(YELLOW, OPEN);
	wait(PRESSURE_DELAY); 

	digitalWrite(RED, CLOSED);
	wait(PRESSURE_DELAY); 

	digitalWrite(GREEN, OPEN);
	wait(FLUSH_TIME); 

	digitalWrite(GREEN, CLOSED);
	wait(REGULAR_OPERATION_TIME); 

	digitalWrite(RED, OPEN);
	wait(PRESSURE_DELAY); 

	digitalWrite(YELLOW, CLOSED);
	wait(PRESSURE_DELAY); 

	digitalWrite(BLUE, OPEN);
	wait(FLUSH_TIME); 

	digitalWrite(BLUE, CLOSED);
	wait(REGULAR_OPERATION_TIME); 
}

/* Waits the specified amount of seconds. Since an arduino seems
 * to have problems with counting to 5 minutes worth of milliseconds,
 * this loop keeps track of the seconds, and lets the arduino count
 * off the milliseconds
 */
void wait(int secondsToWait){
	// in the last iteration of the pump, a for loop seemed to have a few problems with
	// going above 2 minutes. I'm using a while loop here and seeing if it works

	int secondsElapsed = 0;
	while(secondsElapsed < secondsToWait) {
		delay(1000);
		secondsElapsed++;
	}
	
	return; //done waiting
}

