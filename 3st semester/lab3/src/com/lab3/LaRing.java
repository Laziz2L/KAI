package com.lab3;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class LaRing {

    private Point point;
    private LaCircle circle1, circle2;
    private int count;


    LaRing(LaCircle Circle1, LaCircle Circle2, int c, Label lb) {

        this.point = Circle1.getPoint();
        this.circle1 = Circle1;
        this.circle2 = Circle2;
        this.count = c;

        mythread(lb);
    }

    LaRing(Point Point, LaCircle Circle1, LaCircle Circle2, int c, Label lb) {

        this.point = Point;
        this.circle1 = Circle1;
        this.circle2 = Circle2;
        this.count = c;

        mythread(lb);
    }

    public void show(boolean sh, GraphicsContext gc) {
        if (sh) {
            circle1.show(true, gc);
            circle2.show(false, gc);
        }
        else {
            circle1.show(false, gc);
            circle2.show(false, gc);
        }
    }

    public void moveTo(double dx, double dy, Canvas cnv, GraphicsContext gc) {
        this.show(false, gc);
        point.setX(this.point.getX() + dx);
        point.setY(this.point.getY() + dy);
        circle1.checkBorder(dx, dy, cnv);
        this.show(true, gc);
    }

    public void change(double p, Canvas cnv, GraphicsContext gc) {
        if (circle1.checkForResize(p, cnv)) {
            this.show(false, gc);
            this.circle2.setRadius(this.circle2.getRadius() - (this.circle1.getRadius() - p));
            this.circle1.setRadius(p);
            this.show(true, gc);
        }
    }

    public void delete(GraphicsContext gc) {
        this.show(false, gc);
    }

    public void ID(boolean t, GraphicsContext gc) {

        if (t) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillOval(
                    this.point.getX()-this.circle1.getRadius(), this.point.getY()-this.circle1.getRadius(),
                    2*this.circle1.getRadius(), 2*this.circle1.getRadius());
            circle2.show(false, gc);
        }
        else {
            this.show(true, gc);
        }
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

    public LaCircle getCircle1() {
        return circle1;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}

