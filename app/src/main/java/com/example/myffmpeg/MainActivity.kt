package com.example.myffmpeg

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myffmpeg.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    companion object{
        init {
            System.loadLibrary("native-lib")
        }
    }

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.sampleText.text=Jni.ffmpegInfo()
    }

}