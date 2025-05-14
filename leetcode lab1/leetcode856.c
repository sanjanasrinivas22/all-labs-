#include <stdio.h>
#include <string.h>

int scoreOfParentheses(char * S) {
    int stack[1000], top = -1, score = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == '(') {
            stack[++top] = -1;  // Push a marker to represent a new parenthesis group
        } else {
            if (stack[top] == -1) {
                stack[top] = 1;  // It's a pair "()"
            } else {
                stack[top] *= 2;  // If there was a score, double it for the outer parentheses
            }
            if (top > 0) {
                stack[top - 1] += stack[top];  // Add the score to the outer parentheses group
            }
            top--;
        }
    }
    return stack[0];  // The final score is stored in the first element
}

int main() {
    char S[] = "(()(()))";
    printf("Score: %d\n", scoreOfParentheses(S));  // Output will be 6
    return 0;
}
