#!/bin/bash
echo "Updating your software..."
sudo apt-get update
echo "Upgrading your software..."
sudo apt-get upgrade

# Install dependencies
sudo apt-get install cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev

# Install SFML
git clone https://github.com/mickelson/sfml-pi.git
cd sfml-pi
# Build library
mkdir build
cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libbrcmEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libbrcmGLESv2.so
sudo make install
sudo ldconfig

# Clone Repository
git clone https://git.linux.iastate.edu/cs309/fall2019/sr_5_.git
# CD into client folder
cd src_5_/client/GAMEConsole/
# Make the client
make
echo "Installed! Run ./game to start."