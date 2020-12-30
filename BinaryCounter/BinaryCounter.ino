//Program that displays numbers 0 - 15 using 4 LEDS.
//The red led represents the most significant bit. The white led represents the least significant bit.
//Each led is connected to a 330 ohm resistor.
int redLedPin = 8;
int blueLedPin = 7;
int greenLedPin = 6;
int whiteLedPin = 5;
int _delay = 1000;

void setup() {
  //Set up pin
  for (int i = redLedPin; i >= whiteLedPin; i--) {
    pinMode(i, OUTPUT);
  }
}

//Turn off all leds.
void reset() {
  for (int i = redLedPin; i >= whiteLedPin; i--) {
    digitalWrite(i, LOW);
  }
}
//Time complexity: O(1) Space complexity: O(1)
void loop() {
  for (int i = 0; i < 16; i++) {
    int temp = i;
    //Extract the last 4 least significant bits.
    for (int j = 0; j < 4; j++) {
      int _bit = temp & 1;
      temp = temp >> 1;
      digitalWrite(j + whiteLedPin, (_bit == 0) ? LOW : HIGH);
    }
    //Delay to let user's see LED.
    delay(_delay);
    //Turn off all the LEDS.
    reset();
    //Delay before the next number.
    delay(_delay - 300);
  }
  delay(_delay);

}
