package com.lab4;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Rectangle extends TFigure {
    private double length, height;
    private int count;

    public Rectangle(double x, double y, double l, double h, int count) {
       super(x, y);
       this.length = l;
       this.height = h;
       this. count = count;
    }
    @Override
    public void Show(int sh, GraphicsContext gc) {
        if (sh==1) {
            gc.setFill(Color.RED);
            gc.fillPolygon(new double[] {getX()-length/2, getX()+length/2, getX()+length/2, getX()-length/2},
                    new double[] {getY()-height/2, getY()-height/2, getY()+height/2, getY()+height/2},
                    4);
        }
        else if (sh==2) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillPolygon(new double[] {getX()-length/2, getX()+length/2, getX()+length/2, getX()-length/2},
                    new double[] {getY()-height/2, getY()-height/2, getY()+height/2, getY()+height/2},
                    4);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillPolygon(new double[] {getX()-length/2-1, getX()+length/2+1, getX()+length/2+1, getX()-length/2-1},
                    new double[] {getY()-height/2-1, getY()-height/2-1, getY()+height/2+1, getY()+height/2+1},
                    4);
        }
    }

    @Override
    public void MoveTo(double dx, double dy, GraphicsContext gc) {
        this.Show(3, gc);
        this.setX(this.getX() + dx);
        this.setY(this.getY() + dy);
        this.Show(1, gc);
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

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
}
