#include <stdio.h>
#include "calculator.h"

/*
*  Calculates a string equation
*/
void calculate(CalculatorState calc) {
    printf("Calculating.........\n");
    /*
    int *digit = get_digits(calcEq, calcIndex);
    */
}


/*
*  Returns True (1) if a character is an operator
*/
int is_operator(char x) {
    switch (x) {
        case '+': case '-': case 'x': case '/':
            return 1;
            break;
        default:
            return 0;
    }
}


/*
*  Returns array of digits from a string equation 
*/
/*
int* get_digits(CalculatorState calc) {
    /*
    int count = 0;
    
    // Count how many digits there are
    for (int i=0; i<calcIndex; i++) {
        if (!is_operator(calcEq[i])) {
            count++;
        }
    }

    printf("Amount digits: %d\n", count);
    //int listDigit
    //return listDigit;
}
*/



