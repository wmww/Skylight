
#include "skylight_macro.h"

func
abc(args a, b, c, d, e, t) {
	print("yo");
	print(a);
	print(b);
	print(e);
}

int main() {
	print("hay");
	
	//abc(1, 4, 3, 4, 89, 54);
	
	var my_tup = tuple(a, 43, b, 23);
	
	my_tup.a = 12;
	
	print(my_tup.a);
	
	//var a = tuple(a, 54, dsklgs, true);
	
	//print(a.true);
	
	//print(ARG_COUNT(dfsd, sdfds, sfsd, sf));
	
	return 0;
}

/*

# define EMPTY
# define DEFER(...) __VA_ARGS__ EMPTY

#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

# define FUNC_ARGS_A() FUNC_ARGS
# define FUNC_ARGS(first, ...) first, DEFER(FUNC_ARGS_A)()(__VA_ARGS__)

EVAL(FUNC_ARGS(5, 6, 7, 8, 2, 233242, 3))
*/
