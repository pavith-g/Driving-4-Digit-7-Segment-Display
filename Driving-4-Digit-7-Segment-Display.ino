//Temperature Sensor Pins
const int tempRead = A0;
const int ButtonRead = A1;

// Display Pins
const int D1 = 2;
const int D2 = 3;
const int D3 = 4;
const int D4 = 5;
const int A = 6;
const int B = 7;
const int C = 8;
const int D = 9;
const int E = 10;
const int F = 11;
const int G = 12;
const int P = 0;

// Other Values
int del = 5;

// Temp Values
float rawTempVal = 0;
int tempVal = 0;
float celVal = 0;
float fahVal = 0;

// Button Values
int buttonState;
int lastButtonState;
int tempState;



//Displaying Temperature

void pickDigit(int x) { //light up a 7-segment display
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
void three() //the 7-segment led display 3
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void four() //the 7-segment led display 4
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void five() //the 7-segment led display 5
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void six() //the 7-segment led display 6
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void fahrenheit(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  
}

void celsius(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
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

// Main Loops


void setup() {
  Serial.begin(9600);
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
  pinMode(tempRead, INPUT);
  pinMode(ButtonRead, INPUT_PULLUP);


  buttonState = digitalRead(ButtonRead);
}


void loop() {
  // TOGGLE BUTTON
  lastButtonState = buttonState;
  buttonState = digitalRead(ButtonRead);

  if (lastButtonState == HIGH && buttonState == LOW){
    Serial.println("BUTTON PRESSED");

    //Toggle Temp State
    tempState = !tempState;    
  }

  
  // TEMPERATURE
  rawTempVal = analogRead(tempRead);
  rawTempVal = (rawTempVal / 1024.0) * 5000;
  celVal = rawTempVal / 10;
  fahVal = (celVal * 9) / 5 + 32;

  // SELECT TEMPERATURE TYPE
 
  if (tempState) {
    tempVal = (int)celVal;
  }
  else {
    tempVal = (int)fahVal;
  }
  
  Serial.println(tempVal);

  
  // DISPLAY
  
  //clearLEDs();//clear the 7-segment display screen
  pickDigit(4);//Light up 7-segment display d1
  if (tempState){
    celsius();
  }
  else{
    fahrenheit();
  }
  
  delay(del);//delay 5ms
  

  //clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d2
  pickNumber((tempVal % 1000) / 100); // get the value of hundred
  delay(del);//delay 5ms

  //clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d3
  pickNumber(tempVal % 100 / 10); //get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d4
  pickNumber(tempVal % 10 / 1); //Get the value of single digit
  delay(del);//delay 5ms

 

  


}
