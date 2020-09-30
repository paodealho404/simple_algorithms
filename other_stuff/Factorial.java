import java.util.Scanner;
import java.math.BigInteger;
class Factorial{
    public static void main(String[] args) {
        BigInteger fact = BigInteger.ONE;
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        inp.close();
        for (int i = 2; i <= n ; i++) fact = fact.multiply(BigInteger.valueOf(i));    
        
        System.out.println(fact);
    }
}