import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Integer i, j, tam;
        Integer[] car = new Integer[40];
        Scanner sc = new Scanner(System.in);
        String str;
        while (sc.hasNext()) {
            str = sc.nextLine();
            BigInteger n = new BigInteger(new Integer(str.length()).toString());
            tam = str.length();
            for (i = 0; i < 40; i++) car[i] = 0;
            for (i = 0; i < tam; i++)
                car[str.charAt(i) - 'A']++;
            for (i = 1; i < tam; i++)
                n = n.multiply(new BigInteger(i.toString()));
            for (i = 0; i < 40; i++) {
                if (car[i] < 2) continue;
                BigInteger n1 = new BigInteger(car[i].toString());
                for (j = 1; j < car[i]; j++)
                n1 = n1.multiply(new BigInteger(j.toString()));
                n = n.divide(n1);
            }
            System.out.println(n.mod(new BigInteger("1000000007")));
        }
        sc.close();
    }}
