package com.lab5;

import javafx.scene.canvas.GraphicsContext;

public class TFigure {
    private double x;
    private double y;

    public TFigure(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void Show(int sh, GraphicsContext gc) {
        System.out.print("С фигурой что то сделали");
    }
    final public void MoveTo(double dx, double dy, GraphicsContext gc) {
        this.Show(3, gc);
        setX(this.getX() + dx);
        setY(this.getY() + dy);
        this.Show(1, gc);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }
}
