// WAP to find Inverse of a matrix using Gauss Jordan method in C++ language.......
#include <iostream>
using namespace std;

void PrintMatrix(double Matrix[3][6], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout<<Matrix[i][j]<<"\t\t";
        }
        cout << endl;
    }
}

void SetDiagonal(double Matrix[3][6],int row,double Pivot){
    for(int i=0;i<6;i++){
        Matrix[row][i] = Matrix[row][i]/Pivot;
    }
}

void SetElement(double Matrix[3][6],int CurrRow,int PivotRow,double Pivot,double curr){
    double temp=curr/Pivot;
    for(int i=0;i<6;i++){
        if(Matrix[CurrRow][i]==curr){    Matrix[CurrRow][i]=0;    }
        else{    Matrix[CurrRow][i] -= ((temp)*(Matrix[PivotRow][i]));    }
    }
}

void GaussJordan(double Matrix[3][6]) {
    for(int Col=0;Col<3;Col++){
        for(int Row=0;Row<3;Row++){
            if(Row == Col){
                if(Matrix[Row][Col]!=1.0){  SetDiagonal(Matrix,Row,Matrix[Row][Row]);  }
            }
            else{
                if(Matrix[Row][Col]!=0.0){  SetElement(Matrix,Row,Col,Matrix[Col][Col],Matrix[Row][Col]);  }
            }
        }
    }
}

int main() {
    double Matrix[3][6] = {{1,2,-2,1,0,0},{-1,3,0,0,1,0},{0,-2,1,0,0,1}};
    cout << "THE ORIGNAL MATRIX IS ::: " << endl;
    PrintMatrix(Matrix, 3, 6);
    GaussJordan(Matrix);
	cout<<endl;
    cout << "THE INVERSE MATRIX IS ::: " << endl;
    PrintMatrix(Matrix, 3, 6); 
    return 0;
}
