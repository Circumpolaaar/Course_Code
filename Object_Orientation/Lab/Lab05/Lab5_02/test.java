public class test {
    public static void main(String[] args) {
        String[] array1D = {"J","A","V","A"};
        String[][] array2D = {{"J","A"}, {"V","A"}};
        Integer[] intArray1D = { 1, 2, 3, 4, 5 };
        Integer[][] intArray2D = { {1, 2}, {3, 4, 5} };
        ArrayUtils.printArray(array1D); 
        ArrayUtils.printArray(array2D); 
        ArrayUtils.printArray(intArray1D); 
        ArrayUtils.printArray(intArray2D); 
    }
}
