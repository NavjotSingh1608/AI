import java.math.BigInteger;
import java.security.SecureRandom;

public class Assignment6 {
    private final static SecureRandom random = new SecureRandom();

    public static void main(String[] args) {
        BigInteger p = BigInteger.probablePrime(512, random);
        BigInteger g = new BigInteger("3");
        BigInteger aliceSecret = new BigInteger("123456789");
        BigInteger bobSecret = new BigInteger("987654321");

        BigInteger alicePublic = g.modPow(aliceSecret, p);

        BigInteger bobPublic = g.modPow(bobSecret, p);

        BigInteger alicePrivate = bobPublic.modPow(aliceSecret, p);
        BigInteger bobPrivate = alicePublic.modPow(bobSecret, p);

        System.out.println("Alice's Private Key: " + alicePrivate);
        System.out.println("Bob's Private Key: " + bobPrivate);
    }
}
