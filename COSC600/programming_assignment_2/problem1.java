package programming_assignment_2;

import java.util.Random;
import java.io.IOException;
import java.io.FileWriter;
//import java.io.File;

class maxSubSum {

    public static void main( String[] args) throws IOException {
        Random rand = new Random();

        //int[] n = {5000,10000,50000,100000,200000};
        int[] n = {50000}; //running at each sample size individually to weed out algorithm 1 once it gets too time inefficient

        FileWriter outwriter = new FileWriter("programming_assignment_2/branton_p1_output_n50000.txt");

        long startTime;
        long endTime;
        double diff;


        for (int i = 0; i < n.length; i++){
            int[] arr = new int[n[i]]; 
                for (int j = 0; j < arr.length; j++){
                    arr[j] = rand.nextInt(10000) - 5000;
                }
            outwriter.write("===========\n");
            outwriter.write("Sample Size (N) = " + arr.length + "\n");
            outwriter.write("===========\n");
            outwriter.write("\n");

            outwriter.write("Algorithm 1:\n");
            startTime = System.nanoTime();
            int sum1 = maxSubSum1(arr);
            endTime = System.nanoTime();
            diff = (double) (endTime - startTime)/1000000;
            outwriter.write("Sum: " + sum1 + "\n");
            outwriter.write("Execution Time: " + diff + " (MilliSeconds)\n");
            outwriter.write("\n");


            outwriter.write("Algorithm 2:\n");
            startTime = System.nanoTime();
            int sum2 = maxSubSum2(arr);
            endTime = System.nanoTime();
            diff = (double) (endTime - startTime)/1000000;
            outwriter.write("Sum: " + sum2 + "\n");
            outwriter.write("Execution Time: " + diff + " (MilliSeconds)\n");
            outwriter.write("\n");


            outwriter.write("Algorithm 3:\n");
            startTime = System.nanoTime();
            int sum3 = maxSubSum3(arr);
            endTime = System.nanoTime();
            diff = (double) (endTime - startTime)/1000000;
            outwriter.write("Sum: " + sum3 + "\n");
            outwriter.write("Execution Time: " + diff + " (MilliSeconds)\n");
            outwriter.write("\n");


            outwriter.write("Algorithm 4:\n");
            startTime = System.nanoTime();
            int sum4 = maxSubSum4(arr);
            endTime = System.nanoTime();
            diff = (double) (endTime - startTime)/1000000;
            outwriter.write("Sum: " + sum4 + "\n");
            outwriter.write("Execution Time: " + diff + " (MilliSeconds)\n");
            outwriter.write("\n");
            //System.out.println(arr.length);
        }

        outwriter.close();

    }
    /**
2 * Cubic maximum contiguous subsequence sum algorithm.
    */
    public static int maxSubSum1( int [ ] a )
    {
        int maxSum = 0;

        for( int i = 0; i < a.length; i++ )
            for( int j = i; j < a.length; j++ )
            {
                int thisSum = 0;
                for( int k = i; k <= j; k++ )
                    thisSum += a[ k ];

                if( thisSum > maxSum )
                    maxSum = thisSum;
            }

        return maxSum;
    }

    /**
    * Quadratic maximum contiguous subsequence sum algorithm.
    */
    public static int maxSubSum2( int [ ] a )
    {
        int maxSum = 0;
        for( int i = 0; i < a.length; i++ )
        {
            int thisSum = 0;
            for( int j = i; j < a.length; j++ )
            {
                thisSum += a[ j ];

                if( thisSum > maxSum )
                    maxSum = thisSum;
        }
     }

     return maxSum;
         }

    /**
    * Recursive maximum contiguous subsequence sum algorithm.
    * Finds maximum sum in subarray spanning a[left..right].
    * Does not attempt to maintain actual best sequence.
    */
    private static int maxSumRec( int [ ] a, int left, int right )
        {
        if( left == right ) // Base case
            if( a[ left ] > 0 )
                return a[ left ];
        else
            return 0;

        int center = ( left + right ) / 2;
        int maxLeftSum = maxSumRec( a, left, center );
        int maxRightSum = maxSumRec( a, center + 1, right );

        int maxLeftBorderSum = 0, leftBorderSum = 0;
        for( int i = center; i >= left; i-- )
        {
            leftBorderSum += a[ i ];
            if( leftBorderSum > maxLeftBorderSum )
                maxLeftBorderSum = leftBorderSum;
        }

        int maxRightBorderSum = 0, rightBorderSum = 0;
        for( int i = center + 1; i <= right; i++ )
        {
            rightBorderSum += a[ i ];
            if( rightBorderSum > maxRightBorderSum )
                maxRightBorderSum = rightBorderSum;
        }

        return max3( maxLeftSum, maxRightSum,
                    maxLeftBorderSum + maxRightBorderSum );
     }

     /**
     * Driver for divide-and-conquer maximum contiguous
     * subsequence sum algorithm.
     */
     public static int maxSubSum3( int [ ] a )
     {
     return maxSumRec( a, 0, a.length - 1 );
     }

     public static int max3(int a, int b, int c) {
        return Math.max(Math.max(a, b), c);
    }
    /**
    * Linear-time maximum contiguous subsequence sum algorithm.
    */
    public static int maxSubSum4( int [ ] a )
    {
        int maxSum = 0, thisSum = 0;

        for( int j = 0; j < a.length; j++ )
        {
            thisSum += a[ j ];

            if( thisSum > maxSum )
                maxSum = thisSum;
            else if( thisSum < 0 )
                thisSum = 0;
        }

        return maxSum;
    }
}
