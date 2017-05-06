package yuiaragaki.microfun.com.dsaa.jni;

import android.app.Activity;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import yuiaragaki.microfun.com.dsaa.MainActivity;
import yuiaragaki.microfun.com.dsaa.linearListActivity;

/**
 * Created by yuiaragaki on 17/5/5.
 */

public class Provider {

    public void testDemo(String msg)
    {
        Toast.makeText(MainActivity.mContext, "test:"+msg, Toast.LENGTH_SHORT).show();
    }

    public static void ShowWithAndroid(String msg)
    {
        Toast.makeText(MainActivity.mContext, "test:"+msg, Toast.LENGTH_SHORT).show();
    }

    public static void showWithTextView(byte[] bytes, int id)
    {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<bytes.length; i++)
        {
            sb.append(bytes[i]);
            sb.append(" ");
        }
        if(id == 2)
        {
            linearListActivity.mOutputResult.setText(sb.toString());
        }
        MainActivity.tv.setText(sb.toString());
    }

}
