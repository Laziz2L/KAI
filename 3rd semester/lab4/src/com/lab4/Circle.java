package com.lab4;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;

public class Circle extends TFigure{

    private double radius;
    private int count;

    public Circle (double x, double y, double r, int count) {
        super(x, y);
        this.radius = r;
        this.count = count;
    }

    @Override
    public void Show(int sh, GraphicsContext gc) {
        if (sh==1) {
            gc.setFill(Color.BLUE);
            gc.fillOval(getX()-this.radius, getY()-this.radius, 2*this.radius, 2*this.radius);
        }
        else if (sh==2) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillOval(this.getX()-this.radius, this.getY()-this.radius, 2*this.radius, 2*this.radius);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(getX()-(this.radius+1), getY()-(this.radius+1), 2*(this.radius+1), 2*(this.radius+1));
        }
    }

    @Override
    public void MoveTo(double dx, double dy, GraphicsContext gc) {
        this.Show(3, gc);
        setX(this.getX() + dx);
        setY(this.getY() + dy);
        this.Show(1, gc);
    }


    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}
