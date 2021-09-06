/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce button11 = Bounce(11,10);


void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();

  // Check each button for "falling" edge.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    Keyboard.press(KEY_UP);
  }
  if (button1.fallingEdge()) {
    Keyboard.press(KEY_DOWN);
  }
  if (button2.fallingEdge()) {
    Keyboard.press(KEY_LEFT);
  }
  if (button3.fallingEdge()) {
    Keyboard.press(KEY_RIGHT);
  }
  if (button4.fallingEdge()) { // A
    Keyboard.press(MODIFIERKEY_ALT);
  }
  if (button5.fallingEdge()) { // B
    Keyboard.press(MODIFIERKEY_CTRL);
  }
  if (button6.fallingEdge()) { // X
    Keyboard.press(KEY_SPACE);
  }
  if (button7.fallingEdge()) { // Y
    Keyboard.press(MODIFIERKEY_SHIFT);
  }
  if (button8.fallingEdge()) { // Start
    Keyboard.press(KEY_ENTER);
  }
  if (button9.fallingEdge()) { // Select
    Keyboard.press(KEY_BACKSPACE);
  }
  if (button10.fallingEdge()) { // L
    Keyboard.press(KEY_Z);
  }
  if (button11.fallingEdge()) { // R
    Keyboard.press(KEY_X);
  }

  // Check each button for "rising" edge
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    Keyboard.release(KEY_UP);
  }
  if (button1.risingEdge()) {
    Keyboard.release(KEY_DOWN);
  }
  if (button2.risingEdge()) {
    Keyboard.release(KEY_LEFT);
  }
  if (button3.risingEdge()) {
    Keyboard.release(KEY_RIGHT);
  }
  if (button4.risingEdge()) { // A
    Keyboard.release(MODIFIERKEY_ALT);
  }
  if (button5.risingEdge()) { // B
    Keyboard.release(MODIFIERKEY_CTRL);
  }
  if (button6.risingEdge()) { // X
    Keyboard.release(KEY_SPACE);
  }
  if (button7.risingEdge()) { // Y
    Keyboard.release(MODIFIERKEY_SHIFT);
  }
  if (button8.risingEdge()) { // Start
    Keyboard.release(KEY_ENTER);
  }
  if (button9.risingEdge()) { // Select
    Keyboard.release(KEY_BACKSPACE);
  }
  if (button10.risingEdge()) { // L
    Keyboard.release(KEY_Z);
  }
  if (button11.risingEdge()) { // R
    Keyboard.release(KEY_X);
  }
}
