
public class Solution {

    static final String ASCII_GREATER_THAN_SMALL_CASE_Z = "~";

    public String smallestFromLeaf(TreeNode root) {
        return findPath("", root);
    }

    public String findPath(String path, TreeNode node) {
        if (node == null) {
            return ASCII_GREATER_THAN_SMALL_CASE_Z;
        }

        path = Character.toString((char) ('a' + node.val)).concat(path);
        if (node.left == null && node.right == null) {
            return path;
        }
        String left = findPath(path, node.left);
        String right = findPath(path, node.right);

        return left.compareTo(right) < 0 ? left : right;
    }
}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
