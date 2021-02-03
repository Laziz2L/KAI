package com.lab7;

import javafx.application.Platform;
import javafx.scene.control.Label;

public class LaThread implements Runnable{

    static Label label;

    @Override
    public void run() {
        try {
            Thread.sleep(2000);

            Platform.runLater(() -> {
                LaThread.label.setText("                        ");
            });

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    LaThread(Label lb, String text) {
        LaThread.label = lb;
        LaThread.label.setText(text);
    }

}
