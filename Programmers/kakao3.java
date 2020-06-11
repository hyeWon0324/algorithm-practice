import java.util.HashMap;
public class Kakao03 {
    private static HashMap<String,Integer> hashMap;
    private static void count(String[] gems) {
        for (int i = 0; i < gems.length; i++) {
            hashMap.putIfAbsent(gems[i],0);
            hashMap.put(gems[i],hashMap.get(gems[i])+1);
        }
    }
    static class Solution {
        public int[] solution(String[] gems) {
            int[] answer = new int[2];
            int tmpSize = Integer.MAX_VALUE;
            hashMap = new HashMap<>();
            HashMap<String,Integer> window = new HashMap<>();
            count(gems);
            int s,e;
            s = e = 0;
            while(e<gems.length) {
                if(gems.length-s>=tmpSize) break;
                while(e<gems.length && window.size()!=hashMap.size()) {
                    // 넣기
                    window.putIfAbsent(gems[e],0);
                    window.put(gems[e],window.get(gems[e])+1);
                    e++;
                }
                while(window.size()==hashMap.size()) {
                    // 빼기
                    int size = e-s;
                    if(size<tmpSize) {
                        tmpSize = size;
                        answer[0] = s+1;
                        answer[1] = e;
                    }
                    window.put(gems[s],window.get(gems[s])-1);
                    if(window.get(gems[s])==0) window.remove(gems[s]);
                    s++;
                }
            }
            return answer;
        }
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] ex = {"AA","AA","AC","BDBS","EFE"};
        int[] ans = s.solution(ex);
        System.out.println(ans[0]+","+ans[1]);
    }
}
