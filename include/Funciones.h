#pragma once
#include <iostream>
#include <stdio.h>
#include "rlutil.h"
#include "TamagotchiPerro.h"
#include "TamagotchiGato.h"
#include "TamagotchiPollito.h"


void presentacion();
int eleccionDeMascota();
void showItem(const char* text, int posx, int posy, bool selected);
void principalMenu ();
void seePets();

