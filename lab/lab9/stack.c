#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define STACK_LEN 32

char *convert(char *expr) {
	char op_stack[STACK_LEN];
	char stack[STACK_LEN];
	int op_top, top;
	char *c, *ret;

	memset(op_stack, '\0', STACK_LEN);
	memset(stack, '\0', STACK_LEN);
	op_top = top = 0;
	c = expr;

	while (*c != '\0') {
		if ((*c >= '0') && (*c <= '9')) {
			stack[top++] = *c;
		} else if ((*c == '+') || (*c == '-')) {
			while (op_top != 0) {
				stack[top++] = op_stack[op_top - 1];
				op_top--;
			}
			op_stack[op_top++] = *c;
		} else {
			exit(-1);
		}
		c++;
	}

	while (op_top != 0) {
		stack[top++] = op_stack[op_top - 1];
		op_top--;
	}

	ret = (char *) malloc(strlen(stack) + 1);
	sprintf(ret, "%s", stack);
	return ret;
}

int main() {
	puts(convert("3-7+4-5"));
	return 0;
}

