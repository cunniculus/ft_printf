
#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int number = 10;
	int p;

	ft_printf("\nStrings\n");
	ft_printf("%1s |%1s |\n", "abc", "CASA"); 
	ft_printf("\n --- --- u: convert unsigned int --- ---\n");
	p = ft_printf("Largest unsigned int: %u!\n", INT_MAX + (-1) * INT_MIN);
	ft_printf("  # |_> return = %d\n", p); 
	ft_printf("% u\n", 1234);
	ft_printf("% 2u\n", 1234);
	ft_printf("% 4u\n", 1234);
	ft_printf("% 6u\n", 1234);
	ft_printf("%+u\n", 1234);
	ft_printf("%+2u\n", 1234);
	ft_printf("%+4u\n", 1234);
	ft_printf("%+6u\n", 1234);
	ft_printf("%-u\n", 1234);
	ft_printf("%-2u\n", 1234);
	ft_printf("%-4u\n", 1234);
	ft_printf("-->|%-6u\n", 1234);
	ft_printf("%#u\n", 1234);
	ft_printf("%#2u\n", 1234);
	ft_printf("%#4u\n", 1234);
	ft_printf("%#6u\n", 1234);
	ft_printf("%0u\n", 1234);
	ft_printf("%02u\n", 1234);
	ft_printf("%04u\n", 1234);
	ft_printf("%06u\n", 1234);
	ft_printf("%u\n", 1234);
	ft_printf("%2u\n", 1234);
	ft_printf("%4u\n", 1234);
	ft_printf("%6u\n", 1234);
	ft_printf("%.0u\n", 1234);
	ft_printf("%.u\n", 1234);
	ft_printf("%.2u\n", 1234);
	ft_printf("%.4u\n", 1234);
	ft_printf("%.6u\n", 1234);

	ft_printf("  # |_> return = %d\n", p); 

	ft_printf(" #: --- --- Alternative Conversion --- ---\n");
	ft_printf("\t%%#o, 10 --> %#o\n", 10);
	p = ft_printf("%#x\n", -1);
	ft_printf("%x\n", INT_MAX);
	ft_printf("  #return = %d\n", p); 
	ft_printf("\t%%#o, 0 --> %#o\n", 0);
	ft_printf("\t%%#x, 10 --> %#x\n", 10);
	ft_printf("\t%%#X, 10 --> %#X\n", 10);
	ft_printf("\t%%#x, 0 --> %#x\n", 0);
	ft_printf("\t%%#d, 010 --> %#d\n", 010);
	ft_printf("\t%%#i, 0x10 --> %#i\n", 0x10);
	
	ft_printf("\n without #\n");
	ft_printf("\t%%o, 10 --> %o\n", 10);
	ft_printf("\t%%o, 0 --> %o\n", 0);
	ft_printf("\t%%x, 10 --> %x\n", 10);
	ft_printf("\t%%X, 10 --> %X\n", 10);
	ft_printf("\t%%x, 0 --> %x\n", 0);
	ft_printf("\t%%d, 010 --> %d\n", 010);
	ft_printf("\t%%i, 0x10 --> %i\n", 0x10);

	ft_printf("\n ### Mistura de # com +\n");
	ft_printf(" + is ignored\n");
	ft_printf("%#+x!\n", number); 
	ft_printf("%+#X!\n", number); 
	ft_printf("%#+o!\n", number); 
	ft_printf("%+#o!\n", number); 
	ft_printf("|%#20o+\n", number); // as expected
	ft_printf("|%+#20o!\n", number); // as expected 
	ft_printf("|%+#o!\n", number); // ' ' ignored
	ft_printf("|%#+x!\n", number); // ' ' ignored 
	ft_printf("|%+#X!\n", number); // ' ' ignored
	ft_printf("|%#+o!\n", number); // ' ' ignored
	ft_printf("|%+#o!\n", number); // ' ' ignored

	ft_printf("\n ### Mistura de #, width e (.)\n");
	ft_printf(" + is ignored\n");
	ft_printf("|%#20.10d!\n", number); // as expected
	ft_printf("-->> |%#+20.10d!\n", number); // as expected 
	ft_printf("|%+#20.10d!\n", number); // as expected
	ft_printf("|%+#20.10d!\n", number); // as expected 
	ft_printf("|%+#d!\n", number); // ' ' ignored
	ft_printf("|%#+d!\n", number); // ' ' ignored 
	ft_printf("|%+#d!\n", number); // ' ' ignored
	ft_printf("|%#+d!\n", number); // ' ' ignored
	ft_printf("|%+#d!\n", number); // ' ' ignored

	ft_printf("\n ### Mistura de # com ' '\n");
	ft_printf("\n ' ' is ignored\n");
	ft_printf("|%# o!\n", number); // as expected
	ft_printf("|% #o!\n", number); // as expected 
	ft_printf("|%# 1o!\n", number); // as expected
	ft_printf("|% #1o!\n", number); // as expected 
	ft_printf("|%# 2o!\n", number); // as expected
	ft_printf("|% #2o!\n", number); // as expected 
	ft_printf("|%# 5o!\n", number); // as expected
	ft_printf("|% #5o!\n", number); // as expected 
	ft_printf("|%#5o!\n", number); // as expected
	ft_printf("|%#5o!\n", number); // as expected 

	ft_printf("\n ### Mistura de # com -\n");
	ft_printf("%-#20X!\n", number);  // worked as expected
	ft_printf("%#-20o!\n", number); // worked as expected
	ft_printf("%#-x!\n", number); 
	ft_printf("%-#x!\n", number); 
	ft_printf("%-#o!\n", number); 
	
	ft_printf("\n ### Mistura de #, ' ',  e +\n");
	ft_printf(" ' ' and + are ignored\n");
	ft_printf("%#+ x!\n", number); 
	ft_printf("%# +X!\n", number); 
	ft_printf("%+ #o!\n", number); 
	ft_printf("%+# o!\n", number); 
	ft_printf("|%#20o \n", number); // as expected
	ft_printf("|% #20o!\n", number); // as expected 
	ft_printf("|% #o!\n", number); // ' ' ignored
	ft_printf("|%# x!\n", number); // ' ' ignored 
	ft_printf("|% #X!\n", number); // ' ' ignored
	ft_printf("|%# o!\n", number); // ' ' ignored
	ft_printf("|% #o!\n", number); // ' ' ignored

	ft_printf("\n now the ' ':\n");
	ft_printf("% d!\n", number);
	ft_printf("% d!\n", number - 4);
	ft_printf("% d!\n", number - 8);
	ft_printf("% i!\n", number - 12);
	ft_printf("% i!\n", number - 16);
	ft_printf("% i!\n", number - 16);

	ft_printf("\nabc% sef\n", "d");   //-->> sem efeito
	ft_printf("Now for the empty string:% s.\n", ""); //-->> sem efeito
	ft_printf("Now without the ' ' here:%s.\n", "");
	ft_printf("% x!\n", number); //-->> sem efeito 
	ft_printf("% o!\n", number); //--> sem efeito
	ft_printf("% c!\n", 'a'); // sem efeito
	
	ft_printf("\n +:\n");
	ft_printf("%+d!\n", number);
	ft_printf("%+d!\n", number - 4);
	ft_printf("%+d!\n", number - 8);
	ft_printf("%+i!\n", number - 12);
	ft_printf("%+i!\n", number - 16);
	ft_printf("%+o!\n", number);
	ft_printf("%+o!\n", number - 16);

	ft_printf("\n ### Mistura de + com ' '\n");
	ft_printf("\n + overrides ' '\n");
	ft_printf("% +d!\n", number); 
	ft_printf("%+ d!\n", number + 2); 
	ft_printf("% +d!\n", number - 15); 


	ft_printf("\n -: -->> left justify\n");
	ft_printf("%-dHello!\n", number);
	ft_printf("%-1dHello!\n", number);
	ft_printf("%-2dHello!\n", number);
	ft_printf("%-3iHello!\n", number);
	ft_printf("%-4iHello!\n", number);

	ft_printf("\n the same width, but without the -\n");
	ft_printf("%dHello!\n", number);
	ft_printf("%1dHello!\n", number);
	ft_printf("%2dHello!\n", number);
	ft_printf("%3iHello!\n", number);
	ft_printf("%4iHello!\n", number);

	ft_printf("\n 0: --> zero padding\n");
	ft_printf("%0dHello!\n", number);
	ft_printf("%01dHello!\n", number);
	ft_printf("%02dHello!\n", number);
	ft_printf("%03iHello!\n", number);
	ft_printf("%04iHello!\n", number);

	ft_printf("\n the same without the 0\n");
	ft_printf("%0xHello!\n", number);
	ft_printf("%01xHello!\n", number);
	ft_printf("%02xHello!\n", number);
	ft_printf("%03xHello!\n", number);
	ft_printf("%04xHello!\n", number);

/* precision */
	number = 123;
	ft_printf("\n ### Precision: (.)\n");
	ft_printf("%.dHello!\n", number);
	ft_printf("%.0dHello!\n", number);
	ft_printf("%.1dHello!\n", number);
	ft_printf("%.2dHello!\n", number);
	ft_printf("%.3dHello!\n", number);
	ft_printf("%.4dHello!\n", number);
	ft_printf("%.5dHello!\n", number);
	ft_printf("%.6iHello!\n", number);


	ft_printf("\n");
	ft_printf("precision with string\n");
	ft_printf("%.0s nothing if precision .0\n", "Hello!");
	ft_printf("%.s nothing if precifion just .\n", "Hello!");
	ft_printf("%.1s\n", "Hello!");
	ft_printf("%.2s\n", "Hello!");
	ft_printf("%.3s\n", "Hello!");
	ft_printf("%.4s\n", "Hello!");
	ft_printf("%.5s\n", "Hello!");
	ft_printf("%.6s\n", "Hello!");
	ft_printf("%.7s\n", "Hello!");
	ft_printf("%.8s\n", "Hello!");
	ft_printf("%.9s\n", "Hello!");

	ft_printf("\n ### Mistura com - (.)\n");
	ft_printf(" if -. works just like .\n if .- output is bizarre\n");
	ft_printf("%-.dHello!\n", number);
	ft_printf("%-.0dHello!\n", number);
	ft_printf("%-.1dHello!\n", number);
	ft_printf("%-.2dHello!\n", number);
	ft_printf("%-.3dHello!\n", number);
	ft_printf("%-.4dHello!\n", number);
	ft_printf("%-.5dHello!\n", number);
	ft_printf("%-.6iHello!\n", number);

	ft_printf("\n");
	ft_printf("%.-dHello!\n", number);
	ft_printf("%.-0dHello!\n", number);
	ft_printf("%.-1dHello!\n", number);
	ft_printf("%.-2dHello!\n", number);
	ft_printf("%.-3dHello!\n", number);
	ft_printf("%.-4dHello!\n", number);
	ft_printf("%.-5dHello!\n", number);
	ft_printf("%.-6iHello!\n", number);


	ft_printf("\n   ### Combination of . and 0\n");
	ft_printf("%.0xHello!\n", number);
	ft_printf("%.01xHello!\n", number);
	ft_printf("%.02xHello!\n", number);
	ft_printf("%.03xHello!\n", number);
	ft_printf("%.04xHello!\n", number);

	ft_printf("%0.xHello!\n", number);
	ft_printf("%0.1xHello!\n", number);
	ft_printf("%0.2xHello!\n", number);
	ft_printf("%0.3xHello!\n", number);
	ft_printf("%0.4xHello!\n", number);

	ft_printf("\n   ### Combination of - and 0\n");
	ft_printf(" 0 is ignored \n");
	ft_printf("%-0xHello!\n", number);
	ft_printf("%-01xHello!\n", number);
	ft_printf("%-02xHello!\n", number);
	ft_printf("%-03xHello!\n", number);
	ft_printf("%-04xHello!\n", number);

	ft_printf("%0-xHello!\n", number);
	ft_printf("%0-1xHello!\n", number);
	ft_printf("%0-2xHello!\n", number);
	ft_printf("%0-3xHello!\n", number);
	ft_printf("%0-4xHello!\n", number);

	ft_printf("%10%Go\n");
	ft_printf("%10cGo\n", 'G');
	
	ft_printf("\n%0s\n", "abc");

/* tests for padding */
	ft_printf("\n%02d |%03d |\n", 1, -1);
	ft_printf("%02i |%03i |\n", 1, -1);

/* octal */
	ft_printf("\n%o\n", -10);
	ft_printf("%#04o\n", 10);
	ft_printf("%0#4o\n", 10);

/* precision */
	number = -123;
	ft_printf("\n ### Precision: (.)\n");
	ft_printf("%.dHello!\n", number);
	ft_printf("%.0dHello!\n", number);
	ft_printf("%.1dHello!\n", number);
	ft_printf("%.2dHello!\n", number);
	ft_printf("%.3dHello!\n", number);
	ft_printf("%.4dHello!\n", number);
	ft_printf("%.5dHello!\n", number);
	ft_printf("%.6iHello!\n", number);

	ft_printf("\n%dHello!\n", number);
	ft_printf("%0dHello!\n", number);
	ft_printf("%01dHello!\n", number);
	ft_printf("%02dHello!\n", number);
	ft_printf("%03dHello!\n", number);
	ft_printf("%04dHello!\n", number);
	ft_printf("%05dHello!\n", number);
	ft_printf("%06iHello!\n", number);

	ft_printf("\n%6.dHello!\n", number);
	ft_printf("%6.0dHello!\n", number);
	ft_printf("%6.1dHello!\n", number);
	ft_printf("%6.2dHello!\n", number);
	ft_printf("%6.3dHello!\n", number);
	ft_printf("%6.4dHello!\n", number);
	ft_printf("%6.5dHello!\n", number);
	ft_printf("%6.6iHello!\n", number);


	return (0);
}
