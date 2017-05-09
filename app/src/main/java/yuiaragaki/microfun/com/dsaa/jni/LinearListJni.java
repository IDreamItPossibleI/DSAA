package yuiaragaki.microfun.com.dsaa.jni;

/**
 * Created by yuiaragaki on 17/5/3.
 */

public class LinearListJni {

    private static LinearListJni instance = null;

    private LinearListJni()
    {
    }

    public static LinearListJni getInstance()
    {
        if(instance == null)
        {
            instance = new LinearListJni();
        }
        return instance;
    }


    public native int test();

    public native void deletexall(byte[] buffer, int len, int x, int id);

    public native void reverse(byte[] buffer, int len, int id);

    public native void deleteminfirst(byte[] buffer, int len, int id);

    public native void deletesameall(byte[] buffer, int len, int id);

    public native void merge(byte[] buffer1, int len1, byte[] buffer2, int len2, int id);

}
