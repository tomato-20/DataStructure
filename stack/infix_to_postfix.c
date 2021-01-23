// c program to convert infix to postfix expression

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int precedence(char);
int main(void)
{
    char ch, infix[MAX], postfix[MAX], opstack[MAX];
    int otos = -1, ptos = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);
    for (int i = 0, n = strlen(infix); i < n; i++)
    {
        ch = infix[i];

        if (ch == '(')
        {
            opstack[++otos] = ch;
        }
        else if (isalpha(ch))
        {
            postfix[++ptos] = ch;
        }
        else if (ch == ')')
        {
            while (opstack[otos] != '(')
            {
                postfix[++ptos] = opstack[otos];
                otos--;
            }
            otos--;
        }
        else
        {
            if (otos != -1)
            {
                while (precedence(opstack[otos]) > precedence(ch))
                {
                    postfix[++ptos] = opstack[otos];
                    otos--;
                }
            }
            opstack[++otos] = ch;
        }
    }

    while (otos != -1)
    {
        postfix[++ptos] = opstack[otos];
        otos--;
    }

    printf("postfix expression = ");

    for (int i = 0; i <= ptos; i++)
    {
        printf("%c", postfix[i]);
    }

    return 0;
}

int precedence(char ope)
{
    switch (ope)
    {
    case '$':
        return 4;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 1;
    }
}