#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
int stepen(int num, int base) {
    int result = 1;
    int i;
    for(i = 0; i < base; i++) {
        result *= num;
    }
    return result;
}
int factorial(int num) {
    if(num == 0 || num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

// Структура стека для разбора выражения в формы
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char ch) {
    if(stack->top == MAX_SIZE - 1) {
        printf("Стек переполнен\n");
        return;
    }
    stack->data[++stack->top] = ch;
}

char pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Стек пуст\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Проверка на оператор
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '!');
}

// Функция определения приоритета операторов
int getPriority(char op) {
    switch(op) {
        case '!': return 4;
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Структура узла дерева
typedef struct Node {
    char op;      // Оператор или '0' для числа
    int value;    // Значение числа
    struct Node* left;
    struct Node* right;
} Node;

// Глобальные переменные
Node* expression_tree = NULL;
char current_expression[MAX_SIZE] = "";

// Функции для работы с деревом
Node* create_number(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->op = '0';
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* create_operator(char op, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

void free_tree(Node* root) {
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Функции преобразования записей
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;
    char ch;
    
    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        
        if(ch == ' ' || ch == '\t') continue;
        
        if(isdigit(ch)) {
            while(isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if(ch == '(') {
            push(&stack, ch);
        }
        else if(ch == ')') {
            while(!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            pop(&stack); // Удаляем '('
        }
        else if(isOperator(ch)) {
            while(!isEmpty(&stack) && getPriority(stack.data[stack.top]) >= getPriority(ch)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, ch);
        }
    }
    
    while(!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }
    
    if(j > 0) postfix[j-1] = '\0';
    else postfix[0] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    // Инвертируем строку
    int len = strlen(infix);
    char reversed[MAX_SIZE];
    int i, j = 0;
    
    for(i = len-1; i >= 0; i--) {
        if(infix[i] == '(') reversed[j++] = ')';
        else if(infix[i] == ')') reversed[j++] = '(';
        else reversed[j++] = infix[i];
    }
    reversed[j] = '\0';
    
    // Конвертируем в постфиксную форму
    char postfix[MAX_SIZE];
    infixToPostfix(reversed, postfix);
    
    // Инвертируем результат
    len = strlen(postfix);
    for(i = 0; i < len; i++) {
        prefix[i] = postfix[len-1-i];
    }
    prefix[len] = '\0';
}

// Функция разбора выражения
Node* parse_expression(const char* expr) {
    Node* nodes[MAX_SIZE];
    char ops[MAX_SIZE];
    int node_top = -1, op_top = -1;
    int i = 0, num;
    
    while(expr[i] != '\0') {
        if(expr[i] == ' ') { i++; continue; }
        
        if(isdigit(expr[i])) {
            num = 0;
            while(isdigit(expr[i])) {
                num = num * 10 + (expr[i++] - '0');
            }
            nodes[++node_top] = create_number(num);
            continue;
        }
        
        if(expr[i] == '(') {
            ops[++op_top] = expr[i];
            i++;
            continue;
        }
        
        if(expr[i] == ')') {
            while(op_top >= 0 && ops[op_top] != '(') {
                char op = ops[op_top--];
                Node* right = (op != '!') ? nodes[node_top--] : NULL;
                Node* left = (op != '!') ? nodes[node_top--] : nodes[node_top];
                nodes[++node_top] = create_operator(op, left, right);
            }
            op_top--;
            i++;
            continue;
        }
        
        if(isOperator(expr[i])) {
            while(op_top >= 0 && ops[op_top] != '(' && 
                  getPriority(ops[op_top]) >= getPriority(expr[i])) {
                char op = ops[op_top--];
                Node* right = (op != '!') ? nodes[node_top--] : NULL;
                Node* left = (op != '!') ? nodes[node_top--] : nodes[node_top];
                nodes[++node_top] = create_operator(op, left, right);
            }
            ops[++op_top] = expr[i];
            i++;
            continue;
        }
    }
    
    while(op_top >= 0) {
        char op = ops[op_top--];
        Node* right = (op != '!') ? nodes[node_top--] : NULL;
        Node* left = (op != '!') ? nodes[node_top--] : nodes[node_top];
        nodes[++node_top] = create_operator(op, left, right);
    }
    
    return nodes[node_top];
}

// Функция вычисления
//обрати внимание на факториал
int evaluate(Node* root) {
    if(root == NULL) return 0;
    
    if(root->op == '0') return root->value;
    
    if(root->op == '!') {
        int left = evaluate(root->left);
        return factorial(left);
    }
    
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    
    switch(root->op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        case '^': return stepen(left, right);
        default: return 0;
    }
}

void print_prefix(Node* root) {
    if(root == NULL) return;
    
    if(root->op == '0') {
        printf("%d ", root->value);
    } else {
        printf("%c ", root->op);
        print_prefix(root->left);
        if(root->op != '!') print_prefix(root->right);
    }
}

void print_postfix(Node* root) {
    if(root == NULL) return;
    
    print_postfix(root->left);
    if(root->op != '!') print_postfix(root->right);
    
    if(root->op == '0') {
        printf("%d ", root->value);//делим на цифры и операции
    } else {
        printf("%c ", root->op);
    }
}

int main() {
    char command[50];
    char postfix[MAX_SIZE];
    char prefix[MAX_SIZE];
    setlocale(LC_ALL, "Russian");
    printf("Введите арифметическое выражение\n");
    printf("Доступные операторы:\n");
    printf("1 +\n2 -\n3 *\n4 /\n5 ! (факториал)\n6 ^ (степень)\n");
    printf("Доступные команды:\n");
    printf("parse <выражение> - разобрать выражение\n");
    printf("save_prf - вывести в префиксной форме\n");
    printf("save_pst - вывести в постфиксной форме\n");
    printf("eval - вычислить выражение\n");
    printf("exit - выход\n");
    
    while(1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        
        if(strncmp(command, "parse ", 6) == 0) {
            free_tree(expression_tree);
            strncpy(current_expression, command + 6, MAX_SIZE);
            expression_tree = parse_expression(current_expression);
            if(expression_tree) {
                printf("Выражение успешно разобрано\n");
            } else {
                printf("Ошибка разбора выражения\n");
            }
        }
        else if(strcmp(command, "save_prf") == 0) {
            if(expression_tree) {
                printf("Префиксная запись: ");
                print_prefix(expression_tree);
                printf("\n");
            } else {
                printf("Дерево не построено\n");
            }
        }
        else if(strcmp(command, "save_pst") == 0) {
            if(expression_tree) {
                printf("Постфиксная запись: ");
                print_postfix(expression_tree);
                printf("\n");
            } else {
                printf("Дерево не построено\n");
            }
        }
        else if(strcmp(command, "eval") == 0) {
            if(expression_tree) {
                printf("Результат: %d\n", evaluate(expression_tree));
            } else {
                printf("Дерево не построено\n");
            }
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Неизвестная команда\n");
        }
    }
    
    free_tree(expression_tree);
    return 0;
}
