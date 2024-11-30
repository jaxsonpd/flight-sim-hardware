# Flight Sim Hardware

Hardware for the MSFS2020 flight sim.

This project is split into two sections. One is the [sim-translator] which handles communication with the flight simulator and the other is the [sim-firmware] which is what samples the various inputs. This data is sent over the serial port to the sim-translator where the flight simulator is then manipulated.

## Helpful links:
Event Ids: https://learn.microsoft.com/en-us/previous-versions/microsoft-esp/cc526980(v=msdn.10)
Simulation Variables: https://learn.microsoft.com/en-us/previous-versions/microsoft-esp/cc526981(v=msdn.10)