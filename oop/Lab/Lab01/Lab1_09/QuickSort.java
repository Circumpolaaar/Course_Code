public class QuickSort {
    public static void main(String[] args){
        int[] arr = {33, 2, 0, 57, 12, 21, 4, 38, 100, 6};
        qsort(arr);
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }

  public static int[] qsort(int[] arr) {
    //不存在，返回null
    if (arr == null) {
        return null;
    }
    //空，返回arr
    if (arr.length == 0) {
        return arr;
    }

    Sort(arr, 0, arr.length - 1);
        return arr;
  }

  //递归
  private static void Sort(int[] arr, int left, int right) {
    if (left < right) {
        int p = part(arr, left, right);
        Sort(arr, left, p - 1); // 排左边
        Sort(arr, p + 1, right); // 排右边
    }
  }

  //分区
  private static int part(int[] arr, int left, int right) {
    int p = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= p) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
      }

      int temp = arr[i + 1];
      arr[i + 1] = arr[right];
      arr[right] = temp;
      return i + 1;
  }

}
