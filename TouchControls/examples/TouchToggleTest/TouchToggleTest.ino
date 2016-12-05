// TouchToggleTest
//
// This Arduino sketch demonstrates the use of the TouchToggle
// class together with a Berrett Hill Touch Toggle control.
//
// When the Touch Toggle is touched (because that's what you do
// to Touch Toggles), the Arduino's built-in LED (usually connected
// to pin 13) will turn on or of with the internal state of the
// Touch Toggle.
//
// In this demo, the TouchToggle object is set to non-auto mode,
// where the Touch Toggle's LED(s) are controlled by the Arduino
// and not by the Touch Toggle's state.  In this demo, the Touch
// Toggle's LED(s) will flip states every half second, independently
// of when the Touch Toggle gets touched.
//
// In auto mode, the LED(s) are not driven by the Arduino, but by
// the Touch Toggle itself.  This is the way Touch Toggles work
// out of the package.
//
// This sketch is actually compatible with all of the Berrett Hill
// Touch Controls, which includes:
// * Touch Toggles
// * Touch Triggers (momentary equivalents to Touch Toggles)
// * Momentary Touch (yellow shell)
//
// This sketch requires the following additional libraries, all
// available at the GitHub below.
// * Pulser
// * StateMachine (used by TouchControls and Pulser libraries)
//
// Author: Thomas W Rackers, Nov 2016
// GitHub: https://github.com/twrackers
// Blog:   https://modelrailroadelectronics.blog
//
// For more info on Touch Toggles: http://www.berretthillshop.com/

#include <TouchControls.h>
#include <Pulser.h>

// Define TouchToggle's I/O pin.
const int tt_pin = 2;

// Use built-in LED to show Touch Toggle's state.
const int stat_pin = LED_BUILTIN;

// Define a TouchToggle on the specified pin.
TouchToggle tt(tt_pin);

// Create a Pulser object, which flips between on and off states
// on a 1 second cycle (0.1 sec on, 0.9 sec off).
// The shorter on-time will allow you to know which is the on-state
// for the LED(s), and which is the off-state.
Pulser pulser(100, 900);    // (on time, off time) in milliseconds

// setup runs only once after power-on or reset.
void setup()
{
  // Set the LED I/O pin to output and turn LED off.
  pinMode(stat_pin, OUTPUT);
  digitalWrite(stat_pin, LOW);
  // Disable auto mode, this sketch will control the Touch
  // Toggle's LED(s).
  tt.setAuto(false);
}

// loop is called repeatedly after setup has returned.
void loop()
{
  // Time to update the Pulser?
  if (pulser.update()) {
    // Set the Touch Toggle's LED(s) to one indication or the other,
    // depending on the true/false output of the Pulser.
    tt.write(pulser.read());
  }
  // Time to update the TouchToggle?
  if (tt.update()) {
    // Set the Arduino's built-in LED to match the on/off state
    // of the TouchToggle.
    digitalWrite(stat_pin, tt.read() ? HIGH : LOW);
  }
}
