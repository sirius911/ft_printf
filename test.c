/* Fichier de test pour la fonction ftprintf */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char *print_result(int i, int j)
{
    char *  str;

    if (i == j)
    {
        str = "\033[32m*** OK ***\033[0m";
    }
    else
        str = "\033[33m*** KO ***\033[0m";
    return (str);
}

int		main ()
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    i = printf("This is my magnificent test !\n");
   j = ft_printf("This is my magnificent test !\n");
    
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
   printf("\nChar :\n");
    i = printf("C1 : %c\n", 'a');
    j = ft_printf("C1 : %c\n", 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C2 : >%3c<\n", 'a');
    j = ft_printf("C2 : >%3c<\n", 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C3 : >%-3c<\n", 'a');
    j = ft_printf("C3 : >%-3c<\n", 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C4 : >%*c<\n", 3, 'a');
    j = ft_printf("C4 : >%*c<\n", 3, 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C5 : >%-*c<\n", 3, 'a');
    j = ft_printf("C5 : >%-*c<\n", 3, 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C6 : >%0*.*c<\n", 3, 2, 'a');
    j = ft_printf("C6 : >%0*.*c<\n", 3, 2, 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C7 : >%0*.*c<\n", 3, 0, 'a');
    j = ft_printf("C7 : >%0*.*c<\n", 3, 0, 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C8 : >%-*c%c<\n", 3, 'a', 'b');
    j = ft_printf("C8 : >%-*c%c<\n", 3, 'a','b');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("C9 : >%-*c<%%\n", 3, 'a');
    j = ft_printf("C9 : >%-*c<%%\n", 3, 'a');
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    printf("\nChar * :\n");
    
    i = printf("S1 : <%s>\n", "test");
    j = ft_printf("S1 : <%s>\n", "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S2 : %10s\n", "test");
    j = ft_printf("S2 : %10s\n", "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S3 : %10.0s\n", "test");
    j = ft_printf("S3 : %10.0s\n", "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S4 : %1.3s\n", "test");
    j = ft_printf("S4 : %1.3s\n", "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S5 : %.5s\n", "test");
    j = ft_printf("S5 : %.5s\n", "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S6 : %0*.*s\n", 4, 3, "test");
    j = ft_printf("S6 : %0*.*s\n", 4, 3, "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S7 : %*.*s\n", -4, 4, "test");
    j = ft_printf("S7 : %*.*s\n", -4, 4, "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S8 : %5.*s\n", -5, "test");
    j = ft_printf("S8 : %5.*s\n", -5, "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("S9 : %*.6s\n", -5, "test");
    j = ft_printf("S9 : %*.6s\n", -5, "test");
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    printf("\nINT (but with %%d) :\n");
    
    i = printf("D0 : <%d>\n", 4);
    j = ft_printf("D0 : <%d>\n", 4);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D1 : >%d<\n", 42);
    j = ft_printf("D1 : >%d<\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D2 : %d\n", 123456789);
    j = ft_printf("D2 : %d\n", 123456789);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D3 : %10.1d\n", 42);
    j = ft_printf("D3 : %10.1d\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D4 : %10.3d\n", 42);
    j = ft_printf("D4 : %10.3d\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D5 : %-10.3d\n", -42);
    j = ft_printf("D5 : %-10.3d\n", -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D6 : %.0d\n", 42);
    j = ft_printf("D6 : %.0d\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D7 : %010d\n", -42);
    j = ft_printf("D7 : %010d\n", -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D8 : %010.10d\n", -42);
    j = ft_printf("D8 : %010.10d\n", -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D9 : %010d\n", 42);
    j = ft_printf("D9 : %010d\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D10 : %010.0d\n", 42);
    j = ft_printf("D10 : %010.0d\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D11 : %d\n", 2147483647);
    j = ft_printf("D11 : %d\n", 2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("D12 : >%d<\n", -2147483648);
    j = ft_printf("D12 : >%d<\n", -2147483648);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    printf("\nINT :\n");
    
    i = printf("I0 : %i\n", 4);
    j = ft_printf("I0 : %i\n", 4);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I1 : %010i\n", 42);
    j = ft_printf("I1 : %010i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I2 : %i\n", 123456789);
    j = ft_printf("I2 : %i\n", 123456789);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I3 : %10.1i\n", 42);
    j = ft_printf("I3 : %10.1i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I4 : >%10.3i<\n", 42);
    j = ft_printf("I4 : >%10.3i<\n", 42);
    i = printf("I4bis : >%.3i<\n", 42);
    j = ft_printf("I4bis : >%.3i<\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I5 : %-10.3i\n", -42);
    j = ft_printf("I5 : %-10.3i\n", -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I6 : %.0i\n", 42);
    j = ft_printf("I6 : %.0i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I7 : %02.4i\n", -42);
    j = ft_printf("I7 : %02.4i\n", -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I8 : %10i\n", 42);
    j = ft_printf("I8 : %10i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I9 : %3.2i\n", 42);
    j = ft_printf("I9 : %3.2i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I10 : %i\n", 42);
    j = ft_printf("I10 : %i\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I11 : %i\n", 2147483647);
    j = ft_printf("I11 : %i\n", 2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I12 : >%i<\n", -2147483648);
    j = ft_printf("I12 : >%i<\n", -2147483648);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I13 : %*.*i\n", -12, 4, -42);
    j = ft_printf("I13 : %*.*i\n", -12, 4, -42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I14 : %5.0i\n", 0);
    j = ft_printf("I14 : %5.0i\n", 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I15 : %5.2i\n", 0);
    j = ft_printf("I15 : %5.2i\n", 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("I16 : %5i\n", 0);
    j = ft_printf("I16 : %5i\n", 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    printf("\nHexadecimal :\n");
    
    i = printf("xX0 : %x%X\n", 42, 42);
    j = ft_printf("xX0 : %x%X\n", 42, 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX1 : <%0*.3x> <%0*.3X>\n", -9, 0, -9, 0);
    j = ft_printf("xX1 : <%0*.3x> <%0*.3X>\n", -9, 0, -9, 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX2 : >%-10.5x< >%05.2X<\n", 42, 42);
    j = ft_printf("xX2 : >%-10.5x< >%05.2X<\n", 42, 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX3 : <%16.6x> <%16.6X>\n", 2048, 2048);
    j = ft_printf("xX3 : <%16.6x> <%16.6X>\n", 2048, 2048);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX4 : %.1x %.0X\n", 42, 0);
    j = ft_printf("xX4 : %.1x %.0X\n", 42, 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX5 : %x %0*.*X\n", -2147483647, 3, 6, -2147483647);
    j = ft_printf("xX5 : %x %0*.*X\n", -2147483647, 3, 6, -2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX6 : %1.1x %1.1X\n", 2147483647, -2147483647);
    j = ft_printf("xX6 : %1.1x %1.1X\n", 2147483647, -2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX7 : %.*s%1.1x %.*s%1.1X\n", -1, "", -2147483647, -1, "", -2147483647);
    j = ft_printf("xX7 : %.*s%1.1x %.*s%1.1X\n", -1, "", -2147483647, -1, "", -2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("xX8 : %-13.*x %-13.*X\n", 6, 752086341, 6, 752086341);
    j = ft_printf("xX8 : %-13.*x %-13.*X\n", 6, 752086341, 6, 752086341);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    ft_printf("Essais de nombre en binaire\n");
    ft_printf("255 => %.25b\n",255);

    printf("\nUnsigned INT :\n");
    
    i = printf("U0 : %u\n", 4);
    j = ft_printf("U0 : %u\n", 4);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U1 : %010u\n", 42);
    j = ft_printf("U1 : %010u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U2 : %u\n", 123456789);
    j = ft_printf("U2 : %u\n", 123456789);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U3 : %10.1u\n", 42);
    j = ft_printf("U3 : %10.1u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U4 : %10.3u\n", 42);
    j = ft_printf("U4 : %10.3u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U5 : %-10.3u\n", 42);
    j = ft_printf("U5 : %-10.3u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U6 : %.0u\n", 42);
    j = ft_printf("U6 : %.0u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U7 : >%010.4u<\n", 4294967294);
    j = ft_printf("U7 : >%010.4u<\n", 4294967294);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U8 : %10u\n", 42);
    j = ft_printf("U8 : %10u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U9 : %3.2u\n", 42);
    j = ft_printf("U9 : %3.2u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U10 : %u\n", 42);
    j = ft_printf("U10 : %u\n", 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U11 : %u\n", 2147483647);
    j = ft_printf("U11 : %u\n", 2147483647);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U12 : %u\n", 2147483648);
    j = ft_printf("U12 : %u\n", 2147483648);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U13 : %*.*u\n", -12, 4, 42);
    j = ft_printf("U13 : %*.*u\n", -12, 4, 42);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U14 : %5.0u\n", 0);
    j = ft_printf("U14 : %5.0u\n", 0);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("U15 : >%.4u<\n", 100);
    j = ft_printf("U15 : >%.4u<\n", 100);
    printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    printf("\nPointer :\n");
    char *ptr;
    ptr = "test";
    
    i = printf("P0 : %u\n", &ptr);
    // j = ft_printf("P0 : %u\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    ptr = "test2";
    i = printf("P1 : %05p\n", &ptr);
    // j = ft_printf("P1 : %05p\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    ptr = ",jbsfkdbfs";
    i = printf("P2 : %16.5p\n", &ptr);
    // j = ft_printf("P2 : %16.5p\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    i = printf("P3 : %16.6p\n", &ptr);
    //j = ft_printf("P3 : %16.6p\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("P4 : %.1p\n", &ptr);
    // j = ft_printf("P4 : %.1p\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("P5 : %p\n", &ptr);
    // j = ft_printf("P5 : %p\n", &ptr);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("PNULL : %1.1p\n", NULL);
    // j = ft_printf("PNULL : %1.1p\n", NULL);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("DNULL : %1.1d\n", NULL);
    // j = ft_printf("DNULL : %1.1d\n", NULL);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("SNULL : %10.1s\n", NULL);
    // j = ft_printf("SNULL : %10.1s\n", NULL);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("CNULL : %1.1c\n", NULL);
    // j = ft_printf("CNULL : %1.1c\n", NULL);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // i = printf("xXNULL : %1.1x %1.1X\n", NULL, NULL);
    // j = ft_printf("xXNULL : %1.1x %1.1X\n", NULL, NULL);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    
    // i = printf("ultimate4 %*.*x %1.0X\n", 1, 50, 5000, 10);
    // j = ft_printf("ultimate4 %*.*x %1.0X\n", 1, 50, 5000, 10);
    // printf("\nprintf : %d,  ft_printf : %d => %s\n\n", i, j, print_result(i,j));
    // printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
    //ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
}
