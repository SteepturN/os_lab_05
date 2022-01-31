dll:
	g++ -Wall -pedantic -fPIC -shared e_limit.cpp -o libe_limit.so
	g++ -Wall -pedantic -fPIC -shared e_summ.cpp -o libe_summ.so
	g++ -Wall -pedantic -fPIC -shared sin_rect.cpp -o libsin_rect.so
	g++ -Wall -pedantic -fPIC -shared sin_trap.cpp -o libsin_trap.so
dp:
	g++-11 -fmodules-ts -rdynamic explicit_enum.cpp error_string.cpp dynamic_library.cpp prog_dynamic_time.cpp  -o prog_dynamic_t -ldl
sp:

	g++-11 -o prog_compile_t -fmodules-ts explicit_enum.cpp prog_compile_time.cpp  -L. -lsin_trap -le_summ -Wl,-rpath,.
