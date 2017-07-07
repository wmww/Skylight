#include <iostream>

// helpers

#define CONCAT(a, b) _CONCAT(a, b)
#define _CONCAT(a, b) a##_##b

#define ARG_COUNT(...)ARG_COUNT_INTENAL(dummy, ##__VA_ARGS__, 48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define IS_EMPTY(...) ARG_COUNT_INTENAL(dummy,##__VA_ARGS__,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,NO_ARGS)

#define ARG_COUNT_INTENAL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,N,...)N

// includes

#include <vector>

// mscl

#define var auto
#define let const auto

#define loop while true

inline auto range(int low, int high) {
	std::vector<int> out;
	for (int i = low; i < high; i++)
		out.push_back(i);
	return out;
}

inline auto range(int high) {
	return range(0, high);
}

#define for for (auto
#define do )
#define in :

#define print(arg) std::cout << arg << std::endl

// functions

#define func template< \
	typename T_1  = void, \
	typename T_2  = void, \
	typename T_3  = void, \
	typename T_4  = void, \
	typename T_5  = void, \
	typename T_6  = void, \
	typename T_7  = void, \
	typename T_8  = void, \
	typename T_9  = void, \
	typename T_10 = void, \
	typename T_11 = void, \
	typename T_12 = void> auto

#define FUNC_ARGS_0(...) )
#define FUNC_ARGS_1(arg) T_1 arg)
#define FUNC_ARGS_2( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_3( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_4( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_5( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_6( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_7( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_8( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_9( arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_10(arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_11(arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_12(arg, ...) CONCAT(T, ARG_COUNT(__VA_ARGS__)) arg, CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define args FUNC_ARGS(

#define FUNC_ARGS(...) CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

// tuples

#define TUPLE_ELEM_0()
#define TUPLE_ELEM_2(elem_name, elem_val) decltype(elem_val) elem_name = elem_val;
#define TUPLE_ELEM_4( e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_8( e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_10(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_12(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_14(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_16(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_18(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_20(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_22(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_24(e_name, e_val, ...) decltype(e_val) e_name=e_val; CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define tuple(...) [&]() -> auto {struct anon_struct{CONCAT(TUPLE_ELEM, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)}; return anon_struct();}()

//#define TUPLE_ELEM(e_name, e_val) decltype(e_val) e_name = e_val;

//#define TUPLE_INSIDE(first_name, first_val, ...) TUPLE_ELEM(first_name, first_val) TUPLE_INSIDE(__VA_ARGS__)

//#define tuple(...) [&]() -> auto { struct anon_struct{TUPLE_INSIDE(__VA_ARGS__)}; return anon_struct();}()

//#define tuple(name0, val0) [&]()->auto{struct anon_struct{ \
	TUPLE_ELEM(name0, val0) \
	}; return anon_struct();}()
//#define tuple(name0, val0, name1, val1) [&]()->auto{struct anon_struct{ \
	TUPLE_ELEM(name0, val0) \
	TUPLE_ELEM(name1, val1) \
	}; return anon_struct();}()
