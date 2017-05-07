package yuiaragaki.microfun.com.dsaa;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import yuiaragaki.microfun.com.dsaa.jni.LinearListJni;

/**
 * Created by yuiaragaki on 17/4/20.
 *
 * 线性表
 */

public class linearListActivity extends Activity implements View.OnClickListener {

    public EditText mInputInit, mInputParams;
    public Button mBtnDeleteXAll, mBtnReverse, mBtnDeleteMinFirst;
    public static EditText mOutputResult;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_linear_list);
        init();
    }

    private void init() {
        mInputInit = (EditText) findViewById(R.id.edt_input_initdata);
        mInputParams = (EditText) findViewById(R.id.edt_input_params);
        mOutputResult = (EditText) findViewById(R.id.edt_output_result);
        mBtnDeleteXAll = (Button) findViewById(R.id.btn_delete_x_all);
        mBtnDeleteXAll.setOnClickListener(this);
        mBtnReverse = (Button) findViewById(R.id.btn_reverse);
        mBtnReverse.setOnClickListener(this);
        mBtnDeleteMinFirst = (Button) findViewById(R.id.btn_delete_min_first);
        mBtnDeleteMinFirst.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        String str = mInputInit.getText().toString();
        byte[] bytes = parseInput(str);
        switch(v.getId())
        {
            case R.id.btn_delete_x_all:
                String strX = mInputParams.getText().toString();
                int x = Integer.parseInt(strX);
                LinearListJni.getInstance().deletexall(bytes, bytes.length, x, 2);
                break;
            case R.id.btn_reverse:
                LinearListJni.getInstance().reverse(bytes, bytes.length, 2);
                break;
            case R.id.btn_delete_min_first:
                LinearListJni.getInstance().deleteminfirst(bytes, bytes.length, 2);
                break;
        }
    }

    public byte[] parseInput(String strInput)
    {
        String []temp = strInput.split(" ");
        byte[] bytes = new byte[temp.length];
        for(int i=0; i<temp.length; i++)
        {
            bytes[i] = Byte.parseByte(temp[i]);
        }
        return bytes;
    }
}
