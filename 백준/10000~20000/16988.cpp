#include <iostream>
#include <queue>
using namespace std;

int arr[21][21];
bool visited[21][21];
int n,m;
int answer;

int x[] = {0,0,-1,1};
int y[] = {1,-1,0,0};

bool check(int a, int b){
    if(a>=0 && a<n && b>=0 && b<m){
        return true;
    }
    return false;
}

int main(){
    cin >>n>>m;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>arr[i][j];
            if(arr[i][j]==0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            arr[v[i].first][v[i].second]=1;
            arr[v[j].first][v[j].second]=1;
            for(int p=0; p<n; p++){
                for(int q=0; q<m; q++){
                    visited[p][q]=0;
                }
            }
            int cnt = 0;
            for(int p=0; p<n; p++){
                for(int q=0; q<m; q++){
                    if(arr[p][q]==2 && !visited[p][q]){
                        queue<pair<int, int> > qu;
                        qu.push(make_pair(p,q));
                        visited[p][q]=true;
                        bool get_point = true;
                        int res = 1;
                        while(!qu.empty()){
                            int size = qu.size();
                            while(size--){
                                int front_x = qu.front().first;
                                int front_y = qu.front().second;
                                qu.pop();
                                for(int k=0; k<4; k++){
                                    int nx = front_x +x[k];
                                    int ny = front_y + y[k];
                                    if(check(nx,ny) && !visited[nx][ny] && arr[nx][ny]==2){
                                        visited[nx][ny]=true;
                                        qu.push(make_pair(nx,ny));
                                        res+=1;
                                    }
                                    if(check(nx,ny) && arr[nx][ny]==0){
                                        get_point = false;
                                    }
                                }
                            }
                        }
                        if(get_point){
                            cnt+=res;
                        }
                    }
                }
            }
            arr[v[i].first][v[i].second]=0;
            arr[v[j].first][v[j].second]=0;
            answer = max(answer,cnt);
        }
    }
    cout<<answer<<"\n";
}