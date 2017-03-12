#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void main(int argc, char *argv[])
{
	if (argc != 3 ){
		printf("dosvidaniya");
		return;
	}

	FILE *fp1;
	fp1 = fopen(argv[1], "r");
	int Q1;
	int	S1;
	fscanf(fp1, "%d %d", &Q1, &S1);
	fseek(fp1, 1, SEEK_CUR);
	int i;
	int	j;
	int	**D = NULL;
	D = (int**)malloc(Q1 * sizeof(int*));
	if(!D) {
		printf("dosvidaniya");
		fclose(fp1);
		free(D);
		return;
	}

	for (i = 0; i < Q1; i++) {
		D[i] = (int*)malloc(S1 * sizeof(int));
	
	if(!D[i]) {
		printf("dosvidaniya");
		fclose(fp1);
		free(D);
		return;
	  }
	}

	if (fp1 == NULL)
	{
		printf("Net faila dannux");
		return; //Vuxod iz programmu
	}
		for (i = 0; i<Q1; i++)
	{
		for (j = 0; j<S1; j++)
		{
			fscanf(fp1, "%d", &D[i][j]);
		}
	}
	fclose(fp1);
	//Vuvod soder*imogo faila na ekran
	printf("\n");
	printf("Matrica A");
	for (i = 0; i<Q1; i++)
	{
		printf("\n");
		for (j = 0; j<S1; j++)
			printf("%d ", D[i][j]);
	}
	FILE *fp2;
	fp2 = fopen(argv[2], "r");
	int Q2;
	int S2;
	fscanf(fp2, "%d %d", &Q2, &S2);
	fseek(fp2, 1, SEEK_CUR);
	int **F = NULL;
		F = (int**)malloc(Q2 * sizeof(int*));
	if(!F) {
		printf("dosvidaniya");
		fclose(fp1);
		fclose(fp2);
		free(D);
		free(F);
		return;
	}

	for (i = 0; i < Q2; i++) {
		F[i] = (int*)malloc(S2 * sizeof(int));
		if(!F[i]) {
		printf("dosvidaniya");
		fclose(fp1);
		fclose(fp2);
		free(D);
		free(F);

		return;
		}
	}
	if (fp2 == NULL)
	{
		printf("Net faila dannux");
		return; //Vuxod iz programmu
	}
		for (i = 0; i<Q2; i++)
	{
		for (j = 0; j<S2; j++)
		{
			fscanf(fp2, "%d", &F[i][j]);
		}
	}
	fclose(fp2);
	//Vuvod soder*imogo faila na ekran
	printf("\n");
	printf("Matrica B");
	for (i = 0; i<Q2; i++)
	{
		printf("\n");
		for (j = 0; j<S2; j++)
			printf("%d ", F[i][j]);
	}

	int k;
	int **C = NULL;
	C = (int**)malloc(Q1 * sizeof(int*));
	for (i = 0; i < Q1; i++) 
		C[i] = (int*)malloc(S2 * sizeof(int));
	for (i = 0; i < Q1; i++)
		for (j = 0; j < S2; j++) 
		{
			C[i][j] = 0;
			for (k = 0; k < Q2; k++)
				C[i][j] += D[i][k] * F[k][j];
		}
	printf("\n");
	printf("Matrica C");
		for (i = 0; i < Q1; i++)
	{
		printf("\n");
		for (j = 0; j < S2; j++)
			printf("%d ", C[i][j]);
	}
	for (i = 0; i < Q1; i++)
	{
		free(D[i]);
		free(F[i]);
		free(C[i]);
	}
	free(D);
	free(F);
	free(C); 
}