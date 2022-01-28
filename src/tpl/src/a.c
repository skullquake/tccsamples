#include<stdio.h>
#include"tcc.h"
const char*program=
	"int foo(const int in_value){"
	"	printf(\"this is a test: %d\n\", in_value);"
	"}";
int main(int argc,char**argv){
	TCCState*s=tcc_new();
	if(!s){
		printf("Can’t create a TCC context\n");
		return 1;
	}
   	tcc_set_options(s,"-vvv");
	tcc_set_lib_path(s,"../tcc-0.9.27/");
	tcc_set_output_type(s,TCC_OUTPUT_MEMORY);
	if (tcc_compile_string(s,program)>0) {
		printf("Compilation error!\n");
		return 2;
	}
	tcc_relocate(s,TCC_RELOCATE_AUTO);
	int(*const foo)(const int in_value)=tcc_get_symbol(s,"foo");
	foo(32);
	tcc_delete(s);
	return 0;
}


/*
tcc_set_bounds_check(s,0);
tcc_set_output_type(s, TCC_RELOCATE_AUTO);
tcc_set_options(s,"-vvv -I../tcc-0.9.27/ -L../tcc-0.9.27/");
tcc_add_library(s,"../tcc-0.9.27");
tcc_add_include_path(s,"../tcc-0.9.27/");
tcc_add_sysinclude_path(s,"../tcc-0.9.27/");
tcc_add_library_path(s,"../tcc-0.9.27/");
*/
