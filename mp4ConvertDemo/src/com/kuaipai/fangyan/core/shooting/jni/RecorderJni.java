package com.kuaipai.fangyan.core.shooting.jni;

import android.R.integer;
import android.app.Activity;
import android.util.Log;
import android.view.View;

import com.kuaipai.fangyan.core.shooting.jni.LibLoader;


import android.os.Bundle;


public class RecorderJni extends Activity{
	/**
     * Default library loader
     * Load them by yourself, if your libraries are not installed at default place.
     */
    private static LibLoader sLocalLibLoader = new LibLoader() {
        @Override
        public void loadLibrary(String libName) throws UnsatisfiedLinkError, SecurityException {
            System.loadLibrary(libName);
        }
    };
    

    private static volatile boolean mIsLibLoaded = false;
    public static void loadLibrariesOnce(LibLoader libLoader) {
        synchronized (RecorderJni.class) {
            if (!mIsLibLoaded) {

            	libLoader.loadLibrary("Mp4Transcode");
            	System.out.println("gdebug load Mp4Transcode ok ");
                mIsLibLoaded = true;
            }
        }
    } 
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		loadLibrariesOnce(sLocalLibLoader);
		System.out.println("gdebug test load ok");
		setContentView(R.layout.recode);	
		findViewById(R.id.btn_recod_mp4).setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				Mp4_Recorder_do_faststart("/sdcard/in.mp4", "/sdcard/out.mp4");
			}
			
		});
	}
	
    public native int Mp4_Recorder_do_faststart(String in_filename, String out_filename);
    
}
