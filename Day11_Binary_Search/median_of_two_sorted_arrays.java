class Solution {
    int smaller(int x, int arr[]){
        // number of elements in arr smaller or equal to x
        int n = arr.length;
        if(n == 0){
            return 0;
        }
        if(arr[0] > x){
            return 0;
        }
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(arr[mid] > x){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return l + 1;
    }
    int greater(int x, int arr[]){
        // number of elements in arr greater or equal to x
        int n = arr.length;
        if(n == 0){
            return 0;
        }
        if(arr[n - 1] < x){
            return 0;
        }
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(arr[mid] < x){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return (n - l);
    }
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int N = n + m;
        int l = -1000000, r = 1000000;
        while(l < r){
            int mid = (l + r) / 2;
            if(mid == r){
                mid = l;
            }
            if(smaller(mid, nums1) + smaller(mid, nums2) < (N + 1) / 2){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        // System.out.println(smaller(4, nums1) + smaller(4, nums2));
        int L = l;
        // System.out.println(L + " " + (smaller(L, nums1) + smaller(L, nums2)));
        l = -1000000;
        r = 1000000;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(mid == l){
                mid = r;
            }
            if(greater(mid, nums1) + greater(mid, nums2) < (N + 1) / 2){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        int R = l;
        // System.out.println(L + " " + R);
        return (L + 0.0 + l) / 2;
    }
}
