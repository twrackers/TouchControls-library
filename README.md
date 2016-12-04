# TouchControls-library
This library provides C++ classes to support the Berrett Hill line of Touch Toggle and Touch Trigger capacitive-touch controls, designed for the model-railroad market.  More information on these controls can be found at the Berrett Hill web store:

(http://www.berretthillshop.com/store/products/touch-controls/)
(http://www.berretthillshop.com/store/products/touch-triggers/)

All Touch Toggles and Touch Triggers use the same 3-pin 0.1"-spacing connector pinout used by many hobby servos and sensors:
* yellow - signal
* orange - +5 volts
* brown - ground

Each Touch control also has one or two LEDs which by default give an indication of the control's state.
* For Touch Toggles, touching the control causes the control to toggle between a LOW output (near 0 volts) and a HIGH output (near +5 volts).  The LEDs will show this state.
* For Touch Triggers, the LOW output only appears while the control is being touched, so effectively they are *momentary* controls.  By default, they will show their pressed/non-pressed state, which is of limited usefulness.

What these Arduino classes provide is the ability to control the displayed indication on a Touch control *independent of their toggled or pressed state*.  In other words, you can *read* a control's state while separately *writing* to the control to change the indication it displays.

This library is built upon my StateMachine class, available for download from my GitHub repository at (https://github.com/StateMachine).

#### Instructions to install my Arduino libraries and sketches on Windows systems can be found at [gist.github.com/twrackers](https://gist.github.com/twrackers).
