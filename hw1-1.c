#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

int compare(char op){
    switch(op){
        case '+': case '-' : return 1;
        case '*': case '/' : return 2;
        default:             return 0;
    }
}

int main(){
    char infix[Max];
    char stack[Max];
    char postfix[Max];
    scanf("%s",infix);
    int top = -1; // stack最上層
    int j = strlen(infix); // infix長度
    int k = 0; // postfix中序號
    for(int i= 0; i < j; i++){
        if(infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            while(compare(stack[top]) >= compare(infix[i])){
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            while(stack[top] != '('){
                postfix[k++] = stack[top--];
            }
            top--;    
        }
        else{
            postfix[k++] = infix[i];
        }
    }
    printf("%s",postfix);
    while(top != -1){
        printf("%c",stack[top--]);
    }
}
