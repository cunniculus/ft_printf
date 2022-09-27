#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

int main(void)
{
	int number = 10;
	int p;

	printf(" --- --- u: convert unsigned int --- ---\n");
	p = printf("Largest unsigned int: %u!\n", INT_MAX + (-1) * INT_MIN);
	printf("  # |_> return = %d\n", p); 
	printf("% u\n", 1234);

	printf(" --- --- p: convert pointer --- ---\n");
	p = printf("%p\n", &p);
	printf("  # |_> return = %d\n", p); 

	printf(" #: --- --- Alternative Conversion --- ---\n");
	printf("\t%%#o, 10 --> %#o\n", 10);
	p = printf("%#x\n", -1);
	printf("%x\n", INT_MAX);
	printf("  #return = %d\n", p); 
	printf("\t%%#o, 0 --> %#o\n", 0);
	printf("\t%%#x, 10 --> %#x\n", 10);
	printf("\t%%#X, 10 --> %#X\n", 10);
	printf("\t%%#x, 0 --> %#x\n", 0);
	printf("\t%%#d, 010 --> %#d\n", 010);
	printf("\t%%#i, 0x10 --> %#i\n", 0x10);
	
	printf("\n without #\n");
	printf("\t%%o, 10 --> %o\n", 10);
	printf("\t%%o, 0 --> %o\n", 0);
	printf("\t%%x, 10 --> %x\n", 10);
	printf("\t%%X, 10 --> %X\n", 10);
	printf("\t%%x, 0 --> %x\n", 0);
	printf("\t%%d, 010 --> %d\n", 010);
	printf("\t%%i, 0x10 --> %i\n", 0x10);

	printf("\n ### Mistura de # com +\n");
	printf(" + is ignored\n");
	printf("%#+x!\n", number); 
	printf("%+#X!\n", number); 
	printf("%#+o!\n", number); 
	printf("%+#o!\n", number); 
	printf("|%#20o+\n", number); // as expected
	printf("|%+#20o!\n", number); // as expected 
	printf("|%+#o!\n", number); // ' ' ignored
	printf("|%#+x!\n", number); // ' ' ignored 
	printf("|%+#X!\n", number); // ' ' ignored
	printf("|%#+o!\n", number); // ' ' ignored
	printf("|%+#o!\n", number); // ' ' ignored
	printf("|%20#+x!\n", number); // wrong 
	printf("|%20+#X!\n", number); // wrong
	printf("|%#20+o!\n", number); // wrong
	printf("|%+20#o!\n", number); // wrong 

	printf("\n ### Mistura de # com + e (.)\n");
	printf(" + is ignored\n");
	printf("|%#20.10o!\n", number); // as expected
	printf("|%#+20.5o!\n", number); // as expected 
	printf("|%+#20.10o!\n", number); // as expected
	printf("|%+#20.5o!\n", number); // as expected 
	printf("|%+#o!\n", number); // ' ' ignored
	printf("|%#+x!\n", number); // ' ' ignored 
	printf("|%+#X!\n", number); // ' ' ignored
	printf("|%#+o!\n", number); // ' ' ignored
	printf("|%+#o!\n", number); // ' ' ignored
	printf("|%20#+x!\n", number); // wrong 
	printf("|%20+#X!\n", number); // wrong
	printf("|%#20+o!\n", number); // wrong
	printf("|%+20#o!\n", number); // wrong 

	printf("\n ### Mistura de # com ' '\n");
	printf("\n ' ' is ignored\n");
	printf("|%# o!\n", number); // as expected
	printf("|% #o!\n", number); // as expected 
	printf("|%# 1o!\n", number); // as expected
	printf("|% #1o!\n", number); // as expected 
	printf("|%# 2o!\n", number); // as expected
	printf("|% #2o!\n", number); // as expected 
	printf("|%# 5o!\n", number); // as expected
	printf("|% #5o!\n", number); // as expected 
	printf("|%#5o!\n", number); // as expected
	printf("|%#5o!\n", number); // as expected 

	printf("\n ### Mistura de # com -\n");
	printf("%-#20X!\n", number);  // worked as expected
	printf("%#-20o!\n", number); // worked as expected
	printf("%#-x!\n", number); 
	printf("%-#x!\n", number); 
	printf("%20-#X!\n", number); 
	printf("%20#-X!\n", number); 
	printf("%-20#X!\n", number); 
	printf("%#20-o!\n", number); 
	printf("%-#o!\n", number); 
	
	printf("\n ### Mistura de #, ' ',  e +\n");
	printf(" ' ' and + are ignored\n");
	printf("%#+ x!\n", number); 
	printf("%# +X!\n", number); 
	printf("%+ #o!\n", number); 
	printf("%+# o!\n", number); 
	printf("|%#20o \n", number); // as expected
	printf("|% #20o!\n", number); // as expected 
	printf("|% #o!\n", number); // ' ' ignored
	printf("|%# x!\n", number); // ' ' ignored 
	printf("|% #X!\n", number); // ' ' ignored
	printf("|%# o!\n", number); // ' ' ignored
	printf("|% #o!\n", number); // ' ' ignored
	printf("|%20# x!\n", number); // wrong 
	printf("|%20 #X!\n", number); // wrong
	printf("|%#20 o!\n", number); // wrong
	printf("|% 20#o !\n", number); // wrong 

	printf("\n now the ' ':\n");
	printf("% d!\n", number);
	printf("% d!\n", number - 4);
	printf("% d!\n", number - 8);
	printf("% i!\n", number - 12);
	printf("% i!\n", number - 16);
	printf("% i!\n", number - 16);

	printf("\nabc% sef\n", "d");   //-->> sem efeito
	printf("Now for the empty string:% s.\n", ""); //-->> sem efeito
	printf("Now without the ' ' here:%s.\n", "");
	printf("% x!\n", number); //-->> sem efeito 
	printf("% o!\n", number); //--> sem efeito
	printf("% c!\n", 'a'); // sem efeito
	
	printf("\n +:\n");
	printf("%+d!\n", number);
	printf("%+d!\n", number - 4);
	printf("%+d!\n", number - 8);
	printf("%+i!\n", number - 12);
	printf("%+i!\n", number - 16);
	printf("%+o!\n", number);
	printf("%+o!\n", number - 16);

	printf("\n ### Mistura de + com ' '\n");
	printf("\n + overrides ' '\n");
	printf("% +d!\n", number); 
	printf("%+ d!\n", number + 2); 
	printf("% +d!\n", number - 15); 


	printf("\n -: -->> left justify\n");
	printf("%-dHello!\n", number);
	printf("%-1dHello!\n", number);
	printf("%-2dHello!\n", number);
	printf("%-3iHello!\n", number);
	printf("%-4iHello!\n", number);

	printf("\n the same width, but without the -\n");
	printf("%dHello!\n", number);
	printf("%1dHello!\n", number);
	printf("%2dHello!\n", number);
	printf("%3iHello!\n", number);
	printf("%4iHello!\n", number);

	printf("\n 0: --> zero padding\n");
	printf("%0dHello!\n", number);
	printf("%01dHello!\n", number);
	printf("%02dHello!\n", number);
	printf("%03iHello!\n", number);
	printf("%04iHello!\n", number);

	printf("\n the same without the 0\n");
	printf("%0xHello!\n", number);
	printf("%01xHello!\n", number);
	printf("%02xHello!\n", number);
	printf("%03xHello!\n", number);
	printf("%04xHello!\n", number);



	number = 1234;
	printf("\n ### Precision: (.)\n");
	printf("%.dHello!\n", number);
	printf("%.0dHello!\n", number);
	printf("%.1dHello!\n", number);
	printf("%.2dHello!\n", number);
	printf("%.3dHello!\n", number);
	printf("%.4dHello!\n", number);
	printf("%.5dHello!\n", number);
	printf("%.6iHello!\n", number);


	printf("\n");
	printf("precision with string\n");
	printf("%.0s nothing if precision .0\n", "Hello!");
	printf("%.s nothing if precifion just .\n", "Hello!");
	printf("%.1s\n", "Hello!");
	printf("%.2s\n", "Hello!");
	printf("%.3s\n", "Hello!");
	printf("%.4s\n", "Hello!");
	printf("%.5s\n", "Hello!");
	printf("%.6s\n", "Hello!");
	printf("%.7s\n", "Hello!");
	printf("%.8s\n", "Hello!");
	printf("%.9s\n", "Hello!");

	printf("\n ### Mistura com - (.)\n");
	printf(" if -. works just like .\n if .- output is bizarre\n");
	printf("%-.dHello!\n", number);
	printf("%-.0dHello!\n", number);
	printf("%-.1dHello!\n", number);
	printf("%-.2dHello!\n", number);
	printf("%-.3dHello!\n", number);
	printf("%-.4dHello!\n", number);
	printf("%-.5dHello!\n", number);
	printf("%-.6iHello!\n", number);

	printf("\n");
	printf("%.-dHello!\n", number);
	printf("%.-0dHello!\n", number);
	printf("%.-1dHello!\n", number);
	printf("%.-2dHello!\n", number);
	printf("%.-3dHello!\n", number);
	printf("%.-4dHello!\n", number);
	printf("%.-5dHello!\n", number);
	printf("%.-6iHello!\n", number);


	printf("\n   ### Combination of . and 0\n");
	printf("%.0xHello!\n", number);
	printf("%.01xHello!\n", number);
	printf("%.02xHello!\n", number);
	printf("%.03xHello!\n", number);
	printf("%.04xHello!\n", number);

	printf("%0.xHello!\n", number);
	printf("%0.1xHello!\n", number);
	printf("%0.2xHello!\n", number);
	printf("%0.3xHello!\n", number);
	printf("%0.4xHello!\n", number);

	printf("\n   ### Combination of - and 0\n");
	printf(" 0 is ignored \n");
	printf("%-0xHello!\n", number);
	printf("%-01xHello!\n", number);
	printf("%-02xHello!\n", number);
	printf("%-03xHello!\n", number);
	printf("%-04xHello!\n", number);

	printf("%0-xHello!\n", number);
	printf("%0-1xHello!\n", number);
	printf("%0-2xHello!\n", number);
	printf("%0-3xHello!\n", number);
	printf("%0-4xHello!\n", number);

	return (0);
}
