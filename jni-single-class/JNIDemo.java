
public class JNIDemo {

    static {
        // Load libHello.so at runtime
        // This libarry contains a native method called HelloWorld()
        // This library shall be included in Java's library path 
        // (kept in Java system variable java.library.path). 
        // You could include the library into Java's library path via 
        // VM argument -Djava.library.path=/path/to/lib.
        System.loadLibrary("hello");
    }

    public native void HelloWorld();

    public static void main(String[] args) {
        new JNIDemo().HelloWorld();
    }
}