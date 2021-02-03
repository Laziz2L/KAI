package com.lab3;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;

public class LaChocolate {

    private Point point;
    private LaCircle circle;
    private Square square;
    private int count;

    LaChocolate(Point Point, Square Square, LaCircle Circle, int c, Label lb) {

        this.point = Point;
        this.square = Square;
        this.circle = Circle;
        this.count = c;

        mythread(lb);
    }

    LaChocolate(Square Square, LaCircle Circle, int c, Label lb) {

        this.point = Square.getPoint();
        this.square = Square;
        this.circle = Circle;
        this.count = c;

        mythread(lb);
    }

    public void show(boolean sh, GraphicsContext gc) {
        if (sh) {
            square.showFigure(true, gc);
            circle.showFigure(0, -90, gc);
        }
        else {
            square.show(false, gc);
            circle.show(false, gc);
        }
    }

    public void moveTo(double dx, double dy, Canvas cnv, GraphicsContext gc) {
        this.show(false, gc);
        point.setX(point.getX() + dx);
        point.setY(point.getY() + dy);
        square.checkBorder(dx, dy, cnv);
        this.show(true, gc);
    }

    public void change(double p, Canvas cnv, GraphicsContext gc) {
        if (square.checkForResize(p, cnv)) {
            this.show(false, gc);
            this.circle.setRadius(this.circle.getRadius() - (this.square.getLength() - p)/2);
            this.square.setLength(p);
            this.show(true, gc);
        }
    }

    public void delete(GraphicsContext gc) {
        this.show(false, gc);
    }

    public void ID(boolean t, GraphicsContext gc) {
        if (t) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillRect(point.getX()-this.square.getLength()/2, point.getY()-this.square.getLength()/2,
                    this.square.getLength(), this.square.getLength());
            circle.showFigure(0, -90, gc);
        }
        else this.show(true, gc);
    }

    private void mythread(Label label) {
        LaThread mt = new LaThread(label);
        Thread newThread = new Thread(mt);
        newThread.start();
    }

    public Point getPoint() {
        return point;
    }
    public Square getSquare() {
        return square;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}



