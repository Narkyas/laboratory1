//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//#include <locale.h>
//#define MAX_SIZE 100
//typedef struct {
//	float data[MAX_SIZE];
//	int top;
//} Stack;
//void initialize(Stack* stack) {
//	stack->top = -1;
//}
//int isEmpty(Stack* stack) {
//	return (stack->top == -1);
//}
//void push(Stack* stack, float ch) {
//	if (stack->top == MAX_SIZE - 1) {
//		printf("Стек переполнен\n");
//		return;
//	}
//	stack->data[++(stack->top)] = ch;
//}
//float pop(Stack* stack) {
//	if (isEmpty(stack)) {
//		printf("Стек пуст\n");
//		return '\0';
//	}
//	return stack->data[(stack->top)--];
//}
//int isOperator(char ch) {
//	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == 'q' || ch == 's' ||
//		ch == 'c');
//}
//int getPriority(char ch) {
//	if (ch == '+' || ch == '-')
//		return 1;
//	else if (ch == '*' || ch == '/')
//		return 2;
//	else if (ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c')
//		return 3;
//	else
//		return 0;
//}
//void infixToPostfix(char* infix, char* postfix) {
//	Stack stack;
//	initialize(&stack);
//	int i, j;
//	int k = 0;
//	char ch;
//	char tmp[10];
//	char xs[123] = { 0 };
//	char xs1[123][10];
//	for (i = 0, j = 0; infix[i] != '\0'; i++) {
//		ch = infix[i];
//		if (ch >= 97 && ch <= 122 && ch != 'q' && ch != 's' && ch != 'c') {
//			if (xs[ch] > 0) {
//				while (isdigit(xs1[ch][k])) {
//					postfix[j++] = xs1[ch][k++];
//				}
//				k = 0;
//				postfix[j++] = ' ';
//			}
//			else {
//				printf("Введите значение переменной %c: ", ch);
//				gets_s(tmp, 10);
//				while (isdigit(tmp[k])) {
//					postfix[j++] = tmp[k++];
//				}
//				k = 0;
//				postfix[j++] = ' ';
//				xs[ch]++;
//				while (isdigit(tmp[k])) {
//					xs1[ch][k++] = tmp[k++];
//				}
//				k = 0;
//			}
//		}
//		if (ch == ' ' || ch == '\t')
//			continue;
//		if (isdigit(ch)) {
//			while (isdigit(infix[i])) {
//				postfix[j++] = infix[i++];
//			}
//			postfix[j++] = ' ';
//			i--;
//		}
//		else if (isOperator(ch)) {
//			while (!isEmpty(&stack) && getPriority(stack.data[stack.top]) >= getPriority(ch)) {
//				postfix[j++] = pop(&stack);
//				postfix[j++] = ' ';
//			}
//			push(&stack, ch);
//		}
//		else if (ch == '(') {
//			push(&stack, ch);
//		}
//		else if (ch == ')') {
//			while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
//				postfix[j++] = pop(&stack);
//				postfix[j++] = ' ';
//			}
//			if (!isEmpty(&stack) && stack.data[stack.top] == '(') {
//				pop(&stack);
//			}
//			else {
//				printf("Ошибка: неправильное выражение\n");
//				return;
//			}
//		}
//	}
//	while (!isEmpty(&stack)) {
//		if (stack.data[stack.top] == '(') {
//			printf("Ошибка: неправильное выражение\n");
//			return;
//		}
//		postfix[j++] = pop(&stack);
//		postfix[j++] = ' ';
//	}
//	postfix[j] = '\0';
//	float evaluatePostfix(char* postfix) {
//		Stack stack;
//		initialize(&stack);
//		int i;
//		float result, operand1, operand2;
//		char num[10];
//		int numIndex = 0;
//		char ch;
//		for (i = 0; postfix[i] != '\0'; i++) {
//			ch = postfix[i];
//			if (isdigit(ch)) {
//				while (isdigit(postfix[i])) {
//					num[numIndex++] = postfix[i++];
//				}
//				num[numIndex] = '\0';
//				numIndex = 0;
//				push(&stack, atoi(num));
//			}
//			else if (ch == ' ') {
//				continue;
//			}
//			else if (isOperator(ch)) {
//				if (ch == '!' || ch == 'q' || ch == 's' || ch == 'c') {
//					operand1 = pop(&stack);
//					switch (ch) {
//					case '!':
//						result = 1;
//						for (int j = 1; j <= operand1; j++) {
//							result *= j;
//						}
//						break;
//					case 'q':
//						result = sqrt(operand1);
//						break;
//					case 's':
//						result = sin(operand1);
//						break;
//					case 'c':
//						result = cos(operand1);
//						break;
//					default:
//						printf("Ошибка: неподдерживаемый оператор\n");
//						return 0;
//					}
//				}
//				else {
//					operand2 = pop(&stack);
//					operand1 = pop(&stack);
//					switch (ch) {
//					case '+':
//						result = operand1 + operand2;
//						break;
//					case '-':
//						result = operand1 - operand2;
//						break;
//					case '*':
//						result = operand1 * operand2;
//						break;
//					case '/':
//						result = operand1 / operand2;
//						break;
//					case '^':
//						result = pow(operand1, operand2);
//						break;
//					default:
//						printf("Ошибка: неподдерживаемый оператор\n");
//						return 0;
//					}
//					push(&stack, result);
//					printf("Ошибка: неправильный символ в постфиксной записи\n");
//					return 0;
//					result = pop(&stack);
//					if (!isEmpty(&stack)) {
//						printf("Ошибка: неправильное выражение\n");
//						return 0;
//						return result;
//						int main() {
//							setlocale(LC_ALL, "rus");
//							char infix[MAX_SIZE];
//							char postfix[MAX_SIZE];
//							printf("q - квадратный корень, s - синус, c - косинус, на вход принимает целые числа\n");
//							printf("Введите выражение: ");
//							fgets(infix, sizeof(infix), stdin);
//							infix[strlen(infix) - 1] = '\0';
//							infixToPostfix(infix, postfix);
//							//printf("Постфиксная запись: %s\n", postfix);
//							float result = evaluatePostfix(postfix);
//							printf("Результат: %.2f\n", result);
//							return 0;


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//#include <locale.h>
//
//#define MAX_SIZE 100
//
//typedef struct {
//    float data[MAX_SIZE];
//    int top;
//} Stack;
//
//void initialize(Stack* stack) {
//    stack->top = -1;
//}
//
//int isEmpty(Stack* stack) {
//    return (stack->top == -1);
//}
//
//void push(Stack* stack, float value) {
//    if (stack->top == MAX_SIZE - 1) {
//        printf("Стек переполнен\n");
//        return;
//    }
//    stack->data[++(stack->top)] = value;
//}
//
//float pop(Stack* stack) {
//    if (isEmpty(stack)) {
//        printf("Стек пуст\n");
//        return 0; // Возвращаем 0, если стек пуст
//    }
//    return stack->data[(stack->top)--];
//}
//
//int isOperator(char ch) {
//    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c');
//}
//
//int getPriority(char ch) {
//    if (ch == '+' || ch == '-') return 1;
//    else if (ch == '*' || ch == '/') return 2;
//    else if (ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c') return 3;
//    else return 0;
//}
//
//void infixToPostfix(char* infix, char* postfix) {
//    Stack stack;
//    initialize(&stack);
//
//    int i, j = 0;
//    char ch;
//
//    for (i = 0; infix[i] != '\0'; i++) {
//        ch = infix[i];
//
//        if (isspace(ch)) continue; // Игнорируем пробелы
//
//        if (isdigit(ch)) { // Если символ - цифра
//            while (isdigit(infix[i])) {
//                postfix[j++] = infix[i++];
//            }
//            postfix[j++] = ' ';
//            i--;
//        }
//        else if (isOperator(ch)) { // Если символ - оператор
//            while (!isEmpty(&stack) && getPriority(stack.data[stack.top]) >= getPriority(ch)) {
//                postfix[j++] = pop(&stack);
//                postfix[j++] = ' ';
//            }
//            push(&stack, ch);
//        }
//        else if (ch == '(') { // Открывающая скобка
//            push(&stack, ch);
//        }
//        else if (ch == ')') { // Закрывающая скобка
//            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
//                postfix[j++] = pop(&stack);
//                postfix[j++] = ' ';
//            }
//            pop(&stack); // Удаляем '(' из стека
//        }
//        else { // Неизвестный символ
//            printf("Ошибка: неподдерживаемый символ '%c'\n", ch);
//            return;
//        }
//    }
//
//    while (!isEmpty(&stack)) { // Выгружаем оставшиеся операторы из стека
//        postfix[j++] = pop(&stack);
//        postfix[j++] = ' ';
//    }
//
//    postfix[j] = '\0'; // Завершаем строку
//}
//
//float evaluatePostfix(char* postfix) {
//    Stack stack;
//    initialize(&stack);
//
//    int i;
//    float result, operand1, operand2;
//
//    for (i = 0; postfix[i] != '\0'; i++) {
//        char ch = postfix[i];
//
//        if (isdigit(ch)) { // Если символ - цифра
//            char num[10];
//            int numIndex = 0;
//
//            while (isdigit(postfix[i])) {
//                num[numIndex++] = postfix[i++];
//            }
//            num[numIndex] = '\0';
//            push(&stack, atof(num)); // Преобразуем строку в число с плавающей точкой
//            i--;
//        }
//        else if (ch != ' ') { // Игнорируем пробелы
//            operand2 = pop(&stack);
//            operand1 = pop(&stack);
//
//            switch (ch) {
//            case '+': result = operand1 + operand2; break;
//            case '-': result = operand1 - operand2; break;
//            case '*': result = operand1 * operand2; break;
//            case '/':
//                if (operand2 != 0)
//                    result = operand1 / operand2;
//                else {
//                    printf("Ошибка: деление на ноль\n");
//                    return 0;
//                }
//                break;
//            case '^': result = pow(operand1, operand2); break;
//            case '!':
//                result = 1;
//                for (int j = 1; j <= operand1; j++) result *= j;
//                break;
//            case 'q': result = sqrt(operand1); break;
//            case 's': result = sin(operand1); break;
//            case 'c': result = cos(operand1); break;
//            default:
//                printf("Ошибка: неподдерживаемый оператор '%c'\n", ch);
//                return 0;
//            }
//
//            push(&stack, result); // Помещаем результат обратно в стек
//        }
//    }
//
//    return pop(&stack); // Возвращаем финальный результат
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    char infix[MAX_SIZE];
//    char postfix[MAX_SIZE];
//
//    printf("q - квадратный корень, s - синус, c - косинус\n");
//
//    printf("Введите выражение: ");
//
//    fgets(infix, sizeof(infix), stdin);
//
//    infix[strlen(infix) - 1] = '\0'; // Убираем символ новой строки
//
//    infixToPostfix(infix, postfix);
//
//    //printf("Постфиксная запись: %s\n", postfix); // Можно раскомментировать для отладки
//
//    float result = evaluatePostfix(postfix);
//
//    printf("Результат: %.2f\n", result);
//
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//#include <locale.h>
//
//#define MAX_SIZE 100
//
//typedef struct {
//    float data[MAX_SIZE];
//    int top;
//} Stack;
//
//void initialize(Stack* stack) {
//    stack->top = -1;
//}
//
//int isEmpty(Stack* stack) {
//    return (stack->top == -1);
//}
//
//void push(Stack* stack, float value) {
//    if (stack->top == MAX_SIZE - 1) {
//        printf("Стек переполнен\n");
//        return;
//    }
//    stack->data[++(stack->top)] = value;
//}
//
//float pop(Stack* stack) {
//    if (isEmpty(stack)) {
//        printf("Стек пуст\n");
//        return 0; // Возвращаем 0, если стек пуст
//    }
//    return stack->data[(stack->top)--];
//}
//
//int isOperator(char ch) {
//    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c');
//}
//
//int getPriority(char ch) {
//    if (ch == '+' || ch == '-') return 1;
//    else if (ch == '*' || ch == '/') return 2;
//    else if (ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c') return 3;
//    else return 0;
//}
//
//void infixToPostfix(char* infix, char* postfix) {
//    Stack stack;
//    initialize(&stack);
//
//    int i, j = 0;
//    char ch;
//
//    for (i = 0; infix[i] != '\0'; i++) {
//        ch = infix[i];
//
//        if (isspace(ch)) continue; // Игнорируем пробелы
//
//        if (isdigit(ch)) { // Если символ - цифра
//            while (isdigit(infix[i])) {
//                postfix[j++] = infix[i++];
//            }
//            postfix[j++] = ' ';
//            i--;
//        }
//        else if (isOperator(ch)) { // Если символ - оператор
//            while (!isEmpty(&stack) && getPriority(stack.data[stack.top]) >= getPriority(ch)) {
//                postfix[j++] = pop(&stack);
//                postfix[j++] = ' ';
//            }
//            push(&stack, ch);
//        }
//        else if (ch == '(') { // Открывающая скобка
//            push(&stack, ch);
//        }
//        else if (ch == ')') { // Закрывающая скобка
//            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
//                postfix[j++] = pop(&stack);
//                postfix[j++] = ' ';
//            }
//            pop(&stack); // Удаляем '(' из стека
//        }
//        else { // Неизвестный символ
//            printf("Ошибка: неподдерживаемый символ '%c'\n", ch);
//            return;
//        }
//    }
//
//    while (!isEmpty(&stack)) { // Выгружаем оставшиеся операторы из стека
//        postfix[j++] = pop(&stack);
//        postfix[j++] = ' ';
//    }
//
//    postfix[j] = '\0'; // Завершаем строку
//}
//
//float evaluatePostfix(char* postfix) {
//    Stack stack;
//    initialize(&stack);
//
//    int i;
//    float result, operand1, operand2;
//
//    for (i = 0; postfix[i] != '\0'; i++) {
//        char ch = postfix[i];
//
//        if (isdigit(ch)) { // Если символ - цифра
//            char num[10];
//            int numIndex = 0;
//
//            while (isdigit(postfix[i])) {
//                num[numIndex++] = postfix[i++];
//            }
//            num[numIndex] = '\0';
//            push(&stack, atof(num)); // Преобразуем строку в число с плавающей точкой
//            i--;
//        }
//        else if (ch != ' ') { // Игнорируем пробелы
//            if (ch == 'q') { // Квадратный корень
//                operand1 = pop(&stack);
//                result = sqrt(operand1);
//                push(&stack, result);
//            }
//            else if (ch == 's') { // Синус
//                operand1 = pop(&stack);
//                result = sin(operand1);
//                push(&stack, result);
//            }
//            else if (ch == 'c') { // Косинус
//                operand1 = pop(&stack);
//                result = cos(operand1);
//                push(&stack, result);
//            }
//            else { // Операторы с двумя операндами
//                operand2 = pop(&stack);
//                operand1 = pop(&stack);
//
//                switch (ch) {
//                case '+': result = operand1 + operand2; break;
//                case '-': result = operand1 - operand2; break;
//                case '*': result = operand1 * operand2; break;
//                case '/':
//                    if (operand2 != 0)
//                        result = operand1 / operand2;
//                    else {
//                        printf("Ошибка: деление на ноль\n");
//                        return 0;
//                    }
//                    break;
//                case '^': result = pow(operand1, operand2); break;
//                case '!':
//                    result = 1;
//                    for (int j = 1; j <= operand1; j++) result *= j;
//                    break;
//                default:
//                    printf("Ошибка: неподдерживаемый оператор '%c'\n", ch);
//                    return 0;
//                }
//
//                push(&stack, result); // Помещаем результат обратно в стек
//            }
//        }
//    }
//
//    return pop(&stack); // Возвращаем финальный результат
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    char infix[MAX_SIZE];
//    char postfix[MAX_SIZE];
//
//    printf("q - квадратный корень, s - синус, c - косинус\n");
//
//    printf("Введите выражение: ");
//
//    fgets(infix, sizeof(infix), stdin);
//
//    infix[strlen(infix) - 1] = '\0'; // Убираем символ новой строки
//
//    infixToPostfix(infix, postfix);
//
//    float result = evaluatePostfix(postfix);
//
//    printf("Результат: %.2f\n", result);
//
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#define MAX_SIZE 100

typedef struct {
    float data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

void push(Stack* stack, float value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Стек переполнен\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

float pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст\n");
        return 0;
    }
    return stack->data[(stack->top)--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c');
}

int getPriority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^' || ch == '!' || ch == 'q' || ch == 's' || ch == 'c')
        return 3;
    else
        return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;
    char ch;
    char tmp[10];

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (ch == ' ' || ch == '\t')
            continue;

        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && getPriority(stack.data[stack.top]) >= getPriority(ch)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, ch);
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == '(') {
                pop(&stack);
            }
            else {
                printf("Ошибка: неправильное выражение\n");
                return;
            }
        }
    }

    while (!isEmpty(&stack)) {
        if (stack.data[stack.top] == '(') {
            printf("Ошибка: неправильное выражение\n");
            return;
        }
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}
float evaluatePostfix(char* postfix) {
    Stack stack;
    initialize(&stack);
    int i;
    float operand1, operand2, result;
    char num[10];
    int numIndex = 0;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            while (isdigit(postfix[i])) {
                num[numIndex++] = postfix[i++];
            }
            num[numIndex] = '\0';
            push(&stack, atof(num));
            numIndex = 0;
            i--;
        }
        else if (postfix[i] == ' ') {
            continue;
        }
        else if (isOperator(postfix[i])) {
            char op = postfix[i];
            if (op == '!' || op == 's' || op == 'c') {
                operand1 = pop(&stack);
                switch (op) {
                case '!':
                    result = 1;
                    for (int j = 1; j <= operand1; j++) {
                        result *= j;
                    }
                    break;
                case 'q':
                    result = sqrt(operand1);
                    break;
                case 's':
                    result = sin(operand1);
                    break;
                case 'c':
                    result = cos(operand1);
                    break;
                }
                push(&stack, result);
            }
            else {
                operand2 = pop(&stack);
                operand1 = pop(&stack);
                switch (op) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                }
                push(&stack, result);
            }
        }
    }

    result = pop(&stack);
    if (!isEmpty(&stack)) {
        printf("Ошибка: неправильное выражение\n");
        return 0;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Доступные операции:\n");
    printf("+ - сложение\n- - вычитание\n* - умножение\n/ - деление\n^ - возведение в степень\n");
    printf("! - факториал\nq - квадратный корень\ns - синус\nc - косинус\n");
    printf("Введите выражение: ");

    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';

    infixToPostfix(infix, postfix);
    printf("Постфиксная запись: %s\n", postfix);

    float result = evaluatePostfix(postfix);
    printf("Результат: %.2f\n", result);

    return 0;
}