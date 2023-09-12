

class search{
    public static void main(String[] args){
        int[] nums={4,6,3,9,7,2};
        int target = 8;
        boolean ans = linearsearch(nums,target);
        System.out.println(ans);
    }

    static boolean linearsearch(int[] arr, int target)
    {
        if(arr.length == 0){
            return false;
        }

        for (int i = 0; i < arr.length; i++) {
            if(arr[i] == target) return true;
        }
        return false;
    }
}