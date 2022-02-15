
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @return {string}
 */
var smallestFromLeaf = function (root) {
    return  findPath("", root);
};

/**
 * @param {string} path
 * @param {TreeNode} node
 * @return {string}
 */
function findPath(path, node) {
    if (node === null) {
        return ascii_greater_than_small_case_z();
    }

    path = String.fromCodePoint("a".codePointAt(0) + node.val).concat(path);
    if (node.left === null && node.right === null) {
        return path;
    }
    let left = findPath(path, node.left);
    let right = findPath(path, node.right);

    return left < right ? left : right;
}

function ascii_greater_than_small_case_z() {
    return "~";
}
