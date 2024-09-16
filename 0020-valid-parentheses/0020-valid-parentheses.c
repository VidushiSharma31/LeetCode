struct stack {
    char* arr;
    int capacity;
    int top;
};
struct stack* createStack(int capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr=(char*)malloc(stack->capacity * sizeof(char));
	return stack;
}
int isEmpty(struct stack* stack) {
    return stack->top==-1;
}
void push(struct stack* stack, char val) {
    stack->top++;
    stack->arr[stack->top] = val;
}
char pop(struct stack* stack) {
    if(isEmpty(stack))
        return -1;
    else {
        char top = stack->arr[stack->top--];
        return top;
    }
}
char peek(struct stack* stack) {
    if(isEmpty(stack))
        return -1;
    
    return stack->arr[stack->top];
}

bool isValid(char* s) {
    int n = strlen(s);
    struct stack* stack = createStack(n);
    if (n == 0) return true;

    for(int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
        } else if ((s[i] == ')' && peek(stack) == '(' && !isEmpty(stack)) ||
                    (s[i] == '}' && peek(stack) == '{' && !isEmpty(stack)) ||
                    (s[i] == ']' && peek(stack) == '[' && !isEmpty(stack))) {
                        pop(stack);
                    }

            else    return false;
    }
    return isEmpty(stack);

}
