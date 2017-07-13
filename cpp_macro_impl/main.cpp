
#include "skylight_macro.h"
#include "str.cpp"

func abc(args z, (a, int *), (b, double), c) {
	print(*a);
}

func run() {
	
	var str_0 = str("hay");
	var str_1 = str("hay");
	
	var does_match = true; //str_1 == str_0;
	print(does_match);
}

END

//CHECK_FOR_PEREN(abc)
