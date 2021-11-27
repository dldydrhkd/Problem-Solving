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
    public int maxDepth(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        if(root!=null){
            q.add(root);
        }
        int cnt = 0;
        while(q.size()!=0){
            int s = q.size();
            while(s-- != 0){
                TreeNode front = q.poll();
                if(front!=null){
                    if(front.left!=null){
                        q.add(front.left);
                    }
                    if(front.right!=null){
                        q.add(front.right);
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
}