//
//  main.cpp
//  Prime ring Problem
//
//  Created by APTX on 28/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1016


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace  std;

int ans[22];
bool mark[22];
int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x){
    for(int i = 0; i < 13; i++){
        if(prime[i] == x) return true;
    }
    return false;
}

void check(){
    if(judge(ans[n]+ans[1]) == false) return;
    for(int i = 1; i <= n; i++){
        if(i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

void DFS(int num){
    if(num > 1)
        if(judge(ans[num] + ans[num-1]) == false) return;
    if(num == n){
        check();
        return;
    }
    
    for(int i = 2; i <= n; i++){
        if(mark[i] == false){
            mark[i] = true;
            ans[num+1] = i;
            DFS(num+1);
            mark[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int cas = 0;
    while (cin >> n) {
        cas++;
        for(int i = 0; i < 22; i++) mark[i] = false;
        ans[1] = 1;
        printf("Case %d:\n", cas);
        mark[1] = true;
        DFS(1);
        printf("\n");
    }
    return 0;
}
