#include <vector>
// #include <cmath>
// extern "C"
// float E( int x ) {
// 	return pow( 1 + 1.0f / x, x );
// }
extern "C"
char* translation( long x ) {
	std::vector< char > abc;
	bool negative;
	if( x < 0 ) {
		negative = true;
		x *= -1;
	}
	while( x > 0 ) {
		abc.push_back( '0' + x % 2 );
		x /= 2;
	}
	char* array = new char[ abc.size() ];
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
