package com.lab2;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class LaCircle {

    private double x;
    private double y;
    private double radius;
    private int count;

    LaCircle(double r, int c, Canvas cnv, Label lb) {

        this.x = Math.random() * (cnv.getWidth()-2*(30+r)) + (30 + r);
        this.y = Math.random() * (cnv.getHeight()-2*(30 + r)) + (30 + r);
        this.radius = r;
        this.count = c;

        mythread(lb);
    }

    LaCircle(double x, double y, double r, int c, Label lb) {

        this.x = x;
        this.y = y;
        this.radius = r;
        this.count = c;

        mythread(lb);
    }

    private void doAlert(String text) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.showAndWait();
    }

    public void show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.BLUE);
            gc.fillOval(x-this.radius, y-this.radius, 2*this.radius, 2*this.radius);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(x-(this.radius+1), y-(this.radius+1), 2*(this.radius+1), 2*(this.radius+1));
        }
    }

    private void checkBorder(double dx, double dy, Canvas cnv) {
        if (cnv.getWidth()-x < radius) this.x -= dx;
        else if (x < radius) this.x -= dx;
        else if (cnv.getHeight()-y < radius) this.y -= dy;
        else if (y < radius) this.y -= dy;
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
            this.radius = p;
            this.show(true, gc);
        }
    }

    public void delete(GraphicsContext gc) {
        this.show(false, gc);
    }

    public void ID(boolean t, GraphicsContext gc) {
        if (t) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillOval(this.x-this.radius, this.y-this.radius, 2*this.radius, 2*this.radius);
        }
        else this.show(true, gc);
    }

    private boolean checkForResize(double R, Canvas cnv) {
        if ((cnv.getWidth()-x < R) || (x < R) || (cnv.getHeight()-y < R) || (y < R)) {
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

    public double getRadius() {
        return radius;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}
