package com.lab1;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyGUI extends JFrame{
    private JButton button = new JButton("Press");
//    private JTextField input = new JTextField("", 5);
    private JLabel label_input = new JLabel("Введите урванение :");
    private JLabel label1 = new JLabel("");
    private JLabel label2 = new JLabel("");
    private JLabel label3 = new JLabel("");
    private JLabel label4 = new JLabel("");
    private JLabel label5 = new JLabel("");
    private JLabel label_a = new JLabel("x*x + ");
    private JLabel label_b = new JLabel("x + ");
    private JLabel label_c = new JLabel(" = 0");
    private JTextField input_a = new JTextField("0");
    private JTextField input_b = new JTextField("0");
    private JTextField input_c = new JTextField("0");
//    private JRadioButton radio1 = new JRadioButton("Select this");
//    private JRadioButton radio2 = new JRadioButton("Select that");
//    private JCheckBox check = new JCheckBox("Check", false);

    public MyGUI () {
        super("Quadratic equations calculator");
        this.setBounds(600, 300, 750, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 6, 0, 0));

        container.add(label_input);

        container.add(input_a);
        container.add(label_a);
        container.add(input_b);
        container.add(label_b);
        container.add(input_c);
        container.add(label_c);

        button.addActionListener(new ButtonEventListener());
        container.add(button);
    }
    class ButtonEventListener implements ActionListener {
        public void actionPerformed (ActionEvent e) {
            String message = "";
            message += "Button was pressed\n";
//            message += "Text is " + input.getText() + "\n";
//            message += (radio1.isSelected() ? "Radio #1" : "Radio #2") + " is selected\n";
//            message += "CheckBox is " + ((check.isSelected()) ? "checked" : "unchecked");
            JOptionPane.showMessageDialog(null, message, "output", JOptionPane.PLAIN_MESSAGE);
        }
    }
}
