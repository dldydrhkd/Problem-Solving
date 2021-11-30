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
    public TreeNode invertTree(TreeNode root) {
        recursion(root);
        return root;
    }
    public void recursion(TreeNode t){
        if(t!=null){
            TreeNode temp = new TreeNode();
            temp = t.left;
            t.left = t.right;
            t.right = temp;
            recursion(t.left);
            recursion(t.right);
        }
    }
}