#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 10;
    vector<vector<int>> g(N, vector<int>(N));
    int sx = -1, sy = -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!(cin >> g[i][j])) return 0;
            if(g[i][j]==4){ sx=i; sy=j; }
        }
    }
    if(sx==-1){
        return 0;
    }

    // treat start as empty
    if(g[sx][sy]==4) g[sx][sy] = 1;

    // Directions: 0=up,1=right,2=down,3=left
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int x = sx, y = sy;
    int dir = 0; // start heading up

    bool vis[10][10][4] = {};

    auto inb = [&](int r,int c){ return r>=0 && r<10 && c>=0 && c<10; };

    long long score = 0;

    while(true){
        if(vis[x][y][dir]){
            cout << "Silly Pacman";
            return 0;
        }
        vis[x][y][dir] = true;

        int cand[4] = {(dir+1)&3, dir, (dir+3)&3, (dir+2)&3};
        bool moved = false;
        for(int k=0;k<4;k++){
            int nd = cand[k];
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(!inb(nx,ny)) continue;
            if(g[nx][ny]==0) continue; // wall
            // Move
            x = nx; y = ny; dir = nd; moved = true; break;
        }
        if(!moved){
            cout << "Silly Pacman";
            return 0;
        }

        if(g[x][y]==3){
            // hit ghost, apply penalty and end
            score -= 500;
            cout << score;
            return 0;
        }
        if(g[x][y]==2){
            score += 2;
            g[x][y] = 1; // consumed
        }
    }
}
