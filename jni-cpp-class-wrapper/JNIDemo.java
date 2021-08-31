/**
 * Target: Represent C++ object in Java
 * Reference: https://stackoverflow.com/questions/6270245/return-c-object-to-java
 */

public class JNIDemo {

    private long native_ptr = 0;

    // Create a native instance and return a pointer which is represented with type long in Java
    private native long createNativeInstance();

    private native String nativeMethod(long native_ptr);

    private native void destroyNativeInstance(long native_ptr);

    public JNIDemo() {
        this.native_ptr = this.createNativeInstance();
    }

    // Use pointer saved in Java class to destroy instance
    public void finalize() {
        this.destroyNativeInstance(this.native_ptr);
    } 

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
        // Static JNI method test
        new JNIDemo().HelloWorld();

        // Create a C++ instance and pass to another funtion
        long nativeObj = new JNIDemo().createNativeInstance();
        System.out.println(nativeObj);
        String retFromNativeFunc = new JNIDemo().nativeMethod(nativeObj);
        System.out.println(retFromNativeFunc);
        new JNIDemo().destroyNativeInstance(nativeObj);
    }
}