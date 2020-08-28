#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int arr[100001] = { 0, };
int sum[100001];

int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			sum[i] = arr[i];
		}
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int j = 0; j < m; j++) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b - 1] - sum[a - 1] + arr[a - 1]);
	}
}