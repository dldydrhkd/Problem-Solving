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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null){
            return false;
        }
        boolean answer = recursion(root, targetSum, 0);
        return answer;
    }
    public boolean recursion(TreeNode t, int targetSum, int now){
        if(t!=null){
            now += t.val;
            if(t.left==null && t.right==null){
                if(now == targetSum){
                    return true;
                }
                return false;
            }
            boolean a = recursion(t.left,targetSum,now);
            boolean b = recursion(t.right,targetSum, now);
            return a | b;
        }
        return false;
    }
}