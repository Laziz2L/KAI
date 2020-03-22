package com.lab3;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;

public class LaCircle {

    private Point point;
    private double radius;
    private int count;


    LaCircle(double r, int c, Canvas cnv, Label lb) {
        this.point = new Point(Math.random() * (cnv.getWidth()-2*(30+r)) + (30 + r),
                Math.random() * (cnv.getHeight()-2*(30 + r)) + (30 + r));
        this.radius = r;
        this.count = c;

        mythread(lb);
    }

    LaCircle(Point point, double r, int c, Label lb) {

        this.point = point;
        this.radius = r;
        this.count = c;

        mythread(lb);
    }

    LaCircle(double r, Canvas cnv, Label lb) {
        this.point = new Point(Math.random() * (cnv.getWidth()-2*(30+r)) + (30 + r),
                Math.random() * (cnv.getHeight()-2*(30 + r)) + (30 + r));
        this.radius = r;

        mythread(lb);
    }

    LaCircle(Point point, double r) {
        this.point = point;
        this.radius = r;
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
            gc.fillOval(point.getX()-this.radius, point.getY()-this.radius, 2*this.radius, 2*this.radius);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(point.getX()-(this.radius+1), point.getY()-(this.radius+1), 2*(this.radius+1), 2*(this.radius+1));
        }
    }

    public void showFigure(double arc1, double arc2, GraphicsContext gc) {
        gc.setFill(Color.PEACHPUFF);
        gc.fillArc(point.getX()-2*this.radius, point.getY()-2*this.radius, 2*this.radius, 2*this.radius, arc1, arc2, ArcType.ROUND);
    }

    public void checkBorder(double dx, double dy, Canvas cnv) {
        if (cnv.getWidth()-point.getX() < radius) this.point.setX(this.point.getX() - dx);
        else if (point.getX() < radius) this.point.setX(this.point.getX() - dx);
        else if (cnv.getHeight()-point.getY() < radius) this.point.setY(this.point.getY() - dy);
        else if (point.getY() < radius) this.point.setY(this.point.getY() - dy);
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
            gc.fillOval(this.point.getX()-this.radius, this.point.getY()-this.radius, 2*this.radius, 2*this.radius);
        }
        else this.show(true, gc);
    }

    public boolean checkForResize(double R, Canvas cnv) {
        if ((cnv.getWidth()-point.getX() < R) || (point.getX() < R) || (cnv.getHeight()-point.getY() < R) || (point.getY() < R)) {
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

    public void setPoint(Point point) {
        this.point = point;
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

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Point getPoint() {
        return point;
    }
}
