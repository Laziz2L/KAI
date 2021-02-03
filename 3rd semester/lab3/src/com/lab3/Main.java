package com.lab3;

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
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.FlowPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Main extends Application{

    Alert alert;

    Canvas cnv = new Canvas(1000, 570);
    GraphicsContext gc = cnv.getGraphicsContext2D();

    Label lbl1 = new Label("Диаметр: ");
    Label lbl2 = new Label("'Круг'");
    Label lbl3 = new Label("           Hello!     ");
    Label lbl4 = new Label("Для перемещения фигур используйте кнопки W,A,S,D.");
    Label lbl5 = new Label("Координата X(центра фигуры)");
    Label lbl6 = new Label("Координата Y(центра фигуры)");
    TextField tf1 = new TextField(); //для смены параметра
    TextField tf2 = new TextField(); //для икса
    TextField tf3 = new TextField(); //для игрика
    Button btn1 = new Button("Создать");
    Button btn2 = new Button("Удалить");
    Button btn3 = new Button("Изменить");
    CheckBox checkBox = new CheckBox("Применить для всех фигур ");
    CheckBox checkBox2 = new CheckBox("Создать в случайном месте");
    ObservableList<String> langs = FXCollections.observableArrayList("Круг", "Квадрат", "Отрезок", "Кольцо", "Шоколадка"); 	//choice box
    ChoiceBox<String> choiceBox = new ChoiceBox<String>(langs);
    Rectangle rect = new Rectangle();

    FlowPane root = new FlowPane(choiceBox, btn1,lbl5, tf2, lbl6, tf3, checkBox2, btn2, lbl4, lbl1, tf1, checkBox, lbl2, btn3, rect, lbl3, cnv);
    Scene scene = new Scene(root);

    int id = -1, count0 = -1;                           //0 - количество точек, 1 - кругов, 2 - квадратов, 3 - отрезков
    int count1 = -1, count2 = -1, count3 = -1, count4 = -1, count5 = -1;      //
    int flag = 1;

    double parametr;              //берется из tf1
    double dx = 0, dy = 0;        //для смещения
    double d = 40, l = 40;        //диаметр и длина по умолчанию для рандомного создания
    double border = 30;
    double x, y;
    static LaCircle[] mycircle = new LaCircle[100];
    static Square[] mysquare = new Square[100];
    static LaLine[] myline = new LaLine[100];
    static LaRing[] myring = new LaRing[100];
    static LaChocolate[] mychocolate = new LaChocolate[100];
    static Point[] mypoint = new Point[500];

    public static void main(String[] args) {
        Application.launch(args);
    }

    void doAlert(String text) {
        alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.showAndWait();
    }

    void redraw() {
        for (int i = 0; i <= count1; i++)
            mycircle[i].show(true, gc);
        for (int i = 0; i <= count2; i++)
            mysquare[i].show(true, gc);
        for (int i = 0; i <= count3; i++)
            myline[i].show(true, gc);
        for (int i = 0; i <= count4; i++)
            myring[i].show(true, gc);
        for (int i = 0; i <= count5; i++)
            mychocolate[i].show(true, gc);

        switch (flag) {
            case 1:
                mycircle[id].ID(true, gc);
                break;
            case 2:
                mysquare[id].ID(true, gc);
                break;
            case 3:
                myline[id].ID(true, gc);
                break;
            case 4:
                myring[id].ID(true, gc);
                break;
            case 5:
                mychocolate[id].ID(true, gc);
                break;
        }
    }

    void deleteObject() {

        switch (flag) {
            case 1:
                mycircle[id].delete(gc);
                for (int i = id; i < count1; i++) {
                    mycircle[i] = mycircle[i+1];
                    mycircle[i].setCount(mycircle[i].getCount() - 1);
                }
                count1 --;
                break;
            case 2:
                mysquare[id].delete(gc);
                for (int i = id; i < count2; i++) {
                    mysquare[i] = mysquare[i+1];
                    mysquare[i].setCount(mysquare[i].getCount() - 1);
                }
                count2 --;
                break;
            case 3:
                myline[id].delete(gc);
                for (int i = id; i < count3; i++) {
                    myline[i] = myline[i+1];
                    myline[i].setCount(myline[i].getCount() - 1);
                }
                count3 --;
                break;
            case 4:
                myring[id].delete(gc);
                for (int i = id; i < count4; i++) {
                    myring[i] = myring[i+1];
                    myring[i].setCount(myring[i].getCount() - 1);
                }
                count4 --;
                break;
            case 5:
                mychocolate[id].delete(gc);
                for (int i = id; i < count5; i++) {
                    mychocolate[i] = mychocolate[i+1];
                    mychocolate[i].setCount(mychocolate[i].getCount() - 1);
                }
                count5 --;
                break;
        }

        id = -1;
    }

    void getIndex(double x0, double y0) {

        double x1, y1, r1, l1;
        boolean changeId = false;

        for (int j = count1; j >= 0; j--) {
            x1 = mycircle[j].getX();
            y1 = mycircle[j].getY();
            r1 = mycircle[j].getRadius();
            if ((Math.pow(x1-x0, 2)+Math.pow(y1-y0, 2) <= r1*r1) && !changeId)
            {
                flag = 1;
                id = j;
                changeId = true;
                mycircle[j].ID(true, gc);
                lbl1.setText("Диаметр: ");
                lbl2.setText("'Круг'");
            }
            else mycircle[j].ID(false, gc);
        }

        for (int j = 0; j <= count2; j++) {
            x1 = mysquare[j].getX();
            y1 = mysquare[j].getY();
            l1 = mysquare[j].getLength();
            if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-l1/2<y1) && (y1<y0+l1/2) && !changeId)
            {
                flag = 2;
                id = j;
                changeId = true;
                mysquare[j].ID(true, gc);
                lbl1.setText("Длина: ");
                lbl2.setText("'Квадрат'");
            }
            else mysquare[j].ID(false, gc);
        }

        for (int j = 0; j <= count3; j++) {
            x1 = myline[j].getX();
            y1 = myline[j].getY();
            l1 = myline[j].getLength();
            if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-7<y1) && (y1<y0+7) && !changeId)
            {
                flag = 3;
                id = j;
                changeId = true;
                myline[j].ID(true, gc);
                lbl1.setText("Длина: ");
                lbl2.setText("'Отрезок'");
            }
            else myline[j].ID(false, gc);
        }
        for (int j = 0; j <= count4; j++) {
            x1 = myring[j].getX();
            y1 = myring[j].getY();
            r1 = myring[j].getCircle1().getRadius();
            if (Math.pow(x1 - x0, 2) + Math.pow(y1 - y0, 2) <= r1 * r1 && !changeId) {
                flag = 4;
                id = j;
                changeId = true;
                myring[j].ID(true,gc);
                lbl1.setText("Диаметр: ");
                lbl2.setText("'Кольцо'");
            } else myring[j].ID(false,gc);
        }
        for (int j = 0; j <= count5; j++) {
            x1 = mychocolate[j].getPoint().getX();
            y1 = mychocolate[j].getPoint().getY();
            l1 = mychocolate[j].getSquare().getLength();
            if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-l1/2<y1) && (y1<y0+l1/2) && !changeId)
            {
                flag = 5;
                id = j;
                changeId = true;
                mychocolate[j].ID(true, gc);
                lbl1.setText("Длина: ");
                lbl2.setText("'Шоколадка'");
            }
            else mychocolate[j].ID(false, gc);
        }


        if (!changeId) id = -1;
    }

    void getChoiceBox(ChoiceBox<String> choiceBox) {

        if (choiceBox.getValue() == "Круг") {
            flag = 1;
            lbl1.setText("Диаметр: ");
            lbl2.setText("'Круг'");
        }
        else if (choiceBox.getValue() == "Квадрат") {
            flag = 2;
            lbl1.setText("Длина: ");
            lbl2.setText("'Квадрат'");
        }
        else if (choiceBox.getValue() == "Отрезок") {
            flag = 3;
            lbl1.setText("Длина: ");
            lbl2.setText("'Отрезок'");
        }
        else if (choiceBox.getValue() == "Кольцо") {
            flag = 4;
            lbl1.setText("Диаметр: ");
            lbl2.setText("'Кольцо'");
        }
        else if (choiceBox.getValue() == "Шоколадка") {
            flag = 5;
            lbl1.setText("Длина: ");
            lbl2.setText("'Шоколадка'");
        }
    }

    void createObject() {

        if (checkBox2.isSelected()) {
            switch(flag) {
                case 1:
                    count1 ++; count0 ++;
                    mycircle[count1] = new LaCircle(d/2, count1, cnv, lbl3);
                    mycircle[count1].show(true, gc);

                    break;
                case 2:
                    count2 ++; count0 ++;
                    mysquare[count2] = new Square(l, count2, cnv, lbl3);
                    mysquare[count2].show(true, gc);
                    break;
                case 3:
                    count3 ++; count0 ++;
                    myline[count3] = new LaLine(l, count3, cnv, lbl3);
                    myline[count3].show(true, gc);
                    break;
                case 4:
                    count4 ++; count0 ++;
                    LaCircle mycircle1 = new LaCircle(d/2, cnv, lbl3);
                    LaCircle mycircle2 = new LaCircle(mycircle1.getPoint(), d/2-5);
                    myring[count4] = new LaRing(mycircle1, mycircle2, count4, lbl3);
                    myring[count4].show(true, gc);
                    break;
                case 5:
                    count5 ++; count0 ++;
                    Square mysquare = new Square(d/2+13, cnv);
                    mysquare.show(true, gc);
                    LaCircle mycircle = new LaCircle(mysquare.getPoint(), d/2);
                    mychocolate[count5] = new LaChocolate(mysquare, mycircle, count5, lbl3);
                    mychocolate[count5].show(true, gc);
                    break;
            }
        }
        else {
            x = Double.parseDouble(tf2.getText());
            y = Double.parseDouble(tf3.getText());

            switch(flag) {
                case 1:
                    if (x<21 | y<21 | x>979 | y>549) {
                        doAlert("Круг выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count1 ++; count0 ++;
                        mypoint[count0] = new Point(x, y);
                        mycircle[count1] = new LaCircle(mypoint[count0], d/2, count1, lbl3);
                        mycircle[count1].show(true, gc);
                    }
                    break;
                case 2:
                    if (x<21 | y<21 | x>979 | y>549) {
                        doAlert("Квадрат выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count2++;
                        count0++;
                        mypoint[count0] = new Point(x, y);
                        mysquare[count2] = new Square(mypoint[count0], l, count2, lbl3);
                        mysquare[count2].show(true, gc);
                    }
                    break;
                case 3:
                    if (x<21 | y<1 | x>979 | y>570) {
                        doAlert("Отрезок выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 1<=Y<=570");
                    }
                    else {
                        count3++;
                        count0++;
                        mypoint[count0] = new Point(x, y);
                        myline[count3] = new LaLine(mypoint[count0], l, count3, lbl3);
                        myline[count3].show(true, gc);
                    }
                    break;
                case 4:
                    if (x<21 | y<21 | x>979 | y>549) {
                        doAlert("Круг выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count4 ++; count0 ++;
                        mypoint[count0] = new Point(x, y);
                        LaCircle mycircle1 = new LaCircle(mypoint[count0], d/2);
                        LaCircle mycircle2 = new LaCircle(mypoint[count0], d/2-5);
                        myring[count4] = new LaRing(mypoint[count0], mycircle1, mycircle2, count4, lbl3);
                        myring[count4].show(true, gc);
                    }
                    break;
                case 5:
                    if (x<21 | y<21 | x>979 | y>549) {
                        doAlert("Шоколадка выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count5 ++; count0 ++;
                        mypoint[count0] = new Point(x, y);
                        Square mysquare = new Square(mypoint[count0], d/2+13);
                        mysquare.show(true, gc);
                        LaCircle mycircle = new LaCircle(mypoint[count0], d/2);
                        mychocolate[count5] = new LaChocolate(mypoint[count0], mysquare, mycircle, count5, lbl3);
                        mychocolate[count5].show(true, gc);
                        break;
                    }
                    break;
            }
        }


    }

    void resize(CheckBox checkBox) {

        switch(flag) {
            case 1:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count1; i++)
                        mycircle[i].change(parametr, cnv, gc);
                else
                    mycircle[id].change(parametr, cnv, gc);
                break;
            case 2:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count2; i++)
                        mysquare[i].change(parametr, cnv, gc);
                else
                    mysquare[id].change(parametr, cnv, gc);
                break;
            case 3:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count3; i++)
                        myline[i].change(parametr, cnv, gc);
                else
                    myline[id].change(parametr, cnv, gc);
                break;
            case 4:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count4; i++)
                        myring[i].change(parametr, cnv, gc);
                else
                    myring[id].change(parametr, cnv, gc);
                break;
            case 5:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count5; i++)
                        mychocolate[i].change(parametr, cnv, gc);
                else
                    mychocolate[id].change(parametr, cnv, gc);
                break;
        }
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

        switch(flag) {
            case 1:
                mycircle[id].moveTo(dx, dy, cnv, gc);
                break;
            case 2:
                mysquare[id].moveTo(dx, dy, cnv, gc);
                break;
            case 3:
                myline[id].moveTo(dx, dy, cnv, gc);
                break;
            case 4:
                myring[id].moveTo(dx, dy, cnv, gc);
                break;
            case 5:
                mychocolate[id].moveTo(dx, dy,  cnv, gc);
                break;
        }

        redraw();
    }

    @Override
    public void start(Stage stage) throws Exception {

        choiceBox.setOnAction(event -> {			//choice box action
            getChoiceBox(choiceBox);
        });

        btn1.setOnAction(new EventHandler<ActionEvent>() {  	//button1 {Create}
            @Override
            public void handle(ActionEvent event) {
                createObject();
            }
        });

        cnv.setOnMouseClicked(new EventHandler<MouseEvent>() {		//mouse event
            @Override
            public void handle(MouseEvent event) {
                getIndex(event.getX(),event.getY());
            }
        });

        btn2.setOnAction(new EventHandler<ActionEvent>() {   	//button2 {Delete}
            @Override
            public void handle(ActionEvent event) {
                //id = Integer.parseInt(tf1.getText());
                deleteObject();
                redraw();
            }
        });

        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {	// {Move}
            @Override
            public void handle(KeyEvent event) {
                if (id > -1) {
                    KeyCode key = event.getCode();
                    toMove(key);
                }
            }
        });

        btn3.setOnAction(new EventHandler<ActionEvent>() {  	//button3 {Resize}
            @Override
            public void handle(ActionEvent event) {
                parametr = Double.parseDouble(tf1.getText());
                resize(checkBox);
                redraw();
            }
        });

        new LaScene(cnv, gc, lbl1, lbl2, lbl3, tf1, btn1, btn2, btn3, lbl4, choiceBox, checkBox, rect, scene, lbl5, tf2, lbl6, tf3, checkBox2);

        stage.setScene(scene);
        stage.setTitle("OOP");
        stage.setWidth(1700);
        stage.setHeight(800);
        stage.show();
    }
}
