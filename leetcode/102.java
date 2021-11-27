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
    public List<List<Integer>> levelOrder(TreeNode root) {
        return bfs(root);
    }
    public List<List<Integer>> bfs(TreeNode t){
        List<List<Integer>> li = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(t);
        while(queue.size()!=0){
            int s = queue.size();
            List<Integer> temp = new ArrayList<>();
            while(s-- != 0){
                TreeNode front = queue.poll();
                if(front!=null){
                    queue.add(front.left);
                    queue.add(front.right);
                }
                if(front!=null){
                    temp.add(front.val);
                }
            }
            if(temp.size()!=0){
                li.add(temp);
            }
        }
        return li;
    }
}