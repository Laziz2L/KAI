package com.lab4;

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
import javafx.stage.Stage;

public class Main extends Application{

    Alert alert;

    Canvas cnv = new Canvas(1000, 570);
    GraphicsContext gc = cnv.getGraphicsContext2D();

//    Label lbl1 = new Label("Диаметр: ");
    Label lbl2 = new Label("'Круг'");
    Label lbl3 = new Label("           Hello!     ");
    Label lbl4 = new Label("Для перемещения фигур используйте кнопки W,A,S,D.");
    Label lbl5 = new Label("Координата X(центра фигуры)");
    Label lbl6 = new Label("Координата Y(центра фигуры)");
    Label lbl7 = new Label("Радиус 1");
    Label lbl8 = new Label("Радиус 2");
//    TextField tf1 = new TextField(); //для смены параметра
    TextField tf2 = new TextField(); //для икса
    TextField tf3 = new TextField(); //для игрика
    TextField tf4 = new TextField(); //р1, длина
    TextField tf5 = new TextField(); //р2, высота
    Button btn1 = new Button("Создать");
    Button btn2 = new Button("Удалить");
    Button btn3 = new Button("Изменить");
    CheckBox checkBox = new CheckBox("Применить для всех фигур ");
    CheckBox checkBox2 = new CheckBox("Создать в случайном месте");
    ObservableList<String> langs = FXCollections.observableArrayList("Круг", "Прямоугольник", "Овал", "Трапеция", "Ромб"); 	//choice box
    ChoiceBox<String> choiceBox = new ChoiceBox<String>(langs);
    javafx.scene.shape.Rectangle rect = new javafx.scene.shape.Rectangle();

    FlowPane root = new FlowPane(choiceBox, btn1, checkBox2, lbl5, tf2, lbl6, tf3, lbl7, tf4, lbl8, tf5,
            btn3, checkBox, lbl2, lbl4, btn2, rect, lbl3, cnv);
    Scene scene = new Scene(root);

    int id = -1;
    int count1 = -1, count2 = -1, count3 = -1, count4 = -1, count5 = -1;      //
    int flag = 1;

    double parametr1, parametr2;
    double dx = 0, dy = 0;        //для смещения
    double d = 40, l = 40, h = 40, r, r2, lp, hp;        //диаметр и длина по умолчанию для рандомного создания
    double temp;
    double x, y;
    static Circle[] mycircle = new Circle[100];
    static Rectangle[] mysquare = new Rectangle[100];
    static Ellipse[] myellipse = new Ellipse[100];
    static Trap[] mytrap = new Trap[100];
    static Rhomb[] myrhomb = new Rhomb[100];

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
            mycircle[i].Show(1, gc);
        for (int i = 0; i <= count2; i++)
            mysquare[i].Show(1, gc);
        for (int i = 0; i <= count3; i++)
            myellipse[i].Show(1, gc);
        for (int i = 0; i <= count4; i++)
            mytrap[i].Show(1, gc);
        for (int i = 0; i <= count5; i++)
            myrhomb[i].Show(1, gc);

        switch (flag) {
            case 1:
                mycircle[id].Show(2, gc);
                break;
            case 2:
                mysquare[id].Show(2, gc);
                break;
            case 3:
                myellipse[id].Show(2, gc);
                break;
            case 4:
                mytrap[id].Show(2, gc);
                break;
            case 5:
                myrhomb[id].Show(2, gc);
                break;
        }
    }

    void deleteObject() {

        switch (flag) {
            case 1:
                mycircle[id].Show(3, gc);
                for (int i = id; i < count1; i++) {
                    mycircle[i] = mycircle[i+1];
                    mycircle[i].setCount(mycircle[i].getCount() - 1);
                }
                count1 --;
                break;
            case 2:
                mysquare[id].Show(3, gc);
                for (int i = id; i < count2; i++) {
                    mysquare[i] = mysquare[i+1];
                    mysquare[i].setCount(mysquare[i].getCount() - 1);
                }
                count2 --;
                break;
            case 3:
                myellipse[id].Show(3, gc);
                for (int i = id; i < count3; i++) {
                    myellipse[i] = myellipse[i+1];
                    myellipse[i].setCount(myellipse[i].getCount() - 1);
                }
                count3 --;
                break;
            case 4:
                mytrap[id].Show(3, gc);
                for (int i = id; i < count4; i++) {
                    mytrap[i] = mytrap[i+1];
                    mytrap[i].setCount(mytrap[i].getCount() - 1);
                }
                count4 --;
                break;
            case 5:
                myrhomb[id].Show(3, gc);
                for (int i = id; i < count5; i++) {
                    myrhomb[i] = myrhomb[i+1];
                    myrhomb[i].setCount(myrhomb[i].getCount() - 1);
                }
                count5 --;
                break;
        }

        id = -1;
    }

    void getIndex(double x0, double y0) {

        double x1, y1, r1, r2, l1, h1;
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
                mycircle[j].Show(2, gc);
                lbl2.setText("'Круг'");
                lbl7.setText("Радиус");
                lbl8.setText("  ---------");

            }
            else mycircle[j].Show(1, gc);
        }

        for (int j = 0; j <= count2; j++) {
            x1 = mysquare[j].getX();
            y1 = mysquare[j].getY();
            l1 = mysquare[j].getLength();
            h1 = mysquare[j].getHeight();
            if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-h1/2<y1) && (y1<y0+h1/2) && !changeId)
            {
                flag = 2;
                id = j;
                changeId = true;
                mysquare[j].Show(2, gc);
                lbl2.setText("'Прямоугольник'");
                lbl7.setText("Длина");
                lbl8.setText("    Высота");
            }
            else mysquare[j].Show(1, gc);
        }

        for (int j = count3; j >= 0; j--) {
            x1 = myellipse[j].getX();
            y1 = myellipse[j].getY();
            r1 = myellipse[j].getRadius();
            r2 = myellipse[j].getRadius2();
            if ((Math.pow(x1-x0, 2)/Math.pow(r1, 2) + Math.pow(y1-y0, 2)/Math.pow(r2, 2) <= 1) && !changeId)
            {
                flag = 3;
                id = j;
                changeId = true;
                myellipse[j].Show(2, gc);
                lbl2.setText("'Овал'");
                lbl7.setText("Радиус 1");
                lbl8.setText("Радиус 2");

            }
            else myellipse[j].Show(1, gc);
        }

        for (int j = 0; j <= count4; j++) {
            x1 = mytrap[j].getX();
            y1 = mytrap[j].getY();
            l1 = mytrap[j].getLength();
            h1 = mytrap[j].getHeight();
            if ((y0>y1-h1/2) && (y0<y1+h1/2) && (y0>=(x0-(x1-l1/2))*(-h1)*2/l1+y1+h1/2) &&
                    (y0>=(x0-x1-l1/4)*(2*y1+h1)*2/l1+y1-h1/2) && !changeId)
            {
                flag = 4;
                id = j;
                changeId = true;
                mytrap[j].Show(2, gc);
                lbl2.setText("'Трапеция'");
                lbl7.setText("Длина");
                lbl8.setText("    Высота");
            }
            else mytrap[j].Show(1, gc);
        }

        for (int j = 0; j <= count5; j++) {
            x1 = myrhomb[j].getX();
            y1 = myrhomb[j].getY();
            l1 = myrhomb[j].getLength();
            h1 = myrhomb[j].getHeight();
            if ((y0>=(x0-x1)*h1/l1+y1-h1/2) && (y0<=(x0-x1)*(-h1)/l1+y1+h1/2) && (y0<=(x0-x1+l1/2)*h1/l1+y1) &&
                    (y0>=(x0-x1+l1/2)*(-h1)/l1+y1) && !changeId)
            {
                flag = 5;
                id = j;
                changeId = true;
                myrhomb[j].Show(2, gc);
                lbl2.setText("'Ромб'");
                lbl7.setText("Диагональ 1");
                lbl8.setText("Диагональ 2");
            }
            else myrhomb[j].Show(1, gc);
        }


        if (!changeId) id = -1;
    }

    void getChoiceBox(ChoiceBox<String> choiceBox) {

        if (choiceBox.getValue() == "Круг") {
            flag = 1;
            lbl2.setText("'Круг'");
            lbl7.setText("Радиус");
            lbl8.setText("  ---------");
        }
        else if (choiceBox.getValue() == "Прямоугольник") {
            flag = 2;
            lbl2.setText("'Прямоугольник'");
            lbl7.setText("Длина");
            lbl8.setText("    Высота");
        }
        else if (choiceBox.getValue() == "Овал") {
            flag = 3;
            lbl2.setText("'Овал'");
            lbl7.setText("Радиус 1");
            lbl8.setText("Радиус 2");
        }
        else if (choiceBox.getValue() == "Трапеция") {
            flag = 4;
            lbl2.setText("'Трапеция'");
            lbl7.setText("Длина");
            lbl8.setText("Высота");
        }
        else if (choiceBox.getValue() == "Ромб") {
            flag = 5;
            lbl2.setText("'Ромб'");
            lbl7.setText("Диагональ 1");
            lbl8.setText("Диагональ 2");
        }
    }

    void createObject() {

        if (checkBox2.isSelected()) {
            switch(flag) {
                case 1:
                    count1 ++;
                    mycircle[count1] = new Circle((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                            (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)), d/2, count1);
                    mythread();
                    mycircle[count1].Show(1, gc);

                    break;
                case 2:
                    count2 ++;
                    mysquare[count2] = new Rectangle((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                            (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)), l, h, count2);
                    mythread();
                    mysquare[count2].Show(1, gc);
                    break;
                case 3:
                    count3 ++;
                    myellipse[count3] = new Ellipse((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                            (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)), d/2, d, count3);
                    mythread();
                    myellipse[count3].Show(1, gc);

                    break;
                case 4:
                    count4 ++;
                    mytrap[count4] = new Trap((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                            (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)), l, h, count4);
                    mythread();
                    mytrap[count4].Show(1, gc);
                    break;
                case 5:
                    count5 ++;
                    myrhomb[count5] = new Rhomb((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                            (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)), l, h, count5);
                    mythread();
                    myrhomb[count5].Show(1, gc);
                    break;
            }
        }
        else {
            x = Double.parseDouble(tf2.getText());
            y = Double.parseDouble(tf3.getText());

            switch(flag) {
                case 1:
                    r = Double.parseDouble(tf4.getText());
                    if (x<(r+1) | y<(r+1) | x>(999-r) | y>(569-r)) {
                        doAlert("Круг выходит за рамки поля, создание невозможно. ");
                    }
                    else {
                        count1 ++;
                        mycircle[count1] = new Circle(x, y, r, count1);
                        mythread();
                        mycircle[count1].Show(1, gc);
                    }
                    break;
                case 2:
                    lp = Double.parseDouble(tf4.getText());
                    hp = Double.parseDouble(tf5.getText());
                    if (x<(lp+1) | y<(hp+1) | x>(999-lp) | y>(569-hp)) {
                        doAlert("Прямоугольник выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count2++;
                        mysquare[count2] = new Rectangle(x, y, lp, hp, count2);
                        mythread();
                        mysquare[count2].Show(1, gc);
                    }
                    break;
                case 3:
                    r = Double.parseDouble(tf4.getText());
                    r2 = Double.parseDouble(tf5.getText());
                    if (x<(r+1) | y<(r2+1) | x>(999-r) | y>(569-r2)) {
                        doAlert("Овал выходит за рамки поля, создание невозможно. ");
                    }
                    else {
                        count3 ++;
                        myellipse[count3] = new Ellipse(x, y, r, r2, count3);
                        mythread();
                        myellipse[count3].Show(1, gc);
                    }
                    break;
                case 4:
                    lp = Double.parseDouble(tf4.getText());
                    hp = Double.parseDouble(tf5.getText());
                    if (x<(lp+1) | y<(hp+1) | x>(999-lp) | y>(569-hp)) {
                        doAlert("Трапеция выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count4++;
                        mytrap[count4] = new Trap(x, y, lp, hp, count4);
                        mythread();
                        mytrap[count4].Show(1, gc);
                    }
                    break;
                case 5:
                    lp = Double.parseDouble(tf4.getText());
                    hp = Double.parseDouble(tf5.getText());
                    if (x<(lp+1) | y<(hp+1) | x>(999-lp) | y>(569-hp)) {
                        doAlert("Ромб выходит за рамки поля, создание невозможно. Допустимые интервалы координат " +
                                ": 21<=X<=979 , 21<=Y<=549");
                    }
                    else {
                        count5++;
                        myrhomb[count5] = new Rhomb(x, y, lp, hp, count5);
                        mythread();
                        myrhomb[count5].Show(1, gc);
                    }
                    break;

            }
        }


    }

    void resize(CheckBox checkBox) {

        switch(flag) {
            case 1:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count1; i++) {
                        if (mycircle[i].getX()<(parametr1+1) | mycircle[i].getY()<(parametr1+1) |
                                mycircle[i].getX()>(999-parametr1) | mycircle[i].getY()>(569-parametr1)) {
                            doAlert("Круг выходит за рамки поля, изменение невозможно. ");
                        }else {
                            mycircle[i].Show(3, gc);
                            mycircle[i].setRadius(parametr1);
                            mycircle[i].Show(1, gc);
                        }
                    }
                else {
                    if (mycircle[id].getX()<(parametr1+1) | mycircle[id].getY()<(parametr1+1) |
                            mycircle[id].getX()>(999-parametr1) | mycircle[id].getY()>(569-parametr1)) {
                        doAlert("Круг выходит за рамки поля, изменение невозможно. ");
                    }else {
                        mycircle[id].Show(3, gc);
                        mycircle[id].setRadius(parametr1);
                        mycircle[id].Show(1, gc);
                    }
                }
                break;
            case 2:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count2; i++) {
                        if (mysquare[i].getX()<(parametr1+1) | mysquare[i].getY()<(parametr2+1) |
                                mysquare[i].getX()>(999-parametr1) | mysquare[i].getY()>(569-parametr2)) {
                            doAlert("Прямоугольник выходит за рамки поля, изменение невозможно.");
                        }
                        else {
                            mysquare[i].Show(3, gc);
                            mysquare[i].setLength(parametr1);
                            mysquare[i].setHeight(parametr2);
                            mysquare[i].Show(1, gc);
                        }
                    }

                else {
                    if (mysquare[id].getX()<(parametr1+1) | mysquare[id].getY()<(parametr1+1) |
                            mysquare[id].getX()>(999-parametr2) | mysquare[id].getY()>(569-parametr2)) {
                        doAlert("Прямоугольник выходит за рамки поля, изменение невозможно.");
                    }
                    else {
                        mysquare[id].Show(3, gc);
                        mysquare[id].setLength(parametr1);
                        mysquare[id].setHeight(parametr2);
                        mysquare[id].Show(1, gc);
                    }
                }
                break;
            case 3:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count3; i++) {
                        if (myellipse[i].getX()<(parametr1+1) | myellipse[i].getY()<(parametr2+1) |
                                myellipse[i].getX()>(999-parametr1) | myellipse[i].getY()>(569-parametr2)) {
                            doAlert("Овал выходит за рамки поля, изменение невозможно. ");
                        }else {
                            myellipse[i].Show(3, gc);
                            myellipse[i].setRadius(parametr1);
                            myellipse[i].setRadius2(parametr2);
                            myellipse[i].Show(1, gc);
                        }
                    }
                else {
                    if (myellipse[id].getX()<(parametr1+1) | myellipse[id].getY()<(parametr2+1) |
                            myellipse[id].getX()>(999-parametr1) | myellipse[id].getY()>(569-parametr2)) {
                        doAlert("Овал выходит за рамки поля, изменение невозможно. ");
                    }else {
                        myellipse[id].Show(3, gc);
                        myellipse[id].setRadius(parametr1);
                        myellipse[id].setRadius2(parametr2);
                        myellipse[id].Show(1, gc);
                    }
                }
                break;
            case 4:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count4; i++) {
                        if (mytrap[i].getX()<(parametr1+1) | mytrap[i].getY()<(parametr2+1) |
                                mytrap[i].getX()>(999-parametr1) | mytrap[i].getY()>(569-parametr2)) {
                            doAlert("Трапеция выходит за рамки поля, изменение невозможно.");
                        }
                        else {
                            mytrap[i].Show(3, gc);
                            mytrap[i].setLength(parametr1);
                            mytrap[i].setHeight(parametr2);
                            mytrap[i].Show(1, gc);
                        }
                    }
                else {
                    if (mytrap[id].getX()<(parametr1+1) | mytrap[id].getY()<(parametr1+1) |
                            mytrap[id].getX()>(999-parametr2) | mytrap[id].getY()>(569-parametr2)) {
                        doAlert("Трапеция выходит за рамки поля, изменение невозможно.");
                    }
                    else {
                        mytrap[id].Show(3, gc);
                        mytrap[id].setLength(parametr1);
                        mytrap[id].setHeight(parametr2);
                        mytrap[id].Show(1, gc);
                    }
                }
                break;
            case 5:
                if (checkBox.isSelected())
                    for (int i = 0; i <= count5; i++) {
                        if (myrhomb[i].getX()<(parametr1+1) | myrhomb[i].getY()<(parametr2+1) |
                                myrhomb[i].getX()>(999-parametr1) | myrhomb[i].getY()>(569-parametr2)) {
                            doAlert("Ромб выходит за рамки поля, изменение невозможно.");
                        }
                        else {
                            myrhomb[i].Show(3, gc);
                            myrhomb[i].setLength(parametr1);
                            myrhomb[i].setHeight(parametr2);
                            myrhomb[i].Show(1, gc);
                        }
                    }
                else {
                    if (myrhomb[id].getX()<(parametr1+1) | myrhomb[id].getY()<(parametr1+1) |
                            myrhomb[id].getX()>(999-parametr2) | myrhomb[id].getY()>(569-parametr2)) {
                        doAlert("Ромб выходит за рамки поля, изменение невозможно.");
                    }
                    else {
                        myrhomb[id].Show(3, gc);
                        myrhomb[id].setLength(parametr1);
                        myrhomb[id].setHeight(parametr2);
                        myrhomb[id].Show(1, gc);
                    }
                }
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
        else if (key == KeyCode.T) {
            myellipse[id].Turn(gc);
        }
        else {
            dx = 0;
            dy = 0;
        }

        switch(flag) {
            case 1:
                mycircle[id].MoveTo(dx, dy, gc);
                if ((cnv.getWidth()-mycircle[id].getX() < mycircle[id].getRadius()) ||
                        (mycircle[id].getX() < mycircle[id].getRadius())) {
                    mycircle[id].Show(3, gc);
                    mycircle[id].setX(mycircle[id].getX() - dx);
                    mycircle[id].Show(1, gc);
                }
                else if ((cnv.getHeight()-mycircle[id].getY() < mycircle[id].getRadius()) ||
                        (mycircle[id].getY() < mycircle[id].getRadius())) {
                    mycircle[id].Show(3, gc);
                    mycircle[id].setY(mycircle[id].getY() - dy);
                    mycircle[id].Show(1, gc);
                }
                break;
            case 2:
                mysquare[id].MoveTo(dx, dy, gc);
                if ((cnv.getWidth()-mysquare[id].getX() < mysquare[id].getLength()/2) ||
                        (mysquare[id].getX() < mysquare[id].getLength()/2)) {
                    mysquare[id].Show(3, gc);
                    mysquare[id].setX(mysquare[id].getX() - dx);
                    mysquare[id].Show(1, gc);
                }
                else if ((cnv.getHeight()-mysquare[id].getY() < mysquare[id].getHeight()/2) ||
                        (mysquare[id].getY() < mysquare[id].getHeight()/2)) {
                    mysquare[id].Show(3, gc);
                    mysquare[id].setY(mysquare[id].getY() - dy);
                    mysquare[id].Show(1, gc);
                }
                break;
            case 3:
                myellipse[id].MoveTo(dx, dy, gc);
                if ((cnv.getWidth()-myellipse[id].getX() < myellipse[id].getRadius()) ||
                        (myellipse[id].getX() < myellipse[id].getRadius())) {
                    myellipse[id].Show(3, gc);
                    myellipse[id].setX(myellipse[id].getX() - dx);
                    myellipse[id].Show(1, gc);
                }
                else if ((cnv.getHeight()-myellipse[id].getY() < myellipse[id].getRadius2()) ||
                        (myellipse[id].getY() < myellipse[id].getRadius2())) {
                    myellipse[id].Show(3, gc);
                    myellipse[id].setY(myellipse[id].getY() - dy);
                    myellipse[id].Show(1, gc);
                }
                break;
            case 4:
                mytrap[id].MoveTo(dx, dy, gc);
                if ((cnv.getWidth()-mytrap[id].getX() < mytrap[id].getLength()/2) ||
                        (mytrap[id].getX() < mytrap[id].getLength()/2)) {
                    mytrap[id].Show(3, gc);
                    mytrap[id].setX(mytrap[id].getX() - dx);
                    mytrap[id].Show(1, gc);
                }
                else if ((cnv.getHeight()-mytrap[id].getY() < mytrap[id].getHeight()/2) ||
                        (mytrap[id].getY() < mytrap[id].getHeight()/2)) {
                    mytrap[id].Show(3, gc);
                    mytrap[id].setY(mytrap[id].getY() - dy);
                    mytrap[id].Show(1, gc);
                }
                break;
            case 5:
                myrhomb[id].MoveTo(dx, dy, gc);
                if ((cnv.getWidth()-myrhomb[id].getX() < myrhomb[id].getLength()/2) ||
                        (myrhomb[id].getX() < myrhomb[id].getLength()/2)) {
                    myrhomb[id].Show(3, gc);
                    myrhomb[id].setX(myrhomb[id].getX() - dx);
                    myrhomb[id].Show(1, gc);
                }
                else if ((cnv.getHeight()-myrhomb[id].getY() < myrhomb[id].getHeight()/2) ||
                        (myrhomb[id].getY() < myrhomb[id].getHeight()/2)) {
                    myrhomb[id].Show(3, gc);
                    myrhomb[id].setY(myrhomb[id].getY() - dy);
                    myrhomb[id].Show(1, gc);
                }
                break;
        }

        redraw();
    }


    private void mythread() {
        LaThread mt = new LaThread(lbl3);
        Thread newThread = new Thread(mt);
        newThread.start();
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
                parametr1 = Double.parseDouble(tf4.getText());
                if ((choiceBox.getValue() != "Круг")) {
                    parametr2 = Double.parseDouble(tf5.getText());
                }
                resize(checkBox);
                redraw();
            }
        });

        new LaScene(cnv, gc, lbl2, lbl3, btn1, btn2, btn3, lbl4,
                choiceBox, checkBox, rect, scene, lbl5, tf2, lbl6, tf3, checkBox2, lbl7, tf4, lbl8, tf5);

        stage.setScene(scene);
        stage.setTitle("OOP");
        stage.setWidth(1800);
        stage.setHeight(800);
        stage.show();

    }
}
