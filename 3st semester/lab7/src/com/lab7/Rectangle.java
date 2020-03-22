package com.lab7;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Rectangle extends TFigure {
    private double length, height;

    public Rectangle(double x, double y, double l, double h) {
       super(x, y);
       this.length = l;
       this.height = h;
    }
    @Override
    public void Show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.RED);
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

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
}
