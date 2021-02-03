package com.lab7;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class Main extends Application{

    Alert alert;

    Canvas cnv = new Canvas(1000, 570);
    GraphicsContext gc = cnv.getGraphicsContext2D();

    Label lbl3 = new Label("           Hello!     ");
    Label lbl4 = new Label("Для перемещения фигур используйте кнопки W,A,S,D.");
    Label lbl5 = new Label("Перемещать : ");
    Button btn1 = new Button("Создать");
    Button btn2 = new Button("Уничтожить");
    Button btn3 = new Button("Добавить фигуру");

    ObservableList<String> langs = FXCollections.observableArrayList("Все", "Круги", "Прямоугольники", "Овалы",
            "Трапеции", "Ромбы"); 	//choice box
    ChoiceBox<String> choiceBox = new ChoiceBox<String>(langs);

    ObservableList<String> langs1 = FXCollections.observableArrayList("Массив", "Список"); 	//choice box
    ChoiceBox<String> choiceBox1 = new ChoiceBox<String>(langs1);

    javafx.scene.shape.Rectangle rect = new javafx.scene.shape.Rectangle();

    FlowPane root = new FlowPane(choiceBox1, btn1, btn2, btn3, lbl4, lbl5, choiceBox, rect, lbl3, cnv);
    Scene scene = new Scene(root);

    int flag = 0;
    double dx = 0, dy = 0;

    LaArray arr;
    boolean arrIsExist = false;
    LaList list;
    boolean listIsExist = false;


    public static void main(String[] args) {
        Application.launch(args);
    }

    private void mythread(String text) {
        LaThread mt = new LaThread(lbl3, text);
        Thread newThread = new Thread(mt);
        newThread.start();
    }

    void toMove(KeyCode key) {

        if (key == KeyCode.W) {
            dx = 0;
            dy = -5;
        }
        else if (key == KeyCode.S) {
            dx = 0;
            dy = 5;
        }
        else if (key == KeyCode.A) {
            dx = -5;
            dy = 0;
        }
        else if (key == KeyCode.D) {
            dx = 5;
            dy = 0;
        }
        else {
            dx = 0;
            dy = 0;
        }
    }

    @Override
    public void start(Stage stage) throws Exception {

        btn1.setOnAction(new EventHandler<ActionEvent>() {  	//button1 {Create}
            @Override
            public void handle(ActionEvent event) {
                if (choiceBox1.getValue()=="Массив") {
                    if (listIsExist) {
                        mythread("Список существует,\nРабота с массивом\nневозможна");
                    }
                    else if (arrIsExist) {
                        mythread("Массив уже существует");
                    } else {
                        arr  = new LaArray();
                        mythread("Массив создан");
                        arrIsExist = true;
                    }
                } else {
                    if (arrIsExist) {
                        mythread("Массив существует,\nРабота со списком\nневозможна");
                    }
                    else if (listIsExist) {
                        mythread("Список уже существует");
                    } else {
                        list  = new LaList();
                        mythread("Список создан");
                        listIsExist = true;
                    }
                }
            }
        });

        btn2.setOnAction(new EventHandler<ActionEvent>() {   	//button2 {Delete}
            @Override
            public void handle(ActionEvent event) {
                if (choiceBox1.getValue()=="Массив") {
                    if (listIsExist) {
                        mythread("Список существует,\nРабота с массивом\nневозможна");
                    }
                    else if (arrIsExist) {
                        arr.Iterator(4, cnv, gc, false, 0, 0, 0);
                        mythread("Массив уничтожен");
                        arrIsExist = false;
                    }
                    else mythread("Массив не создан");
                } else {
                    if (arrIsExist) {
                        mythread("Массив существует,\nРабота со списком\nневозможна");
                    }
                    else if (listIsExist) {
                        list.Iterator(4, cnv, gc, false, 0, 0, 0);
                        mythread("Список уничтожен");
                        listIsExist = false;
                    }
                    else mythread("Список не создан");
                }
            }
        });

        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {	// {Move}
            @Override
            public void handle(KeyEvent event) {
                KeyCode key = event.getCode();
                toMove(key);
                if (choiceBox1.getValue()=="Массив") {
                    if (listIsExist) {
                        mythread("Список существует,\nРабота с массивом\nневозможна");
                    }
                    else if (arrIsExist) {
                        toMove(key);
                        String type = choiceBox.getValue();
                        switch (type) {
                            case "Все" :
                                arr.Iterator(3, cnv, gc, false, 0, dx, dy);
                                break;
                            case "Круги" :
                                arr.Iterator(3, cnv, gc, false, 1, dx, dy);
                                break;
                            case "Прямоугольники" :
                                arr.Iterator(3, cnv, gc, false, 2, dx, dy);
                                break;
                            case "Овалы" :
                                arr.Iterator(3, cnv, gc, false, 3, dx, dy);
                                break;
                            case "Трапеции" :
                                arr.Iterator(3, cnv, gc, false, 4, dx, dy);
                                break;
                            case "Ромбы" :
                                arr.Iterator(3, cnv, gc, false, 5, dx, dy);
                                break;
                        }
                    }
                    else mythread("Массив не создан");
                } else {
                    if (arrIsExist) {
                        mythread("Массив существует,\nРабота со списком\nневозможна");
                    }
                    else if (listIsExist) {
                        toMove(key);
                        String type = choiceBox.getValue();
                        switch (type) {
                            case "Все" :
                                list.Iterator(3, cnv, gc, false, 0, dx, dy);
                                break;
                            case "Круги" :
                                list.Iterator(3, cnv, gc, false, 1, dx, dy);
                                break;
                            case "Прямоугольники" :
                                list.Iterator(3, cnv, gc, false, 2, dx, dy);
                                break;
                            case "Овалы" :
                                list.Iterator(3, cnv, gc, false, 3, dx, dy);
                                break;
                            case "Трапеции" :
                                list.Iterator(3, cnv, gc, false, 4, dx, dy);
                                break;
                            case "Ромбы" :
                                list.Iterator(3, cnv, gc, false, 5, dx, dy);
                                break;
                        }
                    }
                    else mythread("Список не создан");
                }
            }
        });

        btn3.setOnAction(new EventHandler<ActionEvent>() {  	//button3 {Add}
            @Override
            public void handle(ActionEvent event) {
                if (choiceBox1.getValue()=="Массив") {
                    if (listIsExist) {
                        mythread("Список существует,\nРабота с массивом\nневозможна");
                    }
                    else if (arrIsExist) {
                        arr.Iterator(2, cnv, gc, false, 0, 0, 0);
                        arr.Iterator(1, cnv, gc, false, 0, 0, 0);
                        arr.Iterator(2, cnv, gc, true, 0, 0, 0);
                        mythread("Фигура добавлена");
                    }
                    else mythread("Массив не создан");
                } else {
                    if (arrIsExist) {
                        mythread("Массив существует,\nРабота со списком\nневозможна");
                    }
                    else if (listIsExist) {
                        list.Iterator(2, cnv, gc, false, 0, 0, 0);
                        list.Iterator(1, cnv, gc, false, 0, 0, 0);
                        list.Iterator(2, cnv, gc, true, 0, 0, 0);
                        mythread("Фигура добавлена");
                    }
                    else mythread("Список не создан");
                }
            }
        });


        LaScene scn = new LaScene(choiceBox1, btn1, btn2, btn3, lbl4, lbl5, choiceBox, rect, lbl3, cnv, gc, scene);

        stage.setScene(scene);
        stage.setTitle("OOP");
        stage.setWidth(1750);
        stage.setHeight(700);
        stage.show();

    }
}
