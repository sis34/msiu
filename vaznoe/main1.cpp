#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include "polyfmt1.h"
#include <iostream>
#include <memory>
#include <thread>
#include <vector>


double **  convert_from_5_16_to_9_31(double ** array, int h, int w){
  double **res;
  int rows = w + w - 1;
  int cols = h + h - 1;

  res = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < cols; i++)
    res[i] = (double *)malloc(rows * sizeof(double));
	
  // создание матрицы для записи результата
	
  int arr_i = 0, arr_j = 0; 
	
  for(int i = 0; i < cols; i++){
    for(int j = 0; j < rows; j++){
      if(i%2 == 0){
	if(j%2 == 0){
	  res[i][j] = array[arr_i][arr_j];
	  arr_j++;
	}
      }else continue;
    }
    i++;
    arr_i++;
    arr_j = 0;
  }
	
  
   for(int i = 0; i < cols; i++){
    for(int j = 0; j < rows; j++){
      if(i%2 == 0 && j%2 == 1){
	res[i][j]  = (res[i][j-1] + res[i][j+1])/2;
      }else if(i%2 == 1 && j % 2 != 1){
	res[i][j] = (res[i-1][j] + res[i+1][j	])/2;
      } 
    }
   }
     //~ 
  for(int i = 0; i < cols; i++){
    for(int j = 0; j < rows; j++){
      if(i%2 == 1 && j % 2 == 1){
	res[i][j]  = (res[i][j-1] + res[i][j+1])/2;
      }
    }
  }
  return res;
}


int main(void){
  double **array;
  int rows = 17;
  int cols = 5;
  int cc, kk;
  array = (double **)malloc(cols * sizeof(double *));
  for (cc = 0; cc < rows; cc++)
  array[cc] = (double *)malloc(rows * sizeof(double));
  //~ 
   int r; 

    scanf("%d", &r);
//  std::cout << r;
  double *array80;
  array80 = (double *)malloc(80 * sizeof(double ));
  int fileWithDateDescriptor = open("./export.240", O_RDONLY);
  
  if(fileWithDateDescriptor == -1){
    printf("Can't open file");
    exit(0);
  }
  
  ExportFileHeader* fileHeader = (ExportFileHeader*)malloc(sizeof(ExportFileHeader));
  read(fileWithDateDescriptor, fileHeader, 3);  
  read(fileWithDateDescriptor, fileHeader, 256);  
  

  int bytes_read = 0;
  ExportRecordUnit* record = NULL;
  int i = 0;
  int j = 0;
  
  do{	
    record = (ExportRecordUnit*)malloc(sizeof(ExportRecordUnit));		
    bytes_read =  read(fileWithDateDescriptor, record, 512);  
    
    if (bytes_read == 512){
		
      if (i == r){
	    while (j<80){
	      array80[j] = double(record->ExtroECG[j]);
	      j++; 
	    }
      }
    }
    i++; 
    
    free(record);		
  }while (bytes_read == 512 ); 
  close(fileWithDateDescriptor);
  free(fileHeader);

         for(int ccc = 0; ccc < 5; ccc++){
            for(int kkk = 0; kkk < 17; kkk++){
				array[ccc][kkk] = array80[16*ccc+kkk];
				array[ccc][rows-1] = array[ccc][0];
			}
		}

	 double ** res1 = convert_from_5_16_to_9_31(array, cols, rows);
	 double ** res2 = convert_from_5_16_to_9_31(res1, 9, 33);
		  for(int cccc = 0; cccc < 17; cccc++){
            for(int kkkk = 0; kkkk < 65; kkkk++){
		std::cout << int(res2[cccc][kkkk]) << std::endl;//<< " ";
			}
			//std::cout << std::endl;
		}
  return 0;
}
