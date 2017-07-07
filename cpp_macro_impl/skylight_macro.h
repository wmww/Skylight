#include <iostream>

// helpers

#define ARG_COUNT(...)ARG_COUNT_INTENAL(dummy, ##__VA_ARGS__, 48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define IS_EMPTY(...) ARG_COUNT_INTENAL(dummy,##__VA_ARGS__,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,NO_ARGS)

#define ARG_COUNT_INTENAL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,N,...)N

#define var auto

#define print(arg) std::cout << arg << std::endl

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

/*
#define FUNC_0_ARGS(dummy) )
#define FUNC_1_ARGS(dummy, arg0) T0 arg0)
#define FUNC_2_ARGS(dummy, arg0, arg1) T0 arg0, T1 arg1)
#define FUNC_3_ARGS(dummy, arg0, arg1, arg2) T0 arg0, T1 arg1, T2 arg2)
#define FUNC_4_ARGS(dummy, arg0, arg1, arg2, arg3) T0 arg0, T1 arg1, T2 arg2, T3 arg3)

#define _0 FUNC_0_ARGS(
#define _1 FUNC_1_ARGS(
#define _2 FUNC_2_ARGS(
#define _3 FUNC_3_ARGS(
*/

#define CONCAT(a, b) CONCAT3(a, b)
#define CONCAT3(a, b) a##_##b

#define args FUNC_ARGS(

#define FUNC_ARGS(...) CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

/*
#define CONCAT(a, b) CONCAT3(a, b)
//#define CONCAT0(a, b) CONCAT1(a, b)
//#define CONCAT1(a, b) CONCAT2(a, b)
//#define CONCAT2(a, b) CONCAT3(a, b)
#define CONCAT3(a, b) a##_##b

# define EMPTY
# define DEFER(...) __VA_ARGS__ EMPTY

#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__


#define args FUNC_ARGS(

#define FUNC_ARGS_WITH_FIRST_NO_ARGS(type, first) bool dummy_to_consume_comma=true)

#define DEFERED_FUNC_ARGS_WITH_FIRST_SOME_ARGS() FUNC_ARGS_WITH_FIRST_SOME_ARGS
#define DEFERED_FUNC_ARGS_WITH_FIRST_NO_ARGS() FUNC_ARGS_WITH_FIRST_NO_ARGS

#define FUNC_ARGS_WITH_FIRST_SOME_ARGS(type, first, ...) type first, DEFER(CONCAT(DEFERED, CONCAT(FUNC_ARGS_WITH_FIRST, IS_EMPTY(__VA_ARGS__))))()(type##T, __VA_ARGS__)

#define FUNC_ARGS(...) EVAL(CONCAT(FUNC_ARGS_WITH_FIRST, IS_EMPTY(__VA_ARGS__))(_T, __VA_ARGS__))
*/
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
