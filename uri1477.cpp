#include <stdio.h>
#include <string.h>
#define MAX 112345

typedef struct{ int h, e, r; }jog;

int N, M;
jog J[MAX];
jog tree[MAX * 4];
int lazy[MAX * 4];

jog soma(jog a, jog b){
    jog ret;
    ret.h = a.h + b.h;
    ret.e = a.e + b.e;
    ret.r = a.r + b.r;
    return ret;
}

jog rot(jog a){
    jog ret;
    ret.h = a.r;
    ret.e = a.h;
    ret.r = a.e;
    return ret;
}

jog rotK(jog a, int K){
    int tmp, i;
    for(i = 0; i < K % 3; i++){
        tmp = a.h;
        a.h = a.r;
        a.r = a.e;
        a.e = tmp;
    }
    return a;
}

void build(int node, int start, int end){
    if(start == end){
        tree[node] = J[start];
    }else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = soma(tree[2*node], tree[2*node+1]);
    }
}

void updateRange(int node, int start, int end, int l, int r){
    if(lazy[node] != 0){
        tree[node] = rotK(tree[node], lazy[node]);
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l) return;
    if(start >= l && end <= r){
        tree[node] = rot(tree[node]);
        if(start != end){
            lazy[node * 2] += lazy[node] + 1;
            lazy[node * 2 + 1] += lazy[node] + 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r);
    updateRange(node * 2 + 1, mid + 1, end, l, r);
    tree[node] = soma(tree[node*2], tree[node*2+1]);
}

jog queryRange(int node, int start, int end, int l, int r){
    if(start > end or start > r or end < l){
        jog zero;
        zero.h = zero.e = zero.r = 0;
        return zero;
    }
    if(lazy[node] != 0){
        tree[node] = rotK(tree[node], lazy[node]);
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r) return tree[node];
    int mid = (start + end) / 2;
    jog p1 = queryRange(node * 2, start, mid, l, r);
    jog p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
    return soma(p1, p2);
}

int main(void){
    jog a;
    char ev;
    int i, A, B;
    while(scanf("%d %d", &N, &M) != EOF){
        a.h = 1; a.e = 0; a.r = 0;
        for(i = 0; i < N; i++) J[i] = a;
        build(1, 0, N - 1); memset(lazy, 0, sizeof(lazy));
        while(M--){
            scanf(" %c %d %d", &ev, &A, &B);
            if(ev == 'C'){
                a = queryRange(1, 0, N - 1, A - 1, B - 1);
                printf("%d %d %d\n", a.h, a.e, a.r);
            } else {
                updateRange(1, 0, N - 1, A - 1, B - 1);
            }}
        printf("\n");
    }
    return 0;
}
