

const int buttonPin = 2;    // Button is connected to Arduino pin 2.
const int LEDa = 4;         // LEDa is connected to pin 4.
const int LEDb = 7;         // LEDb is connected to pin 7.


int buttonCounter = 0;      // Variable for counting button press.

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

// Shifts and shows which part (A or B) the user is calculating
void loop () {
  if (digitalRead(buttonPin)) {
  
    buttonCounter++;        // Counts every time user press the button
    
    digitalWrite(LEDa, buttonCounter % 2);    // If buttonCounter is an even number, LEDa lights. 
    digitalWrite(LEDb, !(buttonCounter % 2)); // If buttonCounter is an odd number, LEDb lights.

    delay(600);       // Delays the counting with 6 milliseconds.
    
    if (!(buttonCounter % 2)) {
      Serial.println("B");          // If buttonCounter is even, call function B.
    }
    if (buttonCounter %2) {   
      Serial.println("A");            // If buttonCounter is odd, function A.
    }
    
  
    } 
  }
