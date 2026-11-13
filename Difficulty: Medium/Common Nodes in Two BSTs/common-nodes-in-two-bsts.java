class Solution {

    private void inorder(Node root, Set<Integer> set, List<Integer> list) {
        if(root == null)
            return;

        inorder(root.left, set, list);

        if(set.contains(root.data))
            list.add(root.data);

        inorder(root.right, set, list);
    }

    private void inorder(Node root, Set<Integer> set) {
        if(root == null)
            return;

        inorder(root.left, set);
        set.add(root.data);
        inorder(root.right, set);
    }

    public ArrayList<Integer> findCommon(Node r1, Node r2) {
        // code here
        Set<Integer> set = new TreeSet<>();
        List<Integer> list = new ArrayList<>();

        inorder(r1, set);
        inorder(r2, set, list);

        Collections.sort(list);

        return new ArrayList<>(list);
    }
}
