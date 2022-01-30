#include <iostream>

import explicit_enum;

extern "C" {
	float SinIntegral(float, float, float);
	float E(int);
}

int main(int argc, char *argv[]) {

	int command = 0;
	const int count_1_func_args = 3;
	float args_func1[ count_1_func_args ];
	const int count_2_func_args = 1;
	int args_func2[ count_2_func_args ];

	while( true ) {
		std::cin >> command;
		if( std::cin.fail() )
			return ReturnValue::nice;
		switch( command ) {
			case 1:
				for( int i = 0; i < count_1_func_args; ++i ) {
					std::cin >> args_func1[ i ];
					if( std::cin.fail() )
						return ReturnValue::nice;
				}
				std::cout << SinIntegral( args_func1[ 0 ], args_func1[ 1 ],
				             args_func1[ 2 ] ) << std::endl;
				break;
			case 2:
				for( int i = 0; i < count_2_func_args; ++i ) {
					std::cin >> args_func2[ i ];
					if( std::cin.fail() )
						return ReturnValue::nice;
				}
				std::cout << E( args_func2[ 0 ] ) << std::endl;
				break;
		}
	}
	return 0;
}
