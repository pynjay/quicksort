
#include <iostream>
using namespace std;

int arrange(int *arr, int num, int s, int e){
   int n = 0, m = 0;
   int r = e;
   int temp;
   while(m < r){
    if(arr[m] == num){
    m++;
   } else if(arr[m] > num){
    temp = arr[r];
    arr[r] = arr[m];
    arr[m] = temp;
    r--;
   } else {
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
    n++;
    m++;
   }
   }
   if(m==r){
    if(arr[m] < num){
        temp = arr[n];
        arr[n] = arr[m];
        arr[m] = temp;
        m++;
        n++;
    } else if(arr[m] > num){
        temp = arr[r];
        arr[r] = arr[m];
        arr[m] = temp;
        r--;
    }
   }
   if(arr[m-1] == num){
    return m - 1;
   } else return m;
}

void quickSort(int *arr, int num, int s, int e){
    int n = e - s + 1;
    int a;
    int r;
    if(n > 1){
        a = arrange(arr, num, s, e);
        if(a>s+1){
            r = rand() % (a-s-1);
            quickSort(arr, arr[s+r], s, a-1);
        }
        if(e>a+1){
            r = rand() % (e-a-1);
            quickSort(arr, arr[r+a+1], a+1, e);
        }

    }

}

int main(){
    srand( (unsigned)time(NULL));


    const int max = 20;

    int d[max];
    int no1;
    

    for(int i = 0; i < 1000; i++){
        for(int s = 0; s < max; s++){
            no1 = rand() % 100;
            d[s] = no1;
        }
        int no2 = rand() % max;

        int num = d[no2];

        quickSort(d, num, 0, max-1);

        int temp = d[0];

        for(int s = 0; s < max-1; s++){
            if(d[s] > d[s+1]){
                cout << "false" << endl;
            }
        }

        for(int i = 0; i < max; i++){
            cout << d[i] << ' ';
        }

        cout << endl;

    }




   
}