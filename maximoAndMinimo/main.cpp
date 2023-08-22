#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int A[] = {9,10,6,3,8,4,3,10,9,6};
    int n = (sizeof(A)/sizeof(A[0]));
    int max = A[0];
    int min = A[0];



    for (int i = 0; i < n; i++)
    {
        //cout<<A[i]<<endl;
        if(max < A[i]){
            max = A[i];
        }
        if(min > A[i]){
            min = A[i];
        }

    }
    cout<<max<<endl;
    cout<<min<<endl;
    cout<<"-----------"<<endl;

    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        contador = 0;
        for (int x = 0; x < n; x++)
        {

            if( A[i] == A[x]){
                contador++;
                if(contador > 1){
                    cout<<x<<endl;
                }
            }


        }

    }




    return 0;
}
