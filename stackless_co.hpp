#pragma once
#include <tuple>
#define macro_expand(...) __VA_ARGS__
#define args_placehold() 10,9,8,7,6,5,4,3,2,1,0
#ifdef _MSC_VER
#define args_number_unsed(...) unused,__VA_ARGS__
#else // _MSVC
#define args_number_unsed(...) unused,##__VA_ARGS__
#endif
#define __args_number__(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,N,...)  N
#define args_number_inner(...) macro_expand(__args_number__(__VA_ARGS__))
#define args_number(...) macro_expand(args_number_inner(args_number_unsed(__VA_ARGS__),args_placehold()))

#define __concat_ab__(A,B) A##B
#define concat_ab(A,B) __concat_ab__(A,B)

#define FOR_ACTION(Func,...) macro_expand(concat_ab(Func,args_number(__VA_ARGS__)) (__VA_ARGS__))

#define CAtor0()
#define CAtor1(element) decltype(element) element##_
#define CAtor2(element,...) decltype(element) element##_, macro_expand(CAtor1(__VA_ARGS__))
#define CAtor3(element,...) decltype(element) element##_, macro_expand(CAtor2(__VA_ARGS__))
#define CAtor4(element,...) decltype(element) element##_, macro_expand(CAtor3(__VA_ARGS__))
#define CAtor5(element,...) decltype(element) element##_, macro_expand(CAtor4(__VA_ARGS__))
#define CAtor6(element,...) decltype(element) element##_, macro_expand(CAtor5(__VA_ARGS__))
#define CAtor7(element,...) decltype(element) element##_, macro_expand(CAtor6(__VA_ARGS__))
#define CAtor8(element,...) decltype(element) element##_, macro_expand(CAtor7(__VA_ARGS__))
#define CAtor9(element,...) decltype(element) element##_, macro_expand(CAtor8(__VA_ARGS__))
#define CAtor10(element,...) decltype(element) element##_, macro_expand(CAtor9(__VA_ARGS__))



#define ActorInit0()
#define ActorInit1(element) element##(element##_)
#define ActorInit2(element,...) element##(element##_), macro_expand(ActorInit1(__VA_ARGS__))
#define ActorInit3(element,...) element##(element##_), macro_expand(ActorInit2(__VA_ARGS__))
#define ActorInit4(element,...) element##(element##_), macro_expand(ActorInit3(__VA_ARGS__))
#define ActorInit5(element,...) element##(element##_), macro_expand(ActorInit4(__VA_ARGS__))
#define ActorInit6(element,...) element##(element##_), macro_expand(ActorInit5(__VA_ARGS__))
#define ActorInit7(element,...) element##(element##_), macro_expand(ActorInit6(__VA_ARGS__))
#define ActorInit8(element,...) element##(element##_), macro_expand(ActorInit7(__VA_ARGS__))
#define ActorInit9(element,...) element##(element##_), macro_expand(ActorInit8(__VA_ARGS__))
#define ActorInit10(element,...) element##(element##_), macro_expand(ActorInit9(__VA_ARGS__))



#define ActorDeclareVar0()
#define ActorDeclareVar1(element) decltype(element) element;
#define ActorDeclareVar2(element,...) decltype(element) element; macro_expand(ActorDeclareVar1(__VA_ARGS__))
#define ActorDeclareVar3(element,...) decltype(element) element; macro_expand(ActorDeclareVar2(__VA_ARGS__))
#define ActorDeclareVar4(element,...) decltype(element) element; macro_expand(ActorDeclareVar3(__VA_ARGS__))
#define ActorDeclareVar5(element,...) decltype(element) element; macro_expand(ActorDeclareVar4(__VA_ARGS__))
#define ActorDeclareVar6(element,...) decltype(element) element; macro_expand(ActorDeclareVar5(__VA_ARGS__))
#define ActorDeclareVar7(element,...) decltype(element) element; macro_expand(ActorDeclareVar6(__VA_ARGS__))
#define ActorDeclareVar8(element,...) decltype(element) element; macro_expand(ActorDeclareVar9(__VA_ARGS__))
#define ActorDeclareVar9(element,...) decltype(element) element; macro_expand(ActorDeclareVar8(__VA_ARGS__))
#define ActorDeclareVar10(element,...) decltype(element) element; macro_expand(ActorDeclareVar9(__VA_ARGS__))

#define ActDot0(...) 
#define ActDot1(...) :
#define ActDot2(...) :
#define ActDot3(...) :
#define ActDot4(...) :
#define ActDot5(...) :
#define ActDot6(...) :
#define ActDot7(...) :
#define ActDot8(...) :
#define ActDot9(...) :
#define ActDot10(...) :

template<typename T, typename Tuple, std::size_t...Index>
auto expand_tuple(Tuple&& tuple, std::index_sequence<Index...>) {
	return T{ std::get<Index>(tuple)... };
}
#define CO_BEGIN(...)\
\
auto save_stack_ = std::make_tuple(__VA_ARGS__);\
\
class co_type{ \
public:\
co_type(macro_expand(FOR_ACTION(CAtor,__VA_ARGS__)))macro_expand(FOR_ACTION(ActDot,__VA_ARGS__)) macro_expand(FOR_ACTION(ActorInit,__VA_ARGS__)){};\
\
private:\
macro_expand(FOR_ACTION(ActorDeclareVar,__VA_ARGS__))\
private:\
 int state_ = 0;\
public:\
co_type& operator()(){\
switch(state_){case 0:{

#define CO_yiled() state_= __LINE__;}break;case __LINE__:{\

#define CO_END()  state_ = 0;}}return *this;}}; return expand_tuple<co_type>(save_stack_,std::make_index_sequence<std::tuple_size_v<decltype(save_stack_)>>{});
