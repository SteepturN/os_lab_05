
#include <cmath>
extern "C"
float E( int x ) {
	float e_val = 1.0f;
	float prev_elem = 1.0f;
	for( int i = 1; i <= x; ++i ) {
		prev_elem = prev_elem / i;
		e_val += prev_elem;
	}
	return e_val;
}
