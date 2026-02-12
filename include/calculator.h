#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_EQUATION 100  // Maximum amount of operators and digits

typedef struct {
    // String of current equation
    char equationStr[MAX_EQUATION];
    int equationStrIdx;

    // List of digits in current equation
    int *digits;
    int digitsIdx;

    // List of operators in current equation
    int *operators;
    int operatorsIdx;

    // If current equation has an operator
    int hasOperator;
    int hasOperaterIdx;

    // Result
    double result;
} CalculatorState;

void  calculate(CalculatorState);
int   is_operator(char x);
//int*  get_digits(CalculatorState);
//char* get_operators(CalculatorState);

#endif
