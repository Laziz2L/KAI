package com.lab7;

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
    Label lbl3, lbl4, lbl5;
    Button btn1, btn2, btn3;
    ChoiceBox<String> choiceBox, choiceBox1;
    Rectangle rect;
    Scene scene;

    //

    void function() {

        this.gc.setFill(Color.PEACHPUFF);
        this.gc.fillRect(0,0,1000,1000);

        this.choiceBox1.setValue("Массив");
        this.choiceBox.setValue("Все");

        this.rect.setWidth(200);
        this.rect.setHeight(100);
        this.rect.setFill(Color.GAINSBORO);


        FlowPane.setMargin(this.choiceBox1, new Insets(-190,0,0,20));
        FlowPane.setMargin(this.btn1, new Insets(-190,0,0,20));
        FlowPane.setMargin(this.btn2, new Insets(-100,0,0,-192));
        FlowPane.setMargin(this.btn3, new Insets(-10,0,0,-102));
        FlowPane.setMargin(this.lbl4, new Insets(90,0,0, -137));
        FlowPane.setMargin(this.lbl5, new Insets(170,0,0,-375));
        FlowPane.setMargin(this.choiceBox, new Insets(170,0,0,10));
        FlowPane.setMargin(this.rect, new Insets(400,0,0,-270));
        FlowPane.setMargin(this.lbl3, new Insets(400,0,0,-200));
        FlowPane.setMargin(this.cnv, new Insets(40,0,0,500));



    }

    LaScene(ChoiceBox choiceBox1, Button btn1, Button btn2, Button btn3, Label lbl4, Label lbl5,
            ChoiceBox choiceBox, Rectangle rect, Label lbl3, Canvas cnv, GraphicsContext gc, Scene scene) {

        this.cnv = cnv;
        this.gc = gc;
        this.lbl3 = lbl3;
        this.lbl4 = lbl4;
        this.lbl5 = lbl5;
        this.btn1 = btn1;
        this.btn2 = btn2;
        this.btn3 = btn3;
        this.choiceBox = choiceBox;
        this.choiceBox1 = choiceBox1;
        this.scene = scene;
        this.rect = rect;

        function();

    }
}
