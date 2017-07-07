#include <iostream>

// helpers

#define ARG_COUNT(...) ARG_COUNT_INTENAL(dummy, ##__VA_ARGS__, 48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define IS_EMPTY(...) ARG_COUNT_INTENAL(dummy, ##__VA_ARGS__, args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,args,empty)

#define ARG_COUNT_INTENAL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,N,...) N

#define var auto

#define print(arg) std::cout << arg << std::endl

#define func template<typename T0 = void, typename T1 = void, typename T2 = void, typename T3 = void> auto

#define FUNC_0_ARGS(dummy) )
#define FUNC_1_ARGS(dummy, arg0) int dummy_arg, T0 arg0)
#define FUNC_2_ARGS(dummy, arg0, arg1) int dummy_arg, T0 arg0, T1 arg1)
#define FUNC_3_ARGS(dummy, arg0, arg1, arg2) int dummy_arg, T0 arg0, T1 arg1, T2 arg2)
#define FUNC_4_ARGS(dummy, arg0, arg1, arg2, arg3) int dummy_arg, T0 arg0, T1 arg1, T2 arg2, T3 arg3)

#define _0 FUNC_0_ARGS(
#define _1 FUNC_1_ARGS(
#define _2 FUNC_2_ARGS(
#define _3 FUNC_3_ARGS(


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
