#include "GS.h"

// Static variables initialization
Debug GS::debug;
bool GS::gameEnd = false;
bool GS::play = true;
unsigned char GS::PageUpDown = 0;
unsigned char GS::KeyInterface = 0;
Character* GS::character;
float GS::moveSpeed = 0.1f;
GameOption GS::option;
bool GS::isCinematicPlaying = false;
