#include <stack>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void PrintIntVecotr(vector<int> a){
    printf("size = %d vector = ",a.size());
    for(int i=0;i<a.size();i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}