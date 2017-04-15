#include "TCommon.h"

TCommon::Sign TCommon::getNumberSign(double d) {

	Sign sign;

	if (d < 0) {
		sign = negative;
	}
	else if (d > 0) {
		sign = positive;
	}
	else {
		sign = null;
	}

	return sign;
}


