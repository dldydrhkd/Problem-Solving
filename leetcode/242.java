class Solution {
	public boolean isAnagram(String s, String t) {
		int[] arr1 = new int[256];
		int[] arr2 = new int[256];

		for(int i=0; i<s.length(); i++){
			arr1[s.charAt(i)]++;
		}
		for(int i=0; i<t.length(); i++){
			arr2[t.charAt(i)]++;
		}
		for(int i=0; i<256; i++){
			if(arr1[i]!=arr2[i]){
				return false;
			}
		}
		return true;
	}
}