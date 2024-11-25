#include <stdarg.h>
#include <unistd.h>

/**
* _printf - custom implementation of printf function
* @format: format string containing the characters and format specifiers
* Return: the number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr = format;

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
                count += write(1, &(char){va_arg(args, int)}, 1);
            else if (*ptr == 's')
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                    count += write(1, str++, 1);
            }
            else if (*ptr == '%')
                count += write(1, "%", 1);
        }
        else
            count += write(1, ptr, 1);
        
        ptr++;
    }

    va_end(args);
    return count;
}
