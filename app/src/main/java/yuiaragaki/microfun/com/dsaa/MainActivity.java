package yuiaragaki.microfun.com.dsaa;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import yuiaragaki.microfun.com.dsaa.jni.LinearListJni;
import yuiaragaki.microfun.com.dsaa.jni.Provider;

public class MainActivity extends Activity {

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
    public static TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;
        tv = (TextView) findViewById(R.id.tv);
//        tv.setText(sayHello());
        linearListJni = LinearListJni.getInstance();
//        tv.setText(linearListJni.test()+"");
//        linearListJni.test();
        lvList = (ListView) findViewById(R.id.lv_list);
        adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, data);
        lvList.setAdapter(adapter);
        lvList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                switch(position)
                {
                    case 0:
                        Intent intent = new Intent(MainActivity.this, linearListActivity.class);
                        startActivity(intent);
                        break;
                }
            }
        });
    }

//    public native String sayHello();

    static {
        System.loadLibrary("dsaa");
    }
}
