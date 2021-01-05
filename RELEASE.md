# Mfgtest application for mbed-os

### What's Included?

Please refer to the [README.md](./README.md)

v3.0.0 : Mfgtest application supports MBED-OS 6.2.0 
Version 3.0.0 is built from the current Github repo.

### Release Versions
|  Mfgtest App (version) |       MBED-OS  Version   |
|  :---                  |       :-------------:    |
|  v3.0.0                |       MBED-OS 6.2.0      |
|  v2.0.0                |       MBED-OS 6.2.0      |
|  v1.0.0                |       MBED-OS 5.12.0     |


### Supported Software and Tools
This version of the Mfgtest app was validated for compatibility with the following Software and Tools:

| Software and Tools     | Version |
| :---                   | :----:  |
| GCC Compiler           | 9.2.0   |
| ARM Compiler 6         | 6.14    |
| MBED OS                | 6.2.0   |

### Known Issues

### ChangeLog
The following Changes are done from v2.0.0 to v3.0.0:
* MfgTest App generated from new repo which is publicly available.
* Added support for CYW43438 and CYW4373 Wlan Chips and supported Cypress targets.
* Adapted mbed_app.json for shared mfg-test repo for MfgTest App.

The following Changes are done from v1.0.0 to v2.0.0:
* For mbed-os 6.0 compatibility, Adapt the  to newer MBED-OS 6.x APIs. Also fix errors/warnings in Mfgtest code
* Added Support for ARMC6, needed some fixes for it
* Adapted mbed_app.json for mbed-os 6.x requirements for tty output for wl_tool utility
* Update README.md and RELEASE.md files. 
