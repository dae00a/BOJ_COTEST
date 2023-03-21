class Solution {
    public String solution(String s) {
        String answer = "";
        
        char str[] = s.toLowerCase().toCharArray();
        int len = s.length();
        //StringBuilder sb = new StringBuilder(s);
              
        for(int i = 0; i < len; i++) {
            if(i == 0 || str[i-1] == ' ') {
                if(str[i] >= 'a' && str[i] <= 'z') {
                    str[i] += ('A' - 'a');
                }
            }     
        }
        answer = new String(str);
        
        return answer;
    }
}