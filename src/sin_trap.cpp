#include <cmath>
#include <iostream>
#include <cstdio>
extern "C"
float SinIntegral( float A, float B, float e ) { //e - difference between steps
	float integral = 0.0f;
	if( std::signbit( B - A ) )
		e *= -1;
	const int n = trunc( ( B - A ) / e );
	if( n > 0 ) {
		for( int i = 0; i < n; ++i ) {
			integral += ( sin( A ) + sin( A + e ) ) / 2.0f * e;
			A += e;
		}
		integral += ( sin( A ) + sin( B ) ) / 2.0f * ( B - A );
		// integral = sin( A ) / 4.0f; //cos I *2 in last summ
		// A += e;
		// for( int i = 1; i < n; ++i ) {
		// 	integral += sin( A );
		// 	A += e;
		// }
		// integral = integral * 2.0f * e + sin( A ) * ( B - A + e )
		// 	+ sin( B ) / 2.0f * ( B - A );
	} else {
		integral = ( sin( A ) + sin( B ) ) / 2.0f * ( B - A );
	}
	return integral;
}
