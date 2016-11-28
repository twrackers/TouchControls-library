#include <StateMachine.h>
#include <OneShot.h>
#include <TouchControls.h>

const int tt_pin = 2;
const int stat_pin = 3;

TouchTrigger tt(tt_pin);
OneShot os(5000);

void setup()
{
  pinMode(stat_pin, OUTPUT);
}

void loop()
{
  if (tt.update()) {
    digitalWrite(stat_pin, tt.read() ? HIGH : LOW);
    if (tt.isTriggered()) {
      tt.write(true);
      os.trigger();
    }
  }
  if (os.update()) {
    if (!os.isTriggered()) {
      tt.write(false);
    }
  }
}

