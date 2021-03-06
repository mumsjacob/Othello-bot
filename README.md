# Othello-bot
This project was made for the course 'Electromechanical project' as a part of the engineering physics programme at Uppsala University.
## Participants
* Jacob Olofsson
* Thomas Danielsson
* Aksel Wännström
## Project
Our goal was to construct a robot that could play a human player in the game reversi (Othello).
This was acheived by programming an arduino and constructing a 3D-printer like arm, game-pieces with magnets and a playing-board equipped with linear Hall effect sensors to sense orientation of pieces.
See the documentation for a full write-up (in swedish).
## Code
The AI controlling the bot was made for arduino, all the code resides in the 'othello\_bot' folder and was compiled with the arduino IDE.
The tests was made with the framework Catch2 and resides in the test folder.
The tests are compiled by Cmake (preferably in the build folder to avoid file clutter):
```
cd build
cmake ..
make
./test_exec # Run tests
./bench # Run benchmark
./play # Test to play against the AI in the terminal
```
To use with arduino the library AF\_motor is used for the stepper motors. To build the whole project and upload to an arduino the library needs to be [downloaded](https://learn.adafruit.com/adafruit-motor-shield/library-install). The arduino also needs to have at least 16 analog pins (like arduino mega).
When the library is installed the arduino IDE can be used to upload the project.
