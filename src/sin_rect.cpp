#include <cmath>
//#include <iostream>
#include <cstdio>


extern "C"
float SinIntegral( float A, float B, float e ) { //e - difference between steps
	float integral = 0.0f;
	if( std::signbit( B - A ) )
		e *= -1;
	const int n = trunc( ( B - A ) / e );
	for( int i = 0; i < n; ++i ) {
		integral += sin( A + ( e / 2.0f ) ) ;
		A += e;
	}
	integral = integral * e + sin( ( B + A ) / 2.0f ) * ( B - A );
	return integral;
}
