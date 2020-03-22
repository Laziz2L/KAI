package com.lab3;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;

public class LaLine {

    private Point point;
    private double length;
    private int count;

    LaLine(double l, int c, Canvas cnv, Label lb) {
        this.point = new Point(Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2),
                Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2));
        this.length = l;
        this.count = c;

        mythread(lb);
    }

    LaLine(Point point, double l, int c, Label lb) {

        this.point = point;
        this.length = l;
        this.count = c;

        mythread(lb);
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
            gc.setFill(Color.BLACK);
            gc.fillRect(
                    point.getX()-length/2, point.getY()-2, this.length, 4);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillRect(point.getX()-length/2-5, point.getY()-2-5, this.length+10, 4+10);
        }
    }

    private void checkBorder(double dx, double dy, Canvas cnv) {
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
            gc.fillRect(
                    point.getX()-length/2, point.getY()-2, this.length, 4);
        }
        else this.show(true, gc);
    }

    private boolean checkForResize(double L, Canvas cnv) {
        if ((cnv.getWidth()-point.getX() < L/2) || (point.getX() < L/2) || (cnv.getHeight()-point.getY() < 5) || (point.getY() < 5)) {
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

    public double getX() {
        return point.getX();
    }

    public double getY() {
        return point.getY();
    }

    public double getLength() {
        return length;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}
