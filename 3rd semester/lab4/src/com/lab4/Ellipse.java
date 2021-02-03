package com.lab4;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Ellipse extends Circle {

    private double radius2;

    public Ellipse (double x, double y, double r, double r2, int count) {

        super(x, y, r, count);
        this.radius2 = r2;

    }

    @Override
    public void Show(int sh, GraphicsContext gc) {
        if (sh==1) {
            gc.setFill(Color.LIGHTSTEELBLUE);
            gc.fillOval(getX()-this.getRadius(), getY()-radius2, 2*this.getRadius(), 2*radius2);
        }
        else if (sh==2) {
            gc.setFill(Color.CHARTREUSE);
            gc.fillOval(this.getX()-this.getRadius(), this.getY()-this.radius2, 2*this.getRadius(), 2*this.radius2);
        }
        else {
            gc.setFill(Color.PEACHPUFF);
            gc.fillOval(getX()-(this.getRadius()+1), getY()-(radius2+1), 2*(this.getRadius()+1), 2*(radius2+1));
        }
    }

    public void Turn(GraphicsContext gc) {

        double temp = this.getRadius();
        this.Show(3, gc);
        this.setRadius(this.getRadius2());
        this.setRadius2(temp);
        this.Show(1, gc);
    }

    public double getRadius2() {
        return radius2;
    }

    public void setRadius2(double radius2) {
        this.radius2 = radius2;
    }
}
