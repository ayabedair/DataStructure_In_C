#include <stdio.h>
#include <math.h>
#include "stack.h"
Stack s;

//bool isChar(char c){
//    return c >= 'A' && c <= 'Z';
//}
//
//bool precedent(char a, char b){
//    if(a == '$') return 1;
//
//    if(a == '*' || a == '/') return b != '$';
//
//    if(a == '+' || a == '-') return b != '$' && b != '*' && b != '/';
//
//    return 0;
//}
//
//void InfixToPostfix(char infix[], char postfix[]){
//    int j = 0;
//    char op;
//    for(int i = 0 ; infix[i] != '\0' ; i++){
//        if(isChar(infix[i])){
//            postfix[j++] = infix[i];
//        }else {
//            if(!StackEmpty(&s)){
//                StackTop(&op, &s);
//                while(!StackEmpty(&s) && precedent(op, infix[i])){
//                    Pop(&op, &s);
//                    postfix[j++] = op;
//                    if(!StackEmpty(&s))
//                        Pop(&op, &s);
//                }
//            }
//            Push(infix[i], &s);
//        }
//    }
//    while (!StackEmpty(&s)){
//        Pop(&op, &s);
//        postfix[j++] = op;
//    }
//    postfix[j] = '\0';
//}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

double Oper(char op, double a, double b){
    double res;
    switch (op) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case'*' :
            return a * b;
        case '/' :
            return a / b;
        case '$' :
            return pow(a, b);
    }
    return 0;
}

double EvaluatePostfix(char expr[]){
    double op1, op2, val;

    for(int i = 0 ; expr[i] != '\0' ; i++){
        if(isDigit(expr[i]))
            Push((double) (expr[i] - '0'), &s);
        else{
            Pop(&op2, &s);
            Pop(&op1, &s);
            val = Oper(expr[i], op1, op2);
            Push(val, &s);
        }
    }

    Pop(&val, &s);
    return val;
}

int main() {
//    IntializeStack(&s);
//    char infix[50], postfix[50];
//
//    printf("Enter the infix function :\n");
//    scanf("%s", infix);
//
//    InfixToPostfix(infix, postfix);
//
//    printf("The postfix function :\n");
//    for(int i = 0 ; postfix[i] != '\0' ; i++){
//        printf("%c", postfix[i]);
//    }

    IntializeStack(&s);
    char arr[] = "123*+";
    printf("%f", EvaluatePostfix(arr));

    return 0;
}
