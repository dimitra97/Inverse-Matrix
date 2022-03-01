//A class that finds the adjoint matrix adj(A) of a 3x3 matrix A, by calculating the algebraic complements.

class Inverse{

  float c[3][3];
  float Determinant2(float myArr[][2]);
  
 public:
  Inverse();
  //~Inverse();
  void SetMatrix(float myArr[][3]);
  float** GetAdjoint();
  float Determinant3(float myArr[][3]);
  

};

Inverse::Inverse(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      c[i][j]=0;


    }

  }

}


void Inverse:: SetMatrix(float myArr[][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      c[i][j]=myArr[i][j];


    }


  }


}

float** Inverse::GetAdjoint(){
  float a[2][2];
  float det[9];
  int n=0;
  float temp;
  int k,l;
  float** adj=0;
  adj=new float*[3];
  
  for(int i=0;i<3;i++){
    adj[i]= new float[3];

  }

   for(int row=0;row<3;row++){
    for(int col=0;col<3;col++){
      k=0;
      l=0;
      for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){

	  if(i!=row && j!=col){
	    a[k][l]=c[i][j];
	    l++;  

	  }
     
	}
	if(l>0) k++;    
	l=0;
	
      }

      det[n]=pow(-1,row+col)*Determinant2(a);
      n++;
      
    }
   }

   //Calculate the complements of the c array.
   n=0;
   for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
       adj[i][j]=det[n];
       n++;

     }

   }


   return adj;
   
}

float Inverse::Determinant2(float myArr[][2]){

  float det;
  det=(myArr[0][0]*myArr[1][1]-myArr[0][1]*myArr[1][0]);
  return det;

}

float Inverse::Determinant3(float myArr[][3]){
  float det=0;
  int row=0;
  int k=0,l=0;
  float a[2][2];
  for(int col=0;col<3;col++){
    k=0;
    l=0;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	
	if(i!=row && j!=col){
	  a[k][l]=myArr[i][j];
	  l++;
	}

      }
      if(l>0) k++;
      l=0;

    }
    det=det+myArr[row][col]*pow(-1,col)*Determinant2(a);


  }
  return det;

}


