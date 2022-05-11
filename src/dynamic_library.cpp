module;
#include <dlfcn.h>
#include <iostream>
#include <array>
import explicit_enum;
import error_string;
export module dynamic_library;


namespace DynamicLibrary {
	enum state {
	    first,
	    second,
	};
	state func_type;
	void* sin_rect;
	void* sin_trap;
	void* e_limit;
	void* e_summ;

	void check_errors_dlopen() {
		char* error;
		if( ( error = dlerror() ) != ReturnValue::dlerror_no_error ) {
			std::cerr << error << std::endl;
			exit( ReturnValue::error_dlopen_fail );
		}
	}
	void check_errors_dlsym() {
		char* error;
		if( ( error = dlerror() ) != ReturnValue::dlerror_no_error ) {
			std::cerr << error << std::endl;
			exit( ReturnValue::error_dlsym_fail );
		}
	}
	void check_errors_dlclose(int return_val) {
		if( return_val != ReturnValue::dlclose_success ) {
			std::cerr << Error::dlclose_fail() << std::endl;
			exit( ReturnValue::error_dlclose_fail );
		}
	}
	void first_config( void*& sin_f, void*& e_f ) {
		sin_f = sin_trap;
		e_f = e_limit;
	}
	void second_config( void*& sin_f, void*& e_f ) {
		sin_f = sin_rect;
		e_f = e_summ;
	}

	export void init( float ( *&SinIntegral )( float, float, float ),
	                  char* ( *&translation )( long ) ) {
		sin_trap = dlopen( "./libsin_trap.so", RTLD_LAZY );
		check_errors_dlopen();
		sin_rect = dlopen( "./libsin_rect.so", RTLD_LAZY );
		check_errors_dlopen();
		e_limit = dlopen( "./libe_limit.so", RTLD_LAZY );
		check_errors_dlopen();
		e_summ = dlopen( "./libe_summ.so", RTLD_LAZY );
		check_errors_dlopen();


		void* sin_file_ptr;
		void* e_file_ptr;
		func_type = first;
		first_config( sin_file_ptr, e_file_ptr );
		SinIntegral = reinterpret_cast< float( * )( float, float, float ) >
			( dlsym( sin_file_ptr, "SinIntegral" ) );
		check_errors_dlsym();
		translation = reinterpret_cast< char*( * )( long ) >( dlsym( e_file_ptr, "translation" ) );
		check_errors_dlsym();
	}
	export void switch_realisation( float ( *&SinIntegral )( float, float, float ),
	                                char* ( *&translation )( long ) ) {
		void* sin_file_ptr;
		void* e_file_ptr;
		switch( func_type ) {
			case first:
				func_type = second;
				second_config(sin_file_ptr, e_file_ptr);
				break;
			case second:
				func_type = first;
				first_config(sin_file_ptr, e_file_ptr);
				break;
		}
		SinIntegral = reinterpret_cast< float ( * )( float, float, float ) >
			( dlsym( sin_file_ptr, "SinIntegral" ) );
		check_errors_dlsym();
		translation = reinterpret_cast< char*( * )( long ) >( dlsym( e_file_ptr, "translation" ) );
		check_errors_dlsym();
	}
	export void detach() {
		std::array file_ptr{ sin_rect, sin_trap, e_limit, e_summ };
		for( auto file : file_ptr ) {
			check_errors_dlclose( dlclose( file ) );
		}
	}
};
