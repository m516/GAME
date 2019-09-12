# Remote Development for the Pi
After completing the steps below, you should be able to write C++ code on any device capable of running Visual Studio. The code is stored on that device, but it's compiled and executed on a Raspberry Pi.

This setup has been tested (and works) on a laptop (Windows 10) and a Raspberry Pi 3B (Raspbian Jessie), though I don't see why it couldn't also work for other computer operating systems and Raspberry Pi versions.

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
For this project, we need to use the SFML libraries for our Pi. There is a special repository for this library [here](https://github.com/mickelson/sfml-pi).

To install it (and all dependencies) through the command line, use the following set of commands (taken from the GitHub repository)
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

Edit the Library Dependencies option if necessary. 
![Image](documents/RPi/Development/images/08.png)

The values in this field will tell Visual Studio what installed libraries to  link into your project. When Visual Studio builds your code and populates its intellisense code completion database, it will look for these libraries. (To link a project on the Pi with an installed library called *foo*, it adds -l*foo* to the build command automatically). 

SFML names its libraries as follows:
*  sfml-graphics [Graphics Module](https://www.sfml-dev.org/tutorials/2.5/#graohics-module)
*  sfml-window [Window Module](https://www.sfml-dev.org/tutorials/2.5/#window-module)
*  sfml-system [System Module](https://www.sfml-dev.org/tutorials/2.5/#system-module)
*  sfml-audio [Audio Module](https://www.sfml-dev.org/tutorials/2.5/#audio-module)
*  sfml-network [Network Module](https://www.sfml-dev.org/tutorials/2.5/#network-module)

![Image](documents/RPi/Development/images/09.png)

SFML depends on an X11 display for rendering graphics, but when a program is run apart from X11 (e.g. via SSH or TTY), it will not have access to that display. If X11 isn't installed on the Pi (as is the case with Raspbian lite), install it with the following commands:

```
sudo apt-get update
sudo apt-get upgrade
sudo apt install lxde lxde-core lxterminal lxappearance
sudo apt install lightdm
sudo apt install xinit
sudo apt install raspberrypi-ui-mods
```
Then in Visual Studio, set the pre-launch command to `export DISPLAY=:0`
![Image](documents/RPi/Development/images/10.png)

To clean up your build settings, if you removed the Blink code and your project doesn't depend on WiringPi anymore, or if you want to add your own post-bulid commands, remove/replace the "command line" and "description" fields under Build Events/Remote Post-Build Events
![Image](documents/RPi/Development/images/11.png)

Repeat this process for all your project deployment configurations. What fun!
![Image](documents/RPi/Development/images/12.png)

## 6. Deploy/Debug the code
Write your code...
![Image](documents/RPi/Development/images/13.png)

...and (hopefully) SFML works on your Pi!
![Image](documents/RPi/Development/images/14.png)
