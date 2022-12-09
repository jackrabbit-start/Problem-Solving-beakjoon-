#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int king, queen, bishop, rook, knight, pawn; // 킹 1개 퀸 2개 룩 2개 비숍 2개 나이트 2개 폰 8개
int main(){
    scanf("%d %d %d %d %d %d", &king, &queen, &rook, &bishop, &knight, &pawn);
    printf("%d %d %d %d %d %d\n", 1-king, 1-queen, 2-rook, 2-bishop, 2-knight, 8-pawn);
    return 0;
}