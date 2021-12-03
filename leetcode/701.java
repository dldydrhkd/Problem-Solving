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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root==null){
            TreeNode temp = new TreeNode(val);
            root = temp;
        }
        else{
            insertion(root, val);
        }
        return root;
    }
    void insertion(TreeNode t, int val){
        if(t!=null){
            if(t.val < val){
                if(t.right == null){
                    TreeNode temp = new TreeNode(val);
                    t.right = temp;
                }
                else{
                    insertion(t.right, val);
                }
            }
            else{
                if(t.left==null){
                    TreeNode temp = new TreeNode(val);
                    t.left = temp;
                }
                else{
                    insertion(t.left,val);
                }
            }
        }
    }
}