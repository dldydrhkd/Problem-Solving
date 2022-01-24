class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String str = "";
        for(int i=0; i<strs[0].length(); i++){
            char t = strs[0].charAt(i);
            boolean check = true;
            for(int j=1; j<strs.length; j++){
                if(t!=strs[j].charAt(i)){
                    return str;
                }
            }
            str+=Character.toString(t);
        }
        return str;
    }
}