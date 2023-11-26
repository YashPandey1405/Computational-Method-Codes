// Code To Implement Power Method On Matrix Using C++.....
// WAP To Find Largest Eigen value and corresponding Eigen vector using Power Method......
#include<iostream>
#include<cmath>
using namespace std;

double GetMax(double Temp[3][1]){
    double Max = 0.0;
    for (int i=0;i<3;i++){
        if (Temp[i][0] > Max){  Max = Temp[i][0];   }
    }
    return Max;
}

void Multiply(double A[3][3] , double X[3][1] , double Result[3][1]){
    for(int i=0;i<3;i++){  Result[i][0]=0;  }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Result[i][0] += ((A[i][j])*(X[j][0]));
        }
    }   
}

void SetVector(double Vector[3][1],double Lamda){
    for(int i=0;i<3;i++){
        Vector[i][0] = (Vector[i][0]/Lamda);
    }
}

void Update(double X[3][1],double Result[3][1]){
    for(int i=0;i<3;i++){
        X[i][0]=Result[i][0];
    }  
}

void Display(int itr,double NewLamda,double X[3][1]){
    cout<<"itr-"<<itr<<"\t\t"<<NewLamda<<"\t\t [ ";
    for(int i=0;i<3;i++){
        if(i==2){  cout<<X[i][0]<<" ]"<<endl;   }
        else{      cout<<X[i][0]<<"  ,  ";      }
    }
}

int main(){
    cout<<endl;
    double A[3][3]={{2,-1,0},{-1,2,-1},{0,-1,2}};
    double X[3][1]={{1},{0},{0}};
    double Vector[3][1]={0};
    double OldLamda=1.0 , NewLamda=0.0;
    double e=0.001,Diff=fabs(NewLamda-OldLamda);
    int itr=1;
    cout<<"Itr"<<"\t\tEigen Value"<<"\t\tEigen Vector"<<endl;
    cout<<endl;

    while(Diff >= e){
        Multiply(A,X,Vector);
        OldLamda=NewLamda;
        NewLamda=GetMax(Vector);
        SetVector(Vector,NewLamda);
        Update(X,Vector);
        Display(itr,NewLamda,X);
        Diff=fabs(NewLamda-OldLamda);
        itr++;
    }

    cout<<endl;

    cout<<"Largest Eigen Value Is ::: "<<NewLamda<<endl;    
    cout<<"It's Eigen Vector Will Be ::: [ ";
    for(int i=0;i<3;i++){
        if(i==2){  cout<<Vector[i][0]<<" ]"<<endl;   }
        else{      cout<<Vector[i][0]<<"  ,  ";      }
    }

    cout<<endl;

    return 0;
}