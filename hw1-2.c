#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

int main(){
    char postfix [Max];
    scanf("%s",postfix);
    char *stack[Max];
    int top = 0;
    int j = strlen(postfix);
    for(int i = 0; i < j; i++){
        char *a = (char *)calloc(sizeof(char),Max);
        a[0] = postfix[i];
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            char *c = stack[--top];
            char *b = stack[--top];
            strcat(b,c);
            strcat(a,b);
        }
        stack[top++] = a;
    }
    printf("%s",stack[0]);
}