# TouchControls library APIs #

----------

## TouchToggle

### TouchToggle(const int pin)
Constructor, sets the Arduino I/O pin to which the Touch Toggle's signal lead is connected.
### virtual bool update()
Inherited from StateMachine class, returns true when the TouchToggle's state has been updated.
### void setAuto(const bool mode)
If *mode* is **true**, the Touch Toggle's indication will match its toggled on/off state.  If *mode* is **false**, the Touch Toggle's indication is controlled by calls to the **write** method.
### void write(const bool illum)
For non-auto mode, sets the Touch Toggle's LED(s) to one of its two indications.
### bool read() const
Returns the current toggled state of the Touch Toggle, LOW on the I/O pin returns **true** when read.

## TouchTrigger

### TouchTrigger(const int pin)
Constructor, sets the Arduino I/O pin to which the Touch Trigger's signal lead is connected.
### virtual bool update()
Inherited from StateMachine class, returns true when the TouchTrigger's state has been updated.
### void write(const bool illum)
Sets the Touch Trigger's LED(s) to one of its two indications.  Unlike the Touch Toggle, there is no auto mode for Touch Triggers.
### bool read() const
Returns the current pressed state of the Touch Trigger, LOW on the I/O pin returns **true** when read (control pressed).
### bool isTriggered()
Returns **true** when the Touch Trigger has been pressed since the last time this method was called.  In other words, this method latches a touch to the control until this method is called.  Calling this method clears the triggered state.
