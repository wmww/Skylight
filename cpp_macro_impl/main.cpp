
#include "skylight_macro.h"

func abc(args a) {
	print(*a);
}

func run() {
	
	var a = ref(9);
	var b = ref(tuple(abc, 8, xyz, false));
	
	*a = 2;
	
	print(*a);
	
	print((*b).abc);
	
	var jdfskgf = 4;
	abc(&jdfskgf);
}

END
