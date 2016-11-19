#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//---------------------------------------------------------------------------
//! \brief	    Calculates the DNA problem solution.
//!
//! \param[in,out]  st Char pointer to the DNA sequence. The content will be modified with the lexicographically smallest string.
//!
//! \return	    TRUE if everything is OK, FALSE in case of error.   
//!
//! \notes          The algorithm is O(n): slicing is O(n) + comparisong is O(n).
//!
//!		    I made some assumptions as:
//!                 - Infinite memory (malloc never fails).
//!                 - Standard lib functions always work (no errors).
//!                 - Inputs from STDIN are always OK.
//!
int DNA_Problem(char st[])
{
	if (st != NULL)
	{
		int idx = 0;
		int length = strlen(st);
		char* buffer = (char *) malloc (length * sizeof(char));		
		/*
			Essentially it takes the slice playing with the indexes (Python style) and then compare using strncmp (lexicographically).
	        */
		for (int i = 0; i < strlen(st); i++) {
			memset(buffer, 0, length); // O(n)
			strcat(buffer, st+i); // first slice O(n)
			strncpy(buffer+strlen(st+i),st,i); //second slice O(n)
			if (strncmp(buffer, st, length) < 0) // comparing if is smaller or not O(n)
			{				
				strncpy(st,buffer,length);
			}
		}
	
		free(buffer);	

		return true;
	}

	return false;	
}


int main(){
    int t; 
    scanf("%d",&t);
//  printf("%d\n",t);
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char)); //value totally arbitrary
        scanf("%s\n",expression);
	DNA_Problem(expression);
	printf("%s\n",expression);	
	free(expression);
    }
    return 0;
}