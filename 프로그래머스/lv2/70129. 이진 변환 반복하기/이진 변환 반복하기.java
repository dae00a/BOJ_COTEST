import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {0, 0};
        
        int delZeroNum = 0;
        int cnt = 0;
        int len = s.length();

        while(len > 1) {
            String tmps;
            int tmp = 0;
            
            for(int i = 0; i < len; i++) {
                if(s.charAt(i) == '0')
                    delZeroNum++;
                else
                    tmp++;
            }
            
            s = Integer.toBinaryString(tmp);
            len = s.length();
            
            cnt++;
        }
        
        answer[0] = cnt;
        answer[1] = delZeroNum;
        
        return answer;
    }
}