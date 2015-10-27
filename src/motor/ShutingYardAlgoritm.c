#include <stdlib.h>

/* LIKE like, on se troben els possibles errors */

/* Extremadament facil que hi hagi algun error 0xXX, ja que ho estic corregint, pos eso */

/* Aquest no pot ser el final, ja que necessitem moltes versions d'aquest mateix ;) */
/* Fer que 0xB0, potser ho calculi d'alguna forma el propi programa */
/* De la mateixa forma, tenim que volem que calculi el famos 00 0x40 0x80 0xB0 */
void
main (void)
{
	while (Token) /* program */
	{ /* basic, Treball basic */
		t = nextToken ();
		switch (t.type && 0xC0) /* 0xC0 = 11 00 0000, diferenciar: digit, Operator, (funtion, ) */
		{ /* Colect IF */
		case 0x00: /* digit / variable */
			addQueue (t); break;
		case 0x40: /* O, Operant // 0x40 = 0100 0000 */
			if (s)
			{
				o = peekStack ().type;
				if ( (o & 0xC0) == 0x40) /* if operator */
				{
					if ( t & 0x20) /* Right assotiation */
						if ( (t.type & 0x1f) < (o & 0x1f) )
							addQueue ( popStack () );
					else /* Left assotation */
						if ( (t.type & 0x1f) <=(o & 0x1f) )
							addQueue ( popStack () );
				}
			}
			pushStack (t); break;
		case 0x80: /* function, ( */
			pushStack (t); break;
		default:/*case 0xC0: / * ) * /  ha de ser aquest! 0xC0 */
			while (s)
			{
				t = popStack ();
				if ( (t & 0xE0) == 0x80 ) break; /* Mirem que sigui un parentesis obert 10 00 0000 */
				addQueue (t);
			}
			if (s)
			{
				t = peekStack ();
				if ( (t & 0xE0) == 0xA0 ) /* Mirem que sigui una funcio */
					addQueue ( popStack () );
			}
		}
	}
	while (s)
	{ /* basic, final */
		t = popStack ();
		if ( (t & 0xE0) == 0x80 ) /* busquem parentesis oberts */
		{ /* LIKE like, error gros, no se com acabar en cas d'error, hauria de tornar la posicio de l'error crec jo xD error de parentesis */
			exit (1);
		}
		addQueue (t);
	}
return 0;
}
