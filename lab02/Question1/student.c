// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h>

typedef struct {
    int size; // always 1 over actual highest index
    int top; // always set to next potential active index
    char *elements;
} Stack;

void resizeStack(Stack *stack) { // set stack size before calling
    if(stack->size == 0) {
        free(stack->elements);
    }
    stack->elements = malloc(sizeof(char) * stack->size);
    stack->top = 0;
}

bool push(Stack *stack, char push) { // returns true if successful
    if(stack->top == stack->size) {
        return false;
    }
    stack->elements[stack->top] = push;
    stack->top++;
    return true;
}

bool pop(Stack *stack) { // returns true if successful
    if(stack->top <= 0) {
        return false;
    }
    //stack->elements[stack->top - 1] = ' ';
    stack->top--;
    return true;
}

char peek(Stack *stack) {
    if(stack->top == 0) {
        return ' ';
    }
    return stack->elements[stack->top - 1];
}

bool corresponds(char open, char close) {
    if(open == '(' && close == ')') {
        return true;
    } else if(open == '[' && close == ']') {
        return true;
    } else if(open == '{' && close == '}') {
        return true;
    }
    return false;
}

bool isValid(const char *s) {

    int sLength = strlen(s);

    Stack myStack = {.size = sLength};
    resizeStack(&myStack);

    for(int i = 0; i < sLength; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') { // if OPEN BRACKET
            push(&myStack, s[i]);
        } else if(s[i] == ')' || s[i] == ']' || s[i] == '}') { // if CLOSE BRACKET
            if(myStack.top == 0) {
                return false; // if a CLOSE is present without any OPENs
            }
            if(corresponds(peek(&myStack), s[i])) { // if the OPEN and CLOSE are the same type of bracket, then...
                pop(&myStack);
            } else { // if brackets do not correspond
                return false;
            }
        }
    }

    if(myStack.top > 0) { // if there are any leftover brackets
        return false;
    }

    return true; // if all fails pass by
}
