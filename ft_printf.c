#include "libftprintf.h"
#include <stdio.h>

void    printfaddr(long long addr, char *hex)
{
    if (addr > 16)
        printfaddr(addr / 16, hex);
    else
        ft_putchar_fd(hex[addr], 1);
}

void    pprocessor(void *addr, char *hex)
{
    ft_putstr_fd("0x", 1);
    printfaddr((long long)addr, hex);
}

void    parsing(char form, va_list av)
{
    if (form == 'c')
        ft_putchar_fd(va_arg(av, int), 1);
    else if (form == 's')
        ft_putstr_fd(va_arg(av, char *), 1);
    else if (form== 'p')
        pprocessor(va_arg(av, void *), "0123456789abcdef");
    else if (form == 'd' || form == 'i')
        ft_putnbr_fd(va_arg(av, int), 1);
    else if (form == 'u')
        printf("u\n");
    else if (form == 'x' || form == 'X')
        printf("x\n");
    else if (form == '%')
        ft_putchar_fd('%', 1);
}

int ft_printf(char *str, ...)
{
    va_list av;
    int     idx;

    idx = -1;
    va_start(av, str);
    while (str[++idx])
    {
        if (str[idx] != '%')
            parsing(str[++idx], av);
        else if (!str[idx])
            break;
        else
            ft_putchar_fd(str[idx], 1);
    }
    
   return (0);
}

int main(){
    ft_printf("wdwdwdwwdw");
}