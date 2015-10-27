struct
{
	char	type;		/* defineix que es. digit/variable, operant, parentesis/funcio */
	int	contener;	/* contingut, l'unic realment important */
	int	entrada;	/* idica en quina posicio de la entrada esta,*/
/* aquest valor perd valor un cop s'ha comporvat que es correcte la entrada. */
} elementCalculus;
