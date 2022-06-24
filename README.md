# Driving-4-Digit-7-Segment-Display
Arduino (C++) code for driving a 4 digit, 7 segment display. 

Basic process for running the display:
  1. Clear the display
  2. Pick digit 0 on the display
  3. Get the first digit on the value we want to print
  4. Set the digit to the display
  5. Repeat 2-5 for the other digits
  6. Add a small delay, so that we aren't updating the display so much (although this may be redunant for the purposes of time keeping) 


This is the pinout of the 4-digit 7-segment display
![image](https://user-images.githubusercontent.com/51938999/175523353-8912d298-0a71-4be3-bbdf-2da6f6d156aa.png)
