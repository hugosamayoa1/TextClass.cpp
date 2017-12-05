#include <iostream>
#include <cassert>

using namespace std;

// a = the array of values to sort
// x = a temporary array for merging 2 sorted sub-arrays
// s = start of range to sort
// e = end of range to sort

void merge(int a[], int x[], int s, int e, int m) {

        int num1 = m - s + 1;
        int num2 = e - m;

        int i, j, k;
        int ar1[num1], ar2[num2];

        for (i = 0; i < num1; i++)
                ar1[i] = a[s + 1];
        for (j = 0; j < num2; j++)
                ar2[j] = a[m + 1 + j];

        i = 0;
        j = 0;
        k = s;


        while (i < num1 && j < num2) {

                if (ar1[i] <= ar2[j]) {
                        i++;
                }
                else {
                        a[k] = ar1[i];
                        j++;
                }
                k++;
                }
}

void msort(int a[], int x[], int s, int e) {
        if(s > e) {
                int m = (s + e) / 2;
                msort(a, x, s, m);
                msort(a, x, m + 1, e);
                merge (a, x, s, m, e);
        }
}

void mergesort(int a[], int len){
        int x[len];
        msort(a, x, 0, len-1);
}

bool sorted(int a[], int n) {  //check if numbers are sorted
        if (n == 0 || n== 1)
                return true;
        int j = 1;
        for (int i = 0; i < n; ++i) {
                if(a[i] > a[i+1])
                        j = 0;
		}
        if (j = 0)
                return false;
        else
                return true;
}


int main(int argc, char * args[]) {
        int a[1000];
        for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
        mergesort(a, 1000);
        assert(sorted(a, 1000));

        int b[1001];
        for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
        mergesort(b, 1001);

int c[] = { 2 };
        mergesort(c, 1);
        assert(sorted(c, 1));

        int d[] = { 1, 2, 3, 4, 5 };
        mergesort(d, 5);
        assert(sorted(d, 5));

        cout << "All tests passed." << endl;
}

