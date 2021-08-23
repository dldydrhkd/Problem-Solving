function solution(scores) {
    var answer = '';
    for(var i=0; i<scores.length; i++){
        var only_max = true;
        var only_min = true;
        for(var j=0; j<scores[i].length; j++){
            if(i==j) continue;
            if(scores[j][i]>=scores[i][i]){
                only_max = false;
            }
            if(scores[j][i]<=scores[i][i]){
                only_min = false;
            }
        }
        var cnt = 0;
        var sum = 0;
        for(var j=0; j<scores[i].length; j++){
            if((only_max || only_min) && i==j){
                
            }
            else{
                cnt++;
                sum+=scores[j][i];
            }
        }
        var avg = sum/cnt;
        if(avg>=90) answer+='A';
        else if(avg>=80) answer += 'B';
        else if(avg>=70) answer += 'C';
        else if(avg>=50) answer += 'D';
        else answer += 'F';
    }
    return answer;
}