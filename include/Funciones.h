#pragma once
#include <iostream>
#include "rlutil.h"
#include "Tamagotchi.h"


void presentacion();
int eleccionDeMascota();
void showItem(const char* text, int posx, int posy, bool selected);
void principalMenu ();
Tamagotchi petCreator(int);
void seePets();
