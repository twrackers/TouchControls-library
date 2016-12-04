# TouchControls-library
This library provides C++ classes to support the Berrett Hill line of Touch Toggle and Touch Trigger capacitive-touch controls, designed for the model-railroad market.  More information on these controls can be found at the Berrett Hill web store:

* (http://www.berretthillshop.com/store/products/touch-controls/) for Touch Toggles

* (http://www.berretthillshop.com/store/products/touch-triggers/) for Touch Triggers

All Touch Toggles and Touch Triggers use the same 3-pin 0.1"-spacing connector pinout used by many hobby servos and sensors:
* yellow - signal
* orange - +5 volts
* brown - ground

Each Touch control also has one or two LEDs which by default give an indication of the control's state.
* For Touch Toggles, touching the control causes the control to toggle between a LOW output (near 0 volts) and a HIGH output (near +5 volts).  The LEDs will show this state.
* For Touch Triggers, the LOW output only appears while the control is being touched, so effectively they are *momentary* controls.  By default, they will only show their pressed/non-pressed state, which is of limited usefulness.

What these Arduino classes provide is the ability to control the displayed indication on a Touch control *independent of their toggled or pressed state*.  In other words, you can *read* a control's state while separately *writing* to the control to change the indication it displays.  This capability is pretty much necessary in order to use the Touch Triggers in a useful manner.  With these classes the Touch Toggles can also be operated in the same way.

This library is built upon my StateMachine class, available for download from my GitHub repository at (https://github.com/StateMachine).

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

#### Instructions to install my Arduino libraries and sketches on Windows systems can be found at [gist.github.com/twrackers](https://gist.github.com/twrackers).
