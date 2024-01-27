#include <stdio.h>
#define STACKSIZE 1000

struct stack {
    char item[STACKSIZE];
    int top;
};

void initialize(struct stack *s) {
    s->top = -1;
}

void push(struct stack *s, char x) {
    s->item[++s->top] = x;
}

char pop(struct stack *s) {
    return s->item[s->top--];
}

int isEmpty(struct stack *s) {
    return (s->top == -1);
}

int ValidParenthesis(char exp[]) {
    struct stack S;
    initialize(&S);

    for (int i = 0; exp[i] != '\0'; i++) {
        char x = exp[i];
        if (x == '(') {
            push(&S, x);
        } else if (x == ')') {
            if (isEmpty(&S)) {
                return 0;
            } else {
                pop(&S);
            }
        }
    }

    return isEmpty(&S);
}

int main() {
    char exp[30];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (ValidParenthesis(exp)) {
        printf("Balanced Parenthesis\n");
    } else {
        printf("Unbalanced Parenthesis\n");
    }

    return 0;
}
