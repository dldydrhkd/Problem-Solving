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
    
    public List<Integer> inorderTraversal(TreeNode root) {
        li = new ArrayList<Integer>();
        recursion(root);
        return li;
    }
    
    public void recursion(TreeNode t){
        if(t!=null){
            recursion(t.left);
            li.add(t.val);
            recursion(t.right);
        }
    }
}