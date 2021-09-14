#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include<stdlib.h>

#endif /* matrix_h */
struct matrix
{
    unsigned row;
    unsigned column;
    double ** head;
};
typedef struct matrix matrix;

/* Prototypes */

/* Construction and destruction */
matrix createMatrix(unsigned);
void freeMatrix(matrix);

/* Printing and scaning */
void printMatrix(matrix);
void scanMatrix(matrix *);

/* Arithmetic operations */
matrix sumMatrix(matrix,matrix);
matrix productMatrix(matrix,matrix);

/* The function createMatrix */
matrix createMatrix(unsigned r)
{
	
    matrix M={0,0,NULL};
    M.row=r;
    M.column=r;
    M.head=(double **)malloc(r*sizeof(double *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(double *)malloc(r*sizeof(double));
    return M;
}

/* The function freeMatrix */
void freeMatrix(matrix M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

/* The function printMatrix */
void printMatrix(matrix M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%lf ",M.head[i][j]);
        printf("%lf |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}

/* The function scanMatrix */
void scanMatrix(matrix * M)
{
    if(M->head==NULL)
        return;
    for(int i=0;i<M->row;i++)
    {
        for(int j=0;j<M->column;j++)
            scanf("%lf",M->head[i]+j);
    }
    return;
}
/* The function productMatrix */
matrix productMatrix(matrix M,matrix N)
{
    if(M.column!=N.row)
		{
			printf("la matrice n'est pas une matrice carree");
		
        exit(EXIT_FAILURE);
		}
    matrix R=createMatrix(M.row);
    for(int i=0;i<R.row;i++)
    {
        for(int j=0;j<R.column;j++)
        {
            R.head[i][j]=0;
            for(int k=0;k<M.column;k++)
            {
               
                R.head[i][j]+=M.head[i][k]*N.head[k][j];
            }
        }
    }
    return R;
}
int testmatrixnull(matrix M)
{
	  for(int i=0;i<M.row;i++)
    {
        for(int j=0;j<M.column;j++)
			{
				if (M.head[i][j]!=0.000000)
					return 0;
			}
	}
return 1;
}
int tr(matrix M)
{	
	int j=0;
	int x=0;
	for(int i=0;i<M.row;i++)
	{
		x+=M.head[i][j];
		j+=1;
	}
	return x;

}
int verification(matrix M)
{
	if(tr(M)!=0)
		return 0;
	return 1;


}
void coefficient_matrix_nilpotente(matrix M)
{	
	int a=0;
	if(verification(M)==1)
	{
		
		while(testmatrixnull(M)==0)
		{
			M=productMatrix(M,M);
			a+=1;
			if(verification(M)==0)
				{printf("la matrice n'est pas nilpotente");
				return;
				}
		}printf("la matrice est nilpotente d'ordre :%d\n",a);
	return ;
	}
	else
	{printf("la matrice n'est pas nilpotente \n");}
return;
																																																																																																																																																																																										
}
int main()
{
	
	matrix P=createMatrix(4);
    scanMatrix(&P);
    printMatrix(P);
	coefficient_matrix_nilpotente(P);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
    freeMatrix(P);
    return 0;
}
