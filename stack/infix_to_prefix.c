#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int precedence(char);

int main(void)
{
    char infix[MAX], opstack[MAX], prestack[MAX], ch;
    int otos, ptos;
    otos = ptos = -1;
    printf("Enter valid infix expression: ");
    scanf("%s", infix);

    //read character right to left one at a time
    for (int i = strlen(infix) - 1; i >= 0; i--)
    {
        ch = infix[i];

        if (ch == ')')
        {
            opstack[++otos] = ch;
        }
        else if (isalpha(ch))
        {
            prestack[++ptos] = ch;
        }
        else if (ch == '(')
        {
            while (opstack[otos] != ')')
            {
                prestack[++ptos] = opstack[otos];
                otos--;
            }
            otos--;
        }
        else
        {
            if (otos != -1)
            {
                while (precedence(opstack[otos]) >= precedence(ch))
                {
                    prestack[++ptos] = opstack[otos];
                    otos--;
                }
            }
            opstack[++otos] = ch;
        }
    }

    //empty ostack by pushing its items to prestack
    while (otos != -1)
    {
        prestack[++ptos] = opstack[otos];
        otos--;
    }

    //displaying equivalent prefix expression
    printf("prefix expression = ");
    while (ptos != -1)
    {
        printf("%c", prestack[ptos]);
        ptos--;
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