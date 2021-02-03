package com.lab7;

import javafx.scene.canvas.GraphicsContext;

public class TFigure {
    private double x;
    private double y;

    public TFigure(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void Show(boolean sh, GraphicsContext gc) {
        System.out.print("С фигурой что то сделали");
    }
    final public void MoveTo(double dx, double dy, GraphicsContext gc) {
        this.Show(false, gc);
        setX(this.getX() + dx);
        setY(this.getY() + dy);
        this.Show(true, gc);
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
