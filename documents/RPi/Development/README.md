# Remote Development for the Pi
After completing the steps below, you should be able to 
write C++ code on any device capable of running Visual 
Studio. The code is stored on that device, but it's 
compiled and executed on a Raspberry Pi.

This setup has been tested (and works) on a laptop (Windows 
10) and a Raspberry Pi 3B (Raspbian Jessie), though I don't
see why it couldn't also work for other computer operating
systems and Raspberry Pi versions.

## 1. Install Visual Studio on your computer
More info can be found at the 
[Visual Studio download page](https://visualstudio.microsoft.com/downloads/)

## 2. Prepare Your Pi
### Initial Pi Setup
TODO document initial Pi setup (expand filesystem, set OpenGL driver, etc.)

### SSH Setup
TODO document SSH server/client preparation

### Install C++ Development Packages
TODO document C++ compiler/debugger

### Install SFML
For this project, we need to use the SFML libraries for our Pi.
There is a special repository for this library 
[here](https://github.com/mickelson/sfml-pi).

To install it (and all dependencies) through the command line 
use the following set of commands (taken from the GitHub repository)
```
sudo apt-get install cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev
mkdir build
cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libbrcmEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libbrcmGLESv2.so
sudo make install
sudo ldconfig
```

## 3. Configure Visual Studio
Run Visual Studio Installer to modify your version of Visual Studio
![Image](documents/RPi/Development/images/01.png)
Install the "Linux Development with C++" workload and open Visual
Studio after it's done installing
![Image](documents/RPi/Development/images/02.png)

## 4. Create a New Visual Studio Project
For this project, we'll use the "Raspberry Pi Blink" template
![Image](documents/RPi/Development/images/03.png)
Name your project and give it a home
![Image](documents/RPi/Development/images/04.png)
Study how this project works and read the built-in README very well. 
It will be your friend as you setup your Pi.
![Image](documents/RPi/Development/images/05.png)

## 5. Configure Your Project
Go to the Properties editor for your new project.
![Image](documents/RPi/Development/images/06.png)
A window like this should pop up. Go to the Linker/Input setting
to configure the libraries that should be included when Visual
Studio builds your code.
![Image](documents/RPi/Development/images/07.png)

![Image](documents/RPi/Development/images/08.png)
![Image](documents/RPi/Development/images/09.png)
![Image](documents/RPi/Development/images/10.png)
![Image](documents/RPi/Development/images/11.png)
![Image](documents/RPi/Development/images/12.png)

## 6. Deploy/Debug the code
![Image](documents/RPi/Development/images/13.png)
![Image](documents/RPi/Development/images/14.png)
