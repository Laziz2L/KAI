package com.lab1;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JustGUI {
    public JPanel panel1;
    public JButton finalbutton;
    public JLabel greetinglabel;
    public JLabel Alabel;
    public JTextField inputA;
    public JLabel XAlabel;
    public JLabel Blabel;
    public JTextField inputB;
    public JLabel XBlabel;
    public JLabel Clabel;
    public JTextField inputC;

    public JustGUI() {
        finalbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                inputA.setText("0");
//                inputB.setText("0");
//                inputC.setText("0");

                String msg = "";

                Pattern p = Pattern.compile("([-])?(([0-9]){1,}([\\.]){0,})+");
                Matcher mA = p.matcher(inputA.getText());
                Matcher mB = p.matcher(inputB.getText());
                Matcher mC = p.matcher(inputC.getText());

                if (mA.matches() & mB.matches() & mC.matches()) {
                    double a = 0;
                    double b = 0;
                    double c = 0;
                    a += Double.parseDouble(inputA.getText());
                    b += Double.parseDouble(inputB.getText());
                    c += Double.parseDouble(inputC.getText());
                    Quadratic eq = new Quadratic(a, b, c);
                    msg += "Дискриминант уравнения равен : " + eq.discriminant() + "\n";
                    if (eq.discriminant() < 0) {
                        msg += "Дискриминант меньше нуля, действительных корней нет.";
                    } else if (eq.discriminant() == 0) {
                        msg += "Дискриминант равен нулю, корень уравнения единственный\n";
                        msg += "Корень уравнения : " + eq.result1();
                    } else {
                        msg += "Дискриминант больше нуля, существует два корня уравнения\n";
                        msg += "Первый корень : " + eq.result1() + "\n";
                        msg += "Второй корень : " + eq.result2();
                    }
                } else {
                    msg += "Введите данные корректно\n";
                    msg += "Допустимы цифры от 0 до 9 и символ \".\"\n";
                    msg += "Также убедитесь, что точка стоит в правильном месте (если имеется)";
                }

                JOptionPane.showMessageDialog(null, msg, "output", JOptionPane.PLAIN_MESSAGE);
            }
        });
    }
}
