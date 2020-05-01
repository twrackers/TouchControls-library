#ifndef _TOUCH_CONTROLS__H_
#define _TOUCH_CONTROLS__H_

// TouchControls.h
//
// Author: Thomas W Rackers, Nov 2016
// GitHub: https://github.com/twrackers
// Blog:   https://modelrailroadelectronics.blog
//
// For more info on Touch Triggers: http://www.berretthillshop.com/

#include <StateMachine.h>

class TouchToggle : public StateMachine
{
private:
  const int m_pin;  // I/O pin connected to Touch Toggle
  bool m_auto;      // false = LEDs controlled programmatically,
                    // true = LEDs controlled by TouchToggle state
  bool m_light;     // LED state when not in auto mode
  bool m_state;     // Touch Toggle state, true = active low input

public:
  // Constructor.
  // @param pin I/O pin connected to Touch Toggle signal
  TouchToggle(const int pin);
  
  // Update state machine of this object.
  // Overrides StateMachine::update.
  // @return true if state updated during this call
  virtual bool update();
  
  // Set auto-mode on or off.
  // @param mode true for auto mode (Touch Toggle controls its own
  //   LEDs), false for control of LEDs by I/O pin
  void setAuto(const bool mode);
  
  // Set state of Touch Toggle's LEDs, only effective when in
  //   non-auto mode.
  // @param illum true sets LEDs to same state as when state is
  //   ON (active low) in auto mode
  void write(const bool illum);
  
  // Return current state of Touch Toggle as input.
  // @return false when Touch Toggle high (not active),
  //   true when Touch Toggle is active (low)
  bool read() const;
};

class TouchTrigger : public StateMachine
{
private:
  const int m_pin;  // I/O pin connected to Touch Trigger
  bool m_light;     // LED state
  bool m_state;     // Touch Toggle state, true = active low input
  bool m_triggered; // true after Touch Trigger is touched
                    //   until after call to isTriggered

public:
  // Constructor.
  // @param pin I/O pin connected to Touch Trigger signal
  TouchTrigger(const int pin);
  
  // Update state machine of this object.
  // Overrides StateMachine::update.
  // @return true if state updated during this call
  virtual bool update();
  
  // Set state of Touch Trigger's LEDs.
  // @param illum new state of LEDs
  void write(const bool illum);
  
  // Return current state of Touch Trigger as input.
  // @return false when Touch Trigger not pressed,
  //   true when Touch Trigger is pressed
  bool read() const;
  
  // Return latched state.
  // When a Touch Trigger is pressed, this condition is latched.
  // When this method is called, it will return true if a pressed
  //   has been latched since the previous call to this method.
  // Calling this method will clear an existing latched condition.
  // @return latched state, true = press latched
  bool isTriggered();
};

#endif
