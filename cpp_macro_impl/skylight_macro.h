#include <iostream>

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
