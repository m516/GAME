# Remote Development for the Pi
After completing the steps below, you should be able to write C++ code on any device capable of running Visual Studio. The code is stored on that device, but it's compiled and executed on a Raspberry Pi.

This setup has been tested (and works) on a laptop (Windows 10) and a Raspberry Pi 3B (Raspbian Jessie), though I don't see why it couldn't also work for other computer operating systems and Raspberry Pi versions.

## 1. Install Visual Studio on your computer
More info can be found at the 
[Visual Studio download page](https://visualstudio.microsoft.com/downloads/)

## 2. Prepare Your Pi

### TL;DR
In a Raspberry Pi terminal type

```
sudo raspi-config nonint do_expand_rootfs
sudo raspi-config nonint get_config_var gpu_mem_256 /boot/config.txt
sudo raspi-config nonint do_ssh 0
sudo apt-get install make git openssh-server g++ gdb gdbserver cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev
cd
git clone https://github.com/mickelson/sfml-pi.git
cd sfml-pi
mkdir build
cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libbrcmEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libbrcmGLESv2.so
sudo make install
sudo ldconfig
sudo apt-get install boost-all-dev libssl1.0-dev
cd
git clone --recurse-submodules https://github.com/socketio/socket.io-client-cpp.git
cd socket.io-client-cpp/
cmake ./
sudo make install
cd
sudo apt-get install boost-all-dev libssl1.0-dev libwebsocketpp-dev libwebsocketpp-doc
```

### Initial Pi Setup
* [Install Raspbian](https://www.raspberrypi.org/documentation/installation/installing-images/README.md)
* Use [raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md) to expand the Pi's filesystem, enable SSH, set the GPU memory to something decent and set the GL driver to "full KMS" to acclerate graphics with the GPU.

**Cool Pi hack:** raspi-config doesn't need the interactive menus. You can do most of the same things with commands such as these [(Source)](https://github.com/l10n-tw/rc_gui/blob/master/src/rc_gui.c):
```
raspi-config nonint do_expand_rootfs
raspi-config nonint get_config_var gpu_mem_256 /boot/config.txt
raspi-config nonint do_ssh 0
```

Then install packages for compiling and debugging C++

```
sudo apt-get install openssh-server g++ gdb gdbserver avahi-daemon
```

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

### Install Websocket++
This project also requires [Websocket++](https://www.zaphoyd.com/websocketpp/) to connect to the server. To install it on the Raspberry Pi, use these commands:
```
sudo apt-get install boost-all-dev libssl1.0-dev libwebsocketpp-dev libwebsocketpp-doc
```

## 3. Configure Visual Studio
Run Visual Studio Installer to modify your version of Visual Studio
![Visual Studio Installer](documents/RPi/Development/images/01.png)

Install the "Linux Development with C++" workload and open Visual
Studio after it's done installing
![Installing the "Linux Development with C++" workload](documents/RPi/Development/images/02.png)

## 4. Create a New Visual Studio Project
For this project, we'll use the "Raspberry Pi Blink" template

![Raspberry Pi Blink Template](documents/RPi/Development/images/03.png)

Name your project and give it a home

![Naming the Project](documents/RPi/Development/images/04.png)

Study how this project works and read the built-in README very well. 
It will be your friend as you setup your Pi.

Also, deploy the code that already exists in the project. In doing so, you will build the code for the first time. This build will trigger a configuration dialog specific to your instance of Visual Studio that asks for the hostname/password of your Pi. If you ever need to get back to this dialog, go to *tools/options*, and under *Cross Platform/Conection Manager*, you can edit your SSH connections.

If you fill these out correctly, Visual Studio will connect to the Raspberry Pi via SSH and install its own packages on your Pi. These packages will enable you to remotely deploy and debug your code. Once it has successfully deployed, you will notice that GPIO pin 17 should turn off and on as written in *main.cpp*. When this happens, Visual Studio has successfully connected to your Pi via SSH, deployed its code to the Pi, and executed it. Now you can start configuring your project so you can developing your own code!

![Pressing the circled button will cause the configuration dialog to appear](documents/RPi/Development/images/05.png)

## 5. Configure Your Project
Right now, your project is set up to use the WiringPi library that came with the Pi's OS. Our project relies on [SFML](https://www.sfml-dev.org/), and that is a library that must be installed on your Pi and is not registered by Visual Studio. This section is dedicated to configuring the Pi and Visual Studio to support remote development with the SFML library.

Go to the Properties editor for your new project.

![Circled is the Properties editor](documents/RPi/Development/images/06.png)

A window like this should pop up. Go to the Linker/Input setting to configure the libraries that should be included when Visual Studio builds your code.

![The Properties editor](documents/RPi/Development/images/07.png)

Edit the Library Dependencies option if necessary. 

![Library Dependencies option under Configuration Properties / Linker / Input](documents/RPi/Development/images/08.png)

The values in this field will tell Visual Studio what installed libraries to  link into your project. When Visual Studio builds your code and populates its intellisense code completion database, it will look for these libraries. (To link a project on the Pi with an installed library called *foo*, it adds -l*foo* to the build command automatically). 

SFML names its libraries as follows:
*  sfml-graphics [Graphics Module](https://www.sfml-dev.org/tutorials/2.5/#graohics-module)
*  sfml-window [Window Module](https://www.sfml-dev.org/tutorials/2.5/#window-module)
*  sfml-system [System Module](https://www.sfml-dev.org/tutorials/2.5/#system-module)
*  sfml-audio [Audio Module](https://www.sfml-dev.org/tutorials/2.5/#audio-module)
*  sfml-network [Network Module](https://www.sfml-dev.org/tutorials/2.5/#network-module)

![The Library Dependencies option edited to use the 5 SFML modules](documents/RPi/Development/images/09.png)

## 6. Programming Your Project

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

![The pre-launch command option under Configuration Properties/Debugging](documents/RPi/Development/images/10.png)

To clean up your build settings, if you removed the Blink code and your project doesn't depend on WiringPi anymore, or if you want to add your own post-bulid commands, remove/replace the "command line" and "description" fields under Build Events/Remote Post-Build Events

![Cleaning the command line option (optional)](documents/RPi/Development/images/11.png)

Repeat this process for all your project deployment configurations. What fun!

![Press the configuration dropdown menu to do these steps for all your deployment configurations](documents/RPi/Development/images/12.png)

## 7. Writing and Deploying Programs

Write your code. Note that the function initially executed is *int main* in the file *main.cpp*, which may still be occupied by the Blink program. If you don't want the Pi to blink an LED, you can modify the source code or remove it entirely so you have an empty *main* function.

If you don't have any or would just like to test your setup, use the following code:

```
//Source: https://www.sfml-dev.org/tutorials/2.5/start-linux.php
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```

![The code above in Visual Studio](documents/RPi/Development/images/13.png)

...and (hopefully) SFML works on your Pi!

![The Pi successfully running and debugging our code!](documents/RPi/Development/images/14.png)
