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
    List<Integer> li;
    public boolean isValidBST(TreeNode root) {
        li = new ArrayList<>();
        valid(root);
        for(int i=1; i<li.size(); i++){
            if(li.get(i)<=li.get(i-1)){
                return false;
            }
        }
        return true;
    }
    public void valid(TreeNode t){
        if(t!=null){
            if(t.left != null){
                valid(t.left);
            }
            li.add(t.val);
            if(t.right != null){
                valid(t.right);
            }
        }
    }
}