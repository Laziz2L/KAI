package com.lab6;

import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class LaScene {

    Canvas cnv;
    GraphicsContext gc;
    Label lbl2, lbl3, lbl4, lbl5, lbl6, lbl7, lbl8;
    TextField tf2, tf3, tf4, tf5;
    Button btn1, btn2, btn3;
    CheckBox checkBox, checkBox2;
    ChoiceBox<String> choiceBox;
    Rectangle rect;
    Scene scene;

    //

    void function() {

        this.gc.setFill(Color.PEACHPUFF);
        this.gc.fillRect(0,0,1000,1000);

        this.tf2.setPrefColumnCount(5);
        this.tf3.setPrefColumnCount(5);
        this.tf4.setPrefColumnCount(5);
        this.tf5.setPrefColumnCount(5);

        this.choiceBox.setValue("Круг");

        this.checkBox.setSelected(false);

        this.rect.setWidth(200);
        this.rect.setHeight(100);
        this.rect.setFill(Color.GAINSBORO);


        FlowPane.setMargin(this.choiceBox, new Insets(-300,0,0,20));
        FlowPane.setMargin(this.btn1, new Insets(-300,0,0,20));
        FlowPane.setMargin(this.checkBox2, new Insets(-220,0,0,-196));
        FlowPane.setMargin(this.lbl5, new Insets(-150,0,0,-218));
        FlowPane.setMargin(this.tf2, new Insets(-150,0,0,10));
        FlowPane.setMargin(this.lbl6, new Insets(-80,0,0,-307));
        FlowPane.setMargin(this.tf3, new Insets(-80,0,0,10));
        FlowPane.setMargin(this.lbl7, new Insets(-10,0,0,-307));
        FlowPane.setMargin(this.tf4, new Insets(-10,0,0,10));
        FlowPane.setMargin(this.lbl8, new Insets(60,0,0,-159));
        FlowPane.setMargin(this.tf5, new Insets(60,0,0,10));
        FlowPane.setMargin(this.btn3, new Insets(140,0,0,-160));
        FlowPane.setMargin(this.checkBox, new Insets(215,0,0,-87));
        FlowPane.setMargin(this.lbl2, new Insets(215,0,0,0));
        FlowPane.setMargin(this.lbl4, new Insets(300,0,0, -252));
        FlowPane.setMargin(this.btn2, new Insets(370,0,0,-374));
        FlowPane.setMargin(this.rect, new Insets(510,0,0,-73));
        FlowPane.setMargin(this.lbl3, new Insets(520,0,0,-160));
        FlowPane.setMargin(this.cnv, new Insets(100,0,0,400));

    }

    LaScene(Canvas cnv, GraphicsContext gc, Label lbl2, Label lbl3, Button btn1,
            Button btn2, Button btn3, Label lbl4, ChoiceBox<String> choiceBox, CheckBox checkBox, Rectangle rect,
            Scene scene, Label lbl5, TextField tf2, Label lbl6, TextField tf3, CheckBox checkBox2, Label lbl7,
            TextField tf4, Label lbl8, TextField tf5) {

        this.cnv = cnv; // полотно
        this.gc = gc; // полотно
//        this.lbl1 = lbl1; // просит параметр
        this.lbl2 = lbl2; // пишет "фигура" после слов чекбокса
        this.lbl3 = lbl3; // уведомление
        this.lbl4 = lbl4; // "Для перемещения фигур используйте кнопки W,A,S,D."
        this.lbl5 = lbl5;
        this.lbl6 = lbl6;
        this.lbl7 = lbl7;
        this.lbl8 = lbl8;
//        this.tf1 = tf1; // записывает параметр
        this.tf2 = tf2;
        this.tf3 = tf3;
        this.tf4 = tf4;
        this.tf5 = tf5;
        this.btn1 = btn1; // создать
        this.btn2 = btn2; // удалить
        this.btn3 = btn3; // изменить
        this.checkBox = checkBox; // "Применить для всех фигур "
        this.checkBox2 = checkBox2; //в случ месте
        this.choiceBox = choiceBox; // "Круг", "Квадрат", "Отрезок", "Кольцо", "Фигура"
        this.scene = scene;
        this.rect = rect; // окно уведомлений


        function();

    }
}
