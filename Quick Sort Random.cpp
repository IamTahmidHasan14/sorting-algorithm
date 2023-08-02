#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int *ara, int p, int r) {
    int pivot = ara[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; ++j)
        if(ara[j] <= pivot) {
            ++i;
            swap(ara[i], ara[j]);
        }
    swap(ara[i+1], ara[r]);
    return i + 1;
}

int randomized_partition(int *ara, int p, int r) {
    int n = r - p;
    int i_rand = p + rand() % n;
    swap(ara[i_rand], ara[r]);
    return partition(ara, p, r);
}

void quick_sort(int *ara, int p, int r) {
    if(p < r) {
        int q = randomized_partition(ara, p, r);
        quick_sort(ara, p, q-1);
        quick_sort(ara, q+1, r);
    }
}

int main() {
    int ara[] = {4, 1, 5, 3, 2, 6, 2};
    int n = sizeof(ara) / sizeof(ara[0]);
    quick_sort(ara, 0, n-1);
    for(int i = 0; i < n; ++i) printf("%d ", ara[i]);
    return 0;
}
