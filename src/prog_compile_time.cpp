#include <iostream>

import explicit_enum;

extern "C" {
	float SinIntegral(float, float, float);
	char* translation(long);
}

int main(int argc, char *argv[]) {

	int command = 0;
	const int count_1_func_args = 3;
	float args_func1[ count_1_func_args ];
	const int count_2_func_args = 1;
	long args_func2[ count_2_func_args ];
	std::cout << "SinIntegral ( command = 1 ): 3 float args\n"
			  << "translation ( command = 2 ): 1 float arg\n";

	while( true ) {
		std::cout << "> ";
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
				char* delete_this = translation( args_func2[ 0 ] );
				std::cout << delete_this << std::endl;
				delete delete_this;
				break;
		}
	}
	return 0;
}
