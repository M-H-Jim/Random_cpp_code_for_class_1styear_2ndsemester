#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack;
    int top;
    int capacity;
    int initial_capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->stack = (int *)malloc(capacity * sizeof(int));
    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->initial_capacity = capacity;
    
    return newStack;
}

void push(Stack* s, int element) {
    if(s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->stack = realloc(s->stack, s->capacity * sizeof(int));
    }
    s->stack[++s->top] = element;
}

int pop(Stack *s) {
    if(s->top == -1) {
        printf("stack is empty\n");
        return -1;
    }
    int currentSize = s->top + 1;
    if(currentSize > 0 && currentSize <= s->capacity / 4 && s->capacity > s->initial_capacity) {
        int newCapacity = s->capacity / 2;
        if(newCapacity < s->initial_capacity)
            newCapacity = s->initial_capacity;
        
        s->stack = realloc(s->stack, newCapacity * sizeof(int));
        s->capacity = newCapacity;
    }
    return s->stack[s->top--];
}

int peek(Stack* s) {
    if(s->top == -1) {
        printf("Stack is empty\n");
    }
    return s->stack[s->top];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int size(Stack* s) {
    return s->top + 1;
}

void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}


int main() {
    
	  Stack *myStack = createStack(2);

    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);
    push(myStack, 6);
    push(myStack, 9);

    // Print initial stack
    printStack(myStack);

    printf("Pop: %d\n", pop(myStack));
    printf("Peek: %d\n", peek(myStack));
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", size(myStack));

	
	  pop(myStack);
    pop(myStack);
    pop(myStack);
    printStack(myStack);
	
	
	  free(myStack->stack);
	  free(myStack);
	
    
    return 0;
}
