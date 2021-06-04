#include"primlib.h"



void display(double **matrix);
void allocateMemory(double **matrix);
void inputValues(double **matrix);
void calculateDeterminant(double **matrix, int dimensionOfMinor);
void freeMemory(double **matrix);

int iteration;

int dimensionOfMatrix;
int elementX, elementY;
float determinant;


int main()
{
 int dimensionOfMinor;
 double** matrix=NULL;
 
 iteration=1;
  
  inputValues(matrix);
  display(matrix);
 do{
        dimensionOfMinor=dimensionOfMatrix-iteration;
        allocateMemory(matrix);
        calculateDeterminant(matrix, dimensionOfMinor);
        freeMemory(matrix);
    iteration++;
 }while(iteration<=dimensionOfMatrix-2);
}

printf("%f",determinant);


void display(double **matrix)
{

    
    for(elementX=0; elementX<dimensionOfMatrix; elementX++)
    {
        for(elementY=0; elementY<dimensionOfMatrix; elementY++)
        {
            printf("%f",**matrix);
            
        }
    }
}



void allocateMemory(double **matrix)
{
    
    scanf("%d",&dimensionOfMatrix);
  
    if(dimensionOfMatrix<0){ printf("Error! Incorrect dimension of Matrix"); return;}

    matrix = malloc(sizeof(double*)*dimensionOfMatrix);
    if(matrix == NULL)
    {
        printf("Error! Memory was not allcated");
        free(matrix);
        return;
    }
    
    for(iteration=0; iteration<dimensionOfMatrix; iteration++)
    {
        matrix[iteration] = malloc(sizeof(double)*dimensionOfMatrix);   
    }
        
}


void inputValues(double **matrix)
{
   
    
 for(elementX=0; elementX<dimensionOfMatrix; elementX++)
    {   
        
        for(elementY=0; elementY<dimensionOfMatrix; elementY++)
        {
            scanf("%lf",&matrix[elementX][elementY]); 
            
            if(matrix[elementX][elementY] != '\n') 
            {
                printf(" Error! Input only numbers");
                
            }
        }
    }
}



void calculateDeterminant(double **matrix, int dimensionOfMinor)
{
    double minor[dimensionOfMinor][dimensionOfMinor];
    for(iteration=1; iteration<dimensionOfMatrix; iteration++)
    {
           
        
         for(elementX=1; elementX<dimensionOfMatrix; elementX++)
    {   
        
        for(elementY=0; elementY<dimensionOfMatrix; elementY++)
        {
           if (elementY==iteration) break;
           minor[elementX][elementY]=matrix[elementX][elementY];     
            
        }
    }
        
        
        determinant=+pow(-1,1+iteration)*matrix[1][iteration-1]*minor[1][iteration-1];
    }
    
}

void freeMemory(double **matrix)
{
    for(iteration=0; iteration<dimensionOfMatrix; iteration++)
    {
       free( matrix[iteration] );  
    }
         
    free(matrix);
    
}
