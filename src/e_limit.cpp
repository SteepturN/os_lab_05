#include <cmath>

extern "C"
float E( int x ) {
	return pow( 1 + 1.0f / x, x );
}
