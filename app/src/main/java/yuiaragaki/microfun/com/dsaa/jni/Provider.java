package yuiaragaki.microfun.com.dsaa.jni;

import android.widget.Toast;

import yuiaragaki.microfun.com.dsaa.MainActivity;

/**
 * Created by yuiaragaki on 17/5/5.
 */

public class Provider {

    public void sayHello(String msg)
    {
        Toast.makeText(MainActivity.mContext, "test:"+msg, Toast.LENGTH_SHORT).show();
    }

    public static void ShowWithAndroid(String msg)
    {
        Toast.makeText(MainActivity.mContext, "test:"+msg, Toast.LENGTH_SHORT).show();
    }

}
