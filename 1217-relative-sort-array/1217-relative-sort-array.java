class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {

        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < arr2.length; i++){
            mp.put(arr2[i], i);
        }

        for(int ele: arr1){
            if(!mp.containsKey(ele))
                mp.put(ele, 1000000000);
        }

        List<Integer> list = new ArrayList<>(arr1.length);
        for (int ele : arr1) 
            list.add(ele);

        Collections.sort(list, (num1, num2) -> {
            if(mp.get(num1).equals(mp.get(num2)))
                return Integer.compare(num1,num2);
            return Integer.compare(mp.get(num1), mp.get(num2));
        });

        int i = 0;
        for(int ele: list){
            arr1[i++] = ele;
        }

        return arr1;
    }
}