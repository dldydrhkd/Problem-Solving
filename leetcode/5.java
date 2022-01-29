class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int idx = 0;
        int length = 0;
        boolean[][] dp = new boolean[n][n];
        for(int i=0; i<s.length(); i++){
            dp[0][i] = true;
        }
        for(int i=0; i<s.length()-1; i++){
            if(s.charAt(i)==s.charAt(i+1)){
                dp[1][i]=true;
                length = 1;
                idx = i;
            }
        }
        for(int i=2; i<s.length(); i++){
            for(int j=0; j<s.length(); j++){
                if(i+j<s.length() && dp[i-2][j+1]==true){
                    if(s.charAt(j)==s.charAt(i+j)){
                        dp[i][j]=true;
                        if(i>length){
                            length=i;
                            idx = j;
                        }
                    }
                }
            }
        }
        return s.substring(idx,idx+length+1);
    }
}