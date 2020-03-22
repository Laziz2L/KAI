package com.lab3;

public class Point {

    private double X, Y;

    Point(double X0, double Y0) {
        this.X = X0;
        this.Y = Y0;
    }

    public double getX() {
        return X;
    }

    public void setX(double x) {
        X = x;
    }

    public double getY() {
        return Y;
    }

    public void setY(double y) {
        Y = y;
    }
}
