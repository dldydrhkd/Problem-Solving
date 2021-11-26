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
    static List<Integer> li = new ArrayList<>();
        
    public void recursion(TreeNode t){
        if(t!=null){
            li.add(t.val);
            recursion(t.left);
            recursion(t.right);
        }
        
    }
    
    public List<Integer> preorderTraversal(TreeNode root) {
        li.clear();
        recursion(root);
        return li;
    }
}