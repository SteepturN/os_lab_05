module;
#include <dlfcn.h>

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

	export void init( float (*&SinIntegral)(float, float, float), float (*&E)(int) ) {
		func_type = first;
		sin_trap = dlopen( "./libsin_trap.so", RTLD_LAZY );
		dlerror();
		sin_rect = dlopen( "./libsin_rect.so", RTLD_LAZY );
		dlerror();
		e_limit = dlopen( "./libe_limit.so", RTLD_LAZY );
		dlerror();
		e_summ = dlopen( "./libe_summ.so", RTLD_LAZY );
		dlerror();

		SinIntegral = reinterpret_cast< float( * )( float, float, float ) >( dlsym( sin_trap, "SinIntegral" ) );
		dlerror();
		E = reinterpret_cast< float( * )( int ) >( dlsym( e_limit, "E" ) );
		dlerror();
	}
	export void switch_realisation( float (*&SinIntegral)(float, float, float), float (*&E)(int) ) {
		void* sin_file_ptr;
		void* e_file_ptr;
		switch( func_type ) {
			case first:
				func_type = second;
				sin_file_ptr = sin_trap;
				e_file_ptr = e_summ;
				break;
			case second:
				func_type = first;
				sin_file_ptr = sin_rect;
				e_file_ptr = e_limit;
				break;
		}
		SinIntegral = reinterpret_cast< float ( * )( float, float, float ) >( dlsym( sin_file_ptr, "SinIntegral" ) );
		dlerror();
		E = reinterpret_cast< float( * )( int ) >( dlsym( e_file_ptr, "E" ) );
		dlerror();
	}
	export void detach() {
		dlclose(sin_rect);
		dlclose(sin_trap);
		dlclose(e_limit);
		dlclose(e_summ);
	}
};
