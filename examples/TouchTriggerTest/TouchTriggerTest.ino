// TouchTriggerTest
//
// This Arduino sketch demonstrates the use of the TouchTrigger
// class together with a Berrett Hill Touch Trigger control.
//
// When the Touch Trigger is touched (because that's what you do
// to Touch Triggers), the Arduino's built-in LED (usually connected
// to pin 13) will light as long as the Trigger remains touched.
// The Touch Trigger's own LED(s) will change state and remain so
// until after 5 seconds, when it/they will reset to their original
// state.  The 5-second timeout is retriggerable, so if you repeatedly
// touch the Trigger, the timeout will restart each time.
//
// This sketch requires the following additional libraries, all
// available at the GitHub below.
// * OneShot
// * StateMachine (used by TouchControls and OneShot libraries)
//
// Author: Thomas W Rackers, Nov 2016
// GitHub: https://github.com/twrackers
// Blog:   https://modelrailroadelectronics.blog
//
// For more info on Touch Triggers: http://www.berretthillshop.com/

#include <TouchControls.h>
#include <OneShot.h>

// Define TouchTrigger's I/O pin.
const int tt_pin = 2;

// Use built-in LED to show when Touch Trigger is pressed.
const int stat_pin = LED_BUILTIN;

// Define a TouchTrigger on the specified pin.
TouchTrigger tt(tt_pin);

// Create a OneShot object with an on-time of 5 seconds.
OneShot os(5000);

// setup runs only once after power-on or reset.
void setup()
{
  // Set the LED I/O pin to output and turn LED off.
  pinMode(stat_pin, OUTPUT);
  digitalWrite(stat_pin, LOW);
}

// loop is called repeatedly after setup has returned.
void loop()
{
  // Time to update the TouchTrigger?
  if (tt.update()) {
    // Set the LED to match the TouchTrigger's momentary
    // (not latched) state (pressed -> LED on).
    digitalWrite(stat_pin, tt.read() ? HIGH : LOW);
    // If TouchTrigger is triggered (latched), change the
    // LED state, then trigger the 5-second one-shot.
    if (tt.isTriggered()) {
      tt.write(true);
      os.trigger();
    }
  }
  // Time to update the one-shot?
  if (os.update()) {
    // If it hasn't been triggered, or 5 seconds have passed since
    // the last time it was triggered, change the LED state back.
    if (!os.isTriggered()) {
      tt.write(false);
    }
  }
}
