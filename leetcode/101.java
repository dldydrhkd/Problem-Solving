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
    List<Integer> left;
    List<Integer> right;
    public boolean isSymmetric(TreeNode root) {
        left = new ArrayList<>();
        right = new ArrayList<>();
        left_search(root.left);
        right_search(root.right);
        if(left.size()==right.size()){
            for(int i=0; i<left.size(); i++){
                if(left.get(i)!=right.get(i)){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void left_search(TreeNode t){
        if(t!=null){
            left.add(t.val);
            left_search(t.left);
            left_search(t.right);
        }
        else{
            left.add(null);
        }
    }
    void right_search(TreeNode t){
        if(t!=null){
            right.add(t.val);
            right_search(t.right);
            right_search(t.left);
        }
        else{
            right.add(null);
        }
    }
}