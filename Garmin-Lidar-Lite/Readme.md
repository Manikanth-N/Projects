# Garmin Lidar Lite V3

## Agenda

This repository contains a C++ library for interfacing with the Garmin Lidar Lite V3 sensor to read distance measurements.

## Features

- **Simple Interface**: Provides an easy-to-use interface for reading distance measurements from the Lidar Lite V3 sensor.

- **Compatibility**: Designed to work seamlessly with the Garmin Lidar Lite V3 sensor.

## Installation

To use this library, simply clone the repository and include the necessary header files in your project.

```bash
git clone https://github.com/yourusername/garmin-lidar-lite-v3.git
```


## Snippets
- llv3_socket_master.py : this script creates a master socket port and listens on it
- llv3_socket_slave.py  : this script listens on the socket port, it is listens to script of socket created in cpp
- llv3_subprocess.py : this script has input of compiled cpp file to create a sub process and gets the data
