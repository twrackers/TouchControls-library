#include <StateMachine.h>
#include <Pulser.h>
#include <TouchControls.h>

const int tt_pin = 2;
const int stat_pin = LED_BUILTIN;

TouchToggle tt(tt_pin);
Pulser pulser(500, 500);

void setup()
{
  pinMode(stat_pin, OUTPUT);
  tt.setAuto(false);
}

void loop()
{
  if (pulser.update()) {
    tt.write(pulser.read());
  }
  if (tt.update()) {
    digitalWrite(stat_pin, tt.read() ? HIGH : LOW);
  }
}
