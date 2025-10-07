public class LCS {
    
   static class Cell {
        int length;
        String sequence;

        Cell() {
            this.length = 0;
            this.sequence = "";
        }
    }

    public static String findLCS(String X, String Y) {
        int m = X.length();
        int n = Y.length();

        Cell[][] sub = new Cell[m + 1][n + 1];

      
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                sub[i][j] = new Cell();
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X.charAt(i - 1) == Y.charAt(j - 1)) {
                    
                    sub[i][j].length = sub[i - 1][j - 1].length + 1;
                    sub[i][j].sequence = sub[i - 1][j - 1].sequence + X.charAt(i - 1);
                } else {
                    
                    int top = sub[i - 1][j].length;
                    int left = sub[i][j - 1].length;
                    int maxLen = Math.max(top, left);

                    sub[i][j].length = maxLen;
                    if (top >= left) {
                        sub[i][j].sequence = sub[i - 1][j].sequence;
                    } else {
                        sub[i][j].sequence = sub[i][j - 1].sequence;
                    }
                }
            }
        }

      
        Cell result = sub[m][n];
        System.out.println("Length of LCS: " + result.length);
        System.out.println("LCS Sequence: " + result.sequence);

        return result.sequence;
    }

    public static void main(String[] args) {
        String X = "AGCCCTAAGGGCTACCTAGCTT";
        String Y = "GACAGCCTACAAGCGTTAGCTTG";
        findLCS(X, Y);
    }
}
