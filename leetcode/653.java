/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        int i = -100000;
        while(i<=100000){
            int j = k-i;
            if(i==j){
                i++;
                continue;
            }
            if(find(root,i) && find(root,j)){
                return true;
            }
            i++;
        }
        return false;
    }
    public boolean find(TreeNode t, int k){
        if(t!=null){
            if(t.val == k){
                return true;
            }
            else if(t.val > k){
                return find(t.left,k);
            }
            else{
                return find(t.right, k);
            }
        }
        return false;
    }
}