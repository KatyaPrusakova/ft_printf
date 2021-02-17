# ft_printf

A recreation of the standard C library's printf function.

## Function prototypes:

```C
int		ft_printf(const char *format, ...)
```

```C
char	*ft_sprintf(char *s, const char *format, ...)
```

```C
int		ft_dprintf(int fd, const char *format, ...)
```

## Usage:

Run make, which results in library called libftprintf.a. In your source file, use ft_printf() function just as you would use printf(). Furthermore, compile your source code with libftprintf.a to use ft_printf() function. So libftprint.a includes the ft_printf() function.

```C
gcc main.c libftprintf.a
```

#### Syntax for format specifiers:
`%[flags][width][.precision][length]type`

This implementation of printf supports the following:
 
<table><tr>  
<td>
 
| Flags field            |
| ---------------------- |
| `#` &ensp; (hash)      |
| `0` &ensp; (zero)      |
| ` ` ` ` &ensp; (space) |
| `+` &ensp; (plus)      |
| `-` &ensp; (minus)     |


</td>
<td>

| Width field | 
| ----------- |
| `<number>`  |
| `*`         |

</td>
<td>

| Precision field |
| --------------- |
| `.<number>`     |
| `.*`            |

</td>
<td>

| Length field |
| ------------ |
| `hh`         |
| `h`          |
| `l`          |
| `ll`         |
| `j`          |
| `z`          |
  
</td>
<td>

| Type field |
| ---------- |
| `d` or `i` |
| `D`        |
| `o`        |
| `O`        |
| `u`        |
| `U`        |
| `x`        |
| `X`        |
| `p`        |
| `c`        |
| `C`        |
| `s`        |
| `S`        |
| `%`        |
| `b`        |
| `r`        |

</td>
</tr></table>

The format specifiers `%b` is custom. They print binary, respectively.

### Example:

```C
#include "ft_printf.h"
#include <locale.h>

int    main(void)
{
    int i;

    setlocale(LC_ALL, "");
    ft_printf("Hello World!\n");
    ft_printf("%s", "This is ");
    ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");
    ft_printf("%d\n", 123);
    ft_printf("%05d\n", 42);
    ft_printf("%+09d\n", 42);
    ft_printf("%u\n", UINT_MAX);
    ft_printf("%#b\n", 256);
    ft_printf("%#o\n", 1039);
    ft_printf("%#X\n", 16417188);
    ft_printf("%p\n", &i);
    return (0);
}
```
Output:
```
Hello World!
This is ft_printf
123
00042
+00000042
4294967295
0b100000000
02017
0XFA81A4
0x7fff5c7159e8
```

## Code snippet:

```C
void    ft_process_string(const char *format, t_struct *f, va_list ap)
{
    while (format[f->i] != '\0')
    {
        if (format[f->i] == '%')
        {
            f->i++;
            if (ft_strchr("#-+ .*0123456789hljz", format[f->i]))
                ft_parse_modifiers(format, f, ap);
            if (ft_strchr("sSpdDioOuUxXcCbr%", format[f->i]))
            {
                ft_print(format, f, ap);
                if (f->len == -1)
                    return ;
                ft_reset_struct(f);
            }
        }
        else
            f->len += write(f->fd, &format[f->i], 1);
        f->i++;
    }
}
```

## [Subject](https://github.com/fpetras/42-subjects/blob/master/ft_printf.en.pdf "ft_printf.en.pdf")