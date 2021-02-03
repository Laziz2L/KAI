package com.lab2;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class LaSquare {

    private double x, y;
    private double length;
    private int count;

    LaSquare(double l, int c, Canvas cnv, Label lb) {

        this.x = Math.random() * (cnv.getWidth()-2*(30 + l/2)) + (30 + l/2);
        this.y = Math.random() * (cnv.getHeight()-2*(30 + l/2)) + (30 + l/2);
        this.length = l;
        this.count = c;

        mythread(lb);
    }

    LaSquare(double x, double y, double l, int c, Label lb) {

        this.x = x;
        this.y = y;
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
            gc.setFill(Color.RED);
            gc.fillRect(
                    x-length/2, y-length/2, this.length, this.length);
            }
            else {
                gc.setFill(Color.PEACHPUFF);
                gc.fillRect(x-length/2-1, y-length/2-1, this.length+2, this.length+2);
            }
    }

    private void checkBorder(double dx, double dy, Canvas cnv) {
        if (cnv.getWidth()-x < length/2) this.x -= dx;
        else if (x < length/2) this.x -= dx;
        else if (cnv.getHeight()-y < length/2) this.y -= dy;
        else if (y < length/2) this.y -= dy;
    }

    public void moveTo(double dx, double dy, Canvas cnv, GraphicsContext gc) {
        this.show(false, gc);
        x += dx;
        y += dy;
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
            gc.fillRect(x-length/2, y-length/2, this.length, this.length);
        }
        else this.show(true, gc);
    }

    private boolean checkForResize(double L, Canvas cnv) {
        if ((cnv.getWidth()-x < L/2) || (x < L/2) || (cnv.getHeight()-y < L/2) || (y < L/2)) {
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
        return x;
    }

    public double getY() {
        return y;
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
