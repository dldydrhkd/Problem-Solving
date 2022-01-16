class Solution {
    public String sum(String num1, String num2){
        int max_len = Math.max(num1.length(), num2.length())+1;
        char[] answer = new char[max_len];
        int cnt = 0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        int k = max_len-1;
        while(i>=0 && j>=0){
            cnt += (int)(num1.charAt(i)-'0')+(int)(num2.charAt(j)-'0');
            answer[k] = (char)((int)'0'+cnt%10);
            cnt/=10;
            i--;
            j--;
            k--;
        }
        while(i>=0){
            cnt += (int)(num1.charAt(i)-'0');
            answer[k] = (char)((int)'0'+cnt%10);
            cnt/=10;
            i--;
            k--;
        }
        while(j>=0){
            cnt+= (int)(num2.charAt(j)-'0');
            answer[k] = (char)((int)'0'+cnt%10);
            cnt/=10;
            j--;
            k--;
        }
        if(cnt!=0){
            answer[0] = '1';
            return String.valueOf(answer);
        }
        return String.valueOf(answer, 1, answer.length-1);
    }
    public String addStrings(String num1, String num2) {
        return sum(num1, num2);
    }
}