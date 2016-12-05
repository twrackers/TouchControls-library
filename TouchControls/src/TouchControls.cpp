#include "TouchControls.h"

// TouchControls.cpp
//
// Author: Thomas W Rackers, Nov 2016
// GitHub: https://github.com/twrackers
// Blog:   https://modelrailroadelectronics.blog
//
// For more info on Touch Triggers: http://www.berretthillshop.com/

// TouchToggle

TouchToggle::TouchToggle(const int pin) :
  StateMachine(25, true),   // 25 msec <=> 40 samples/sec
  m_pin(pin),               // I/O pin
  m_auto(true),             // auto mode
  m_light(false),           // LED state
  m_state(false)            // toggle state
{
  // Set pin to input mode for first read.
  pinMode(m_pin, INPUT);
}

bool TouchToggle::update()
{
  // Do nothing if it's not time to update yet.
  if (!StateMachine::update()) return false;
  
  // Set pin to input mode, then read.
  pinMode(m_pin, INPUT);
  m_state = (digitalRead(m_pin) == LOW);
  // If in auto mode, return.  Pin remains in input mode.
  if (m_auto) return true;
  // Otherwise, set pin's output state and set it
  // to output mode.
  digitalWrite(m_pin, m_light ? HIGH : LOW);
  pinMode(m_pin, OUTPUT);
  
  return true;
}

void TouchToggle::setAuto(const bool mode)
{
  // Set or clear auto mode.  Will take effect upon
  // next update.
  m_auto = mode;
}

void TouchToggle::write(const bool illum)
{
  // Set state of LEDs, will take effect upon next update,
  // but only in non-auto mode.
  m_light = illum;
}

bool TouchToggle::read() const
{
  // Return Touch Toggle's output state.
  return m_state;
}

// TouchTrigger

TouchTrigger::TouchTrigger(const int pin) :
  StateMachine(25, true),   // 25 msec <=> 40 samples/sec
  m_pin(pin),               // I/O pin
  m_light(false),           // LED state
  m_state(false),           // pressed state
  m_triggered(false)        // latched press state
{
  // Set pin to output initialize to LOW (off).
  // This sets the initial state of the LEDs.
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, LOW);
}

bool TouchTrigger::update()
{
  // Do nothing if it's not time to update yet.
  if (!StateMachine::update()) return false;

  // Set pin to input mode, then read.
  pinMode(m_pin, INPUT);
  bool pressed = (digitalRead(m_pin) == LOW);
  // If not pressed before but is now,
  // set triggered state true.
  if (pressed && !m_state) {
    m_triggered = true;
  }
  // Update the pressed state.
  m_state = pressed;
  // Set pin back to output mode and set LEDs again.
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, m_light ? HIGH : LOW);
  
  return true;
}

void TouchTrigger::write(const bool illum)
{
  // Set state of LEDs, will take effect upon next update.
  m_light = illum;
}

bool TouchTrigger::read() const
{
  // Return Touch Trigger's pressed state from most recent update.
  return m_state;
}

bool TouchTrigger::isTriggered()
{
  // Reset triggered state, return state prior to this call.
  bool triggered = m_triggered;
  m_triggered = false;
  return triggered;
}