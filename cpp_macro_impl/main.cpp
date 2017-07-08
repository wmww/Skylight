
#include "skylight_macro.h"

func run() {
	
	var a = ref(9);
	var b = tuple(abc, 8, xyz, false);
	var c = ref(b);
	
	*a = 2;
	
	print(*a);
}

END
