#include <stdio.h>
#include <stdlib.h>

/*****
*	int max
******
*	Identifica el máximo entre dos enteros
******
*	Input:
*		int a: Primer entero a comparar
*		int b: Segundo entero a comparar
******
*	Returns:
*		int, Retorna el entero mayor, en caso de ser iguales retorna el input b.
*****/
int max(int a, int b) {
	if (a>b) return a;
	else return b;
}

/*****
*	int main
******
*	Función principal.
*	Para cada muestra lee la dimensión de las matrices, el largo de las secuencias de números y las almacena en arreglo.
*	Luego, crea una matriz que almacenará los resultados parciales de comparación de largo entre las matrices. mat[n][m].
*	Los elementos de la primera fila y de la primera columna tienen valor 0.
*	Los elementos de las casillas pueden ser:
*		mat[n][m]=max(mat[n-1][m],mat[n][m-1]),		si los elementos comparados son diferentes.
*		mat[n][m]=mat[n-1][m-1]+1,					si los elementos comparados son iguales.
*	De este modo, el último elemento de la matriz indica el máximo largo.
******
*	Input:
*		Sin input
******
*	Returns:
*		int, siempre retorna 0.
*****/
int main() {
	int n_pruebas=0, n,p_size,s_size,i,j;
	int* p;
	int* s;
	int **mat;

	/* Mientras no se termine el archivo input seguirá leyendo */
	scanf("%d",&n_pruebas);
	while(n_pruebas>0) {
		scanf("%d",&n);
		scanf("%d",&p_size);
		scanf("%d",&s_size);
		p = (int *)calloc(p_size, sizeof(int));
		s = (int *)calloc(s_size, sizeof(int));
		
		for(i=0;i<p_size;i++) scanf("%d",&p[i]);
		for(i=0;i<s_size;i++) scanf("%d",&s[i]);
		
		mat=(int **)calloc(p_size+1,sizeof(int *));
		for(i=0;i<=p_size;i++) mat[i]=(int *)calloc(s_size+1,sizeof(int));
		for(i=0;i<=p_size;i++) mat[i][0]=0;
		for(i=0;i<=s_size;i++) mat[0][i]=0;

		for(i=1;i<=p_size;i++)
			for(j=1;j<=s_size;j++)
				if (p[i-1]==s[j-1]) mat[i][j]=mat[i-1][j-1]+1;
				else mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
		printf("%d\n", mat[p_size][s_size]);

		free(p);
		free(s);
		for(i=p_size;i>=0;i--) free(mat[i]);
		
		free(mat);

		n_pruebas--;
	}
	return 0;
}