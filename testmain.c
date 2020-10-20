/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:39:34 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/20 16:53:31 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PI (3.1415926535897932384626433832795f)
#include <unistd.h>
#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>


static void	ft_nl(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, "\n", 1);
		i++;
	}
}

void    test_undefined(void)
{
    ft_printf("undefined behaviour? |%jx|\n", 4294967295);
    ft_printf("%%   %", "test");
}

void	test_c(void)
{
	int a;
	int b;

	printf("TEST %%c\n-----------------------------------------------------------------\n\n");

	a = ft_printf("FT character = |%c|\n", 'a');
	b = printf("PF character = |%c|\n", 'a');
	assert(a == b);
	ft_nl(1);


}

void	test_s(void)
{
	int a;
	int b;

	printf("TEST %%s\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%s = |%s|\n", "test");
    b = printf("PF %%s = |%s|\n", "test");
    assert(a == b);
	ft_nl(1);

    a = ft_printf("FT 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 FT\n");
    b = printf("PF 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 PF\n");
    assert(a == b);
    ft_nl(2);

    a = ft_printf("FT epic test%-7s%5s", "hello", "world");
    b = printf("PF epic test%-7s%5s", "hello", "world");
    assert(a == b);
    ft_nl(1);
}

void    test_d(void)
{
    int a;
    int b;

    printf("TEST %%d\n-----------------------------------------------------------------\n\n");

	a = ft_printf("FT %%hd |%hd|\n", 12);
	b = printf("PF %%hd |%hd|\n", 12);
    assert(a == b);
    ft_nl(1);

	a = ft_printf("FT %%hhd |%55.hhd|\n", 12);
	b = ft_printf("PF %%hhd |%55.hhd|\n", 12);
	assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0 width > pre {%08.5d}\n", 42);
    b = printf("PF 0 width > pre {%08.5d}\n", 42);
    assert (a == b);

    a = ft_printf("FT %%d = |%d|\n", 42);
    b = printf("PF %%d = |%d|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d LONG_MAX |%ld|\n", LONG_MAX);
    b = printf("PF %%d LONG_MAX |%ld|\n", LONG_MAX);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d LONG_MIN |%ld|\n", LONG_MIN);
    b = printf("PF %%d LONG_MIN |%ld|\n", LONG_MIN);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width > pre %%d |%20.5d|\n", 444);
    b = printf("PF width > pre %%d |%20.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width < pre %%d |%5.20d|\n", 444);
    b = printf("PF width < pre %%d |%5.20d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width left > pre %%d |%-20.5d|\n", 444);
    b = printf("PF width left > pre %%d |%-20.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width left > pre && 0 %%d |%-020.5d|\n", 444);
    b = printf("PF width left > pre && 0 %%d |%-020.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width > pre && 0 %%d |%020.5d|\n", 444);
    b = printf("PF width > pre && 0 %%d |%020.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width > pre %%d |%20.5d|\n", -444);
    b = printf("PF neg_val width > pre %%d |%20.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width < pre %%d |%5.20d|\n", -444);
    b = printf("PF neg_val width < pre %%d |%5.20d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width left > pre %%d |%-20.5d|\n", -444);
    b = printf("PF neg_val width left > pre %%d |%-20.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width left > pre && 0 %%d |%-020.5d|\n", -444);
    b = printf("PF neg_val width left > pre && 0 %%d |%-020.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width > pre && 0 %%d |%020.5d|\n", -444);
    b = printf("PF neg_val width > pre && 0 %%d |%020.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width > pre && 0+ %%d |%+020.5d|\n", -444);
    b = printf("PF neg_val width > pre && 0+ %%d |%+020.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT neg_val width > pre && 0+ %%d |%+-020.5d|\n", -444);
    b = printf("PF neg_val width > pre && 0+ %%d |%+-020.5d|\n", -444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width left > pre && 0+ %%d |%+-020.5d|\n", 444);
    b = printf("PF width left > pre && 0+ %%d |%+-020.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d w/ space |% d|\n", 649);
    b = printf("PF %%d w/ space |% d|\n", 649);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d w/ space plus |%+ d|\n", 649);
    b = printf("PF %%d w/ space plus |%+ d|\n", 649);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d w/ space plus 0 |%+0 d|\n", 649);
    b = printf("PF %%d w/ space plus 0 |%+0 d|\n", 649);
    assert(a == b);
    ft_nl(1);

    ft_printf("FT %%d LONG_MIN |%035ld|\n", LONG_MIN - 1);
    printf("PF %%d LONG_MIN |%035ld|\n", LONG_MIN - 1);
    assert (a == b);
    ft_nl(1);

}

void    test_i(void)
{
    int a;
    int b;

    printf("TEST %%i\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%i = |%i|\n", 42);
    b = printf("PF %%i = |%i|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%i LONG_MAX |%li|\n", LONG_MAX);
    b = printf("PF %%i LONG_MAX |%li|\n", LONG_MAX);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%i LONG_MIN |%li|\n", LONG_MIN);
    b = printf("PF %%i LONG_MIN |%li|\n", LONG_MIN);
    assert(a == b);
    ft_nl(1);
}

void    test_x(void)
{
    int a;
    int b;
    unsigned long long	ull_pos_1 = 22337203685477;

    printf("TEST %%x\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%x = |%x|\n", 42);
    b = printf("PF %%x = |%x|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT   %%#llx, ull_pos_1 |%#llx|\n", ull_pos_1);
    b = printf("PF   %%#llx, ull_pos_1 |%#llx|\n", ull_pos_1);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%lx LONG_MAX |%lx|\n", LONG_MAX);
    b = printf("PF %%lx LONG_MAX |%lx|\n", LONG_MAX);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%x u|%x|\n", 4294967295u);
    b = printf("PF %%x u|%x|\n", 4294967295u);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 4 values %%x |%lx| |%x| |%hx|%llx|\n", 1234567890999u, 1234567890999u, 1234567890999u, 1234567890999u);
    b = printf("PF 4 values %%x |%lx| |%x| |%hx|%llx|\n", 1234567890999u, 1234567890999u, 1234567890999u, 1234567890999u);
    assert(a == b);
    ft_nl(1);

}

void    test_xx(void)
{
    int a;
    int b;

    printf("TEST %%X\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%X = |%X|\n", 42);
    b = printf("PF %%X = |%X|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%lX LONG_MAX |%lX|\n", LONG_MAX);
    b = printf("PF %%lX LONG_MAX |%lX|\n", LONG_MAX);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%X u|%X|\n", 4294967295u);
    b = printf("PF %%X u|%X|\n", 4294967295u);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 4 values %%X |%lX| |%X| |%hX|%llX|\n", 1234567890999u, 1234567890999u, 1234567890999u, 1234567890999u);
    b = printf("PF 4 values %%X |%lX| |%X| |%hX|%llX|\n", 1234567890999u, 1234567890999u, 1234567890999u, 1234567890999u);
    assert(a == b);
    ft_nl(1);

}

void    test_o(void)
{
    int a;
    int b;

    printf("TEST %%o\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%o = |%o|\n", 42);
    b = printf("PF %%o = |%o|\n", 42);
    assert(a == b);
    ft_nl(1);
}

void    test_u(void)
{
    int a;
    int b;

     ft_printf("TEST %%u\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %%X = |%u|\n", 42);
    b = printf("PF %%X = |%u|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%lu, -42 |%lu|\n", -42);
    b = printf("PF %%lu, -42 |%lu|\n", -42);
    assert(a == b);
    ft_nl(1);
    ft_printf("%llu\n", ULLONG_MAX);
    a = ft_printf("FT 2 %%llu, 0, ULLONG_MAX |%llu|, |%llu|\n", 0llu, ULLONG_MAX);
    b = printf("FT 2 %%llu, 0, ULLONG_MAX |%llu|, |%llu|\n", 0llu, ULLONG_MAX);
    assert(a == b);
    ft_nl(1);
    }

void    test_p(void)
{
    int a;
    int b;
   int a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11, a12;

   ft_printf("TEST %%p\n-----------------------------------------------------------------\n\n");

   a = ft_printf("FT %%p = |%p|\n", 42);
   b = printf("PF %%p = |%p|\n", 42);
   assert(a == b);
   ft_nl(1);

    a = ft_printf("FT %%.0p |%.0p|\n", 0);
    b = printf("PF %%.0p |%.0p|\n", 0);
    assert(a == b);
    ft_nl(1);

    ft_printf("FT %%p with 12 addresses and with 70|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    printf("PF %%p with 12 addresses and with 70|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
}

void    test_g(void)
{
    int a;
    int b;

    ft_printf("TEST %%g\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT 0.15|%#.5g|\n", 0.15);
    b = printf("PF 0.15|%#.5g|\n", 0.15);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.25|%#.5g|\n", 0.25);
    b = printf("PF 0.25|%#.5g|\n", 0.25);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.15|%#.1g|\n", 0.15);
    b = printf("PF 0.15|%#.1g|\n", 0.15);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.25|%#.1g|\n", 0.25);
    b = printf("PF 0.25|%#.1g|\n", 0.25);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.35|%#.1g|\n", 0.35);
    b = printf("PF 0.35|%#.1g|\n", 0.35);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.45|%.1g|\n", 0.45);
    b = printf("PF 0.45|%.1g|\n", 0.45);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.55|%.1g|\n", 0.55);
    b = printf("PF 0.55|%.1g|\n", 0.55);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.65|%.1g|\n", 0.65);
    b = printf("PF 0.65|%.1g|\n", 0.65);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.75|%.1g|\n", 0.75);
    b = printf("PF 0.75|%.1g|\n", 0.75);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.85|%.1g|\n", 0.85);
    b = printf("PF 0.85|%.1g|\n", 0.85);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.95|%.1g|\n", 0.95);
    b = printf("PF 0.95|%.1g|\n", 0.95);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.555|%.2g|\n", 0.555);
    b = printf("PF 0.555|%.2g|\n", 0.555);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT   %%g, -958.125|%g|\n", -958.125);
    b = printf("PF   %%g, -958.125|%g|\n", -958.125);
    assert(a == b);
    ft_nl(1);


    a = ft_printf("FT %%g neg_val w presicion 0 |%.0g|\n", -958.125);
    b = printf("PF %%g neg_val w presicion 0 |%.0g|\n", -958.125);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%g width greater than presicion |%15.5g|\n", -9587.3333);
    b = printf("PF %%g width greater than presicion |%15.5g|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%g width greater than presicion left|%-15.5g|\n", -9587.3333);
    b = printf("PF %%g width greater than presicion left|%-15.5g|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%g width greater than presicion zero padding minus|%0-15.5g|\n", -9587.3333);
    b = printf("PF %%g width greater than presicion zero padding minus|%0-15.5g|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%g width greater than presicion zero padding minus|%015.5g|\n", -9587.3333);
    b = printf("PF %%g width greater than presicion zero padding minus|%015.5g|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ g with # flag presicion 1|%#.1g|\n", -0.0);
    b = printf("PF_ g with # flag presicion 1|%#.1g|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ g with # flag presicion 0|%#.0g|\n", -0.0);
    b = printf("PF_ g with # flag presicion 0|%#.0g|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ g #-5.3|%#-5.3g|\n", 0.0);
    b = printf("PF_ g #-5.3|%#-5.3g|\n", 0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ g #.1g|%#.1g|\n", -7.3);
    b = printf("PF_ g #.1g|%#.1g|\n", -7.3);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("ft_ significant digits %s |%g|\n", "23.00041", 23.00041);
    b = printf("pf_ significant digits %s |%g|\n", "23.00041", 23.00041);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("significant digits, shouldn't be rounded up ft_ |%.4g|\n", -1.2385);
    b = printf("significant digits, shouldn't be rounded up pf_ |%.4g|\n", -1.2385);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("ft_ significant digits, should print all the digits with no presicion %%g |%g|\n", 0.00894255);
    b = printf("pf_ significant digits, should print all the digits with no presicion %%g |%g|\n", 0.00894255);
    assert(a == b);
    ft_nl(1);
}

void    test_e(void)
{
    int a;
    int b;

    ft_printf("TEST %%e\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT test e basic |%e|\n", 7.5);
    b = printf("PF test e basic |%e|\n", 7.5);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.15|%#.5e|\n", 0.15);
    b = printf("PF 0.15|%#.5e|\n", 0.15);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.25|%#.5e|\n", 0.25);
    b = printf("PF 0.25|%#.5e|\n", 0.25);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.35|%#.1e|\n", 0.35);
    b = printf("PF 0.35|%#.1e|\n", 0.35);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.45|%.1e|\n", 0.45);
    b = printf("PF 0.45|%.1e|\n", 0.45);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.55|%.1e|\n", 0.55);
    b = printf("PF 0.55|%.1e|\n", 0.55);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.65|%.1e|\n", 0.65);
    b = printf("PF 0.65|%.1e|\n", 0.65);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.75|%.1e|\n", 0.75);
    b = printf("PF 0.75|%.1e|\n", 0.75);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.85|%.1e|\n", 0.85);
    b = printf("PF 0.85|%.1e|\n", 0.85);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.95|%.1e|\n", 0.95);
    b = printf("PF 0.95|%.1e|\n", 0.95);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT 0.555|%.2e|\n", 0.555);
    b = printf("PF 0.555|%.2e|\n", 0.555);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT   %%e, -958.125|%e|\n", -958.125);
    b = printf("PF   %%e, -958.125|%e|\n", -958.125);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%e width greater than presicion |%15.5e|\n", -9587.3333);
    b = printf("PF %%e width greater than presicion |%15.5e|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%e width greater than presicion left|%-15.5e|\n", -9587.3333);
    b = printf("PF %%e width greater than presicion left|%-15.5e|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%e width greater than presicion zero padding minus|%0-15.5e|\n", -9587.3333);
    b = printf("PF %%e width greater than presicion zero padding minus|%0-15.5e|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%e width greater than presicion zero padding minus|%015.5e|\n", -9587.3333);
    b = printf("PF %%e width greater than presicion zero padding minus|%015.5e|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ e with # flag presicion 1|%#.1e|\n", -0.0);
    b = printf("PF_ e with # flag presicion 1|%#.1e|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ e with # flag presicion 0|%#.0e|\n", -0.0);
    b = printf("PF_ e with # flag presicion 0|%#.0e|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ e #-5.3|%#-5.3e|\n", 0.0);
    b = printf("PF_ e #-5.3|%#-5.3e|\n", 0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ e #.1e|%#.1e|\n", -7.3);
    b = printf("PF_ e #.1e|%#.1e|\n", -7.3);
    assert(a == b);
    ft_nl(1);
}

void    test_float(void)
{
    int a;
    int b;

    ft_printf("TEST %%f\n-----------------------------------------------------------------\n\n");


    a = ft_printf("PF 0.15|%#.5f|\n", 0.15);
    b = printf("PF 0.15|%#.5f|\n", 0.15);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.25|%#.5f|\n", 0.25);
    b = printf("PF 0.25|%#.5f|\n", 0.25);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.15|%#.1f|\n", 0.15);
    b = printf("PF 0.15|%#.1f|\n", 0.15);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.25|%#.1f|\n", 0.25);
    b = printf("PF 0.25|%#.1f|\n", 0.25);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.35|%#.1f|\n", 0.35);
    b = printf("PF 0.35|%#.1f|\n", 0.35);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.45|%.1f|\n", 0.45);
    b = printf("PF 0.45|%.1f|\n", 0.45);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.55|%.1f|\n", 0.55);
    b = printf("PF 0.55|%.1f|\n", 0.55);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.65|%.1f|\n", 0.65);
    b = printf("PF 0.65|%.1f|\n", 0.65);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.75|%.1f|\n", 0.75);
    b = printf("PF 0.75|%.1f|\n", 0.75);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.85|%.1f|\n", 0.85);
    b = printf("PF 0.85|%.1f|\n", 0.85);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.95|%.1f|\n", 0.95);
    b = printf("PF 0.95|%.1f|\n", 0.95);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("PF 0.555|%.2f|\n", 0.555);
    b = printf("PF 0.555|%.2f|\n", 0.555);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%f(undefined, int input) = |%f|\n", 42);
    b = printf("PF %%f(undefined, int input) = |%f|\n", 42);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT   %%f, -958.125|%f|\n", -958.125);
    b = printf("PF   %%f, -958.125|%f|\n", -958.125);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%f width greater than presicion |%15.5f|\n", -9587.3333);
    b = printf("PF %%f width greater than presicion |%15.5f|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%f width greater than presicion left|%-15.5f|\n", -9587.3333);
    b = printf("PF %%f width greater than presicion left|%-15.5f|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%f width greater than presicion zero padding minus|%0-15.5f|\n", -9587.3333);
    b = printf("PF %%f width greater than presicion zero padding minus|%0-15.5f|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%f width greater than presicion zero padding minus|%015.5f|\n", -9587.3333);
    b = printf("PF %%f width greater than presicion zero padding minus|%015.5f|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ f with # flag presicion 1|%#.1f|\n", -0.0);
    b = printf("PF_ f with # flag presicion 1|%#.1f|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ f with # flag presicion 0|%#.0f|\n", -0.0);
    b = printf("PF_ f with # flag presicion 0|%#.0f|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ f #-5.3|%#-5.3f|\n", 0.0);
    b = printf("PF_ f #-5.3|%#-5.3f|\n", 0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ f #.1f|%#.1f|\n", -7.3);
    b = printf("PF_ f #.1f|%#.1f|\n", -7.3);
    assert(a == b);
    ft_nl(1);

    a =    printf("PF inf |%010.15f|\n", 1.0 / 0.0);
	b = ft_printf("FT inf |%010.15f|\n", 1.0 / 0.0);
	assert(a == b);

	a =    printf("PF -inf |%010.15f|\n", 1.0 / -0.0);
	b = ft_printf("FT -inf |%010.15f|\n", 1.0 / -0.0);
	assert(a == b);

	a =    printf("PF nan |%010.15f|\n", 0.0 / 0.0);
	b = ft_printf("FT nan |%010.15f|\n", 0.0 / 0.0);
    assert(a == b);
    ft_nl(2);
}

void    test_percent(void)
{
    int a;
    int b;

    ft_printf("TEST %%\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT %% = |%%|\n", 42);
    b = printf("PF %% = |%%|\n", 42);
    assert(a == b);
    ft_nl(1);
}

void    test_E(void)
{
    int a;
    int b;

    ft_printf("TEST %%E\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT   %%E, -958.125|%E|\n", -958.125);
    b = printf("PF   %%E, -958.125|%E|\n", -958.125);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%E width greater than presicion |%15.5E|\n", -9587.3333);
    b = printf("PF %%E width greater than presicion |%15.5E|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%E width greater than presicion left|%-15.5E|\n", -9587.3333);
    b = printf("PF %%E width greater than presicion left|%-15.5E|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%E width greater than presicion zero padding minus|%0-15.5E|\n", -9587.3333);
    b = printf("PF %%E width greater than presicion zero padding minus|%0-15.5E|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%E width greater than presicion zero padding minus|%015.5E|\n", -9587.3333);
    b = printf("PF %%E width greater than presicion zero padding minus|%015.5E|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ E with # flag presicion 1|%#.1E|\n", -0.0);
    b = printf("PF_ E with # flag presicion 1|%#.1E|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ E with # flag presicion 0|%#.0E|\n", -0.0);
    b = printf("PF_ E with # flag presicion 0|%#.0E|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ E #-5.3|%#-5.3E|\n", 0.0);
    b = printf("PF_ E #-5.3|%#-5.3E|\n", 0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ E #.1e|%#.1E|\n", -7.3);
    b = printf("PF_ E #.1e|%#.1E|\n", -7.3);
    assert(a == b);
    ft_nl(1);
}

void    test_G(void)
{
    int a;
    int b;

    ft_printf("TEST %%G\n-----------------------------------------------------------------\n\n");

    a = ft_printf("FT   %%G, -958.125|%G|\n", -958.125);
    b = printf("PF   %%G, -958.125|%G|\n", -958.125);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion |%15.5G|\n", -9587.3333);
    b = printf("PF %%G width greater than presicion |%15.5G|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion left|%-15.5G|\n", -9587.3333);
    b = printf("PF %%G width greater than presicion left|%-15.5G|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion zero padding minus|%0-15.5G|\n", -9587.3333);
    b = printf("PF %%G width greater than presicion zero padding minus|%0-15.5G|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion zero padding minus|%015.5G|\n", -9587.3333);
    b = printf("PF %%G width greater than presicion zero padding minus|%015.5G|\n", -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G with # flag presicion 1|%#.1G|\n", -0.0);
    b = printf("PF_ G with # flag presicion 1|%#.1G|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G with # flag presicion 0|%#.0G|\n", -0.0);
    b = printf("PF_ G with # flag presicion 0|%#.0G|\n", -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G #-5.3|%#-5.3G|\n", 0.0);
    b = printf("PF_ G #-5.3|%#-5.3G|\n", 0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G #.1G|%#.1G|\n", -7.3);
    b = printf("PF_ G #.1G|%#.1G|\n", -7.3);
    assert(a == b);
    ft_nl(1);
}
/*
void    test_sn(void)
{
    int a;
    int b;
	char *mine;
	char *original;

    mine = ft_strnew(11000);
    original = ft_strnew(11000);
    ft_printf("TEST ft_snprintf\n-----------------------------------------------------------------\n\n");


    a = ft_snprintf(mine, 420, "FT snprintf = |%X|\n", 42);
    b = snprintf(original, 420, "FT snprintf = |%X|\n", 42);
    assert(a == b);
    ft_printf("mine saves: |%s| with return value |%d|\n", mine, a);
    printf("orig saves: |%s| with return value |%d| \n", original, b);
	if (ft_strcmp(mine, original))
		ft_printf("ERROR snprintf test 1");
    ft_nl(1);
//    free(mine);
//    free(original);

    a = ft_snprintf(mine, 1000, "%%G width greater than presicion left|%-15.5G|\n", -9587.3333);
    b = snprintf(original, 1000, "%%G width greater than presicion left|%-15.5G|\n", -9587.3333);
    ft_printf("mine saves: |%s| with return value |%d|\n", mine, a);
    ft_printf("orig saves: |%s| with return value |%d| \n", original, b);
    assert(a == b);
    if (ft_strcmp(mine, original))
        ft_printf("ERROR snprintf test 2");
    ft_nl(1);
//    free(mine);
//    free(original);

    a = ft_snprintf(mine, 2000, "%%G width greater than presicion zero padding minus|%0-15.5G|\n", -9587.3333);
    b = snprintf(original, 2000, "%%G width greater than presicion zero padding minus|%0-15.5G|\n", -9587.3333);
    ft_printf("mine saves: |%s| with return value |%d|\n", mine, a);
    ft_printf("orig saves: |%s| with return value |%d| \n", original, b);
    assert(a == b);
    if (ft_strcmp(mine, original))
        ft_printf("ERROR snprintf test 3");
    ft_nl(1);
//    free(mine);
//    free()

    a = ft_snprintf(mine, 100, "%%G width greater than presicion zero padding minus|%015.5G|\n", -9587.3333);
    b = snprintf(original, 100, "%%G width greater than presicion zero padding minus|%015.5G|\n", -9587.3333);
    ft_printf("mine saves: |%s| with return value |%d|\n", mine, a);
    ft_printf("orig saves: |%s| with return value |%d| \n", original, b);
    assert(a == b);
    if (ft_strcmp(mine, original))
        ft_printf("ERROR snprintf test 4");
    ft_nl(1);

    a = ft_snprintf(mine, 10000, "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\n");
    b = snprintf(original, 10000, "VebUBa13li3nHzoAimfcH9krT5EYWsJ8gMmQxe0fF6mgpOUyXzzKKv4Hmvec3TJhAzYcDN4PR6s8UJqrEOCrKSYYSYGtDNcWYAGjoX9lMXPqHVIPPUDUJd79b9TRuf9KAqv0n38tmbkj0tmWHDy384ymLfQC9Cbg47L54sqSb2Y1e99u6rpCBcnArmtp8jZiSERTWLOz3gEJAPBuB6VgciCXWsq4tl1XhovJqtCSQWDQdFyfCW2VzdbcR7h8eZLrMya1VcwXFYW5RTM6tivbHbEkk0gCtJ5WcDEDbmkT5FB2FPOSPujopiwp6V9mTXbECOA6IswENqJHNzbvFr7iLIo7FKyx0nMt2rJcAWig1Ithx8Qhe723WoP95fDyuZPEuSRhxJD0SZxRgJiqck5BsL5pEBGvIKBnadyqK2s0PItNdcvVzuxLS9IqBMwL0MAX4mVg89Fh91Agei2AZqsZQ2EMKfwdYpdtRVL8hgSkbR7FQxXhb3B034e1zI6ufhaA3umxuWJowSdC6dm7HJzyaD46BqhpwWzP92D9jA7Jry17hUf9j7b24LzrxkL4xHLMmJerjniqiMivqJkdyiGpantbCqJ6CDXakReO5Krr3atlc5tWgMON900hBFD8J3KnljRCFn0YJICOuQxXCcbiVOkifT6EtX5atRea4MoVJ1Cmn62hJsdPD4y5uD4rQNJcPevTBLl0L3PLOXxd6AA1QIdyymYGfbd9sK9kUaNMAtoXUYSetmO4sFOkQ69r0f270NIcCIAvgt4sS50oXS33cBtHS08oinEJjQGgK9UkGhS8ahv4QiF3oxTvUi5aQ9g0zNyzuepj5h5eIda5YavYACU5zCXYrnj89KSjpkwBTYC7dtnSD8sAb2mI5SOmi1qFnR9huiejzgnokXW8XM6KoBsAVgLF9eVstkZFrGNXI5RLsUibacBqKE4pyM6EleSnwYjeG3rBeGjlwAXgKSiCvjX48pOkYcwxleBkY3YdY0XrM5i2nTPW7fdLQEo3pAOhUDaequDxBS342HX9csFkJita0bgAwNEkpmIggb4bOfLgi46GhekDx4BGDmCL42wyZ6bzqewb1tCvZYhnm5aorEEmyKuTkEZKNdoDJAQep13f9P4x0jvjYb7JZmzO5mNmZ7WGUHpFIvBOfKCiOthSKbEKwhXHkQiMCpRcDARigL8owr5lkVeZZh72T9CgoHXp89jk9DJXDC1VyllsXSnEOGGIAANrLPcT0BJIH51BTeRk5fsuAMF5t0khjDLHQKwFQroNmgOcdJxMExo6UmmgB2e1mbfr39xThuCV7yNnKI0S95xuR6Rm7pnHaCDClvpgDtFAs3uA2jbwihSIBT5xucdQ5l4gNNdgU6P0k7gcTjyWCTDRQVRTMwXiHsmNMPdJft8W21EpXFTp3btDH1FXZ78yxnpN0MBgg70pk6opAi7R0WfnL3PMO2oEbQ5eQIOUUAzcesxz87a3uLUmEXYngJ2YsVddiuoxw2UerfXNDvxfTXgjjXfn0A4NHyaAlDKmDXW9CxQU6jqCITydjj3TEAdQs382MBj307THVbnAn7PNhoX1v0HDnbr1jxDAjRP79msKHmuzJ59q4oeOhMhiT6qWKlWKF9JolHBfdgGKcmEOb4ZdDqysZlcLMtddL2hx2y6Jhl0yssBiAdCQTfvfQIGO0ZhfHO28nRF4IpJ9v5aPZSNJEFHwp9vjNbfCyyPJwXNfUIudTaCICSWo4CYNjPbvKlHYCYPsnfyOqycrFtKhzzVR7lAeuOWFm1SCvkkrdLSQRAM6kVF4bdciNfNssbCtOyn6a8Act6RNbbIFKuQ4eB2hNLa8M9zWgpB5H09uTB38f8y6Dip3rPftW2JZXTjleCEmX4THti33TEAQ2EGbZz7Ay5wLDE6uKwWuahRbKReydTStQC9qHhx5GNenSEc14dXwRHfXG1M9sEPTIK3pZRPl4NP9nLLNdRguJuLiXbPbbZiMmp2U7iWGPErCEuIdJyf3lSYL58iT2Zb5U9mf74NwfhKCPMoKy4aAaaBoPORxf1BNmLRYw0P2ctgucuNRTKPAQxuD4bYFGvqVPOyNDZRnOjpcVG62CDHdcqMa6FZyGW9xJHO5QZ0jMEk2HHOWR2hwwvoF7AIyYFviaiDydGUwbGvMhoFTZmI3M1UbeSJn0ZNt83bKvwHE7zPXsFnuqcKU28AfIej0iZCRGcCXmUXndJnk64iUDtzINrU9TdTRwCwSQ1SIFsrZAx2rjr7ppCYZBzKivuIBKcIkB6FMc8Iyfbnv2bfH0OdD1i49Thxgsih4mBHYUaCpo5BMtqvMU4EvnkpwneSSI5N9R6vPxeb9eXTJRof4mkVGMviGjcKrmOWqGvpvMO7YDsaYxImH1ZKNM7TnurdK0aydXE7iKEbYG7NG68OQO2dBN6fFAxB2yjfvcf4MYvKolIDGSHgQeT5r4nwO7ZMWpZ5GOq27WkZKid6SpvaFR7nDp4RpQEnPZR1RO3xobb7UZPE8NZ7d9jh3hrWe3XJXswmLcCQL3EZahZIeqSUgvkREZw6xIhDt3FrQQ5qbDAppguoeuRKEPirjpYGDk1Bkwi9ATeBsqGNhp6rbElahBej7GpegA6yZB3S2TOnbHFysGckTGJOFuMSGWvZcW8XD75lAqqtEmQyMwAl6xIZMNFynb6XbduYTZ40ce2la2bdelQeNgt7cv7TNuvHpqmwVaMQUaApV94GjlquKPJZoHVVTrJNte6a6ywd0BzZqfhWtFfVUzOGxxooFwOtpVjggjA7zPfZxEieLHATPvy882i2HwwHbXCah11uJRQZiZPHT2KMpDThfZOIWdIC9g8jjik7Z2GFKi0gbJ8sISVMZT1pmP9P2ttT9ALKjX9jpZJFtNg1e2DWXtuewW0inmuJmkA6BvtUn6bn2XACRCVjqQyDCH1T78dBJdNmhnQfiAs6zH7SgUUQZQE8OtMSSI6FZRLmlRn5zbsBsdzZ75KBucAb7z4MIaU8HAzW6KmBIgsIPV0PMfRBdQMk08hB6EGENEOrwpmZeJCAc4MTTBemO6epufgr5vwqaq2ZC4OtVaCfNKHzoftFY6RerCWkAZvAMbGcDt4mePQCrGgJNjUV0g88AwbCmuPGVlPvvkHZzjhC9v9E5mP0fusDnQrG3yaUSTPnhBXxKHPil0gC9gqN2SL2j5ABl9DnrgVd3odJwXzzaEmPEYK7EVc0uUYvB8IwHLiMlzFN4qghFADezuEM2AHCJh4ZOUv6oIIJzLhJo1wjgMHARFDfm36SrOlAVHCeuJJFXbtP0G9jg0Qr3iwWnVmm4ZEsqATwSGS1DsBNvwgeWtUPmtuAvmhcBUrS1BGB79uqFJtlnRyLtjUOHIGvFLmc06Ze9kvMrxfnC1BXd2Vn3RoRakl6Nsd9ZrfTUC0GZz6htttntQpLZLvxD5O9VWockxwwQJMjvKRSbeDIeTSWlbnWDhfrD40LkBUDUAoKwQcjrwElO9aEf5h44L1m5BDfwKdCQyXf6wcj4vAE9RKdQUGGgAA3boK2kgoVp9y0Lzmt3c0TsMjbjXZWA32k2GAIGLLD1kwjnyEa6xGqixTzPRAdRnZMJq8HTcQCnsjeK7jtzpqLOJuDFCOTjot8csD541MjKgR4K6a5hp9gHl12On6uz4B5OUeAomcmUP46319MdfTfimS6teQYGTCFbYUUZRS2pOk8ZLk6FMzBhfBELjoDjlXhQT8prCMie8371RUcmAXjyBehKp210CprB7Pa9LNg9Hy4kHDQIwFNhd8gTAuleluizEFZ3EFREo39yMICkpe8e2Fb6sXtMcgxPcXR1YWnLJi5Pwfgz0qViy1c65T7OJpWPB59uYYqHjhHmbzehqasgfvDOgWHnBT0L3F5yZnjsoSJDpMar3JajZOTy4cq70PHYCa3renDSVa1p399E5xuElQZ0pBEIeL7NEt0ILi1YvInIP7JaHHQMWrMjIuBPLkUld32dalIX2lbwJQ4JSEbUT9y5rlmP3KjAgLPBCGM2JkPVpGP3Vsfael3iBTGcHDhlEUlX0JC83Dgd1iJGaHbOaq6WdMe4gKYCbMqeDZVsR9F8PS3FdcU61H4bm0JUJaSe5QZU21c9cUUxtq53UXh7ugG4OdpfPCj3aopRj0xIqXzBUvo2Qw4Ow4TYsejef2R2roDl5vrG6XGptIjeIZjxBIivPsNpqdbVcYPaCLfN3v5LrqoVlheP8bxtwnAnPLFtCIRwDfJ7SyI12xMrJm9HrKO8JUKcSVmkYyFp1rl0rdbFkoZe1n4PYV8GNLOo7uzcpdLzaBRblXLsnCY57nL56Mx1G6csAWZoCOUCzKeWqZ003VWNAd30FVAHXU00QB43YVs7xIMSS9T3Eb5mgMcELymssD6g1Xd1VEeiGN9jrX8VktZx3fTvgUSmzzfItjbOzSvNTV9xrIadTmdfHdjaoZBqJHHRZ5SWK662zVDhA5krZBTzpSKiOYAxEz90HCQiNbg3EJmz5NGnoKbQWQ6zWN4o75kFoJL7kN90gD6RbLjof9YzjjvnOUTbBRFnyi7RJdapWEemGYdFczFHlg4ZMQX5BilYj2vRsifkhSCqcTIp9kSVKEH8UNlrRJSseMeyVWlSB6hhR1mv5dLmpyd4quTFVTSBlFsVjBUXAGpVPAGoz8VRxRGzPkzMblrOSfa7yZ4tuMUkKPN9HduRW9GebsCSLBbCxDfl7NkXrYFRCXPoEyOd9gw3vQP4p2I4ZLD0LLndOmqvKqWgXNfgOcneGrnLrESlMgPzteGE25hryXkloRaOzVH5pmDYVBN7J3u3mjFCmtrexDHKt7ZoD58UyF1aHo2C52s0IFz9ycvT9uwoNi0077XGMHFgAXbmoLlpVYB29pYvmKq2fcgcdDKI4vGAWKGv83RXZ53PgXRi5BcNzLG5CDHjyb3aqV2zZ87gDTTpjuq42DSmqri00m7M1sgD9oih71yUHb97eCMUaLAxJPU4DUyBhXzY4j5LRA4CkGSKINJK5GPl3Qm7F7Mn04ZzO2gNynvqaEXOVJAJiNdpMcGYcf0mfDwa8dGH7oVaRvxFZvLktsnlp73yk8SM52ZVLoAGMwali0khxVIVgTxwc5WFWrok7GLxRlkk1tCsYWoLUlttUwqR0DFaNzpyi1aJPGBEFefiSqI1Gl7lhBFURh92DEBbnejThpZCEMDpXQX5ZMhy527uu5ezCDscpik4Javh7R52vFzbVI6GL2laS6jjya9eackVwyk5T5UGFs67VdqdRjhbqyGd1EnuwCansP3iKRhs9FqdObbadHZQQAKsr6c6UCKTbunIGepvSEv8Zq03YaNFvO5hn83Mzxx1QR8NVB6vcKpgrDeSzGB8E3j0tP5qAYDefah6nzwdYfr54s2dVfhuuHNQvVvxIqbC6ak6RyMMrLrcch2Ew4XbSvIjitzwUgeYmj7aoe03Ow4WzHfjfQ9IbOsrkDOcNXl2mqRyp8HJJttYcq8IlmG8bYVgQjh8hRUkstSh3UEvGwvsWnMtzLIJbQ6sRtztywa7WrHxZvgNcNxR5CjpA2jlGalIdkYLl7Qjqcfmsrw7EBNciR2SzC22pLg7kb5e4UZCZFX4kKJXEiin4D9k2g8Yu9eowMBhxRxn4kY60BrsE7X5hOvuZxqVup2VpB8eRAuXDKgUDkmQNjYWOBQpeccHLvgzXbpEPFZ3GHzd5pbVobrYzyIJC6Czq47lnOnquXawAfegCUrLufYnhflmnKXh169a0EIcsMFTy7hb2WSXCDNHKNp7Ss7t4EUTXLH43Mf4QJeGAox6jAefSvk9SFh1LeN0KNvppVGG5gnEO6YqCWDB1sZPsuHpyaOMjNPBd6gRRB7QHTOhWkixQrJ5aLUNdoPw2jSBp1e7mzNwrcWIpKl4znsaw7jhyfDcmTW7E831YHKI09BcKFoYqKNgZouOLjJQpq8IoFcmDPQuIgPbTxoum41USGaweVuc9qEIT2XKd1R857uaNZl0mpXL9grx41pEmDzXyVp9Z0HsP6SQZji1dCBMCbkNnvhgSVTTmiBaxEwzDmOsnC3577bY6ALI9GWb8nuOB2mFJZ3OvQapzAkNO95Py37U9qxaXDDK7aSaKZQdiENacfkEqXZq4wyAwnuiXGDSmH8nA4iDCqwkkez6BFfDbQGZbcQtlogEMxlGJohmttIy3AfD8yT9f7pOkNEibeXBa2f4Fcl72jUVtUjmeZ4vTAnS7r3TMwbvwpUqFwBI7zXJvNP5HGYYHrvbdl5pbVbYoDcpLa1Tx6CRI7hbU9WzgqAzQeUE8KQqO3TGihClEIACKXON8udUQ0Cpoms410SL4by4c4tvCDJnF2dO2O3ieEyyqd1ticms3q5cNJnJVqbPvQctJcZmabuaHNT6z67Isl1bdcobj4LBnW9S1RuhaTIkpPSWxLcAgidkED4So1bfrNRWdYGQyhSD73BdEUsmLej1wD9Rx7oYJX6NoZ0rqhjAndW3h5PuZxNRSf3mx79RmeWIpczOIEydijKFqMcM9hN6WARofa2Oq9VJAcGYDx2JitBtNUkE5xBi1o2SNXgz8OTpFkgCwfyQqRA1sfCulQU3Dgk1RgoJYWqI1pjLnCDaaNpKU9cxOQlBAeYywmY5PPPAut9gk8ziSA2jKYAUNykIW8C20cvJPBoPQ79U9LbeYXOqrgJkg98pDGb5HmIPZoxCxa9GHVvObm5uQWluE8JcvXpP7Gmz8jaLPGL8n3kQEjU2P6bs5metmpykCu82FAdhgZpe9pQ5CTCJPvPIWl1GEC3kXnGK2cZNX2tOLLo38nqSzTyxI3hS7RoQDlhdV4QXgSWyfeNenbBcH6jJQjLUc7lFHxfjSZfJIkaHiMXv2mKYZT6s12LA67fiZJsne3DqLu3VHqP4SiM5BHXVpzgPLXnDziqL7066uLsPYIFsdntMEdga61me84pOAu78ta11t1RTz4wJpFBE5E0T5S6E8VXODHmbp55wzCxuCJdSoVDKjckbZesGmWqp2JvAjrsGUtLZoZWnwklTZzx5jVzpiKOuEYHDbWX7wRgyPJlWezkLqzcyQvrbcNOoXNnF12SOoFXxVBa2hCvW0eI4GhocG6fHmwbO5O7Q1rBpxkSivwckp6cxwuvThCzP4TZhdIE9B5ogGrSHa7QznFNyetlqM9Wb4Axdva524aox7uZl0ehWzI1r7FwjWXHdf8QznAYWb6CCrSaPcxHO31tkkavdzJZqBD8wnRaXBTVBZrkpptzNs0UkS0FKVmO6G1QuAMh4dyzdL1anrKPcBS2EyyPP9O3hfu2SBwrRRRGqAIYAoOXJI4Fm4q1espypX4Qw3dgTwIajlvowXqRwJAW8bxBq3b8EPhTiLHrLMi5FhLY4q8eGhazXqSeuNT6kMXQxd3OhJbfUPywZcXPftX5LsmCfCT5Ai1OERXW26Nouow5Q2U903dwcEyjJ3op02xh39YwebEOjQoEaPjuiUAdrmOP6sPKB0GKKSAsBgU4e0ro7ijP9JdNUGbSbr6WshIkk8pniIveBIp5SyuNR5pNW3R73f6OcwPjJsVWyvcC2pvvKknboMfVfNOmgfgQrb1Xsn44Hw5b44gPrQp5Bf5QYmPIn7muNixi7mP5lqKjdBQHHImD5vzqbqakcT31Uvgnqay46HoOCXlSX4o4IjOtT9JJG1LsaIqNZIgZC9N2LdeRcd0GzA09rl3qxBqG8QdqNxAFR3LddEQGx7ja05Ca5BvH1xnz6jeyxBN5gdaH8jVuwMkQ5HHAPEfVuh4wehl4K8kyY18f3bHhtEFFslAWGIgBUfeBTKlFNUjpiHOspnHgPfOMlybdqyKeX5RM32u326wky0OSMsxRBTRYjwUIwNHodEHRTGG7hO4BeblPyacZhLP6bpvh0k28hfBzACRVqMSUqCpblJSlDT2HFog046Thr60tJ6vU2erN3zwaYCucoIkM6H2TPQiwR7E6oScUJ5KpIpR5lvNfMx5w5TwQbNqURRIsTdrRefp5vAq0V3m5BHfsAFN1uUlQtWaT6WHIO6BUYQ3wWOAwbhGoUJQx6s6DKEANXhu6H215Q3WAwEIqFjPFR0GbQFuVAFk8SA9542eUFI4lkNlY1HC1GCJIIk8wga9HTT9tqvH4IUSLbwFiBtArrZUCnOp38nMfa2pfX8tUQdPkMxzxr1Aaq9T6kao0ugOlAZPwvUd3WUtxm3eZOR99gD2GO9Zy5EG285wkQJqWcTwVjPFbNXhabF8EmMNKI1AzxniiyLTYnTJa3sxXK5gFUaZdZ5vnIdfUrNtvwkaGjxPcMsxIrdWniitN8jUl20ATPNSy9ZDA3RiSTnA2PSoY4KnQalgdXCEnN7F22r0RmPz55kjSm8BdOOccsDqaUVyM4n1YNog77Z98q0TRRs4kISdHH2uk15B3OZloju2zWxmqGK00m3NcQBBqdlu2fNYhcU3xNUg1zps4uefEsKRL7ycB86AOpPx5LFnxbNFt8gIjpcQwsL9UNoosxqZL4eUnuo6zxx2betArdYW7VFBg894GNskfSrlSNziuBKwSJCFFM1fErjQu7fYZtNpeat7O6rpnj12DbbUcuxzge2dhcJD6KaYC8uRJmae1c9sLfaGMiLxv33wb7ZCzwzid6U7Cfy7I7VSffYssYpKW5ZyIbikSCecKOvilGALGFgqyw8tskehXKSMPjGjvARlFuK4ZY8JvZFzNtGGIzvA15DcBwh2hNVteu3kUAzsx3mIpyPRD9PU9ieAZWTTI7FSC6yeCvyXW3JryekyJhXpA7wj32MUJF0N5xdtG0J2JpT8MxiEsEowvCIM0FN2lwYSeDXPMJH92QsEAQ7NSibmq1moWTjz3TsvliE1hmf4xWUBhDVXDgxG4uCYEdYG69ddNtCOCCLETeQwFKIQn5B0RPWpHWX8b6uHYWVu8FOtvaOLCQ1NfFXcEAlnKa6SYSLQKWhLfDWFjqXpLwfAH3o06k70r3G6D23rb9aPeGcyxwJCaO3HTJui0MF1dUYxnNESVgcbixVIIHNn7NmFlczXg3hkgc4xE9A73AG6EX1gBHo1LgNL4BBpBRc9TSe6TxFJD46RwT1wyAOls1gsvp1YG9xwDlVclPHvkALdIY64PigOBUndn3v7h0ISdERUCLUqcIc5Vb2HJKN4Ozfm0cpGBxZAsh44rhvC3Qrsgxk7yfgpnxsJh5HSPA4MGicA9wCMH6FibpDoEzeOe8NfHgUbq62DDoozRaBahsFnl0qPOaPTfd5hER9GkAXaYd26ACYVsdbPZw13xn7ILgcilf1OIQ3rjcLbwPDEhzu3dWGphKx9A3otpPM7NyLjNO7jIUh4KkTiOAQQ37m2avqSWOwYgfiggXbqSz1RwLzfD2sRlr21Bd1OriitjNeEraeObEd7m3Jq7FdUpHiQ0PeOLyeblOfzXlSVXf3lwHryXQt2L1Fm3SkF3KHFVqFZdHwjtl6q2xyEVCpepUGoXqCLa7U6jO8z6jQFrWvbQaGWBddTpM7LnQAGthCnQBboPIPCR8vWtVjMeZCQsJ8Gs6vfwKEM7RyyBOGCjCVdkSadFKdY3ugtLlkIdKNocwq31ZHFg8ZUilUdkhimaREHkitf0q1kGudMb8hGqrmexiXKDMgw02KUS7GYMLh7RpXDThEfA6J4wLy8t4bFq6m8Yi5e4rSJds3odcKwOr4DfVvQ8LN5WdvIviMn6EeDUcdaHlkK3EHSVLk9Vrxz6J2SKsPYhBpYu5NgF4kADW0GLkfVTmQHyCMAXBqWCE5l1UMkwknotgdXJ2vHBA5H712BqZOBQEyuFR1fqnit5L6fxvVi\n");
    ft_printf("ft return value(long format string) = |%d|\npf return value(long format string) = |%d|\n", a, b);
    assert(a == b);
    if (ft_strcmp(mine, original))
        ft_printf("ERROR snprintf test 5");
    ft_nl(2);

}
 */
void	test_all(void)
{
	test_c();
	test_s();
	test_d();
	test_i();
	test_p();
	test_x();
	test_xx();
	test_o();
	test_u();
	test_percent();
	test_float();
}

void    test_asterix(void)
{
	int a;
	int b;

	ft_printf("TEST *\n-----------------------------------------------------------------\n\n");
	a = ft_printf("FT %%*d = |%*d|\n", 42, 42);
	b = printf("PF %%*d = |%*d|\n", 42, 42);
	assert(a == b);
	ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion zero padding minus|%0-*15.5G|\n", 10, -9587.3333);
    b = printf("PF %%G width greater than presicion zero padding minus|%0-*15.5G|\n", 10, -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%G width greater than presicion zero padding minus|%*015.5G|\n", 10, -9587.3333);
    b = printf("PF %%G width greater than presicion zero padding minus|%*015.5G|\n", 10, -9587.3333);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G with # flag presicion 1|%#*.1G|\n", 5, -0.0);
    b = printf("PF_ G with # flag presicion 1|%#*.1G|\n", 5, -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT_ G with # flag presicion 0|%#*.*0G|\n", 5, 5, -0.0);
    b = printf("PF_ G with # flag presicion 0|%#*.*0G|\n", 5, 5, -0.0);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d LONG_MAX |%.*ld|\n", 5, LONG_MAX);
    b = printf("PF %%d LONG_MAX |%.*ld|\n", 5, LONG_MAX);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT %%d LONG_MIN |%*0ld|\n", 35, LONG_MIN);
    b = printf("PF %%d LONG_MIN |%*0ld|\n", 35, LONG_MIN);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width > pre %%d |%20.5d|\n", 444);
    b = printf("PF width > pre %%d |%20.5d|\n", 444);
    assert(a == b);
    ft_nl(1);

    a = ft_printf("FT width < pre %%d |%5.20d|\n", 444);
    b = printf("PF width < pre %%d |%5.20d|\n", 444);
    assert(a == b);
    ft_nl(1);

}

void	run_argument(char *arg)
{
	if (!ft_strcmp(arg, "1"))
	{
		test_all();
	}
	else if (!ft_strcmp(arg, "2"))
	{
		test_all();
		test_g();
		test_e();
		test_G();
		test_E();
	/* 	test_sn(); */
	}
	else if (!ft_strcmp(arg, "3"))
	{
		test_c();
		test_s();
	}
	else if (!ft_strcmp(arg, "4"))
	{
		test_d();
		test_i();
	}
	else if (!ft_strcmp(arg, "5"))
	{
		test_p();;
		test_x();
		test_xx();
		test_o();
	}
	else if (!ft_strcmp(arg, "6"))
	{
		test_u();
		test_percent();
	}
	else if (!ft_strcmp(arg, "7"))
	{
		test_float();
	}
	else if (!ft_strcmp(arg, "8"))
	{
		test_g();
		test_e();
		test_G();
		test_E();
	}
	else if (!ft_strcmp(arg, "9"))
		test_asterix();
/* 	else if (!ft_strcmp(arg, "10"))
		test_sn(); */
    else if (!ft_strcmp(arg, "undef"))
        test_undefined();
    else if (!ft_strcmp(arg, "leaks"))
    {
        while (1);
    }
    else if (!ft_strcmp(arg, "e"))
        test_e();
    else if (!ft_strcmp(arg, "s"))
        test_s();
    else if (!ft_strcmp(arg, "g"))
        test_g();
    else if (!ft_strcmp(arg, "f"))
        test_float();
    else if (!(ft_strcmp(arg, "d")))
        test_d();
    else if (!(ft_strcmp(arg, "c")))
        test_c();
    else if (!ft_strcmp(arg, "i"))
        test_i();
    else if (!ft_strcmp(arg, "o"))
        test_o();
    else if (!ft_strcmp(arg, "u"))
        test_u();
    else if (!ft_strcmp(arg, "*"))
        test_asterix();
  /*   else if (!(ft_strcmp(arg, "sn")))
        test_sn(); */
    else if (!(ft_strcmp(arg, "x")))
        test_x();
    else if (!(ft_strcmp(arg, "p")))
        test_p();
    else if (!(ft_strcmp(arg, "X")))
        test_xx();
    else if (!(ft_strcmp(arg, "all")))
        run_argument("2");
	else
		printf("usage: ./pftest 1 - 10");
}

int main(int ac, char **av)
{
	int i = 1;
	char *arg;

	while (i < ac)
	{
		arg = ft_strdup(av[i]);
		run_argument(arg);
        free(arg);
        i++;
	}

//    ft_printf("FT 0.25|%#.1g|\n", 0.25);
}
