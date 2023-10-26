// Write a program to reverse a string using recursion


#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; // Base case: when the start index is greater than or equal to the end index
    }

    // Swap the characters at start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively call the function on the remaining substring
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);

    printf("Original String: %s\n", str);

    // Reverse the string using recursion
    reverseString(str, 0, length - 1);

    printf("Reversed String: %s\n", str);

    return 0;
}
