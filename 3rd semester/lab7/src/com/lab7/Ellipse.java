package com.lab7;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Ellipse extends Circle {

    private double radius2;

    public Ellipse (double x, double y, double r, double r2) {

        super(x, y, r);
        this.radius2 = r2;

    }

    @Override
    public void Show(boolean sh, GraphicsContext gc) {
        if (sh) {
            gc.setFill(Color.LIGHTSTEELBLUE);
            gc.fillOval(getX()-this.getRadius(), getY()-radius2, 2*this.getRadius(), 2*radius2);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(getX()-(this.getRadius()+1), getY()-(radius2+1), 2*(this.getRadius()+1), 2*(radius2+1));
        }
    }

    public void Turn(GraphicsContext gc) {

        double temp = this.getRadius();
        this.Show(false, gc);
        this.setRadius(this.getRadius2());
        this.setRadius2(temp);
        this.Show(true, gc);
    }

    public double getRadius2() {
        return radius2;
    }

    public void setRadius2(double radius2) {
        this.radius2 = radius2;
    }
}
