#include<bits/stdc++.h>
using namespace std;

char mat[50][50];
bool vis[50][50];
int dis[50][50];
int n;
vector<pair<int, int> > d;

void bfs(int si, int sj){
    queue<pair<int, int> > q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;

    while (!q.empty()){
        pair<int, int> parent = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (ci >= 0 && ci < n && cj >=0 && cj<n&& !vis[ci][cj] && mat[ci][cj] != 'T'){
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[parent.first][parent.second] + 1;
            }
        }
    }   
}

int main(){
    d.push_back({0, 1});
    d.push_back({0, -1});
    d.push_back({-1, 0});
    d.push_back({1, 0});
    while (cin >> n)
    {
        int si, sj;
        int di, dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];

                if (mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        bfs(si, sj);
        cout << dis[di][dj] << endl;
  }

    return 0;
}