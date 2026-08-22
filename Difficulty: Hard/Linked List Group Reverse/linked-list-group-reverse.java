class Solution {
    public Node reverseKGroup(Node head, int k) {
        if (head == null || k == 1) return head;

        Node dummy = new Node(0);
        dummy.next = head;
        Node prevGroupEnd = dummy;

        while (true) {
            // Check if k nodes available
            Node kthNode = getKthNode(prevGroupEnd, k);

            if (kthNode == null) {
                // Reverse remaining nodes bhi (as per problem requirement)
                Node remaining = prevGroupEnd.next;
                if (remaining != null) {
                    Node reversed = reverseAll(remaining);
                    prevGroupEnd.next = reversed;
                }
                break;
            }

            Node nextGroupStart = kthNode.next;

            // Reverse k nodes
            Node groupStart = prevGroupEnd.next;
            Node reversed = reverseKNodes(groupStart, k);

            // Connect
            prevGroupEnd.next = reversed;
            groupStart.next = nextGroupStart;

            // Move forward
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }

    private Node getKthNode(Node start, int k) {
        Node current = start;
        while (current != null && k > 0) {
            current = current.next;
            k--;
        }
        return current;
    }

    private Node reverseKNodes(Node head, int k) {
        Node prev = null, current = head;

        while (k > 0 && current != null) {
            Node next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            k--;
        }

        return prev;
    }

    private Node reverseAll(Node head) {
        Node prev = null, current = head;

        while (current != null) {
            Node next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
}