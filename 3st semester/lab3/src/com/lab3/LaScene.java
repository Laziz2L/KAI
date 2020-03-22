package com.lab3;

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
    Label lbl1, lbl2, lbl3, lbl4, lbl5, lbl6;
    TextField tf1, tf2, tf3;
    Button btn1, btn2, btn3;
    CheckBox checkBox, checkBox2;
    ChoiceBox<String> choiceBox;
    Rectangle rect;
    Scene scene;

    //

    void function() {

        this.gc.setFill(Color.PEACHPUFF);
        this.gc.fillRect(0,0,1000,1000);

        this.tf1.setPrefColumnCount(5);
        this.tf2.setPrefColumnCount(5);
        this.tf3.setPrefColumnCount(5);

        this.choiceBox.setValue("Круг");

        this.checkBox.setSelected(false);

        this.rect.setWidth(200);
        this.rect.setHeight(100);
        this.rect.setFill(Color.GAINSBORO);


        FlowPane.setMargin(this.choiceBox, new Insets(-500,0,0,20));
        FlowPane.setMargin(this.btn1, new Insets(-500,0,0,20));
        FlowPane.setMargin(this.lbl5, new Insets(-410,0,0,-200));
        FlowPane.setMargin(this.tf2, new Insets(-410,0,0,10));
        FlowPane.setMargin(this.lbl6, new Insets(-320,0,0,-306));
        FlowPane.setMargin(this.tf3, new Insets(-320,0,0,10));
        FlowPane.setMargin(this.checkBox2, new Insets(-230,0,0,-306));
        FlowPane.setMargin(this.btn2, new Insets(-100,0,0,-218));
        FlowPane.setMargin(this.lbl4, new Insets(30,0,0, -74));
        FlowPane.setMargin(this.lbl1, new Insets(140,0,0,-374));
        FlowPane.setMargin(this.tf1, new Insets(140,0,0,10));
        FlowPane.setMargin(this.checkBox, new Insets(250,0,0,-167));
        FlowPane.setMargin(this.lbl2, new Insets(250,0,0,0));
        FlowPane.setMargin(this.btn3, new Insets(340,0,0,-255));
        FlowPane.setMargin(this.rect, new Insets(570,0,0,-88));
        FlowPane.setMargin(this.lbl3, new Insets(570,0,0,-150));
        FlowPane.setMargin(this.cnv, new Insets(40,0,0,375));

    }

    LaScene(Canvas cnv, GraphicsContext gc, Label lbl1, Label lbl2, Label lbl3, TextField tf1, Button btn1, Button btn2, Button btn3,
            Label lbl4, ChoiceBox<String> choiceBox, CheckBox checkBox, Rectangle rect, Scene scene,
            Label lbl5, TextField tf2, Label lbl6, TextField tf3, CheckBox checkBox2) {

        this.cnv = cnv; // полотно
        this.gc = gc; // полотно
        this.lbl1 = lbl1; // просит параметр
        this.lbl2 = lbl2; // пишет "фигура" после слов чекбокса
        this.lbl3 = lbl3; // уведомление
        this.lbl4 = lbl4; // "Для перемещения фигур используйте кнопки W,A,S,D."
        this.lbl5 = lbl5;
        this.lbl6 = lbl6;
        this.tf1 = tf1; // записывает параметр
        this.tf2 = tf2;
        this.tf3 = tf3;
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
