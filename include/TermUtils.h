#pragma once
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <iomanip>

/* Foreground Colors    Background Colors   Decorations
 * 0 = black            0 = black           0 = Reset
 * 1 = red              1 = red             1 = bright
 * 2 = green            2 = green           2 = dim
 * 3 = yellow           3 = yellow          4 = underscore
 * 4 = blue             4 = blue            5 = blink
 * 5 = magenta          5 = magenta         7 = reverse
 * 6 = cyan             6 = cyan            8 = hidden
 * 7 = white            7 = white
 */

int getTermWidth();
int getTermHeight();
void printMenuBar(std::vector <std::string> entrys, int active);
void printMaxWidth(std::string text, int width);
std::string color(int fg = 0, int bg = 0, int deco = -1);
