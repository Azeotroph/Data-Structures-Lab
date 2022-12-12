#include<stdio.h>
#include<math.h>
int value[20],stack[20],top=-1;
char postfix[20];

void push(int val){
    top++;
    stack[top]=val;
};

int pop(){
    int val;
    val=stack[top];
    top--;
    return val;
};

int evaluate(){
    int i=0;
    char ch;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(isalpha(ch)){
            push(value[i]);
        }
        else{
            int op1,op2;
            op1=pop();
            op2=pop();
            switch(ch){
                case('+'):
                    push(op1+op2);
                    break;
                case('-'):
                    push(op1-op2);
                    break;
                case('*'):
                    push(op1*op2);
                    break;
                case('/'):
                    push(op1/op2);
                    break;
                case('^'):
                    push(pow(op1,op2));
                    break;
            }
        }
        i++;
    }
    int result=pop();
    return(result);
}
int main(){
    printf("enter the postfix expression\n");
    scanf("%s",postfix);
    int i=0;
    int result;
    while(postfix[i]!='\0'){
        if(isalpha(postfix[i])){
            printf("enter the value of operand\n");
            scanf("%d",&value[i]);
        }
        i++;
    }
    result=evaluate();
    printf("result=%d",result);
    return 0;
}