// Display Pins

// Adjust the pin values accordingly
// These pins refer to which digit on the display to update
const int D1 = 2;
const int D2 = 3;
const int D3 = 4;
const int D4 = 5;

// These pins refer to which segment on the digit to update
const int A = 6;
const int B = 7;
const int C = 8;
const int D = 9;
const int E = 10;
const int F = 11;
const int G = 12;
const int P = 0;


int del = 5; // Delay between updating display (ms)
int value = 2345; // This is the value that will be printed onto the display - The maxmimum value is 9999

int digits[] = {0, 0, 0, 0}; // For debugging purposes

void pickDigit(int x) { 
  // Pick which digit we want to update
  // Note that setting the digit high, means that it is not selected. Setting it low, means we select it. 
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  switch (x)
  {
    case 0:
      digitalWrite(D1, LOW);//Light d1 up
      break;
    case 1:
      digitalWrite(D2, LOW); //Light d2 up
      break;
    case 2:
      digitalWrite(D3, LOW); //Light d3 up
      break;
    default:
      digitalWrite(D4, LOW); //Light d4 up
      break;
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(P, LOW);
}

// --- Different combinations of segments for each number 0 - 9 ---- // 
void zero() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(P, LOW);
}

void one() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(P, LOW);
}

void two()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(P, LOW);
}
void three() 
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void four() 
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void five()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void six()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void seven()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void eight()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void nine()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void pickNumber(int x)
{
  switch (x)
  {
    default:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}

void setup() {
  Serial.begin(9600);
  
  // Set pin values on arduino
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(P, OUTPUT);
}


void loop() {
  // Update the 4 DIGIT DISPLAY
  
  /* Basic process:
  1. Clear the display
  2. Pick digit 0 on the display
  3. Get the first digit on the value we want to print
  4. Set the digit to the display
  5. Repeat 2-5 for the other digits
  6. Add a small delay, so that we aren't updating the display so much (although this may be redunant for the purposes of time keeping) 
  */

  
  
  pickDigit(0);
  clearLEDs();
  pickNumber((value % 10000) / 1000); // Get the first digit and update
  digits[0] = (value % 10000) / 1000;

  pickDigit(1);
  clearLEDs();
  pickNumber((value % 1000) / 100); // Get the second digit and update
  digits[1] = (value % 1000) / 100;

  pickDigit(2);
  clearLEDs();
  pickNumber((value % 100) / 10); // Get the third digit and update
  digits[2] = ((value % 100) / 10);

  pickDigit(3);
  clearLEDs();
  pickNumber((value % 10) / 1); // Get the fourth digit and update
  digits[3] = ((value % 10) / 1);


  // Print each digit individually, make sure it's working as intended. 
  for (int i = 0; i < 4; i++){
    Serial.print(digits[i]);
    Serial.print(" ");
  }
  Serial.println();
  
  delay(del); // Optional line

  

 

  


}
