#include<stdio.h>
#include<stdlib.h>
#define MAXN 12000 

int set[MAXN];
int height[MAXN];

int max(int a, int b){
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}

int find(int x)
{
    if(set[x]==x) return x;  // 如果他自己就是他那群的源頭，就回報他自己的編號
    
    int root = find(set[x]); // 找出他老大的源頭
    set[x] = root; // 更新成真正的老大
    return root;
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    else if (height[a] >= height[b]) {
        set[b] = a;
        height[a] = max(height[a], height[b] + 1);
    } 
    else {
        set[a] = b;
        height[b] = max(height[b], height[a] + 1);
    }
}

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        int n, ops;
        scanf("%d %d", &n, &ops);
        for(int i = 0; i < n; i++){
            set[i] = i;
            height[i] = 1;
        }
        while(ops--){
            char ope[10];
            int a, b;
            scanf("%s",ope);
            if(ope[0] == 'u'){
                scanf("%d %d", &a, &b);
                Union(a,b);
            
            }
            else if(ope[0] == 'f'){
                scanf("%d", &a);
                printf("%d",find(a));
                if(m || ops) printf("\n");
            }
            else if(ope[0] == 's'){
                scanf("%d %d", &a, &b);
                if(find(a) == find(b)){
                    printf("true");
                    if(m || ops) printf("\n");
                }
                else{
                    printf("false");
                    if(m || ops) printf("\n");
                }
            }
            
        }
    }
}