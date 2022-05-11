# -rdynamic
# 	Pass the flag -export-dynamic to the ELF linker, on targets that support it. This instructs the linker to add all symbols, not only
# 	used ones, to the dynamic symbol table. This option is needed for some uses of "dlopen" or to allow obtaining backtraces from within a
# 	program.

# -static
# 	On systems that support dynamic linking, this overrides -pie and prevents linking with the shared libraries.  On other systems, this
# 	option has no effect.

# -shared
# 	Produce a shared object which can then be linked with other objects to form an executable.  Not all systems support this option.  For
# 	predictable results, you must also specify the same set of options used for compilation (-fpic, -fPIC, or model suboptions) when you
# 	specify this linker option.[1]
#
#-fpic
# 	Generate position-independent code (PIC) suitable for use in a shared library, if supported for the target machine.  Such code
# 	accesses all constant addresses through a global offset table (GOT).  The dynamic loader resolves the GOT entries when the program
# 	starts (the dynamic loader is not part of GCC; it is part of the operating system).  If the GOT size for the linked executable exceeds
# 	a machine-specific maximum size, you get an error message from the linker indicating that -fpic does not work; in that case, recompile
# 	with -fPIC instead.  (These maximums are 8k on the SPARC, 28k on AArch64 and 32k on the m68k and RS/6000.  The x86 has no such limit.)

# 	Position-independent code requires special support, and therefore works only on certain machines.  For the x86, GCC supports PIC for
# 	System V but not for the Sun 386i.  Code generated for the IBM RS/6000 is always position-independent.

# 	When this flag is set, the macros "__pic__" and "__PIC__" are defined to 1.

# -fPIC
# 	If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size
# 	of the global offset table.  This option makes a difference on AArch64, m68k, PowerPC and SPARC.

# 	Position-independent code requires special support, and therefore works only on certain machines.

# 	When this flag is set, the macros "__pic__" and "__PIC__" are defined to 2.

# -fpie
# -fPIE
# 	These options are similar to -fpic and -fPIC, but the generated position-independent code can be only linked into executables.
# 	Usually these options are used to compile code that will be linked using the -pie GCC option.

# 	-fpie and -fPIE both define the macros "__pie__" and "__PIE__".  The macros have the value 1 for -fpie and 2 for -fPIE.
# -pie
# 	Produce a dynamically linked position independent executable on targets that support it.  For predictable results, you must also
# 	specify the same set of options used for compilation (-fpie, -fPIE, or model suboptions) when you specify this linker option.

all: dll sp dp
dll:
	g++ -Wall -pedantic -fpic -shared e_limit.cpp -o libe_limit.so
	g++ -Wall -pedantic -fpic -shared e_summ.cpp -o libe_summ.so
	g++ -Wall -pedantic -fpic -shared sin_rect.cpp -o libsin_rect.so
	g++ -Wall -pedantic -fpic -shared sin_trap.cpp -o libsin_trap.so
dp:
	g++-11 -o prog_dynamic_t -fmodules-ts -pie -rdynamic explicit_enum.cpp error_string.cpp dynamic_library.cpp prog_dynamic_time.cpp -ldl
sp:
	g++-11 -o prog_compile_t -fmodules-ts -pie explicit_enum.cpp prog_compile_time.cpp  -L. -lsin_trap -le_summ -Wl,-rpath,.
clean:
	rm *.so prog_dynamic_t prog_compile_t
	rm -r gcm.cache
