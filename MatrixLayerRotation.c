int countElements(int* vector){
    int tot = 0;
    while(vector[tot]!=0){
        tot++;
    }
    return tot;
}

// Complete the matrixRotation function below.
void matrixRotation(int matrix_rows, int matrix_columns, int** matrix, int r) {

    int max_r = matrix_rows - 1;
    int max_c = matrix_columns - 1;
    int rows,cols,index = 0;
    int b_index = r;

    int max_r2 = matrix_rows - 1;
    int max_c2 = matrix_columns - 1;
    int rows2 = 0;
    int cols2 = 0;
         
   
    int* linear = malloc((matrix_rows*matrix_columns)*sizeof(int));


      while(rows2 < max_r2 && cols2 < max_c2 ){
           
            index =0; 
            memset(linear, 0, (matrix_rows*matrix_columns)*sizeof(int));
            
            for(int i=rows;i<=max_c;i++){
                linear[index] = matrix[rows][i];
                index++;
            }
            rows++;
            for(int i=rows;i<=max_r;i++){
                linear[index] = matrix[i][max_c];
                index++;
            }
            max_c--;

            for(int i=max_c;i>=cols;i--){
                    linear[index] = matrix[max_r][i];
                    index++;
                }
                max_r--;
                
            for(int i=max_r;i>=rows;i--){
                linear[index] = matrix[i][cols];
                index++;

                }
                cols++;    
                

      
            b_index = r;
            int n = countElements(linear);
            for(int i=rows2;i<=max_c2;i++){
                  matrix[rows2][i] = linear[b_index%n];
                    b_index++;
            }
            rows2++;
            for(int i=rows2;i<=max_r2;i++){
                matrix[i][max_c2] = linear[b_index%n];
                b_index++;
            }
            max_c2--;

            for(int i=max_c2;i>=cols2;i--){
                    matrix[max_r2][i]= linear[b_index%n];
                    b_index++;
                }
                max_r2--;


            for(int i=max_r2;i>=rows2;i--){
                matrix[i][cols2] = linear[b_index%n];
                b_index++;
                }
               
                cols2++;  
        
       }

        for(int i=0;i<matrix_rows;i++){
            for(int j=0;j<matrix_columns;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
        
}
      
