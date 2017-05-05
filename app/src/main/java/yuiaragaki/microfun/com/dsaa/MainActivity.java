package yuiaragaki.microfun.com.dsaa;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.ListViewCompat;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import yuiaragaki.microfun.com.dsaa.jni.LinearListJni;
import yuiaragaki.microfun.com.dsaa.jni.Provider;

public class MainActivity extends AppCompatActivity {

    private LinearListJni linearListJni;
    private Provider provider;

    private ListView lvList;
    private ArrayAdapter<String> adapter;
    private String[] data = new String[] {
            "线性表",
            "栈",
            "队列",
            "二叉树",
            "图"
    };

    public static Context mContext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;
        TextView tv = (TextView) findViewById(R.id.tv);
//        tv.setText(sayHello());
        linearListJni = LinearListJni.getInstance();
        tv.setText(linearListJni.test()+"");
        lvList = (ListView) findViewById(R.id.lv_list);
        adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, data);
        lvList.setAdapter(adapter);
    }

//    public native String sayHello();

    static {
        System.loadLibrary("dsaa");
    }
}
