#include <vector>
// #include <cmath>
// extern "C"
// float E( int x ) {
// 	float e_val = 1.0f;
// 	float prev_elem = 1.0f;
// 	for( int i = 1; i <= x; ++i ) {
// 		prev_elem = prev_elem / i;
// 		e_val += prev_elem;
// 	}
// }
// 	return e_val;
//3
extern "C"
char* translation( long x ) {
	std::vector< char > abc;
	bool negative;
	if( x < 0 ) {
		negative = true;
		x *= -1;
	}
	while( x > 0 ) {
		abc.push_back( '0' + x % 3 );
		x /= 3;
	}
	char* array = new char[ abc.size() + 1 ];
	array[ abc.size() ] = '\0';
	if( negative ) {
		array[ 0 ] = '-';
		array += 1;
	}
	for( std::vector<char>::size_type i = 0; i < abc.size(); ++i ) {
		array[ i ] = abc[ abc.size() - 1 - i ];
	}
	return negative ? --array : array;
}
