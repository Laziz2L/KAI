package com.lab3;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;

public class Square {

    private Point point;
    private double length;
    private int count;

    Square(double l, int c, Canvas cnv, Label lb) {
        this.point = new Point((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)));
        this.length = l;
        this.count = c;

        mythread(lb);
    }

    Square(Point point, double l, int c, Label lb) {

        this.point = point;
        this.length = l;
        this.count = c;

        mythread(lb);
    }

    Square(Point Point, double l) {
        this.point = Point;
        this.length = l;
    }

    Square(double l, Canvas cnv) {
        this.point = new Point((Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2)),
                (Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2)));
        this.length = l;
    }

    private void doAlert(String text) {
        Alert alert;
        alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.showAndWait();
    }

    public void show(boolean sh, GraphicsContext gc) {
            if (sh) {
            gc.setFill(Color.RED);
            gc.fillRect(
                    point.getX()-length/2, point.getY()-length/2, this.length, this.length);
            }
            else {
                gc.setFill(Color.PEACHPUFF);
                gc.fillRect(point.getX()-length/2-1, point.getY()-length/2-1, this.length+2, this.length+2);
            }
    }

    public void showFigure(boolean sh, GraphicsContext gc){
        gc.setFill(Color.SADDLEBROWN);
        gc.fillRect(
                point.getX()-length/2, point.getY()-length/2, this.length, this.length);
    }

    public void checkBorder(double dx, double dy, Canvas cnv) {
        if (cnv.getWidth()-point.getX() < length/2) this.point.setX(this.point.getX() - dx);
        else if (point.getX() < length/2) this.point.setX(this.point.getX() - dx);
        else if (cnv.getHeight()-point.getY() < 5) this.point.setY(this.point.getY() - dy);
        else if (point.getY() < 5) this.point.setY(this.point.getY() - dy);
    }

    public void moveTo(double dx, double dy, Canvas cnv, GraphicsContext gc) {
        this.show(false, gc);
        point.setX(this.point.getX() + dx);
        point.setY(this.point.getY() + dy);
        checkBorder(dx, dy, cnv);
        this.show(true, gc);
    }

    public void change(double p, Canvas cnv, GraphicsContext gc) {
        if (checkForResize(p, cnv)) {
            this.show(false, gc);
            this.length = p;
            this.show(true, gc);
        }
    }


    public void delete(GraphicsContext gc) {
        this.show(false, gc);
    }

    public void ID(boolean t, GraphicsContext gc) {
        if (t) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillRect(point.getX()-length/2, point.getY()-length/2, this.length, this.length);
        }
        else this.show(true, gc);
    }

    public boolean checkForResize(double L, Canvas cnv) {
        if ((cnv.getWidth()-point.getX() < L/2) || (point.getX() < L/2) || (cnv.getHeight()-point.getY() < L/2) || (point.getY() < L/2)) {
            doAlert("Изменения невозможны, фигура выходит за рамки поля!");
            return false;
        }
        else return true;
    }

    private void mythread(Label label) {
        LaThread mt = new LaThread(label);
        Thread newThread = new Thread(mt);
        newThread.start();
    }

    public Point getPoint() {
        return point;
    }

    public double getX() {
        return point.getX();
    }

    public double getY() {
        return point.getY();
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void setPoint(Point point) {
        this.point = point;
    }
}
