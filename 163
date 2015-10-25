tor<string> findMissingRanges(int A[], int n, int lower, int upper) {
  vector<string> res;
  string tmp;
  int num = lower;
 
  for (int i = 0; i < n; ++i) {
    if (num != A[i]) {
      tmp += to_string(num);
 
      if (num != A[i] - 1) {
        tmp += "->";
        tmp += to_string(A[i] - 1);
      }
      
      res.push_back(tmp);
      tmp.clear();
    }
    
    num = A[i] + 1;
  }
 
  if (num <= upper) {    
    if (num != upper) {
      tmp += to_string(num);
      tmp += "->";
    }
    
    tmp += to_string(upper);
    res.push_back(tmp);
    tmp.clear();
  }
 
  return res;
}

