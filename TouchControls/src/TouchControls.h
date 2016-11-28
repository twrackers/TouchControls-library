#ifndef _TOUCH_CONTROLS__H_
#define _TOUCH_CONTROLS__H_

#include <StateMachine.h>

class TouchToggle : public StateMachine
{
private:
  const int m_pin;
  bool m_auto;
  bool m_light;
  bool m_state;

public:
  TouchToggle(const int pin);
  virtual bool update();
  void setAuto(const bool mode);
  void write(const bool illum);
  bool read() const;
};

class TouchTrigger : public StateMachine
{
private:
  const int m_pin;
  bool m_light;
  bool m_state;
  bool m_triggered;

public:
  TouchTrigger(const int pin);
  virtual bool update();
  void write(const bool illum);
  bool read() const;
  bool isTriggered();
};

#endif
