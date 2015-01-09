#include <iostream>
#include <memory>
#include <thread>
#include <vector>



double **  convert_from_5_17_to_9_33(double ** array, int h, int w){
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
	    } else if(i%2 == 1 && j % 2 == 1){
	      res[i][j] = (res[i-1][j - 1] + res[i - 1][j + 1] + res[i+1][j-1] + res[i+1][j+1])/4;
	    }
	}
    }
  return res;
}

#include <stdlib.h>

int main(){
  double **array;
  int rows = 17;
  int cols = 5;
  int i, j;
  array = (double **)malloc(cols * sizeof(double *));
  for (i = 0; i < rows; i++)
    array[i] = (double *)malloc(rows * sizeof(double));


  FILE * file;
  file = fopen("test1.txt", "r");

  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows-1; j++){
      fscanf(file, "%lf", &array[i][j]); // or whatever you want
      array[i][rows-1] = array[i][0];
    }
  }
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;
  //~ for (i = 0; i < cols; i++) {
    //~ for (j = 0; j < rows; j++){
      //~ std::cout << array[i][j]  << " "; // or whatever you want
    //~ }
    //~ std::cout << std::endl;
  //~ }

  double ** res1 = convert_from_5_17_to_9_33(array, cols, rows);
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;
  //~ for(int i = 0; i < 9; i++)
    //~ {
      //~ for(int j = 0; j < 33; j++)
	//~ {
	  //~ std::cout << res1[i][j]  << " ";
	//~ }
      //~ std::cout << std::endl;
    //~ }
  //~ std::cout << std::endl << std::endl;
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;

  double ** res2 = convert_from_5_17_to_9_33(res1, 9, 33);
  //~ std::cout << std::endl;
  //~ for(int i = 0; i < 17; i++)
    //~ {
      //~ for(int j = 0; j < 65; j++)
	//~ {
	  //~ std::cout << res2[i][j]  << " ";
	//~ }
      //~ std::cout << std::endl;
    //~ }
  //~ std::cout << std::endl << std::endl;
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;

  double ** res3 = convert_from_5_17_to_9_33(res2, 17, 65);
  //std::cout << std::endl;
  for(int i = 0; i < 33; i++)
    {
      for(int j = 0; j < 129; j++)
	{
	  //std::cout << res3[i][j]  << std::endl;
	}
      //std::cout << std::endl;
    }
     double ** res4 = convert_from_5_17_to_9_33(res3, 33, 129);
      for(int i = 0; i < 65; i++)
    {
      for(int j = 0; j < 257; j++)
	{
	//  std::cout << res4[i][j]  << std::endl;
	}
      //std::cout << std::endl;
    }
     double ** res5 = convert_from_5_17_to_9_33(res4, 65, 257);
        for(int i = 0; i < 129; i++)
    {
      for(int j = 0; j < 513; j++)
	{
	  std::cout << res5[i][j]  << std::endl;
	}
 } 
  //~ std::cout << std::endl << std::endl;
  //~ std::cout << std::endl;
  //~ std::cout << std::endl;
  return 0;
}
