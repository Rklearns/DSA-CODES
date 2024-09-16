#include <stdio.h>
#define MAX 100 // Maximum size of the stack

int top = -1;    // Top of the stack
int arr[MAX];    // Stack array

// Function to push an element onto the stack
void push(int ele) {
    if (top == MAX - 1) { // Correct boundary check for stack overflow
        printf("Stack Overflow\n");
    } else {
        top++; // Increment top
        arr[top] = ele;
        printf("%d pushed to stack\n", ele);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return -1 when stack is empty
    } else {
        int popped = arr[top--]; // Return top element and decrement top
        printf("%d popped from stack\n", popped);
        return popped;
    }
}

// Function to get the top element (peek)
int peek() {
    if (top == -1) {
        printf("Stack is empty! No peek element\n");
        return -1;
    } else {
        return arr[top]; // Return top element, not top index
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty! Can't display\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    /*push(20);
    push(56);
    push(65);
    push(69);
    push(5);*/
    

    pop();
    pop();

    printf("Peek is %d\n", peek());

    display();
    
    return 0;
}
