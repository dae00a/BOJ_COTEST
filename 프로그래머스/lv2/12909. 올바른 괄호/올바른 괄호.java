class Solution {
    boolean solution(String s) {
        boolean answer = true;

        char[] bracket = {'(', ')'};
        char[] ch = s.toCharArray();
        int top = 0;
        int len = s.length();
        
        for(int i = 0; i < len; i++) {
            if(ch[i] == bracket[0]) {
                top++;
            }
            else {
                if(top <= 0) {
                    answer = false;
                    break;
                }
                top--;
            }
        }

        return (top > 0 ? false : answer);
    }
}