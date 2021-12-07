/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    List<TreeNode> li;
    List<TreeNode> li2;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        li = new ArrayList<>();
        li2 = new ArrayList<>();
        search(root,p);
        search2(root,q);
        int s = Math.min(li.size(), li2.size());
        for(int i=s-1 ; i>=0; i--){
            if(li.get(i)==li2.get(i)){
                return li.get(i);
            }
        }
        return null;
    }
    public void search(TreeNode t, TreeNode p){
        if(t!=null){
            if(p==t){
                li.add(t);
            }
            else{
                li.add(t);
                if(t.val < p.val){
                    search(t.right, p);
                }
                else{
                    search(t.left, p);
                }
            }
        }
    }
    public void search2(TreeNode t, TreeNode q){
        if(t!=null){
            if(q==t){
                li2.add(t);
            }
            else{
                li2.add(t);
                if(t.val < q.val){
                    search2(t.right, q);
                }
                else{
                    search2(t.left, q);
                }
            }
        }
    }
}