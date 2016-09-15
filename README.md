# Marlin4Due Firmware for AMBIT
<img align="right" src="Documentation/Logo/Marlin%20Logo%20GitHub.png" />

### Modified for AMBIT (Experimental)
This firmware is an experimental fork of Marlin4Due with the necessary modifications to run UltiMachine's new AMBIT 3d controller. 


WORKS WITH ARDUINO 1.6.0 ONLY!!!
Use the fork ambit-addons160 and copy ArduinoAddons/Arduino_1.6.0/hardware/ultimachine TO
c:/program files (might be x86)/Arduinoxxx/hardware    
That gives the ambit board info to arduino

THEN use the fork Ambit_SPIFLASH-merged for the firmware




### Instructions
Download Arduino 1.6.0 and then install the ArduinoAddons for Arduino_1.6.0.

### Original Marlin4Due Readme
  * [Marlin4Due Readme](/Documentation/Marlin4Due.md)

### This is an experimental repository! You should never leave your printer alone.

### known issues:
* watchdog doesn't work
* advanced extruder not implemented
* some drivers are too slow, i'm working on a solution [FIXED FOR AMBIT]

---
# Marlin 3D Printer Firmware
  * [Configuration & Compilation](/Documentation/Compilation.md)
  * Supported
    * [Features](/Documentation/Features.md)
    * [Hardware](/Documentation/Hardware.md)
    * [GCodes](/Documentation/GCodes.md)
  * Notes
    * [Auto Bed Leveling](/Documentation/BedLeveling.md)
    * [Filament Sensor](/Documentation/FilamentSensor.md)
    * [Ramps Servo Power](/Documentation/RampsServoPower.md)
    * [LCD Language - Font - System](Documentation/LCDLanguageFont.md)
    * [Mesh Bed Leveling](/Documentation/MeshBedLeveling.md)

##### [RepRap.org Wiki Page](http://reprap.org/wiki/Marlin)

## Quick Information

This is a firmware for reprap single-processor electronics setups.
It also works on the Ultimaker PCB. It supports printing from SD card+Folders and look-ahead trajectory planning.
This firmware is a mashup between [Sprinter](https://github.com/kliment/Sprinter), [grbl](https://github.com/simen/grbl), and many original parts.

## Current Status: Bug Fixing


## Credits

The current Marlin4Due dev team consists of:

 - Nico [@wurstnase]
 - 

## Donation

If you find our work usefull please consider donating. Donations will be used to pay for our website http://www.marlinfirmware.org/ and to pay some food or rent money for the very active Collaborators

More features have been added by:
  - Lampmaker,
  - Bradley Feldman,
  - and others...

## License

Marlin is published under the [GPL license](/Documentation/COPYING.md) because We believe in open development.
Do not use this code in products (3D printers, CNC etc) that are closed source or are crippled by a patent.

Marlin4Due [![Flattr Marlin4Due](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=Wurstnase&url=https%3A%2F%2Fgithub.com%2FWurstnase%2FMarlin4Due) MarlinFirmware [![Flattr MarlinFirmware](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
