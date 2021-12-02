```
func levelOrderBottom(root *TreeNode) (result [][]int) {
    var dfs func(*TreeNode, int)
    dfs = func(node *TreeNode, level int) {
        if node == nil {return}
        if len(result) == level {
            result = append(result, []int{})
        }
        result[level] = append(result[level], node.Val)
        dfs(node.Left, level+1)
        dfs(node.Right, level+1)
    }
    dfs(root, 0)
    //翻转数组
    for l, r := 0, len(result)-1; l < r; {
        result[l], result[r] = result[r], result[l]
        l++; r--
    }
    return
}
```
