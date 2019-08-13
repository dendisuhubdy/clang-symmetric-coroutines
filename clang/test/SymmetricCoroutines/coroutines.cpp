// RUN: %clang_cc1 %s -verify

// Positive tests

// expected-no-diagnostics

#include <__symmetric_coroutine>

using std::coroutine;
using std::resume_continuation;

// Coroutine with no creation parameters and an empty body
minimal() : coroutine<void(void)> 
{}

void use_minimal() {
   minimal coro;
   coro();
}

// Coroutine with one creation parameter passed by value and an empty body
one_value_param_empty(int a) : coroutine<void(void)> {
}

void use_one_value_param_empty() {
   int a = 0;
   one_value_param_empty coro{a};
   coro();
}

// Coroutine with one creation parameter passed by reference and an empty body
one_ref_param_empty(int& a) : coroutine<void(void)> {
}

void use_one_ref_param_empty() {
   int a = 0;
   one_ref_param_empty coro{a};
   coro();
}

// Coroutine with one creation parameter passed by r-value reference and an empty body
one_rv_ref_param_empty(int&& a) : coroutine<void(void)> {
}

void use_one_rv_ref_param_empty() {
   one_rv_ref_param_empty coro(1);
   coro();
}
