public class Solution extends Relation {
	public int findCelebrity(int n) {
		if (n <= 0)
			throw new IllegalArgumentException("n is invalid");
		if (n == 1)
			return 0;
		Stack<Integer> stack = new Stack<Integer> ();
		for (int i  = 0; i < n; i++)
			stack.push(i);
		while (stack.size() > 1) {
			int i = stack.pop();
			int j = stack.pop();
			if (knows(i, j)) 
				stack.push(j);
			else
				stack.push(i);
		}
		int j = stack.pop();
		for (int i = 0; i < n; i++) {
			if (i != j) {
				if (!knows(i, j) || knows(j, i))
					return -1;
			}
		}
		return j;
	}
}
