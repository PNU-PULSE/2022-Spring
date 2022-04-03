#include <stdio.h>
#include <string.h>
#define P 0 // ¼Ò°ıÈ£(Parentheses)
#define S 1 // ´ë°ıÈ£ (Square bracket)

int stack[100];
int top;

void push(int x) {
	stack[++top] = x;
}
int pop() {
	return stack[top--];
}

int f(char str[]) {
	int flag = 1;
	int length = strlen(str);

	top = -1;
	for (int i = 0; i < length; i++) {
		if (str[i] == '(') push(P);
		else if (str[i] == '[') push(S);
		else if (str[i] == ')') {
			if (top == -1 || pop() !=P) {
				flag = 0; break;
			}
		}
		else if (str[i] == ']') {
			if (top == -1 || pop() != S) {
				flag = 0; break;
			}
		}
	}

	if (flag) {
		if (top != -1) flag = 0;
	}

	return flag;
}

int main() {
	char str[101];

	while (1) {
		scanf("%[^\n]s", str);
		getchar();

		if (strcmp(str, ".") == 0) break;
		if (f(str)) printf("yes\n");
		else printf("no\n");

	}

	return 0;
}
