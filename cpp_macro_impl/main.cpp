
#include "skylight_macro.h"
//#include "str.cpp"

func run() {
	//var str_0 = str("hay");
	//var str_1 = str("hay");
	
	//var does_match = true; //str_1 == str_0;
	//print(does_match);
	
	print("program ran");
	
	auto tup = tupple(a, 4, b, true);
	
	decltype(true) a;
	
	cout << tup.a << endl;
	
	auto tup = [&] () -> auto {
			struct anon_struct {
				decltype(4) a;
				decltype(true) b;
			};
			
			anon_struct out;
			out.a = 4;
			out.b = true;
			
			return out;
		}()
}

construct my_obj(args a, (b, int)) {
	
	return class_tuple((val1, a), (val_int, b));
}

END_CLASS

END_PROGRAM
