class Solution {
    public String removeChars(String s) {
        String result = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                result += ch;
            }
        }

        return result;
        
        
        
    }
};