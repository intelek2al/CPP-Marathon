#pragma once
#include <iostream>

#define BOTTLES(x, j) ((x == -1) ? "99" : (x != 0 ? std::to_string(x) : (j == 0 ? "No more" : "no more")))

#define TAKE(x) ((x) == 0 ? "it" : "one")

#define BOTTLES_OF_MEAD(x, j) BOTTLES((x), j) + " bottle" + (((x) != 1) ? "s" : "") + " of mead"

void sing();
