/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdlib>

#include "defs.h"
#include "Metheorology.h"

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