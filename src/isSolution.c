/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

#include "isSolution.h"

int isSolution(D_Dictionary *dictionary, char *stringToTest)
{
	W_Word *word = W_createWord(stringToTest);
	int res = D_wordIsIN(m, *dictionary);
	W_delete(m);
	return res;
}