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

}
