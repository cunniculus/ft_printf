#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int number = 10;
	int p;

	int fd;

	fd = open ("dprintf_output.txt", O_WRONLY | O_CREAT);
	dprintf(fd, " --- --- u: convert unsigned int --- ---\n");
	p = dprintf(fd, "Largest unsigned int: %u!\n", INT_MAX + (-1) * INT_MIN);
	dprintf(fd, "  # |_> return = %d\n", p); 
	dprintf(fd, "% u\n", 1234);
	dprintf(fd, "% 2u\n", 1234);
	dprintf(fd, "% 4u\n", 1234);
	dprintf(fd, "% 6u\n", 1234);
	dprintf(fd, "%+u\n", 1234);
	dprintf(fd, "%+2u\n", 1234);
	dprintf(fd, "%+4u\n", 1234);
	dprintf(fd, "%+6u\n", 1234);
	dprintf(fd, "%-u\n", 1234);
	dprintf(fd, "%-2u\n", 1234);
	dprintf(fd, "%-4u\n", 1234);
	dprintf(fd, "-->|%-6u\n", 1234);
	dprintf(fd, "%#u\n", 1234);
	dprintf(fd, "%#2u\n", 1234);
	dprintf(fd, "%#4u\n", 1234);
	dprintf(fd, "%#6u\n", 1234);
	dprintf(fd, "%0u\n", 1234);
	dprintf(fd, "%02u\n", 1234);
	dprintf(fd, "%04u\n", 1234);
	dprintf(fd, "%06u\n", 1234);
	dprintf(fd, "%u\n", 1234);
	dprintf(fd, "%2u\n", 1234);
	dprintf(fd, "%4u\n", 1234);
	dprintf(fd, "%6u\n", 1234);
	dprintf(fd, "%.0u\n", 1234);
	dprintf(fd, "%.u\n", 1234);
	dprintf(fd, "%.2u\n", 1234);
	dprintf(fd, "%.4u\n", 1234);
	dprintf(fd, "%.6u\n", 1234);

	dprintf(fd, "  # |_> return = %d\n", p); 

	dprintf(fd, " #: --- --- Alternative Conversion --- ---\n");
	dprintf(fd, "\t%%#o, 10 --> %#o\n", 10);
	p = dprintf(fd, "%#x\n", -1);
	dprintf(fd, "%x\n", INT_MAX);
	dprintf(fd, "  #return = %d\n", p); 
	dprintf(fd, "\t%%#o, 0 --> %#o\n", 0);
	dprintf(fd, "\t%%#x, 10 --> %#x\n", 10);
	dprintf(fd, "\t%%#X, 10 --> %#X\n", 10);
	dprintf(fd, "\t%%#x, 0 --> %#x\n", 0);
	dprintf(fd, "\t%%#d, 010 --> %#d\n", 010);
	dprintf(fd, "\t%%#i, 0x10 --> %#i\n", 0x10);
	
	dprintf(fd, "\n without #\n");
	dprintf(fd, "\t%%o, 10 --> %o\n", 10);
	dprintf(fd, "\t%%o, 0 --> %o\n", 0);
	dprintf(fd, "\t%%x, 10 --> %x\n", 10);
	dprintf(fd, "\t%%X, 10 --> %X\n", 10);
	dprintf(fd, "\t%%x, 0 --> %x\n", 0);
	dprintf(fd, "\t%%d, 010 --> %d\n", 010);
	dprintf(fd, "\t%%i, 0x10 --> %i\n", 0x10);

	dprintf(fd, "\n ### Mistura de # com +\n");
	dprintf(fd, " + is ignored\n");
	dprintf(fd, "%#+x!\n", number); 
	dprintf(fd, "%+#X!\n", number); 
	dprintf(fd, "%#+o!\n", number); 
	dprintf(fd, "%+#o!\n", number); 
	dprintf(fd, "|%#20o+\n", number); // as expected
	dprintf(fd, "|%+#20o!\n", number); // as expected 
	dprintf(fd, "|%+#o!\n", number); // ' ' ignored
	dprintf(fd, "|%#+x!\n", number); // ' ' ignored 
	dprintf(fd, "|%+#X!\n", number); // ' ' ignored
	dprintf(fd, "|%#+o!\n", number); // ' ' ignored
	dprintf(fd, "|%+#o!\n", number); // ' ' ignored

	dprintf(fd, "\n ### Mistura de #, width e (.)\n");
	dprintf(fd, " + is ignored\n");
	dprintf(fd, "|%#20.10d!\n", number); // as expected
	dprintf(fd, "-->> |%#+20.10d!\n", number); // as expected 
	dprintf(fd, "|%+#20.10d!\n", number); // as expected
	dprintf(fd, "|%+#20.10d!\n", number); // as expected 
	dprintf(fd, "|%+#d!\n", number); // ' ' ignored
	dprintf(fd, "|%#+d!\n", number); // ' ' ignored 
	dprintf(fd, "|%+#d!\n", number); // ' ' ignored
	dprintf(fd, "|%#+d!\n", number); // ' ' ignored
	dprintf(fd, "|%+#d!\n", number); // ' ' ignored

	dprintf(fd, "\n ### Mistura de # com ' '\n");
	dprintf(fd, "\n ' ' is ignored\n");
	dprintf(fd, "|%# o!\n", number); // as expected
	dprintf(fd, "|% #o!\n", number); // as expected 
	dprintf(fd, "|%# 1o!\n", number); // as expected
	dprintf(fd, "|% #1o!\n", number); // as expected 
	dprintf(fd, "|%# 2o!\n", number); // as expected
	dprintf(fd, "|% #2o!\n", number); // as expected 
	dprintf(fd, "|%# 5o!\n", number); // as expected
	dprintf(fd, "|% #5o!\n", number); // as expected 
	dprintf(fd, "|%#5o!\n", number); // as expected
	dprintf(fd, "|%#5o!\n", number); // as expected 

	dprintf(fd, "\n ### Mistura de # com -\n");
	dprintf(fd, "%-#20X!\n", number);  // worked as expected
	dprintf(fd, "%#-20o!\n", number); // worked as expected
	dprintf(fd, "%#-x!\n", number); 
	dprintf(fd, "%-#x!\n", number); 
	dprintf(fd, "%20-#X!\n", number); 
	dprintf(fd, "%20#-X!\n", number); 
	dprintf(fd, "%-20#X!\n", number); 
	dprintf(fd, "%#20-o!\n", number); 
	dprintf(fd, "%-#o!\n", number); 
	
	dprintf(fd, "\n ### Mistura de #, ' ',  e +\n");
	dprintf(fd, " ' ' and + are ignored\n");
	dprintf(fd, "%#+ x!\n", number); 
	dprintf(fd, "%# +X!\n", number); 
	dprintf(fd, "%+ #o!\n", number); 
	dprintf(fd, "%+# o!\n", number); 
	dprintf(fd, "|%#20o \n", number); // as expected
	dprintf(fd, "|% #20o!\n", number); // as expected 
	dprintf(fd, "|% #o!\n", number); // ' ' ignored
	dprintf(fd, "|%# x!\n", number); // ' ' ignored 
	dprintf(fd, "|% #X!\n", number); // ' ' ignored
	dprintf(fd, "|%# o!\n", number); // ' ' ignored
	dprintf(fd, "|% #o!\n", number); // ' ' ignored

	dprintf(fd, "\n now the ' ':\n");
	dprintf(fd, "% d!\n", number);
	dprintf(fd, "% d!\n", number - 4);
	dprintf(fd, "% d!\n", number - 8);
	dprintf(fd, "% i!\n", number - 12);
	dprintf(fd, "% i!\n", number - 16);
	dprintf(fd, "% i!\n", number - 16);

	dprintf(fd, "\nabc% sef\n", "d");   //-->> sem efeito
	dprintf(fd, "Now for the empty string:% s.\n", ""); //-->> sem efeito
	dprintf(fd, "Now without the ' ' here:%s.\n", "");
	dprintf(fd, "% x!\n", number); //-->> sem efeito 
	dprintf(fd, "% o!\n", number); //--> sem efeito
	dprintf(fd, "% c!\n", 'a'); // sem efeito
	
	dprintf(fd, "\n +:\n");
	dprintf(fd, "%+d!\n", number);
	dprintf(fd, "%+d!\n", number - 4);
	dprintf(fd, "%+d!\n", number - 8);
	dprintf(fd, "%+i!\n", number - 12);
	dprintf(fd, "%+i!\n", number - 16);
	dprintf(fd, "%+o!\n", number);
	dprintf(fd, "%+o!\n", number - 16);

	dprintf(fd, "\n ### Mistura de + com ' '\n");
	dprintf(fd, "\n + overrides ' '\n");
	dprintf(fd, "% +d!\n", number); 
	dprintf(fd, "%+ d!\n", number + 2); 
	dprintf(fd, "% +d!\n", number - 15); 


	dprintf(fd, "\n -: -->> left justify\n");
	dprintf(fd, "%-dHello!\n", number);
	dprintf(fd, "%-1dHello!\n", number);
	dprintf(fd, "%-2dHello!\n", number);
	dprintf(fd, "%-3iHello!\n", number);
	dprintf(fd, "%-4iHello!\n", number);

	dprintf(fd, "\n the same width, but without the -\n");
	dprintf(fd, "%dHello!\n", number);
	dprintf(fd, "%1dHello!\n", number);
	dprintf(fd, "%2dHello!\n", number);
	dprintf(fd, "%3iHello!\n", number);
	dprintf(fd, "%4iHello!\n", number);

	dprintf(fd, "\n 0: --> zero padding\n");
	dprintf(fd, "%0dHello!\n", number);
	dprintf(fd, "%01dHello!\n", number);
	dprintf(fd, "%02dHello!\n", number);
	dprintf(fd, "%03iHello!\n", number);
	dprintf(fd, "%04iHello!\n", number);

	dprintf(fd, "\n the same without the 0\n");
	dprintf(fd, "%0xHello!\n", number);
	dprintf(fd, "%01xHello!\n", number);
	dprintf(fd, "%02xHello!\n", number);
	dprintf(fd, "%03xHello!\n", number);
	dprintf(fd, "%04xHello!\n", number);

/* precision */
	number = 123;
	dprintf(fd, "\n ### Precision: (.)\n");
	dprintf(fd, "%.dHello!\n", number);
	dprintf(fd, "%.0dHello!\n", number);
	dprintf(fd, "%.1dHello!\n", number);
	dprintf(fd, "%.2dHello!\n", number);
	dprintf(fd, "%.3dHello!\n", number);
	dprintf(fd, "%.4dHello!\n", number);
	dprintf(fd, "%.5dHello!\n", number);
	dprintf(fd, "%.6iHello!\n", number);


	dprintf(fd, "\n");
	dprintf(fd, "precision with string\n");
	dprintf(fd, "%.0s nothing if precision .0\n", "Hello!");
	dprintf(fd, "%.s nothing if precifion just .\n", "Hello!");
	dprintf(fd, "%.1s\n", "Hello!");
	dprintf(fd, "%.2s\n", "Hello!");
	dprintf(fd, "%.3s\n", "Hello!");
	dprintf(fd, "%.4s\n", "Hello!");
	dprintf(fd, "%.5s\n", "Hello!");
	dprintf(fd, "%.6s\n", "Hello!");
	dprintf(fd, "%.7s\n", "Hello!");
	dprintf(fd, "%.8s\n", "Hello!");
	dprintf(fd, "%.9s\n", "Hello!");

	dprintf(fd, "\n ### Mistura com - (.)\n");
	dprintf(fd, " if -. works just like .\n if .- output is bizarre\n");
	dprintf(fd, "%-.dHello!\n", number);
	dprintf(fd, "%-.0dHello!\n", number);
	dprintf(fd, "%-.1dHello!\n", number);
	dprintf(fd, "%-.2dHello!\n", number);
	dprintf(fd, "%-.3dHello!\n", number);
	dprintf(fd, "%-.4dHello!\n", number);
	dprintf(fd, "%-.5dHello!\n", number);
	dprintf(fd, "%-.6iHello!\n", number);

	dprintf(fd, "\n");
	dprintf(fd, "%.-dHello!\n", number);
	dprintf(fd, "%.-0dHello!\n", number);
	dprintf(fd, "%.-1dHello!\n", number);
	dprintf(fd, "%.-2dHello!\n", number);
	dprintf(fd, "%.-3dHello!\n", number);
	dprintf(fd, "%.-4dHello!\n", number);
	dprintf(fd, "%.-5dHello!\n", number);
	dprintf(fd, "%.-6iHello!\n", number);


	dprintf(fd, "\n   ### Combination of . and 0\n");
	dprintf(fd, "%.0xHello!\n", number);
	dprintf(fd, "%.01xHello!\n", number);
	dprintf(fd, "%.02xHello!\n", number);
	dprintf(fd, "%.03xHello!\n", number);
	dprintf(fd, "%.04xHello!\n", number);

	dprintf(fd, "%0.xHello!\n", number);
	dprintf(fd, "%0.1xHello!\n", number);
	dprintf(fd, "%0.2xHello!\n", number);
	dprintf(fd, "%0.3xHello!\n", number);
	dprintf(fd, "%0.4xHello!\n", number);

	dprintf(fd, "\n   ### Combination of - and 0\n");
	dprintf(fd, " 0 is ignored \n");
	dprintf(fd, "%-0xHello!\n", number);
	dprintf(fd, "%-01xHello!\n", number);
	dprintf(fd, "%-02xHello!\n", number);
	dprintf(fd, "%-03xHello!\n", number);
	dprintf(fd, "%-04xHello!\n", number);

	dprintf(fd, "%0-xHello!\n", number);
	dprintf(fd, "%0-1xHello!\n", number);
	dprintf(fd, "%0-2xHello!\n", number);
	dprintf(fd, "%0-3xHello!\n", number);
	dprintf(fd, "%0-4xHello!\n", number);

	dprintf(fd, "%10%Go\n");
	dprintf(fd, "%10cGo\n", 'G');
	
	dprintf(fd, "\n%0s\n", "abc");

/* tests for padding */
	dprintf(fd, "\n%02d |%03d |\n", 1, -1);
	dprintf(fd, "%02i |%03i |\n", 1, -1);

/* octal */
	dprintf(fd, "\n%o\n", -10);
	dprintf(fd, "%#04o\n", 10);
	dprintf(fd, "%0#4o\n", 10);

/* precision */
	number = -123;
	dprintf(fd, "\n ### Precision: (.)\n");
	dprintf(fd, "%.dHello!\n", number);
	dprintf(fd, "%.0dHello!\n", number);
	dprintf(fd, "%.1dHello!\n", number);
	dprintf(fd, "%.2dHello!\n", number);
	dprintf(fd, "%.3dHello!\n", number);
	dprintf(fd, "%.4dHello!\n", number);
	dprintf(fd, "%.5dHello!\n", number);
	dprintf(fd, "%.6iHello!\n", number);

	dprintf(fd, "\n%dHello!\n", number);
	dprintf(fd, "%0dHello!\n", number);
	dprintf(fd, "%01dHello!\n", number);
	dprintf(fd, "%02dHello!\n", number);
	dprintf(fd, "%03dHello!\n", number);
	dprintf(fd, "%04dHello!\n", number);
	dprintf(fd, "%05dHello!\n", number);
	dprintf(fd, "%06iHello!\n", number);

	dprintf(fd, "\n%6.dHello!\n", number);
	dprintf(fd, "%6.0dHello!\n", number);
	dprintf(fd, "%6.1dHello!\n", number);
	dprintf(fd, "%6.2dHello!\n", number);
	dprintf(fd, "%6.3dHello!\n", number);
	dprintf(fd, "%6.4dHello!\n", number);
	dprintf(fd, "%6.5dHello!\n", number);
	dprintf(fd, "%6.6iHello!\n", number);
	close(fd);

	return (0);
}
