let x = [0,0,-1,1];
let y = [1,-1,0,0];
var n;
var m;

function check(i, j){
    if(i>=0 && i<n && j>=0 && j<m){
        return true;
    }
    return false;
}

function solution(maps) {
    var answer = 1;
    let q = [];
    let visited = [];
    n = maps.length;
    m = maps[0].length;
    for(var i=0; i<maps.length; i++){
        var temp = [];
        for(var j=0; j<maps[i].length; j++){
            temp.push(0);
        }
        visited.push(temp);
    }
    q.push([0,0]);
    visited[0][0]=1;
    while(q.length != 0){
        let size = q.length;
        while(size--){
            let top = q.shift();
            let cur_x = top[0];
            let cur_y = top[1];
            if(cur_x==n-1 && cur_y==m-1){
                console.log(visited)
                return answer;
            }
            for(var i=0; i<4; i++){
                let nx = cur_x+x[i];
                let ny = cur_y+y[i];
                if(check(nx,ny) && !visited[nx][ny] && maps[nx][ny]!=0){
                    q.push([nx,ny]);
                    visited[nx][ny]=1;
                }
            }
        }
        answer++;
    }
    answer=-1;
    return answer;
}