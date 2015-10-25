c class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode successor = null;
        //find the position of node and lowest root
        while (root != null && root.val != p.val){
            if (p.val < root.val){
                successor = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        if (root == null){
            return null;
        }
        if (root.right == null){
            return successor;
        }
        //when root.right != null
        root = root.right;
        //找右儿子的最小值也就是一直在它右子树第一个根节点一直向左遍历到叶节点
        while (root.left != null){
            root = root.left;
        }
        return root;
    }
}
