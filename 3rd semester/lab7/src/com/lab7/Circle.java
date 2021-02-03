package com.lab7;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Circle extends TFigure{

    private double radius;

    public Circle (double x, double y, double r) {
        super(x, y);
        this.radius = r;
    }

    @Override
    public void Show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.BLUE);
            gc.fillOval(getX()-this.radius, getY()-this.radius, 2*this.radius, 2*this.radius);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(getX()-(this.radius+1), getY()-(this.radius+1), 2*(this.radius+1), 2*(this.radius+1));
        }
    }


    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
}
