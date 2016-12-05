# TouchControls-library
This library provides C++ classes to support the Berrett Hill line of Touch Toggle and Touch Trigger capacitive-touch controls, designed for the model-railroad market.  More information on these controls can be found at the Berrett Hill web store:

* [www.berretthillshop.com/store/products/touch-controls](http://www.berretthillshop.com/store/products/touch-controls/) for Touch Toggles

* [www.berretthillshop.com/store/products/touch-triggers](http://www.berretthillshop.com/store/products/touch-triggers/) for Touch Triggers

All Touch Toggles and Touch Triggers use the same 3-pin 0.1"-spacing connector pinout used by many hobby servos and sensors:
* yellow - signal
* orange - +5 volts
* brown - ground

Each Touch control also has one or two LEDs which by default give an indication of the control's state.
* For Touch Toggles, touching the control causes the control to toggle between a LOW output (near 0 volts) and a HIGH output (near +5 volts).  The LEDs will show this state.  At the time of this writing, Touch Toggles come in three flavors.

  * The One Light version has a single red/green LED, and comes in a gray shell.
  * The Two Light Red/Green version has one LED of each color, and comes in a black shell.
  * The Two Light Green/Green version has a pair of green LEDs, and comes in a green shell.
    
* For Touch Triggers, the LOW output only appears while the control is being touched, so effectively they are *momentary* controls.  Touch Triggers require some form of external logic (such as an Arduino with appropriate code running) in order to display a useful indication.  At the time of this writing, there are four flavors of Touch Triggers.

  * The One Light version has a single red/green LED, and comes in a gray-and-orange shell.
  * The Two Light Red/Green version has one LED of each color, and comes in a black-and-orange shell.
  * The Two Light Green/Green version has a pair of green LEDs, and comes in a green-and-orange shell.
  * Not technically a Touch Trigger but working in the same manner is the Momentary Touch Control with a single yellow LED, in a yellow shell.  Of the four, this is the only one which, like the Touch Toggles, can be used with or without external control of the LED.

What these Arduino classes provide is the ability to control the displayed indication on a Touch Control *independent of their toggled or pressed state*.  In other words, you can *read* a control's state while separately *writing* to the control to change the indication it displays.  This capability is pretty much necessary in order to use the Touch Triggers in a useful manner.  With these classes the Touch Toggles can also be operated in the same way.

This library is built upon my StateMachine class, available for download from my GitHub repository at [github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library).

#### Instructions to install my Arduino libraries and sketches on Windows systems can be found at [github.com/twrackers/MyDocuments/blob/master/Installation_to_Arduino.md](https://github.com/twrackers/MyDocuments/blob/master/Installation_to_Arduino.md).

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
