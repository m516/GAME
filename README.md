### SR_5_
# G.A.M.E. (Graphics-Advanced Machine for Entertainment)

## Problem
Smartphones have become an integral part of the daily lives of most Americans. From shopping online to texting friends to playing games, these devices intend to bring everything cyberspace has to offer to the fingertips of their users. But with great power comes great responsibility. Malicious apps can steal and corrupt the valuable information stored in these devices, and “free” software--especially games--have been known to contain spyware and analytics software that has enabled large technology companies to acquire vast amounts of information regarding users of these smartphones. We intend to alleviate this issue by building an open-source, multiplayer gaming platform that enables people to play games and have fun without the stress of worrying about the safety of their cyber profiles. 

## Concept of Operations
- Game engine code will ease the development of games by providing access to functions that take care of redundant tasks such as displaying text, pinging sensors, and transmitting/receiving data across devices. The game engine will be versatile and easy to understand to allow third party developers to build their own games.  
- A built-in game selector will allow users to intuitively load, run, and manage games.  
- The game console will contain some awesome built-in games!  

## Hardware
This project will be a self-contained game console and controller built off of either the MKR Arduino. Attached to the controller will be an array of sensors (for the user to interface with the game) and an LCD/OLED screen (to convey visual data back to the user). A WiFi module built into the Arduino will enable multiple consoles to be wirelessly connected for multiplayer games. By using commercial off-the-shelf components, the team building this project will spend a minimal amount of time building the physical product, enabling all of its members to concentrate on writing software.

## Software
The software written for this unit can be split into three parts: (1) the game engine, (2) a game selector, and (3) the games. 

# Implementation Strategy
## Languages, Platforms, and Libraries
All code for the game engine and the game selector will be contained in a single program with many libraries written in Arduino and C++. A minimal amount of libraries may be used for WiFi and hardware connected to I2C. 

## Complexity
To avoid the need for internet access and reduce the cost for hardware, both the server and the client will run on the same machine. This may be difficult on an Arduino, for Arduinos only have a single-core microprocessor and require the use of timer interrupts to simulate multitasking. Multitasking will require a significant amount of collaboration between the various parts of software running the console.

## Interface
How the game consoles interact with each other will depend on how each game is programmed. We will begin by creating a turn-based multiplayer game, but if we have time, we will create a real-time game. 

## Database
Databases will be difficult to implement in this project, especially for Arduinos (program memory constraint of 256 kB in MKR 1010)

## Languages
Arduino/C++

## Frameworks
Arduino Libraries/Large Arduino Project Structure