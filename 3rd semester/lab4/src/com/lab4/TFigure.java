package com.lab4;

import javafx.scene.canvas.GraphicsContext;

public abstract class TFigure {
    private double x;
    private double y;

    public TFigure(double x, double y) {
        this.x = x;
        this.y = y;
    }

    abstract public void Show(int sh, GraphicsContext gc);
    abstract public void MoveTo(double dx, double dy, GraphicsContext gc);

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
