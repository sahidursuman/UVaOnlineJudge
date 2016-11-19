#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool DNA_Problem(char st[])
{
	if (st != NULL)
	{
		int i, j, k;
		int smallest_start = 0;
		int n = strlen(st);

		if ((n >= 2) || (n <= 100))		
		{
			for (i = 0; i < n; i++)
			{	
				for (j=(smallest_start%n), k=(i+1)%n; j != (smallest_start+n-1)%n; j=(++j)%(n), k=(++k)%(n))
				{
					if (st[k] < st[j])
					{
						smallest_start=(i+1)%n;
						break;
					}
					else if (st[k] > st[j])
						break;				
				}
			}
	
			char* cpy = (char*)malloc((n+1)*(sizeof(char)));

			if (NULL != cpy)
			{
				for (i = 0; i < n; i++) {
					cpy[i]= st[(smallest_start+i)%n];
				}

				for (i = 0; i < n; i++) {
					st[i]= cpy[i];
				}

				free(cpy);

				return true;
			}
		}
	}

	return false;
}


int main()
{
    int t; 
    int a0;

    scanf("%d",&t);

	for(a0 = 0; a0 < t; a0++) 
	{
        char* expression = (char *)malloc(512000 * sizeof(char)); 
		scanf("%s\n",expression);
		DNA_Problem(expression);
		printf("%s\n",expression);
		free(expression);
    }

    return 0;
}