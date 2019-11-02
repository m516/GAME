#!/bin/bash

echo "Configuring your Pi"
echo "Expanding your filesystem"
sudo raspi-config nonint do_expand_rootfs
echo "Increasing the dedicated GPU RAM"
sudo raspi-config nonint get_config_var gpu_mem_256 /boot/config.txt

echo "Updating your software..."
sudo apt-get update
echo "Upgrading your software..."
sudo apt-get full-upgrade

# Install dependencies
echo "Installing dependencies"
sudo apt-get install git make cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev boost-all-dev libssl1.0-dev libwebsocketpp-dev libwebsocketpp-doc

# Install SFML
echo "Installing SFML"
git clone https://github.com/mickelson/sfml-pi.git
cd sfml-pi
# Build library
mkdir build
cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libbrcmEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libbrcmGLESv2.so
sudo make install
sudo ldconfig

# Clone Repository
echo "Installing GAMEConsole repository"
cd
git clone https://git.linux.iastate.edu/cs309/fall2019/sr_5_.git
# CD into client folder
cd src_5_/client/GAMEConsole/
# Make the client
make
echo "Installed! Run src_5_/client/GAMEConsole/game to start."