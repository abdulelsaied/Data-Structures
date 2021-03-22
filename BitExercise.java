/** A collection of bit twiddling exercises.
 *  @author Abdul El-Saied
 */

public class BitExercise {

    /** Fill in the function below so that it returns 
    * True iff x is a power of two, otherwise False.
    * For example: 2, 32, and 8192 are powers of two.
    */
    public static boolean powerOfTwo(int x) {
        int minusOne = x - 1;
        if (x == 0) {
            return false;
        }
        return (x & minusOne) == 0;
    }
    
    /** Fill in the function below so that it returns 
    * the absolute value of x WITHOUT USING ANY IF 
    * STATEMENTS OR CALLS TO MATH.
    * For example, absolute(1) should return 1 and 
    * absolute(-1) should return 1.
    */
    public static int absolute(int x) {
        int mask = x >> 31;
        return (x ^ mask) - mask;
    }
}
