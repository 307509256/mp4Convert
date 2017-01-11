package com.kuaipai.fangyan.core.shooting.jni;






import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {
	private RecorderJni  player;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
       
        
        findViewById(R.id.btn_recode).setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Intent i = new Intent("com.kuaipai.fangyan.core.shooting.jni.intent.action.RecorderJni");
				startActivity(i);
			}
		} );
    }
}
