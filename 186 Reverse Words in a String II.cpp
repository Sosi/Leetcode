c void reverseWords(char[] s) {
    // 从头到末尾翻转
    reverse(s, 0, s.length);
    // 从头到尾遍历
    for (int i = 0, j = 0; j <= s.length; j++) {
        // 如果碰到空格（或者已经是末尾了），则翻转i到j位置的字符串，即一个单词。
        if (j == s.length || s[j] == ' ') {
            reverse(s, i, j);
            i = j + 1;
        }
    }
}
 
private void reverse(char[] s, int begin, int end) {
    // 从头到中间遍历
    for (int i = 0; i < (end - begin) / 2; i++) {
        // 左右两边字符（i和j位置）交换
        char temp = s[begin + i];
        s[begin + i] = s[end - i - 1];
        s[end - i - 1] = temp;
    }
}
