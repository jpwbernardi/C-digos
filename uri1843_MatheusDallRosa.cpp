#include <bits/stdc++.h>

#define MAX 7

using namespace std;

int N, M;
bool flood[MAX][MAX];

struct st{
	char grid[MAX][MAX];
	st(char prev[][MAX]){
		memcpy(grid,prev,sizeof(grid));
	}
	bool operator<(const st a) const{
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				if(grid[i][j] != a.grid[i][j])
					return grid[i][j] < a.grid[i][j];
		return false;
	}
};

int confere(st &s){
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(s.grid[1][1] != s.grid[i][j])
				return 0;
	return 1;
}

int valid(int i, int j){
	return 1 <= i && i <= N && 1 <= j && j <= M;
}

char corO, corN;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
void dfs(int i,int j,st &s){
	flood[i][j] = 1;
	for(int p = 0; p < 4; p++){
		int ni = dx[p] + i, nj = dy[p] + j;
		if(valid(ni, nj) && !flood[ni][nj] && (s.grid[ni][nj] == corO || s.grid[ni][nj] == corN)){
			s.grid[ni][nj] = corN;
			dfs(ni, nj, s);
		}
	}
}

queue<st> q;
map<st,int> memo;
int main(){
    bool comp[MAX][MAX];
	char grid[MAX][MAX];
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N;i++) scanf(" %s", grid[i] + 1);
	st ini = st(grid); memo[ini] = 0; q.push(ini);
	while(!q.empty()){
		st u = q.front(); q.pop();
		if(confere(u)){ printf("%d\n",memo[u]); return 0; }
		corN = corO = u.grid[1][1];
		memset(flood, false, sizeof(flood));
		dfs(1, 1, u); memcpy(comp, flood, sizeof(comp));
		int d = memo[u];
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(!comp[i][j]){
					st v = st(u.grid);
					corO = v.grid[1][1];
					corN = v.grid[i][j];
					memset(flood, false, sizeof(flood));
					dfs(1, 1, v);
					v.grid[1][1] = corN;
					if(memo.find(v) == memo.end()){
						q.push(v);
						memo[v] = d + 1;
					}}}}}
    return 0;
}
