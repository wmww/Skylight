#ifndef SKYLIGHT_MACRO_H
#define SKYLIGHT_MACRO_H


//includes

#include <iostream>
#include <memory>
#include <vector>


// helpers

#define CONCAT(a, b) _CONCAT(a, b)
#define _CONCAT(a, b) a##_##b

#define ARG_COUNT(...)ARG_COUNT_INTENAL(dummy, ##__VA_ARGS__, 48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define IS_EMPTY(...) ARG_COUNT_INTENAL(dummy,##__VA_ARGS__,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,SOME_ARGS,NO_ARGS)

#define ARG_COUNT_INTENAL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,N,...) N

#define DOES_NOT_NOT_HAVE_PEREN(...) HAS_PEREN
#define DOES_NOT_HAS_PEREN_FUNC_FUNC(...) NO_PEREN
#define DOES_NOT_HAS_PEREN_FUNC DOES_NOT_HAS_PEREN_FUNC_FUNC(
#define HAS_PEREN_FUNC(...) NOT_HAVE_PEREN(
#define CHECK_FOR_PEREN(in) CONCAT(DOES_NOT, HAS_PEREN_FUNC in) )

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

#define in :

struct null_t {};
extern null_t null; // defined in str.cpp

#define END_PROGRAM int main() {run(); return 0;}


// print

inline void print(bool val) {
	std::cout << (val ? "true" : "false") << std::endl;
}

template <typename T>
inline void print(T val) {
	std::cout << val << std::endl;
}


// functions

#define func template< \
	typename T_0  = void, \
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

#define construct func

#define FUNC_ELEM_NO_PEREN(name, type) type name
#define FUNC_ELEM_HAS_PEREN(arg, dummy_type) FUNC_ELEM_NO_PEREN arg

#define FUNC_ARGS_0(...) )
#define FUNC_ARGS_1( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))))
#define FUNC_ARGS_2( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_3( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_4( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_6( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_7( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_8( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_9( arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_10(arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_11(arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define FUNC_ARGS_12(arg, ...) CONCAT(FUNC_ELEM, CHECK_FOR_PEREN(arg))(arg, CONCAT(T, ARG_COUNT(__VA_ARGS__))), CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define args FUNC_ARGS(

#define FUNC_ARGS(...) CONCAT(FUNC_ARGS, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)


// tuples

#define TUPLE_ELEM_A_0()
#define TUPLE_ELEM_A_2( e_name, e_val) decltype(e_val) e_name;
#define TUPLE_ELEM_A_4( e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_6( e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_8( e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_10(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_12(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_14(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_16(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_18(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_20(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_22(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_A_24(e_name, e_val, ...) decltype(e_val) e_name; CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define TUPLE_ELEM_B_0()
#define TUPLE_ELEM_B_2( e_name, e_val) out.e_name = e_val;
#define TUPLE_ELEM_B_4( e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_6( e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_8( e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_10(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_12(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_14(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_16(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_18(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_20(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_22(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define TUPLE_ELEM_B_24(e_name, e_val, ...) out.e_name = e_val; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define tuple(...) [&]() -> auto {struct anon_struct{CONCAT(TUPLE_ELEM_A, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)}; anon_struct out; CONCAT(TUPLE_ELEM_B, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__); return out;}()


// pointers

template <typename T>
inline auto ref(T a) {
	auto ptr = new T;
	*ptr = a;
	return std::shared_ptr<T>(ptr);
}

template <typename T>
inline auto raw_ptr(T a) {
	auto out = new T;
	*out = a;
	return out;
}

template <typename T>
inline auto null_raw_ptr(T a) {
	return (T*)nullptr;
}

template <typename T>
inline auto del(T a) {
	delete a;
}

#endif // SKYLIGHT_MACRO_H