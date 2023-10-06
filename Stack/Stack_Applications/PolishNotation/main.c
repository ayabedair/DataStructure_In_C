#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

//#define type "charcter"  //c -> for charcter, d -> for digit


bool IsDigit(char c){
    return (c>='A' && c<='Z');
}

bool Precedent(char a, char b){
    if(a == '$')
        return 1;

    if((a == '*') || (a == '/'))
        return (b != '$');

    if((a == '+') || (a == '-'))
        return ((b != '$') && (b != '*') && (b != '/'));

    return 0;
}

void Postfix(char infix[], char postfix[])
{
    int c;
    int e;
    int i,j;
    Stack s;
    IntializeStack(&s);
    for(i=0,j=0; (c=infix[i]) != '\0'; i++){
        if(IsDigit(c)){
            postfix[j++] = c;
        }
        else{
            if(!StackEmpty(&s)){
                StackTop(&e, &s);
                while(!StackEmpty(&s) && Precedent(e, c)){
                    //returns 1 if op1 is higher than op2
                    Pop(&e, &s);
                    postfix[j++] = e;
                    if(!StackEmpty(&s))
                        StackTop(&e, &s);
                }
            }
            Push(c, &s);
        }
    }
    while(!StackEmpty(&s)){
        Pop(&e, &s);
        postfix[j++] = e;
    }
    postfix[j] = '\0';
}

double Oper(char c, int op1, int op2){
    switch (c){
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '$': return (pow(op1,op2));
    }
}

double EvaluatePostfix(char postfix[]){
    int i;
    double res, op1, op2;
    char c;
    Stack s;
    IntializeStack(&s);
    for(i=0; (c=postfix[i])=='\0'; i++){
        if(IsDigit(c)){
            Push((double) (c-'0'), &s);
        }
        else{
            Pop(&op2, &s);
            Pop(&op1, &s);
            res = Oper(c, op1, op2);
            Push(res, &s);
        }
    }
    Pop(&res, &s);
    return res;
}

int main() {

    char arr[100];
    char eqn[100];
    char c;

    printf("Enter the Infix equation:\n");
    for(int i=0; i<100; i++) {
        c = getchar();
        if(c == '\n') {
            eqn[i] = '\0';
            break;
        }
        eqn[i] = c;
    }
//    printf("%d", EvaluatePostfix(eqn));

    Postfix(eqn, arr);

    printf("Postfix equation is:\n");
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++) {
        if(arr[i] == '\0')
            break;
        printf("%c",arr[i]);
    }

    return 0;
}
