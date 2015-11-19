/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#include <cstdlib>

#include "Metheorology.h"
#include "defs.h"

namespace Metheorology {
	unsigned char rainFrame() {
		if (!(rand() % 20))
			return rainFrames[0 + rand() % (sizeof(rainFrames) / sizeof(rainFrames[0]))];
		else
			return '_';
	}

	unsigned char intenseRainFrame() {
		return rainFrames[0 + rand() % (sizeof(rainFrames) / sizeof(rainFrames[0]))];
	}
}