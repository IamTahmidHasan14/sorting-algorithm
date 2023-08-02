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

int select(int *ara, int p, int r, int i) {
    if(p == r) return ara[p];
    int q = randomized_partition(ara, p, r);
    int k = q - p + 1;
    if(k == i) return ara[q];
    else if(i < k) return select(ara, p, q-1, i);
    else return select(ara, q+1, r, i-k);
}

int main() {
    int ara[] = {4, 1, 5, 3, 2, 6, 2};
    int n = sizeof(ara) / sizeof(ara[0]);
    int i = 6;
    printf("%d-th smallest element is %d\n", i, select(ara, 0, n-1, i));
    return 0;
}
