#include <stdio.h>
#include "libft.h"

int main(void)
{
	int number = 10;

	printf(" #:\n");
	int p = printf("%#o", 10);
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

	printf("\n now the ' ':\n");
	printf("% dHello!\n", number);
	printf("% dHello!\n", number - 4);
	printf("% dHello!\n", number - 8);
	printf("% iHello!\n", number - 12);
	printf("% iHello!\n", number - 16);
	printf("% iHello!\n", number - 16);
	printf("\nabc% sef\n", "d");   //-->> erro compilacao
	printf("Now for the empty string:% s.\n", ""); //-->> erro compilacao
	printf("Now without the ' ' here:%s.\n", "");
	printf("% xHello!\n", number); //-->> erro compilacao
	printf("% oHello!\n", number); //-->. erro compilacao
	printf("% cHello!\n", 'a');
	
	printf("\n +:\n");
	printf("%+dHello!\n", number);
	printf("%+dHello!\n", number - 4);
	printf("%+dHello!\n", number - 8);
	printf("%+iHello!\n", number - 12);
	printf("%+iHello!\n", number - 16);

	printf("\n ### Mistura de + com ' '\n");
	printf("\n + overrides ' '\n");
	printf("% +dHello!\n", number); 
	printf("%+ dHello!\n", number + 2); 
	printf("% +dHello!\n", number - 15); 

	printf("\n ### Mistura de + com #\n");
	printf(" + is ignored\n");
	printf("%#+xHello!\n", number); 
	printf("%+#XHello!\n", number); 
	printf("%#+oHello!\n", number); 
	printf("%+#oHello!\n", number); 

	printf("\n ### Mistura de ' ' com #\n");
	printf(" ' ' is ignored\n");
	printf("%# xHello!\n", number); 
	printf("% #XHello!\n", number); 
	printf("%# oHello!\n", number); 
	printf("% #oHello!\n", number); 
	
	printf("\n ### Mistura de ' ', + e #\n");
	printf(" ' ' and + are ignored\n");
	printf("%#+ xHello!\n", number); 
	printf("%# +XHello!\n", number); 
	printf("%+ #oHello!\n", number); 
	printf("%+# oHello!\n", number); 

	printf("\n -:\n");
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

	printf("\n 0:\n");
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

	printf("\n ### Mistura com - (.)\n");
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

	printf("\n");
	printf("%.s\n", "Hello!");
	printf("%.1s\n", "Hello!");
	printf("%.2s\n", "Hello!");
	printf("%.3s\n", "Hello!");
	printf("%.4s\n", "Hello!");
	printf("%.5s\n", "Hello!");
	printf("%.6s\n", "Hello!");
	printf("%.7s\n", "Hello!");
	printf("%.8s\n", "Hello!");
	printf("%.9s\n", "Hello!");

	return (0);
}
