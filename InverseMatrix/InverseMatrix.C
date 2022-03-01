//This programme gives the inverse matrix A-1 of a squared 3x3 matrix A with random integer elements.

#include<iostream>

#include <ctime>

#include <cstdlib>

#include<cmath>

#include "Inverse.h"

using namespace std;

int main(){


  //float A[3][3]={{1,0,-1},{2,1,-1},{1,2,5}};
  float A[3][3];
  int dtrm;
  float** adjA=0;
  adjA=new float*[3];
  for(int i=0;i<3;i++){
    adjA[i]=new float[3];
  }

  
  Inverse matrix;

  srand(2022);

  cout<<"The matrix A is:"<<endl;
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
       A[i][j]=(1+(rand()%10));
     
      cout<<A[i][j]<<"\t";

    }
    cout<<"\n"<<endl;

  }

  matrix.SetMatrix(A);
  adjA=matrix.GetAdjoint();
  dtrm=matrix.Determinant3(A);
  
  
  if(dtrm==0){
    
    cout<<"The determinant of matrix A is:"<<dtrm<<endl;
    cout<<"There is no inverse matrix"<<endl;
    
  }else{

    cout<<"The determinant of matrix A is: "<<dtrm<<endl;
    cout<<"The inverse matrix of A is:"<<endl;
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	adjA[i][j]=adjA[i][j]/dtrm;
	cout<<adjA[i][j]<<"\t";

      }
      cout<<"\n"<<endl;

    }
  }

  return 0;

}
