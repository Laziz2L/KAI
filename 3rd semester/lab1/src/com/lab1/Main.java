package com.lab1;
import javax.swing.*;
import java.lang.String;

public class Main {

    public static void main(String[] args) {
        JFrame app = new JFrame("Решение квадратных уравнений");
        app.setBounds(600, 300, 750, 200);
        app.setContentPane(new JustGUI().panel1);
        app.setVisible(true);
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }





}


