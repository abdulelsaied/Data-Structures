package arrays;

/** Array utilities.
 *  @author Abdul El-Saied
 */
class Arrays {

    /** Returns a new array consisting of the elements of A followed by the
     *  the elements of B. */
    static int[] catenate(int[] A, int[] B) {
        if(A.length == 0){
            return B;
        }
        else if (B.length == 0){
            return A;
        }
        else{
            int total = A.length + B.length;
            int[] result = new int[total];
            for(int i = 0; i < A.length; i++){
                result[i] = A[i];
            }
            for(int j = A.length; j < total; j++){
                result[j] = B[j - A.length];
            }
            return result;
        }
    }

    /** Returns the array formed by removing LEN items from A,
     *  beginning with item #START. */
    static int[] remove(int[] A, int start, int len) {
        int result[] = new int[len];
        int i = 0;
        int pos = 0;
        while (counter < len) {
            answer[pos] = A[start];
            counter ++;
            pos ++;
            start ++;
        }
        return answer;
    }
}
