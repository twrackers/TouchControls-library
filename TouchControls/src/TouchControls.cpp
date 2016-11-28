#include "TouchControls.h"

TouchToggle::TouchToggle(const int pin) :
  StateMachine(25, true),
  m_pin(pin),
  m_auto(true),
  m_light(false),
  m_state(false)
{
  pinMode(m_pin, INPUT);
}

bool TouchToggle::update()
{
  if (!StateMachine::update()) return false;
  
  pinMode(m_pin, INPUT);
  m_state = (digitalRead(m_pin) == LOW);
  if (!m_auto) {
    digitalWrite(m_pin, m_light ? HIGH : LOW);
    pinMode(m_pin, OUTPUT);
  }
  return true;
}

void TouchToggle::setAuto(const bool mode)
{
  m_auto = mode;
}

void TouchToggle::write(const bool illum)
{
  m_light = illum;
}

bool TouchToggle::read() const
{
  return m_state;
}

TouchTrigger::TouchTrigger(const int pin) :
  StateMachine(25, true),
  m_pin(pin),
  m_light(false),
  m_state(false),
  m_triggered(false)
{
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, LOW);
}

bool TouchTrigger::update()
{
  if (!StateMachine::update()) return false;

  pinMode(m_pin, INPUT);
  bool pressed = (digitalRead(m_pin) == LOW);
  if (pressed && !m_state) {
    m_triggered = true;
  }
  m_state = pressed;
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, m_light ? HIGH : LOW);
  return true;
}

void TouchTrigger::write(const bool illum)
{
  m_light = illum;
}

bool TouchTrigger::read() const
{
  return m_state;
}

bool TouchTrigger::isTriggered()
{
  bool triggered = m_triggered;
  m_triggered = false;
  return triggered;
}