
public class Practical4 {

    public static int maximumCrossingSum(int low, int mid, int high, int arr[]) {
        int sum = 0;
        int left_sum = Integer.MIN_VALUE;
        for (int i = mid; i >= low; i--) {
            sum += arr[i];
            if (sum > left_sum) {
                left_sum = sum;
            }
        }
        sum = 0;
        int right_sum = Integer.MIN_VALUE;
        for (int i = mid + 1; i <= high; i++) {
            sum += arr[i];
            if (sum > right_sum) {
                right_sum = sum;
            }
        }
        return left_sum + right_sum;

    }

    public static int maximumSubArraySum(int low, int high, int arr[]) {
        if (low == high) {
            return arr[low];
        }
        int mid = (low + high) / 2;
        int left_sum = maximumSubArraySum(low, mid, arr);
        int right_sum = maximumSubArraySum(mid + 1, high, arr);
        return Math.max(Math.max(left_sum, right_sum), maximumCrossingSum(low, mid, high, arr));
    }

    public static void main(String[] args) {
        int arr[] = {7,-2,3,-8,-1,0,-8};
        int max_sum = maximumSubArraySum(0, arr.length - 1, arr);
        System.out.println("Maximum Subarray Sum: " + max_sum);
    }
}
